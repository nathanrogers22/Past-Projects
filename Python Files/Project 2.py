#Size of the party
import random
print("How many people are dining?")
P = int(input())

SEC = 5

ASS = random.randint(0, 60)                  #Arrival and Seating Schedule
print("Arrival and Seating of Party: ", ASS, "Minutes.")
Seating = 3
print("How long it takes to be seated: ", Seating, "Minutes.")
order = 1
print("Ordering Time: ", order, "Minutes.")
SAO = (SEC + (P * order))
print("Server Arrival and Ordering of Meals: ", SAO, "Minutes.")
#WFF
maximum = 0

for x in range (0, P):
    foodprep = random.randint(0, 45)
    if foodprep > maximum:
        maximum = foodprep
print("How long it takes to cook the food: ", foodprep, "Minites.")

SOF = 5
print("Serving Time of Food: ", SOF, "Minutes.")
ET = random.randint(15, 30)
print("Eating Time: ", ET, "Minutes.")
DO = 1
print("How long it takes to order desert: ", DO, "Minutes.")
DesOrd = (random.randint(0, P)*DO)
print("Desert Ordering: ", DesOrd, "Minutes.")
#WFD
maxD = 0
for x in range (0, P):
    dessert = random.randint(0, 15)
    if dessert > maxD:
        maxD = dessert
print("How long it takes to cook the desert: ", dessert, "Minites.")


SOD = 5
print("How long it takes to serve desert: ", SOD, "Minutes.")
EOM = random.randint(15, 60)
print("Total time it takes to finish the entire meal: ", EOM, "Minutes.")
TT = (ASS + Seating + order + SAO + maximum + SOF + ET + DO + DesOrd + maxD + SOD + EOM)    #Total Time
print("Total Time at the restaurant: ", TT, "Minutes.")
TTH = float(TT/60)
print("Total Time in Hours: ",TTH, "Hours.")

