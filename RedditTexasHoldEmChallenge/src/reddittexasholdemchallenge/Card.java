/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package reddittexasholdemchallenge;

public class Card {
    Suit suit;       // Suit of the card
    CardNum cardNum; //Number of the card
    
    Card(int suitNum, int num)
    {
        suit = Suit.values()[suitNum];
        cardNum = CardNum.values()[num];
    }
    @Override
    public String toString()
    {
        return cardNum + " of " + suit + "s";
    }
}
