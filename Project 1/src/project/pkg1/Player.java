/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package project.pkg1;

import java.util.Scanner;

/**
 *
 * @author ntrog
 */
public class Player
{
    protected String playerName; //Names of player1
    protected int playerScore; //Scores of player 1
    protected int numberofPlayers;
    
    
    
        
    /**
     *
     * @param name
     * @param score
     *
     */ 
    public Player(String name, int score){
        this.playerName = name;
        this.playerScore = score;
        
               
    }       
    public int getScore(){
        return playerScore;
    }
    
    public String getName(){
        return playerName;
    }
    
    public void setName(String name){
        this.playerName = name;
    }
    
    public void addingtoScore(int value){
        this.playerScore = this.playerScore + value;
    }
    
    //Method for creating the new player objects and constructing the name and score and then asking what option they want
    
        
     
    
    
    
    
    
        
}

