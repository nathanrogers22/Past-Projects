import turtle
import math
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


wn.mainloop()

#Program that runs the projectile motion equations

VY =(V*math.sin(math.radians(A)))
VX =(V*math.cos(math.radians(A)))
VfX= VX
Time = (H/VX)
VfY = (VY - 9.8*Time)

HeightFinal = (5 + VY*Time - .5*9.8*Time*Time)
FinalVelocityM = (math.sqrt(VfY**2 + VfX**2))
FinalVelocityD = math.atan(VfY/VfX)


if HeightFinal < 0:
    print("Miss")

elif HeightFinal > 0 and HeightFinal < H:
    print("THE BIRD WENT SPLAT!")

elif HeightFinal > H:
    print("Miss")





