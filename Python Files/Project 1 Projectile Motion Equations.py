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
    
