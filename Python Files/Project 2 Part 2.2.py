import random
print("How many times do you want to run this?")
r = int(input())
print("How many people are dining?")
P = int(input())
AllT = 0
f = 1
while f <= r:

    SEC = 5

    ASS = random.randint(0, 60)                  #Arrival and Seating Schedule
    Seating = 3
    order = 1
    SAO = (SEC + (P * order))
    #WFF
    maximum = 0

    for x in range (0, P):
        foodprep = random.randint(0, 45)
        if foodprep > maximum:
            maximum = foodprep

    SOF = 5
    ET = random.randint(15, 30)
    DO = 1
    DesOrd = (random.randint(0, P)*DO)
    #WFD
    maxD = 0
    for x in range (0, P):
        dessert = random.randint(0, 15)
        if dessert > maxD:
            maxD = dessert

    SOD = 5
    EOM = random.randint(15, 60)
    TT = (ASS + Seating + order + SAO + maximum + SOF + ET + DO + DesOrd + maxD + SOD + EOM)    #Total Time
    AllT += TT
    AllAS = int((TT-60)/5)
    f += 1
    print("Trial",f,":","*"*AllAS)
print("Average dining time among all parties in simulation: ", AllT/r)



