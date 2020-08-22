/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package project.pkg1;

/**
 *
 * @author ntrog
 */
public class Rules extends Game{
    
    /**
     * 
     */
    //these are the start rules for the game and each combo obtainable in the game and can be referenced at the start of
    //the players turn
    public static void startRules(){
        System.out.println("Rules you need to know:");
        System.out.println("On your turn you will roll 6 dice each with a different possible value");
        System.out.println("5 = 50 points");
        System.out.println("1 = 100 points");
        System.out.println("3 1's = 200 points |" + " 4 of any number = 1000 points");
        System.out.println("3 2's = 200 points |" + " 5 of any number = 2000 points");
        System.out.println("3 3's = 300 points |" + " 6 of any number = 3000 points");
        System.out.println("3 4's = 400 points |");
        System.out.println("3 5's = 500 points |");
        System.out.println("3 6's = 600 points |");
        System.out.println("First person to reach 10000 points wins!");
        System.out.println("-----------------------------------------------------------------------------------------------");
        System.out.println("If someone reaches more than 10000 then the person closest to 10000 points has a chance to beat");
        System.out.println("the player in the lead, however, if they do not beat them, the game will end");
        System.out.println("-----------------------------------------------------------------------------------------------");
                
    }
    
    
}
