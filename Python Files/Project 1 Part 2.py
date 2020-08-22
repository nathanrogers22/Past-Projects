#################################
# Imports                       #
#################################
import math
import turtle

###############################################
# Function that builds the structure, ground, #
# slingshot, and draws the (X,Y) locations    #
# until the projectile hit the ground or      #
# structure                                   #
###############################################
def projectile_xy(v, a, D, H, hs=5.0, g=9.8):
    '''
    calculate a list of (x, y) projectile motion data points
    where:
    x axis is distance (or range) in meters
    y axis is height in meters
    v is velocity of the projectile (meter/second)
    a is the angle with repsect to ground (radians)
    dX is the distance to the structure
    dY is the height of the structure
    hs is starting height with respect to ground (meters)
    g is the gravitational pull (meters/second_square)
    '''
#Start time at 0
t = 0.0

print("Hello and welcome to SPLAT A BIRD!")
wn = turtle.Screen()         
wn.bgcolor("blue")
wn.title("Splat a Bird!")

steve = turtle.Turtle()
steve.color("hotpink")
steve.pensize(4)

print("Input a Velocity")
V=float(input())

print("Input an Angle")
A=float(input())

print("Input Distance to Structure")
D=float(input())

print("Input Height of the Building")
H=float(input())
 
steve.forward(D)
steve.left(90)
steve.forward(H)
steve.right(90)
steve.forward(5)
steve.right(90)
steve.forward(H)
steve.right(90)
steve.forward(5+D)
steve.right(90)
steve.forward(5)


#Prep for Takeoff
steve.right(A)
steve.color("red")
steve.pensize(4)
missed = False
    
while True:
        # Calculate the height y at time t
    y = (5 + V*t -4.9*t*t) 
        
        # Check to see if projectile has hit ground level
    if y < 0:
        break
            # if projectile hit the ground, use the break command
            # to exit the loop
        
        # Calculate the distance x at time t
    x = (V*t)

  
        # Check if the projectile has hit the structure
        # Hint: check for the following:
        # missed is False and x value is >= distance x and y is > 0
    if x >= D and y > 0 and missed==False:
        if y < H:
            break
    elif x > (D):
        missed = True

        # Move the Turtle to the (X, Y) position
    steve.goto(x,y)
        # Use the time in increments of 0.1 seconds
    t += 0.1

##############################
# Main Program               #
##############################
#Insert the code from Task 1 of the program here

VY =(V*math.sin(math.radians(A)))
VX =(V*math.cos(math.radians(A)))
VfX= VX
Time = (H/VX)
VfY = (VY - 9.8*Time)

HeightFinal = (5 + VY*Time - .5*9.8*Time*Time)
FinalVelocityM = (math.sqrt(VfY**2 + VfX**2))
FinalVelocityD = math.atan(VfY/VfX)


if HeightFinal <= 0:
    print("Miss")

elif HeightFinal > 0 and HeightFinal < H:
    print("THE BIRD WENT SPLAT!")

elif HeightFinal > H:
    print("Miss")

print("Time taken to reach the building: ", Time, "seconds")
print("Final Height of the bird when it hits the building: ", HeightFinal, "meters")
print("Final Velocity of the bird: ", FinalVelocityM, "meters per seocnd")
print("Final Angle: ", A, "degrees")

#########################################
# Following line calls the function for #
# drawing the results                   #
# Variables used for parameters:        #
# v = Input velocity                    #
# a = Gravity                           #
# d = Distance in X direction           #
# h = Height of the structure           #
#########################################
projectile_xy(V, A, D, H)

# Runs the graphics until they are closed
wn.mainloop()
