/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package reddittexasholdemchallenge;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class RedditTexasHoldEmChallenge {

    public static void main(String[] args) {
        //Input Variables
        Scanner sc = new Scanner(System.in);
        int numPlayers;
        //Containers
        Deck deck = new Deck(); 
        ArrayList<Hand> players = new ArrayList(); //Players Hands
        ArrayList<Card> river = new ArrayList();   //The River
        
        //User defines number of players
        System.out.print("How many Players (2-8) ? ");
        numPlayers = sc.nextInt();
        
        //Instantiates hands
        for(int lcv = 0; lcv < numPlayers; lcv++)
        {
            players.add(new Hand());
        }
        
        realisticDeal(players,deck, numPlayers); //initilize hands and deal

        //Hand Displaying loop
        String player = "Your hand: "; //String identifying hand
        for(int lcv = 0; lcv < players.size(); lcv++)
        {
            System.out.print(player);
            for(int lcv2 = 0; lcv2 < players.get(lcv).hand.size(); lcv2++)
            {
                System.out.print(players.get(lcv).hand.get(lcv2) + " ");
            }
            System.out.println("");
            player = "CPU" + (lcv+1) + " hand: ";
        }
        //setup river
        initRiver(deck,river);
        
        //Display river
        System.out.print("Flop: ");
        System.out.println(river.get(0).toString() + " " +
                         river.get(1).toString() + " " +
                         river.get(2).toString());
        System.out.print("Turn: ");
        System.out.println(river.get(3).toString());
        System.out.print("River: ");
        System.out.println(river.get(4));
        System.out.println(deck.deck.size());
        //Reset game
        repopulateDeck(deck, river, players);
        
     
    }
    public static void realisticDeal(ArrayList<Hand> hands, Deck deck, int numPlayers)
    {
        int cardsToDeal = numPlayers*2;
        for(int lcv = 0; lcv < cardsToDeal; lcv++)
        {
            // Deal in a circle via lcv%hands.size() taking top card 
            // then deleting top card
            Card tempCard = deck.deck.get(0);
            
            hands.get(lcv%numPlayers).hand.add(tempCard);
            deck.deck.remove(0);
        }
    }
    public static void initRiver(Deck deck, ArrayList<Card> river)
    {
        for(int lcv = 0; lcv < 5;/*River Size */ lcv++)
        {
            river.add(deck.deck.get(0));
            deck.deck.remove(0);
        }
    }
    public static void repopulateDeck(Deck deck, ArrayList<Card> river, ArrayList<Hand> hands)
    {
        deck.deck.addAll(river);
        for(int lcv = 0; lcv < hands.size(); lcv++)
        {
            deck.deck.addAll(hands.get(lcv).hand);
        }
        Collections.shuffle(deck.deck);
        river.clear();
        hands.clear();
        
    }
}
