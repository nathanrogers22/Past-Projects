/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package project.pkg1;

import java.util.ArrayList;
import java.util.Scanner;

/**
 *
 * @author ntrog
 */
public class Game  {
    //Creating the 6 dice objects
    protected Dice d1;
    protected Dice d2;
    protected Dice d3;
    protected Dice d4;
    protected Dice d5;
    protected Dice d6;
    protected Player p1;
    protected Player p2;
    protected Player currentPlayer;
    public Integer numbertoKeep; //Variable to store how many dice you want to keep
    public ArrayList<Dice> diceList;
    protected int numberofPlayers;
    
    //NOTE: Not sure how to incorperate the super() call in this project. 
    
        
    @Override
    public String toString()
    {
        return "You rolled: " + d1.value + "," + d2.value + "," + d3.value + "," + d4.value + "," + d5.value + "," + d6.value + "\n"; //not sure what to do with this right now
    }
    
    /**
     * 
     * @param args 
     */
    //Constructor for the game and sets up the new dice objects
    public Game(){
        //Two Players are made for the convienience of the presentation
        //@TODO Make more than two players possible for the GUI - Project Two
        p1 = new Player("p1", 0);
        p2 = new Player("p2", 0);
        d1 = new Dice(1,false);
        d2 = new Dice(1,false);
        d3 = new Dice(1,false);
        d4 = new Dice(1,false);
        d5 = new Dice(1,false);
        d6 = new Dice(1,false);

    }
    
    //Initialzing the names of the players
    public void initialize(){
        Scanner newsc = new Scanner(System.in);
        System.out.print("How many players are playing? ");
        numberofPlayers = Integer.parseInt(newsc.next());
        if (numberofPlayers == 1){
            Scanner nameinput1 = new Scanner(System.in);
            System.out.println("What is your name player 1? ");
            p1.setName(nameinput1.next());
            currentPlayer = p1;
        }else if (numberofPlayers == 2){
            Scanner nameinput2 = new Scanner(System.in);
            System.out.println("What is your name player 1? ");
            p1.setName(nameinput2.next());
            System.out.println("What is your name player 2? ");
            p2.setName(nameinput2.next());
            currentPlayer = p1;
            
        }
        taketurn();
            
        
    }
    
    
        
    
    
    //This is where all the dice are rolled
    protected void rollDice(){   
        d1.roll();
        d2.roll();
        d3.roll();
        d4.roll();
        d5.roll();
        d6.roll();
        //System.out.print(toString());
    }    
    
    //Method taking your turn, this includes deciding what dice to keep during your roll
    public void taketurn(){
                
        rollDice();
        
        Scanner keep = new Scanner(System.in);
        System.out.print("How many dice would you like to keep? ");
        int keeping = Integer.parseInt(keep.next());
        numbertoKeep = keeping;
        for (int i = 0; i < numbertoKeep; i++){
            System.out.print("What dice would you like to keep? ");
            int keepNew = Integer.parseInt(keep.next());
            switch (keepNew) {
                case 0:
                    break;
                case 1:
                    if (!d1.isKept){
                        d1.setisKept();
                    }   break;
                case 2:
                    if (!d2.isKept){
                        d2.setisKept();
                    }   break;
                case 3:
                    if(!d3.isKept){
                        d3.setisKept();
                    }   break;
                case 4:
                    if(!d4.isKept){
                        d4.setisKept();
                    }   break;
                case 5:
                    if(!d5.isKept){
                        d5.setisKept();
                    }   break;
                case 6:
                    if(!d6.isKept){
                        d6.setisKept();
                    }   break;
                default:
                    break;
            }
        }
        if (keeping == 0){
            System.out.println("Oops, you busted");
            decider();
        }else{
            System.out.print("Would you like to roll again? ");
            String keep2 = keep.next();
            if ("Yes".equals(keep2)){
                taketurn();
            }else{
                inputtingScore();
                resetDice();
                testforWin();
                decider();

            }
        }
    }
      
    //This method is to decide who is the current player taking their turn
    public void decider(){
        if(currentPlayer.getName() == p1.getName()){
            currentPlayer = p2;
            System.out.println("Now its " + currentPlayer.getName() + "'s turn");
            taketurn();
        }else if(currentPlayer.getName() == p2.getName()){
            currentPlayer = p1;
            System.out.print("Now its " + currentPlayer.getName() + "'s turn");
            taketurn();
        }
        
    }
    //Method for inputting your score
    public void inputtingScore(){
        Scanner inputting = new Scanner(System.in);
        System.out.print("How many points would you like to bank " + currentPlayer.getName() + "? ");
        int newScore = Integer.parseInt(inputting.next());
        currentPlayer.playerScore = currentPlayer.playerScore + newScore;
        System.out.println(currentPlayer.getName() + " has " + currentPlayer.playerScore + " Points.");
        
    }
    
    public void testforWin(){
        
        if (currentPlayer.playerScore >= 10000){
            System.out.println("Looks like we have a winner");
            System.out.println(currentPlayer.getName() + " is the winner!");
            System.exit(0);
        }



        //Scanner win = new Scanner(System.in);
        //System.out.print("Has anyone won yet? ");
        //String winner = win.next();
        //if ("Yes".equals(winner)){
          //System.out.println("The winner is: " + currentPlayer.getName());
        //}else if("No".equals(winner)){
            //taketurn();
        //}
    }
        

    //This is where the dice are all reset to keep -> false so they can be rolled for the next player. 
    public void resetDice(){
        d1.isKept = false;
        d2.isKept = false;
        d3.isKept = false;
        d4.isKept = false;
        d5.isKept = false;
        d6.isKept = false;
    }    
    


        
        
    //Main method for running the game
    public static void main(String[] args){
        Game game = new Game();
        //@TODO Include a possiility of viewing the rules at any point in the game - revision for Project two
        Rules.startRules();
        game.initialize();
        
    }
}

