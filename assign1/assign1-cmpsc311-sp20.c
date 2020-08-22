////////////////////////////////////////////////////////////////////////////////
//
//  File           : cmpsc311-f16-assign1.c
//  Description    : This is the main source code for for the first assignment
//                   of CMPSC311, Spring 2020, at Penn State.
//                   assignment page for details.
//
//   Author        : Nathan Rogers
//   Last Modified : Jan 27
//

// Include Files
#include <stdio.h>
#include <string.h>

#define NUM_TEST_ELEMENTS 100


// Functions
////////////////////////////////////////////////////////////////////////////////
//
// Function     : round311
// Description  : This function rounds the floating point numbers to the nearest integer number and appends the values to the integer array
//
// Inputs       : float *float_array
//                int *int_array
// Outputs      : 0 if successful test, -1 if failure
int round311(float *float_array, int *int_array) {
    for (int i=0; i<NUM_TEST_ELEMENTS; i++) {
        float FtoI = float_array[i] + 0.5;
        int conv = (int) FtoI;
        int_array[i] = conv;
    }
    return( 0 );
}
////////////////////////////////////////////////////////////////////////////////
//
// Function     : printfloatArr311
// Description  : This function prints out the float array
//
// Inputs       : float *arrPointer
//                int arraySize
// Outputs      : prints out the float array
int printfloatArr311(float *arrPointer, int arraySize){
    for(int i=0; i<arraySize; i++){
        printf("%.2f", arrPointer[i]);
        if ((i)<arraySize-1) {
            printf(", ");
        }
        if ((i) == arraySize-1){
            printf("\n");
        }
    }
    return( 0 );
}
////////////////////////////////////////////////////////////////////////////////
//
// Function     : printIntArr311
// Description  : This function prints the integer array
//
// Inputs       : int *arrPointer
//                int arraySize
// Outputs      : prints out the integer array
int printIntArr311(int *arrPointer, int arraySize){
    for(int i=0; i<arraySize; i++){
        printf("%d", arrPointer[i]);
        if ((i)<arraySize-1) {
            printf(", ");
        }
        if ((i) == arraySize-1){
            printf("\n");
        }
    }
    return( 0 );
}
////////////////////////////////////////////////////////////////////////////////
//
// Function     : bubbleSort311
// Description  : This function sorts the integer array using a bubble sort
//
// Inputs       : int *arrayIpointer
//                int arraySize
// Outputs      : Prints out the finished bubble sort
void bubbleSort311(int *arrayIpointer, int arraySize){
    int temp;
    for (int i=0; i<(arraySize-1); i++){
        for(int s=0; s<(arraySize-i-1); s++){
            if (arrayIpointer[s] > arrayIpointer[s+1]){
                temp = arrayIpointer[s];
                arrayIpointer[s] = arrayIpointer[s+1];
                arrayIpointer[s+1] = temp;
            }
        }
    }
}
////////////////////////////////////////////////////////////////////////////////
//
// Function     : toBinary
// Description  : Takes in the integer array and a value and converts the last 5 integers in the int array to binary
//
// Inputs       : char val
//                int *int_array
// Outputs      : outputs the binary conversion of the integers
void toBinary(char val, int *int_array){
    int value = (int)val;
    int i = int_array[value];
    int temp_array[8] = { [0 ... 7] = 0 };
    int array_count = 7;
    while(i>0){
        if((i%2)==0){
            i = (i / 2);
            temp_array[array_count]=0;
            array_count = array_count -1;
        }
        if((i%2)==1){
            i = (i / 2);
            temp_array[array_count]=1;
            array_count = array_count -1;
        }
    }
    for(int n=0; n<8; n++){
        printf("%d", temp_array[n]);
        if(n==3){
            printf(" ");
        }
        if(n==7){
            printf("\n");
        }
    }
}

int countRange311(int *int_array, int fsize, int min, int max){
    int counter = 0;
    for (int i=0; i<fsize; i++){
        if((min<=int_array[i]) && (int_array[i]<=max)){
            counter = counter + 1;
        }
    }
    
    //printf("%.2f to %.2f counter = %d\n", min, max, counter);
    return counter;
}
////////////////////////////////////////////////////////////////////////////////
//
// Function     : histogram311
// Description  : This function takes in the count of each section and prints out the histogram *I apologize for how lengthy this part was, I tried to implement a 2D array
//                  and it turned out to be very difficult and lengthy but I was too far into this idea to change within the time I had before the due time.
//
// Inputs       : histogram array that holds the count - int *histogram_array
//                
// Outputs      : prints the histogram
int histogram311(int *histogram_array){
    int counter1 = 0;
    int counter2 = 0;
    int counter3 = 0;
    int counter4 = 0;
    int counter5 = 0;
    int counter6 = 0;
    int counter7 = 0;
    int counter8 = 0;
    int counter9 = 0;
    int counter10 = 0;
    int counterCounter = 0;
    //counter assignments based on the histogram counter array
    counter1 = histogram_array[0];
    counter2 = histogram_array[1];
    counter3 = histogram_array[2];
    counter4 = histogram_array[3];
    counter5 = histogram_array[4];
    counter6 = histogram_array[5];
    counter7 = histogram_array[6];
    counter8 = histogram_array[7];
    counter9 = histogram_array[8];
    counter10 = histogram_array[9];

    int counter = 0;
    for (int i=0; i<10; i++){
        if((histogram_array[i])!=0){
            counter = counter + 1;
        }
    }
    if (counter == 0){
        //do not print out the histogram
        printf("-1");
    }
    if ((counter)!=0){
        
        char TwoDarray[23][10] = { "  " };
        int n = 0;
        for (int i=0; i<10; i++){  //for TwoDarray[i][] - columns
            if((counterCounter) == 0){
                n = counter1;
            }
            if((counterCounter) == 1){
                n = counter2;
                
            }
            if((counterCounter) == 2){
                n = counter3;
                
            }
            if((counterCounter) == 3){
                n = counter4;
                
            }
            if((counterCounter) == 4){
                n = counter5;
                
            }
            if((counterCounter) == 5){
                n = counter6;
                
            }
            if((counterCounter) == 6){
                n = counter7;
                
            }
            if((counterCounter) == 7){
                n = counter8;
                
            }
            if((counterCounter) == 8){
                n = counter9;
                
            }
            if((counterCounter) == 9){
                n = counter10;
                
            }
            counterCounter = counterCounter +1;
            
            for(int j=(23-(n+1)); j<23; j++){  //for TwoDarray[][j] - rows
                TwoDarray[j][i] = 'X';
            }
            for(int s=0; s<(23-(n+1)); s++){
                TwoDarray[s][i] = ' ';
                
            }
            
        }
        
        
        printf("   +----------------------------------------+\n");
        printf("22 | %c%c  %c%c  %c%c  %c%c  %c%c  %c%c  %c%c  %c%c  %c%c  %c%c |\n", TwoDarray[0][0], TwoDarray[0][0], TwoDarray[0][1], TwoDarray[0][1], TwoDarray[0][2], TwoDarray[0][2], TwoDarray[0][3], TwoDarray[0][3], TwoDarray[0][4], TwoDarray[0][4], TwoDarray[0][5], TwoDarray[0][5], TwoDarray[0][6], TwoDarray[0][6], TwoDarray[0][7], TwoDarray[0][7], TwoDarray[0][8], TwoDarray[0][8], TwoDarray[0][9], TwoDarray[0][9]);
        printf("22 | %c%c  %c%c  %c%c  %c%c  %c%c  %c%c  %c%c  %c%c  %c%c  %c%c |\n", TwoDarray[1][0], TwoDarray[1][0], TwoDarray[1][1], TwoDarray[1][1], TwoDarray[1][2], TwoDarray[1][2], TwoDarray[1][3], TwoDarray[1][3], TwoDarray[1][4], TwoDarray[1][4], TwoDarray[1][5], TwoDarray[1][5], TwoDarray[1][6], TwoDarray[1][6], TwoDarray[1][7], TwoDarray[1][7], TwoDarray[1][8], TwoDarray[1][8], TwoDarray[1][9], TwoDarray[1][9]);
        printf("20 |.%c%c..%c%c..%c%c..%c%c..%c%c..%c%c..%c%c..%c%c..%c%c..%c%c.|\n", TwoDarray[2][0], TwoDarray[2][0], TwoDarray[2][1], TwoDarray[2][1], TwoDarray[2][2], TwoDarray[2][2], TwoDarray[2][3], TwoDarray[2][3], TwoDarray[2][4], TwoDarray[2][4], TwoDarray[2][5], TwoDarray[2][5], TwoDarray[2][6], TwoDarray[2][6], TwoDarray[2][7], TwoDarray[2][7], TwoDarray[2][8], TwoDarray[2][8], TwoDarray[2][9], TwoDarray[2][9]);
        printf("19 | %c%c  %c%c  %c%c  %c%c  %c%c  %c%c  %c%c  %c%c  %c%c  %c%c |\n", TwoDarray[3][0], TwoDarray[3][0], TwoDarray[3][1], TwoDarray[3][1], TwoDarray[3][2], TwoDarray[3][2], TwoDarray[3][3], TwoDarray[3][3], TwoDarray[3][4], TwoDarray[3][4], TwoDarray[3][5], TwoDarray[3][5], TwoDarray[3][6], TwoDarray[3][6], TwoDarray[3][7], TwoDarray[3][7], TwoDarray[3][8], TwoDarray[3][8], TwoDarray[3][9], TwoDarray[3][9]);
        printf("18 | %c%c  %c%c  %c%c  %c%c  %c%c  %c%c  %c%c  %c%c  %c%c  %c%c |\n", TwoDarray[4][0], TwoDarray[4][0], TwoDarray[4][1], TwoDarray[4][1], TwoDarray[4][2], TwoDarray[4][2], TwoDarray[4][3], TwoDarray[4][3], TwoDarray[4][4], TwoDarray[4][4], TwoDarray[4][5], TwoDarray[4][5], TwoDarray[4][6], TwoDarray[4][6], TwoDarray[4][7], TwoDarray[4][7], TwoDarray[4][8], TwoDarray[4][8], TwoDarray[4][9], TwoDarray[4][9]);
        printf("17 | %c%c  %c%c  %c%c  %c%c  %c%c  %c%c  %c%c  %c%c  %c%c  %c%c |\n", TwoDarray[5][0], TwoDarray[5][0], TwoDarray[5][1], TwoDarray[5][1], TwoDarray[5][2], TwoDarray[5][2], TwoDarray[5][3], TwoDarray[5][3], TwoDarray[5][4], TwoDarray[5][4], TwoDarray[5][5], TwoDarray[5][5], TwoDarray[5][6], TwoDarray[5][6], TwoDarray[5][7], TwoDarray[5][7], TwoDarray[5][8], TwoDarray[5][8], TwoDarray[5][9], TwoDarray[5][9]);
        printf("16 | %c%c  %c%c  %c%c  %c%c  %c%c  %c%c  %c%c  %c%c  %c%c  %c%c |\n", TwoDarray[6][0], TwoDarray[6][0], TwoDarray[6][1], TwoDarray[6][1], TwoDarray[6][2], TwoDarray[6][2], TwoDarray[6][3], TwoDarray[6][3], TwoDarray[6][4], TwoDarray[6][4], TwoDarray[6][5], TwoDarray[6][5], TwoDarray[6][6], TwoDarray[6][6], TwoDarray[6][7], TwoDarray[6][7], TwoDarray[6][8], TwoDarray[6][8], TwoDarray[6][9], TwoDarray[6][9]);
        printf("15 |.%c%c..%c%c..%c%c..%c%c..%c%c..%c%c..%c%c..%c%c..%c%c..%c%c.|\n", TwoDarray[7][0], TwoDarray[7][0], TwoDarray[7][1], TwoDarray[7][1], TwoDarray[7][2], TwoDarray[7][2], TwoDarray[7][3], TwoDarray[7][3], TwoDarray[7][4], TwoDarray[7][4], TwoDarray[7][5], TwoDarray[7][5], TwoDarray[7][6], TwoDarray[7][6], TwoDarray[7][7], TwoDarray[7][7], TwoDarray[7][8], TwoDarray[7][8], TwoDarray[7][9], TwoDarray[7][9]);
        printf("14 | %c%c  %c%c  %c%c  %c%c  %c%c  %c%c  %c%c  %c%c  %c%c  %c%c |\n", TwoDarray[8][0], TwoDarray[8][0], TwoDarray[8][1], TwoDarray[8][1], TwoDarray[8][2], TwoDarray[8][2], TwoDarray[8][3], TwoDarray[8][3], TwoDarray[8][4], TwoDarray[8][4], TwoDarray[8][5], TwoDarray[8][5], TwoDarray[8][6], TwoDarray[8][6], TwoDarray[8][7], TwoDarray[8][7], TwoDarray[8][8], TwoDarray[8][8], TwoDarray[8][9], TwoDarray[8][9]);
        printf("13 | %c%c  %c%c  %c%c  %c%c  %c%c  %c%c  %c%c  %c%c  %c%c  %c%c |\n", TwoDarray[9][0], TwoDarray[9][0], TwoDarray[9][1], TwoDarray[9][1], TwoDarray[9][2], TwoDarray[9][2], TwoDarray[9][3], TwoDarray[9][3], TwoDarray[9][4], TwoDarray[9][4], TwoDarray[9][5], TwoDarray[9][5], TwoDarray[9][6], TwoDarray[9][6], TwoDarray[9][7], TwoDarray[9][7], TwoDarray[9][8], TwoDarray[9][8], TwoDarray[9][9], TwoDarray[9][9]);
        printf("12 | %c%c  %c%c  %c%c  %c%c  %c%c  %c%c  %c%c  %c%c  %c%c  %c%c |\n", TwoDarray[10][0], TwoDarray[10][0], TwoDarray[10][1], TwoDarray[10][1], TwoDarray[10][2], TwoDarray[10][2], TwoDarray[10][3], TwoDarray[10][3], TwoDarray[10][4], TwoDarray[10][4], TwoDarray[10][5], TwoDarray[10][5], TwoDarray[10][6], TwoDarray[10][6], TwoDarray[10][7], TwoDarray[10][7], TwoDarray[10][8], TwoDarray[10][8], TwoDarray[10][9], TwoDarray[10][9]);
        printf("11 | %c%c  %c%c  %c%c  %c%c  %c%c  %c%c  %c%c  %c%c  %c%c  %c%c |\n", TwoDarray[11][0], TwoDarray[11][0], TwoDarray[11][1], TwoDarray[11][1], TwoDarray[11][2], TwoDarray[11][2], TwoDarray[11][3], TwoDarray[11][3], TwoDarray[11][4], TwoDarray[11][4], TwoDarray[11][5], TwoDarray[11][5], TwoDarray[11][6], TwoDarray[11][6], TwoDarray[11][7], TwoDarray[11][7], TwoDarray[11][8], TwoDarray[11][8], TwoDarray[11][9], TwoDarray[11][9]);
        printf("10 |.%c%c..%c%c..%c%c..%c%c..%c%c..%c%c..%c%c..%c%c..%c%c..%c%c.|\n", TwoDarray[12][0], TwoDarray[12][0], TwoDarray[12][1], TwoDarray[12][1], TwoDarray[12][2], TwoDarray[12][2], TwoDarray[12][3], TwoDarray[12][3], TwoDarray[12][4], TwoDarray[12][4], TwoDarray[12][5], TwoDarray[12][5], TwoDarray[12][6], TwoDarray[12][6], TwoDarray[12][7], TwoDarray[12][7], TwoDarray[12][8], TwoDarray[12][8], TwoDarray[12][9], TwoDarray[12][9]);
        printf("09 | %c%c  %c%c  %c%c  %c%c  %c%c  %c%c  %c%c  %c%c  %c%c  %c%c |\n", TwoDarray[13][0], TwoDarray[13][0], TwoDarray[13][1], TwoDarray[13][1], TwoDarray[13][2], TwoDarray[13][2], TwoDarray[13][3], TwoDarray[13][3], TwoDarray[13][4], TwoDarray[13][4], TwoDarray[13][5], TwoDarray[13][5], TwoDarray[13][6], TwoDarray[13][6], TwoDarray[13][7], TwoDarray[13][7], TwoDarray[13][8], TwoDarray[13][8], TwoDarray[13][9], TwoDarray[13][9]);
        printf("08 | %c%c  %c%c  %c%c  %c%c  %c%c  %c%c  %c%c  %c%c  %c%c  %c%c |\n", TwoDarray[14][0], TwoDarray[14][0], TwoDarray[14][1], TwoDarray[14][1], TwoDarray[14][2], TwoDarray[14][2], TwoDarray[14][3], TwoDarray[14][3], TwoDarray[14][4], TwoDarray[14][4], TwoDarray[14][5], TwoDarray[14][5], TwoDarray[14][6], TwoDarray[14][6], TwoDarray[14][7], TwoDarray[14][7], TwoDarray[14][8], TwoDarray[14][8], TwoDarray[14][9], TwoDarray[14][9]);
        printf("07 | %c%c  %c%c  %c%c  %c%c  %c%c  %c%c  %c%c  %c%c  %c%c  %c%c |\n", TwoDarray[15][0], TwoDarray[15][0], TwoDarray[15][1], TwoDarray[15][1], TwoDarray[15][2], TwoDarray[15][2], TwoDarray[15][3], TwoDarray[15][3], TwoDarray[15][4], TwoDarray[15][4], TwoDarray[15][5], TwoDarray[15][5], TwoDarray[15][6], TwoDarray[15][6], TwoDarray[15][7], TwoDarray[15][7], TwoDarray[15][8], TwoDarray[15][8], TwoDarray[15][9], TwoDarray[15][9]);
        printf("06 | %c%c  %c%c  %c%c  %c%c  %c%c  %c%c  %c%c  %c%c  %c%c  %c%c |\n", TwoDarray[16][0], TwoDarray[16][0], TwoDarray[16][1], TwoDarray[16][1], TwoDarray[16][2], TwoDarray[16][2], TwoDarray[16][3], TwoDarray[16][3], TwoDarray[16][4], TwoDarray[16][4], TwoDarray[16][5], TwoDarray[16][5], TwoDarray[16][6], TwoDarray[16][6], TwoDarray[16][7], TwoDarray[16][7], TwoDarray[16][8], TwoDarray[16][8], TwoDarray[16][9], TwoDarray[16][9]);
        printf("05 |.%c%c..%c%c..%c%c..%c%c..%c%c..%c%c..%c%c..%c%c..%c%c..%c%c.|\n", TwoDarray[17][0], TwoDarray[17][0], TwoDarray[17][1], TwoDarray[17][1], TwoDarray[17][2], TwoDarray[17][2], TwoDarray[17][3], TwoDarray[17][3], TwoDarray[17][4], TwoDarray[17][4], TwoDarray[17][5], TwoDarray[17][5], TwoDarray[17][6], TwoDarray[17][6], TwoDarray[17][7], TwoDarray[17][7], TwoDarray[17][8], TwoDarray[17][8], TwoDarray[17][9], TwoDarray[17][9]);
        printf("04 | %c%c  %c%c  %c%c  %c%c  %c%c  %c%c  %c%c  %c%c  %c%c  %c%c |\n", TwoDarray[18][0], TwoDarray[18][0], TwoDarray[18][1], TwoDarray[18][1], TwoDarray[18][2], TwoDarray[18][2], TwoDarray[18][3], TwoDarray[18][3], TwoDarray[18][4], TwoDarray[18][4], TwoDarray[18][5], TwoDarray[18][5], TwoDarray[18][6], TwoDarray[18][6], TwoDarray[18][7], TwoDarray[18][7], TwoDarray[18][8], TwoDarray[18][8], TwoDarray[18][9], TwoDarray[18][9]);
        printf("03 | %c%c  %c%c  %c%c  %c%c  %c%c  %c%c  %c%c  %c%c  %c%c  %c%c |\n", TwoDarray[19][0], TwoDarray[19][0], TwoDarray[19][1], TwoDarray[19][1], TwoDarray[19][2], TwoDarray[19][2], TwoDarray[19][3], TwoDarray[19][3], TwoDarray[19][4], TwoDarray[19][4], TwoDarray[19][5], TwoDarray[19][5], TwoDarray[19][6], TwoDarray[19][6], TwoDarray[19][7], TwoDarray[19][7], TwoDarray[19][8], TwoDarray[19][8], TwoDarray[19][9], TwoDarray[19][9]);
        printf("02 | %c%c  %c%c  %c%c  %c%c  %c%c  %c%c  %c%c  %c%c  %c%c  %c%c |\n", TwoDarray[20][0], TwoDarray[20][0], TwoDarray[20][1], TwoDarray[20][1], TwoDarray[20][2], TwoDarray[20][2], TwoDarray[20][3], TwoDarray[20][3], TwoDarray[20][4], TwoDarray[20][4], TwoDarray[20][5], TwoDarray[20][5], TwoDarray[20][6], TwoDarray[20][6], TwoDarray[20][7], TwoDarray[20][7], TwoDarray[20][8], TwoDarray[20][8], TwoDarray[20][9], TwoDarray[20][9]);
        printf("01 | %c%c  %c%c  %c%c  %c%c  %c%c  %c%c  %c%c  %c%c  %c%c  %c%c |\n", TwoDarray[21][0], TwoDarray[21][0], TwoDarray[21][1], TwoDarray[21][1], TwoDarray[21][2], TwoDarray[21][2], TwoDarray[21][3], TwoDarray[21][3], TwoDarray[21][4], TwoDarray[21][4], TwoDarray[21][5], TwoDarray[21][5], TwoDarray[21][6], TwoDarray[21][6], TwoDarray[21][7], TwoDarray[21][7], TwoDarray[21][8], TwoDarray[21][8], TwoDarray[21][9], TwoDarray[21][9]);
        printf("01 | %c%c  %c%c  %c%c  %c%c  %c%c  %c%c  %c%c  %c%c  %c%c  %c%c |\n", TwoDarray[22][0], TwoDarray[22][0], TwoDarray[22][1], TwoDarray[22][1], TwoDarray[22][2], TwoDarray[22][2], TwoDarray[22][3], TwoDarray[22][3], TwoDarray[22][4], TwoDarray[20][4], TwoDarray[22][5], TwoDarray[22][5], TwoDarray[22][6], TwoDarray[22][6], TwoDarray[22][7], TwoDarray[22][7], TwoDarray[22][8], TwoDarray[22][8], TwoDarray[22][9], TwoDarray[22][9]);
        printf("   +----------------------------------------+\n");
        printf("     00  10  20  30  40  50  60  70  80  90  ");
        
    }
    return ( 0 );
}
////////////////////////////////////////////////////////////////////////////////
//
// Function     : main
// Description  : The main function for the CMPSC311 assignment #1
//
// Inputs       : argc - the number of command line parameters
//                argv - the parameters
// Outputs      : 0 if successful test, -1 if failure

int main(int argc, char **argv) {

    /* Local variables */
    float f_array[NUM_TEST_ELEMENTS];
    int i_array[NUM_TEST_ELEMENTS], i;
    int hist_array[10];
    

    /* Preamble inforamtion */
    printf( "CMPSC311 - Assignment #1 - Spring 2020\n\n" );

    /* Step #1 - read in the float numbers to process */
    for (i=0; i<NUM_TEST_ELEMENTS; i++) {
        scanf("%f", &f_array[i]);
    }

    /* Step #2 - Alter the values of the float array as follows: all 
    even numbered indices of the array should be multiplied by 0.78 
    if the value is greater than 50 and 1.04 otherwise.  All odd valued
    indices should multiplied by 0.92 if the value is greater than 50 
    and 1.15 otherwise */
    for (i=0; i<NUM_TEST_ELEMENTS; i++) {
        if ((i%2)==0) {
                if (f_array[i] > 50) {
                f_array[i] = (f_array[i] * 0.78);
            }
            if (f_array[i] < 50) {
                f_array[i] = (f_array[i] * 1.04);
            }
        }
        if ((i%2)==1) {
            if (f_array[i] > 50) {
                f_array[i] = (f_array[i] * 0.92);
            }
            if (f_array[i] < 50) {
                f_array[i] = (f_array[i] * 1.15);
            }
        }
    }
    


    /* Step  #3 Round all of the values to integers and assign them 
    to i_array using the round311 function */
    printf("Testing round311(void)");
    round311(f_array, i_array);
    printf("\n\n");

    /* Step #4 - Print out all of the floating point numbers in the 
    array in order on a SINGLE line.  Each value should be printed 
    with 2 digits to the right of the decimal point. */
    printf( "Testing printfloatArr311 (floats): " );
    printfloatArr311( f_array, NUM_TEST_ELEMENTS );
    printf("\n\n");

     /* Step #5 - Print out all of the integer numbers in the array in order on a SINGLE line. */
    printf( "Testing printIntArr311 (integers): " );
    printIntArr311( i_array, NUM_TEST_ELEMENTS );
    printf("\n\n");

    /* Step #6 - sort the integer values, print values */
    printf( "Testing bubbleSort311 (integers): " );
    bubbleSort311( i_array, NUM_TEST_ELEMENTS );
    printIntArr311( i_array, NUM_TEST_ELEMENTS );
    printf("\n\n");

    /* Step #7 - print out the last 5 values of the integer array in binary. */
    printf( "Testing toBinary:\n" );
    for (i=NUM_TEST_ELEMENTS-6; i<NUM_TEST_ELEMENTS; i++) {
        toBinary( i, i_array );
    }
    printf("\n\n");

    /* Declare an array of integers.  Fill the array with a count (times three) of the number of values for each 
    set of tens within the floating point array, i.e. index 0 will contain the count of rounded values in the array 0-9 TIMES THREE, the
    second will be 10-19, etc. */
    
    printf("Testing countRange311( floats )\n");
    hist_array[0] = countRange311(i_array, NUM_TEST_ELEMENTS, 0, 9);
    hist_array[1] = countRange311(i_array, NUM_TEST_ELEMENTS, 10, 19);
    hist_array[2] = countRange311(i_array, NUM_TEST_ELEMENTS, 20, 29);
    hist_array[3] = countRange311(i_array, NUM_TEST_ELEMENTS, 30, 39);
    hist_array[4] = countRange311(i_array, NUM_TEST_ELEMENTS, 40, 49);
    hist_array[5] = countRange311(i_array, NUM_TEST_ELEMENTS, 50, 59);
    hist_array[6] = countRange311(i_array, NUM_TEST_ELEMENTS, 60, 69);
    hist_array[7] = countRange311(i_array, NUM_TEST_ELEMENTS, 70, 79);
    hist_array[8] = countRange311(i_array, NUM_TEST_ELEMENTS, 80, 89);
    hist_array[9] = countRange311(i_array, NUM_TEST_ELEMENTS, 90, 99);
    printf("Hist_array: ");
    for(i=0; i<10; i++){
        printf("%d", hist_array[i]);
        if((i)==9){
            printf("\n");
        }
        else {
            printf(", ");
        }
    }
    histogram311(hist_array);
    

    /* Exit the program successfully */
    printf( "\n\nCMPSC311 - Assignment #1 - Spring 2020 Complete.\n" );

    int x1 = (1 + 4/8);
    printf("x1 = %d\n", x1);
    int x2 = (32 * 32) + (8&5);
    printf("x2 = %d\n", x2);
    int x3 = (0xf0^0x0f);
    printf("x3 = %d\n", x3);
    int x4 = (((8*8)%10)+9);
    printf("x4 = %d\n", x4);
    int x5 = ((10|5)>>2);
    printf("x5 = %d\n", x5);
    return( 0 );
}

