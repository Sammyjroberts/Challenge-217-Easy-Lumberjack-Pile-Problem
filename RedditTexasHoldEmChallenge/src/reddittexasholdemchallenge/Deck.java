/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package reddittexasholdemchallenge;

import java.util.ArrayList;
import java.util.Collections;

/**
 *
 * @author sammy
 */
public class Deck {
    ArrayList<Card> deck = new ArrayList();
    
    Deck() //Init Deck
    {
        for(int suit = 0; suit < 4; suit++)
        {
            for(int cardNum = 0; cardNum < 13; cardNum++)
            {
                Card tempCard = new Card(suit, cardNum);
                deck.add(tempCard);
            }
        }
        Collections.shuffle(deck);
    }
}
