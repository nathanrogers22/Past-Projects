/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package project.pkg1;

import java.util.Iterator;
import java.util.Random;


/**
 *
 * @author ntrog
 */
public class Dice
{
    protected int value;
    public boolean isKept = false;
    
    
    
    
    //Constructor for the dice to set the score and whether they are kept or not
    public Dice(int value, boolean isKept){
        this.value = value;
        this.isKept = isKept;
        
    }

    
    
    //Random number is generated for each dice object one by one
    public void roll(){
             
        Random rand1 = new Random();
        if (!isKept){
            value = rand1.nextInt(5)+1;
        }
        
    }  
   
    public boolean isKept(){
        return isKept;
    }
    
    public void setisKept()
    {
        isKept = true;
    }   
    
    public int getValue(){
        return value;
    }
    
}
