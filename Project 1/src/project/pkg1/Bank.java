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
public class Bank{
    private Game game;
    public int occurencesof1;
    public int occurencesof2;
    public int occurencesof3;
    public int occurencesof4;
    public int occurencesof5;
    public int occurencesof6;
    
    
    public Bank(Game game){
        this.game = game;
    }
    
    
    //Game game = new Game();
    public int numofkeptdice;
    public void combinations1(){
        
        if (game.d1.isKept == true){
            if(game.d1.value == 1){
                game.currentPlayer.playerScore = game.currentPlayer.playerScore + 100;
            }else if (game.d1.value == 5){
                game.currentPlayer.playerScore = game.currentPlayer.playerScore + 50;
            }
        }
    }
    public void combinations2(){
        if (game.d2.isKept == true){
            if(game.d2.value == 1){
                game.currentPlayer.playerScore = game.currentPlayer.playerScore + 100;
            }else if (game.d2.value == 5){
                game.currentPlayer.playerScore = game.currentPlayer.playerScore + 50;
            }
        }
    }
    public void combinations3(){
        if (game.d3.isKept == true){
            if(game.d3.value == 1){
                game.currentPlayer.playerScore = game.currentPlayer.playerScore + 100;
            }else if (game.d3.value == 5){
                game.currentPlayer.playerScore = game.currentPlayer.playerScore + 50;
            }
        }
    }
    public void combinations4(){
        if (game.d4.isKept == true){
            if(game.d4.value == 1){
                game.currentPlayer.playerScore = game.currentPlayer.playerScore + 100;
            }else if (game.d4.value == 5){
                game.currentPlayer.playerScore = game.currentPlayer.playerScore + 50;
            }
        }
    }
    public void combinations5(){
        if (game.d5.isKept == true){
            if(game.d5.value == 1){
                game.currentPlayer.playerScore = game.currentPlayer.playerScore + 100;
            }else if (game.d5.value == 5){
                game.currentPlayer.playerScore = game.currentPlayer.playerScore + 50;
            }
        }
    }
    public void combinations6(){
        if (game.d6.isKept == true){
            if(game.d6.value == 1){
                game.currentPlayer.playerScore = game.currentPlayer.playerScore + 100;
            }else if (game.d6.value == 5){
                game.currentPlayer.playerScore = game.currentPlayer.playerScore + 50;
            }
        }    
        
    }
    
    
    public void countOccurences1(Game game){
        if (game.d1.value == 1){
            occurencesof1 = occurencesof1 + 1;
        }
        if (game.d2.value == 1){
            occurencesof1 = occurencesof1 + 1;
        }
        if (game.d3.value == 1){
            occurencesof1 = occurencesof1 + 1;
        }
        if (game.d4.value == 1){
            occurencesof1 = occurencesof1 + 1;
        }
        if (game.d5.value == 1){
            occurencesof1 = occurencesof1 + 1;
        }
        if (game.d6.value == 1){
            occurencesof1 = occurencesof1 + 1;
        }
    }
    
    public void countOccurences2(Game game){
        if (game.d1.value == 2){
            occurencesof2 = occurencesof2 + 1;
        }
        if (game.d2.value == 2){
            occurencesof2 = occurencesof2 + 1;
        }
        if (game.d3.value == 2){
            occurencesof2 = occurencesof2 + 1;
        }
        if (game.d4.value == 2){
            occurencesof2 = occurencesof2 + 1;
        }
        if (game.d5.value == 2){
            occurencesof2 = occurencesof2 + 1;
        }
        if (game.d6.value == 2){
            occurencesof2 = occurencesof2 + 1;
        }
    }
    
    public void countOccurences3(Game game){
        if (game.d1.value == 3){
            occurencesof3 = occurencesof3 + 1;
        }
        if (game.d2.value == 3){
            occurencesof3 = occurencesof3 + 1;
        }
        if (game.d3.value == 3){
            occurencesof3 = occurencesof3 + 1;
        }
        if (game.d4.value == 3){
            occurencesof3 = occurencesof3 + 1;
        }
        if (game.d5.value == 3){
            occurencesof3 = occurencesof3 + 1;
        }
        if (game.d6.value == 3){
            occurencesof3 = occurencesof3 + 1;
        }
        
    }
    
    public void countOccurences4(Game game){
        if (game.d1.value == 4){
            occurencesof4 = occurencesof4 + 1;
        }
        if (game.d2.value == 4){
            occurencesof4 = occurencesof4 + 1;
        }
        if (game.d3.value == 4){
            occurencesof4 = occurencesof4 + 1;
        }
        if (game.d4.value == 4){
            occurencesof4 = occurencesof4 + 1;
        }
        if (game.d5.value == 4){
            occurencesof4 = occurencesof4 + 1;
        }
        if (game.d6.value == 4){
            occurencesof4 = occurencesof4 + 1;
        }
    }
    
    public void countOccurences5(Game game){
        if (game.d1.value == 5){
            occurencesof5 = occurencesof5 + 1;
        }
        if (game.d2.value == 5){
            occurencesof5 = occurencesof5 + 1;
        }
        if (game.d3.value == 5){
            occurencesof5 = occurencesof5 + 1;
        }
        if (game.d4.value == 5){
            occurencesof5 = occurencesof5 + 1;
        }
        if (game.d5.value == 5){
            occurencesof5 = occurencesof5 + 1;
        }
        if (game.d6.value == 5){
            occurencesof5 = occurencesof5 + 1;
        }
    }
    
    public void countOccurences6(Game game){
        if (game.d1.value == 6){
            occurencesof6 = occurencesof6 + 1;
        }
        if (game.d2.value == 6){
            occurencesof6 = occurencesof6 + 1;
        }
        if (game.d3.value == 6){
            occurencesof6 = occurencesof6 + 1;
        }
        if (game.d4.value == 6){
            occurencesof6 = occurencesof6 + 1;
        }
        if (game.d5.value == 6){
            occurencesof6 = occurencesof6 + 1;
        }
        if (game.d6.value == 6){
            occurencesof6 = occurencesof6 + 1;
        }
    }
    
    public void testfor1(Game game){
        if (occurencesof1 == 1){
            game.currentPlayer.playerScore = game.currentPlayer.playerScore + 100;
        }
        if (occurencesof1 == 2){
            game.currentPlayer.playerScore = game.currentPlayer.playerScore + 200;
        }
        if (occurencesof1 == 3){
            game.currentPlayer.playerScore = game.currentPlayer.playerScore + 300;
        }
        if (occurencesof1 == 4){
            game.currentPlayer.playerScore = game.currentPlayer.playerScore + 1000;
        }
        if (occurencesof1 == 5){
            game.currentPlayer.playerScore = game.currentPlayer.playerScore + 2000;
        }
        if (occurencesof1 == 6){
            game.currentPlayer.playerScore = game.currentPlayer.playerScore + 3000;
        }
    }
    
    public void testfor2(Game game){
        if (occurencesof2 == 3){
            game.currentPlayer.playerScore = game.currentPlayer.playerScore + 200;
        }
        if (occurencesof2 == 4){
            game.currentPlayer.playerScore = game.currentPlayer.playerScore + 1000;
        }
        if (occurencesof2 == 5){
            game.currentPlayer.playerScore = game.currentPlayer.playerScore + 2000;
        }
        if (occurencesof2 == 6){
            game.currentPlayer.playerScore = game.currentPlayer.playerScore + 3000;
        }
    }
    
    public void testfor3(Game game){
        if (occurencesof3 == 3){
            game.currentPlayer.playerScore = game.currentPlayer.playerScore + 300;
        }
        if (occurencesof3 == 4){
            game.currentPlayer.playerScore = game.currentPlayer.playerScore + 1000;
        }
        if (occurencesof3 == 5){
            game.currentPlayer.playerScore = game.currentPlayer.playerScore + 2000;
        }
        if (occurencesof3 == 6){
            game.currentPlayer.playerScore = game.currentPlayer.playerScore + 3000;
        }
    }
    
    public void testfor4(Game game){
        if (occurencesof4 == 3){
            game.currentPlayer.playerScore = game.currentPlayer.playerScore + 400;
        }
        if (occurencesof4 == 4){
            game.currentPlayer.playerScore = game.currentPlayer.playerScore + 1000;
        }
        if (occurencesof4 == 5){
            game.currentPlayer.playerScore = game.currentPlayer.playerScore + 2000;
        }
        if (occurencesof4 == 6){
            game.currentPlayer.playerScore = game.currentPlayer.playerScore + 3000;
        }
    }
    
    public void testfor5(Game game){
        if (occurencesof5 == 1){
            game.currentPlayer.playerScore = game.currentPlayer.playerScore + 50;
        }
        if (occurencesof5 == 2){
            game.currentPlayer.playerScore = game.currentPlayer.playerScore + 100;
        }
        if (occurencesof5 == 3){
            game.currentPlayer.playerScore = game.currentPlayer.playerScore + 500;
        }
        if (occurencesof5 == 4){
            game.currentPlayer.playerScore = game.currentPlayer.playerScore + 1000;
        }
        if (occurencesof5 == 5){
            game.currentPlayer.playerScore = game.currentPlayer.playerScore + 2000;
        }
        if (occurencesof5 == 6){
            game.currentPlayer.playerScore = game.currentPlayer.playerScore + 3000;
        }
    }
    
    public void testfor6(Game game){
        if (occurencesof6 == 3){
            game.currentPlayer.playerScore = game.currentPlayer.playerScore + 600;
        }
        if (occurencesof6 == 4){
            game.currentPlayer.playerScore = game.currentPlayer.playerScore + 1000;
        }
        if (occurencesof6 == 5){
            game.currentPlayer.playerScore = game.currentPlayer.playerScore + 2000;
        }
        if (occurencesof6 == 6){
            game.currentPlayer.playerScore = game.currentPlayer.playerScore + 3000;
        }
    }
    
    public void totalCombinations(){
        combinations1();
        combinations2();
        combinations3();
        combinations4();
        combinations5();
        combinations6();
    }
    
    public void testforoccurencestot(Game game){
        countOccurences1(game);
        countOccurences2(game);
        countOccurences3(game);
        countOccurences4(game);
        countOccurences5(game);
        countOccurences6(game);
    }
    
    public void testfortrips(Game game){
        testfor1(game);
        testfor2(game);
        testfor3(game);
        testfor4(game);
        testfor5(game);
        testfor6(game);
        
    }
    
    public void resetValues(){
        occurencesof1 = 0;
        occurencesof2 = 0;
        occurencesof3 = 0;
        occurencesof4 = 0;
        occurencesof5 = 0;
        occurencesof6 = 0;
    }
    
}
