import datetime
import zipcodes as zips

addressbook = {}


def readCSV(filename):
    try:
        counter = 0
        f = open(filename)
        for line in f:
            #print(line)
            splitz = line.replace('"', "").split(',')
            addressbook[splitz[0]] = splitz
            z = zips.Zipcode(splitz[0], splitz[1], splitz[2], splitz[3], splitz[4], splitz[5])
            print(z)
            counter +=1
            if counter >5:
                break
    except:
        f.close(filename)
        print("You know you are supposed to have a file included right?")
    #print(addressbook)
        
readCSV('C:\\Users\\ntrog\\OneDrive\\Documents\\School Work\\Python Files\\Project3-zipcodes.csv')

def findByZipcode(zipcode):
    #zipcode = input("Input the desired zipcode: ")
    result = {}
    z = zipcode
    splitz = addressbook[z]
    if z in addressbook:
        result["zipcode"] = (zipcode)
        result["city"] = splitz[1]
        result["state"] = splitz[2]
        result["latitude"] = splitz[3]
        result["longitude"] = splitz[4]
        result["timediff"] = splitz[5]
        result["observeDaylightSavings"] = splitz[6]
        return result



def findByState(y):
    #y = input("Input a State ")
    for num in range(len(y)):
        c = y[num]
        for (k,v) in addressbook.items():
            if c in v:
                print(k,v)

def findInSameState(a, b):
    #get statesA => state out of setA
    #get statesB => states out of setB
    #find the states in stateA and stateB
    #result the new list of data in the intersection of statesA and stateB
    splitz2 = []
    for num in range(len(a)):
        c = a[num]
        for pos in b:
            if c == pos:
                splitz2.append(findByZipcode(c))

        return splitz2
    

#print(zipcodes.timezone())
print(findByState(["NY", "NH"]))
print(findInSameState(["00211","00215","08123"], ["00215", "00211", "00999"]))
print(findByZipcode("00212"))


