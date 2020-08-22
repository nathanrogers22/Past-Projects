////////////////////////////////////////////////////////////////////////////////
//
//  File           : lcloud_filesys.c
//  Description    : This is the implementation of the Lion Cloud device 
//                   filesystem interfaces.
//
//   Author        : *** INSERT YOUR NAME ***
//   Last Modified : *** DATE ***
//

// Include files
#include <stdlib.h>
#include <string.h>
#include <cmpsc311_log.h>

// Project include files
#include <lcloud_filesys.h>
#include <lcloud_controller.h>

//
// File system interface implementation
int POWERON = 0;
int device_ID = 0;
int firstWrite = 0;
int firstRead = 0;
int writeBlock = 0;
char test_buf[256] = {(char) 0 };
typedef struct RegMap{
    char B0;
    char B1;
    uint8_t C0;
    uint8_t C1;
    uint8_t C2;
    uint16_t D0;
    uint16_t D1;
}Registers;

typedef struct fileInfo{
    LcFHandle fh;
    int Size;
    int position;
    const char *path;
    int isOpen;
    struct fileInfo *next;
}fInfo;
fInfo fileInformation;

typedef struct blockMap{
    int WRhead;
    int currentBlock;
    int currentSector;
    int blockPos;
}Blocks;
Blocks currPos;

//make the blocks structure inside of the file information inside of a new structure that holds the file handles specifically.

int writingMatrix[LC_DEVICE_NUMBER_BLOCKS][LC_DEVICE_NUMBER_SECTORS] = {[0 ... (LC_DEVICE_NUMBER_BLOCKS-1)][0 ... (LC_DEVICE_NUMBER_SECTORS-1)] = 0};

LCloudRegisterFrame create_lcloud_registers(char B0, char B1, uint8_t C0, uint8_t C1, uint8_t C2, uint16_t D0, uint16_t D1){
    LCloudRegisterFrame frame = 0;
    frame = ((uint64_t) B0 << 60) | frame;
    frame = ((uint64_t) B1 << 56) | frame;
    frame = ((uint64_t) C0 << 48) | frame;
    frame = ((uint64_t) C1 << 40) | frame;
    frame = ((uint64_t) C2 << 32) | frame;
    frame = ((uint64_t) D0 << 16) | frame;
    frame = (uint64_t) D1 | frame;
    return frame;
 }

 Registers extract_lcloud_registers(LCloudRegisterFrame frame){
     Registers outputregisters;
     outputregisters.D1 = (frame&0x000000000000ffff);
     outputregisters.D0 = (frame&0x00000000ffff0000)>>16;
     outputregisters.C2 = (frame&0x000000ff00000000)>>32; 
     outputregisters.C1 = (frame&0x0000ff0000000000)>>40;
     outputregisters.C0 = (frame&0x00ff000000000000)>>48;
     outputregisters.B1 = (frame&0x0f00000000000000)>>32;
     outputregisters.B0 = (frame&0xf000000000000000)>>60;

     return(outputregisters);
 }

int POWER_ON(void){
    int B0 = 0;
    int B1 = 0;
    int C0 = LC_POWER_ON;
    int C1 = 0;
    int C2 = 0;
    int D0 = 0;
    int D1 = 0;
    LCloudRegisterFrame busvalin = create_lcloud_registers(B0, B1, C0, C1, C2, D0, D1);
    lcloud_io_bus(busvalin, NULL);
    POWERON = 1;
    return(0);
}

//in write and read, create a buffer of 256 bytes 

int PROBE(){
    int B0 = 0;
    int B1 = 0;
    int C0 = LC_DEVPROBE;
    int C1 = 0;
    int C2 = 0;
    int D0 = 0;
    int D1 = 0;
    LCloudRegisterFrame busvalin = create_lcloud_registers(B0, B1, C0, C1, C2, D0, D1);
    Registers busvalout = extract_lcloud_registers(lcloud_io_bus(busvalin, NULL));

    for(int i=0; i<16; i++){
        if(busvalout.D0 & (1 << i)){
            device_ID = i;
        }
    }    
    return(0);
}
////////////////////////////////////////////////////////////////////////////////
//
// Function     : lcopen
// Description  : Open the file for for reading and writing
//
// Inputs       : path - the path/filename of the file to be read
// Outputs      : file handle if successful test, -1 if failure

LcFHandle lcopen( const char *path ) {
    POWER_ON();
    PROBE();
    if(fileInformation.isOpen == 1){
        return(-1);
    }
    if(fileInformation.isOpen == 0){
        LcFHandle fh = 5;
        fileInformation.fh = fh;
        fileInformation.path = path;
        fileInformation.isOpen = 1;
        fileInformation.Size = 0;
        fileInformation.position = 0;
    }
    return( fileInformation.fh );
} 

////////////////////////////////////////////////////////////////////////////////
//
// Function     : lcread
// Description  : Read data from the file 
//
// Inputs       : fh - file handle for the file to read from
//                buf - place to put the data
//                len - the length of the read
// Outputs      : number of bytes read, -1 if failure
int lcread( LcFHandle fh, char *buf, size_t len ) {
    //int nextIf2 = 1;
    if(fileInformation.fh != fh){
        return(-1);
    }
    if(fileInformation.fh == fh){
        if(fileInformation.isOpen == 0){
            return(-1);
        }
        if(fileInformation.isOpen == 1){
            if(len == 0){
                return(0);
            }
            if(len > 0){
                if(firstRead == 0){
                    currPos.currentSector = 0;
                    currPos.currentBlock = 0;
                    currPos.WRhead = 0;
                    currPos.blockPos = 0;
                    firstRead = 1;
                }
                if(firstRead != 0){
                    if (currPos.WRhead == 0){
                        //start reading from the beginning after the first write
                        currPos.blockPos = 0;
                        currPos.currentBlock = 0;
                        currPos.currentSector = 0;
                    }
                    int B0 = 0;
                    int B1 = 0;
                    int C0 = LC_BLOCK_XFER;
                    int C1 = device_ID;
                    int C2 = LC_XFER_READ;
                    int D0 = currPos.currentSector;
                    int D1 = currPos.currentBlock;
                    currPos.blockPos = currPos.WRhead % 256;

                    if((len + currPos.blockPos) <= 256){
                        logMessage(LcDriverLLevel, "current block: %d, current sector: %d", currPos.currentBlock, currPos.currentSector);
                        LCloudRegisterFrame busvalin = create_lcloud_registers(B0, B1, C0, C1, C2, D0, D1);
                        logMessage(LcDriverLLevel, "current read write head: %d", currPos.WRhead);
                        lcloud_io_bus(busvalin, buf);
                        logMessage(LcDriverLLevel, "Buffer after io call: %s", buf);
                        memcpy(buf, &buf[currPos.blockPos], len);
                        logMessage(LcDriverLLevel, "buffer after memcpy: %s", buf);
                        currPos.WRhead = currPos.WRhead + len;
                        logMessage(LcDriverLLevel, "current read write head: %d", currPos.WRhead);
                        

                    }
                    //Goes into this if statement if the current read write head is greater than 256
                    if(((len + currPos.blockPos) > 256)){    
                        int B0 = 0;
                        int B1 = 0;
                        int C0 = LC_BLOCK_XFER;
                        int C1 = device_ID;
                        int C2 = LC_XFER_READ;
                        int D0 = currPos.currentSector;
                        int D1 = currPos.currentBlock;
                        LCloudRegisterFrame busvalin2 = create_lcloud_registers(B0, B1, C0, C1, C2, D0, D1);
                        lcloud_io_bus(busvalin2, buf);
                        memcpy(buf, &buf[currPos.blockPos], (256-currPos.blockPos));
                        currPos.currentBlock = currPos.currentBlock + 1;
                        int templen = len - (256-currPos.blockPos);
                        currPos.blockPos = len - templen;
                        B0 = 0;
                        B1 = 0;
                        C0 = LC_BLOCK_XFER;
                        C1 = device_ID;
                        C2 = LC_XFER_READ;
                        D0 = currPos.currentSector;
                        D1 = currPos.currentBlock;
                        LCloudRegisterFrame busvalin3 = create_lcloud_registers(B0, B1, C0, C1, C2, D0, D1);
                        char tempBuf[256];
                        memset(tempBuf, 0, 256);
                        lcloud_io_bus(busvalin3, tempBuf);
                        memcpy(&buf[currPos.blockPos], tempBuf, templen); 
                        currPos.WRhead = currPos.WRhead + len;
                        
                    }
                }
            }
        }
    }
    return( len );
}

////////////////////////////////////////////////////////////////////////////////
//
// Function     : lcwrite
// Description  : write data to the file
//
// Inputs       : fh - file handle for the file to write to
//                buf - pointer to data to write
//                len - the length of the write
// Outputs      : number of bytes written if successful test, -1 if failure

int lcwrite( LcFHandle fh, char *buf, size_t len ) {
    int nextIf = 1;
    char passedBuffer[256];
    memset(passedBuffer, 0, sizeof(passedBuffer));
    char modifiedBuf[256];
    memset(modifiedBuf, 0, sizeof(modifiedBuf));
    memcpy(passedBuffer, buf, len);
    //logMessage(LcDriverLLevel, "buf value: %p", buf);
    //logMessage(LcDriverLLevel, "What is being written: %s", buf);
    int count = len;
    if(fileInformation.fh != fh){
        return(-1);
    }
    if(fileInformation.fh == fh){
        if(firstWrite == 0){
            currPos.currentBlock = 0; //initialize the current block to block 0
            currPos.currentSector = 0; //initialize the current block to 0;
            firstWrite = 1;
        }
        if(firstWrite != 0){
            fileInformation.Size = fileInformation.Size + len;
            fileInformation.position = fileInformation.Size;
            int blockCounter = 0;
            while(currPos.blockPos >= 256){
                currPos.blockPos = currPos.blockPos - 256;
                logMessage(LcDriverLLevel, "taking the current block Position down: %d", currPos.blockPos);
                memset(test_buf, 0, LC_DEVICE_BLOCK_SIZE);
                logMessage(LcDriverLLevel, "test buf: %s", test_buf);
                currPos.currentBlock = currPos.currentBlock + 1;
                blockCounter = blockCounter + 1;
            }
            if(currPos.currentBlock == 64){
                currPos.currentBlock = currPos.currentBlock - 64;
                currPos.currentSector = currPos.currentSector + 1;
            }
            
            int currBlock = currPos.currentBlock;
            int currSect = currPos.currentSector;
            
            
            int B0 = 0;
            int B1 = 0;
            int C0 = LC_BLOCK_XFER;
            int C1 = device_ID;
            int C2 = LC_XFER_WRITE;
            int D0 = currSect;
            int D1 = currBlock;
            logMessage(LcDriverLLevel, "currSect: %d, currBlock: %d", currSect, currBlock);

            currPos.WRhead = currPos.WRhead + len;
            if(len<256){
                if((len+(currPos.blockPos))<=256){
                    logMessage(LcDriverLLevel, "Will fit into the current block");
                    memcpy(&modifiedBuf[currPos.blockPos], passedBuffer, len+1);  
                    logMessage(LcDriverLLevel, "Passed Buffer: %s", passedBuffer);
                    LCloudRegisterFrame busvalin = create_lcloud_registers(B0, B1, C0, C1, C2, D0, D1);
                    logMessage(LcDriverLLevel, "block position before io bus: %d", currPos.blockPos);
                    //logMessage(LcDriverLLevel, "Passed Buffer: %s", passedBuffer);
                    memcpy(&test_buf[currPos.blockPos], passedBuffer, len);
                    logMessage(LcDriverLLevel, "Test Buffer: %s", test_buf);  
                    lcloud_io_bus(busvalin, test_buf);
                    currPos.blockPos = currPos.blockPos + len;
                    logMessage(LcDriverLLevel, "block position after io bus: %d", currPos.blockPos);
                    nextIf = 0;
                }
                
                if((len+(currPos.blockPos))>256 && nextIf == 1) {
                    logMessage(LcDriverLLevel, "Getting into the one where the entire buffer wont fit into the current block");
                    int temp = len - (256 - currPos.blockPos);
                    logMessage(LcDriverLLevel, "temp: %d", temp);
                    memcpy(&test_buf[currPos.blockPos], passedBuffer, (256 - currPos.blockPos));
                    logMessage(LcDriverLLevel, "calculating remaining space: %d", (256 - currPos.blockPos));
                    LCloudRegisterFrame busvalin = create_lcloud_registers(B0, B1, C0, C1, C2, D0, D1);
                    logMessage(LcDriverLLevel, "test_buf: %s", test_buf);
                    lcloud_io_bus(busvalin, test_buf);
                    currPos.currentBlock = currPos.currentBlock + 1;
                    currPos.blockPos = 0;
                    logMessage(LcDriverLLevel, "taking the current block Position down: %d", currPos.blockPos);
                    memset(test_buf, 0, LC_DEVICE_BLOCK_SIZE);
                    logMessage(LcDriverLLevel, "block position: %d", currPos.blockPos);
                    logMessage(LcDriverLLevel, "current length: %d", len);
                    logMessage(LcDriverLLevel, "temp: %d", temp);
                    logMessage(LcDriverLLevel, "passed buffer before recursion call: %s", &passedBuffer[(len-temp)]);
                    lcwrite(fileInformation.fh, &passedBuffer[(len-temp)], temp);

                }
                
            }
            if(len==256){
                if(currPos.blockPos == 0){
                    LCloudRegisterFrame busvalin = create_lcloud_registers(B0, B1, C0, C1, C2, D0, D1);
                    lcloud_io_bus(busvalin, test_buf);
                    currPos.blockPos = 0;
                }
                
                if(currPos.blockPos > 0){
                    int temp = len - (256 - currPos.blockPos);
                    memcpy(&modifiedBuf[currPos.blockPos], passedBuffer, temp);
                    LCloudRegisterFrame busvalin = create_lcloud_registers(B0, B1, C0, C1, C2, D0, D1);
                    lcloud_io_bus(busvalin, test_buf);
                    currPos.currentBlock = currPos.currentBlock + 1;
                    currPos.blockPos = 0;
                    currPos.blockPos = currPos.blockPos + temp;
                    lcwrite(fileInformation.fh, &test_buf[len-temp], temp);
                }  
            }

           /*
            writeBlock++;
            if(writeBlock == 8){
                exit(0);
            }
            */
            
            
            
            
        }
    }
    return( count );
}

////////////////////////////////////////////////////////////////////////////////
//
// Function     : lcseek
// Description  : Seek to a specific place in the file
//
// Inputs       : fh - the file handle of the file to seek in
//                off - offset within the file to seek to
// Outputs      : 0 if successful test, -1 if failure

int lcseek( LcFHandle fh, size_t off ) {
    logMessage(LcDriverLLevel, "Getting into seek");
    if(fileInformation.fh != fh){
        return(-1);
    }
    if(fileInformation.fh == fh){
        currPos.WRhead = off;
    }    
    return( 0 );
}

////////////////////////////////////////////////////////////////////////////////
//
// Function     : lcclose
// Description  : Close the file
//
// Inputs       : fh - the file handle of the file to close
// Outputs      : 0 if successful test, -1 if failure

int lcclose( LcFHandle fh ) {
    if(fileInformation.isOpen == 0){
        return(-1);
    }
    if(fileInformation.isOpen == 1){
        fileInformation.fh = -1;
        fileInformation.path = " ";
    }
    return( 0 );
}

////////////////////////////////////////////////////////////////////////////////
//
// Function     : lcshutdown
// Description  : Shut down the filesystem
//
// Inputs       : none
// Outputs      : 0 if successful test, -1 if failure

int lcshutdown( void ) {
    if(POWERON == 0){
        return(-1);
    }
    if(POWERON == 1){
        int B0 = 0;
        int B1 = 0;
        int C0 = LC_POWER_OFF;
        int C1 = 0;
        int C2 = 0;
        int D0 = 0;
        int D1 = 0;
        LCloudRegisterFrame busvalin = create_lcloud_registers(B0, B1, C0, C1, C2, D0, D1);
        lcloud_io_bus(busvalin, NULL);
    }
    return( 0 );
}
