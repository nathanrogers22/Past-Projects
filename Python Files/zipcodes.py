
import datetime


class Zipcode:
    #zip, geo, loc, timezone
    
    def __init__(self, zipco, city, state, lat, long, timediff):
        self.z = zipco
        self.Loc = Location(city, state)
        self.Geo = Geolocation(lat, long)
        self.a = int(timediff)
        

    def __str__(self):
        str(self.Loc)
        str(self.Geo)
        n = datetime.datetime.now()
        adjust = datetime.datetime(n.year, n.month, n.day, n.hour, n.minute, n.second)
        return "%s, %s, %s, %s" %(self.z, self.Loc, self.Geo, adjust)
    


class Geolocation:
    #Lat and Long

    def __init__(self, Lat, Long):
        self.L = Lat
        self.L2 = Long
        
    

    def __str__(self):

        return "The Latitude is %s and the Longitude is %s" %(self.L, self.L2)



class Location:
    #city and state
    
    def __init__(self, city, state):
        self.c = city
        self.s = state

            

    def __str__(self):
        
        return "The City Is %s And The State Is %s" %(self.c, self.s)






    




