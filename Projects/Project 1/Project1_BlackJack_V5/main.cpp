/* File:   main.cpp
 * Author: Christopher Garcia
 * Created on January 27, 2016, 1:54 PM
 * Function: Black Jack Game*WORKING*
 */

//System Libraries
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

//Global Constants

//Function Prototypes
int Deck(int&);
void GameSrt();
void Dealing(int&,int&);
void Hit(char&,int&,int&);
int Wnnr(char&,int&,int&,int&,int&);
void Bet(int&,int&);
//Execution Begins Here
int main(int argc, char** argv) {
//Declare Variables 
    srand(static_cast<int>(time(0)));
    unsigned short menu;
//Introduction to the Black Jack Game game
    cout<<"Welcome to WILD ACE Black Jack Game!"<<endl;
//Menu for the game
    do{
        cout<<"Press 1 to start playing the game!"<<endl;
        cout<<"Press 2 for the rules of WILD ACE Black Jack!"<<endl;
        cout<<"Press 3 for options."<<endl;
        cout<<"Press 4 for instructions and tips."<<endl;
        cin>>menu;
        switch(menu){
            case 1:
                GameSrt();
                break;
            case 2:
                
            case 3:

            default:;
        } 
    }
    while(menu<=1);
    return 0;
}
//The main engine the game runs on
void GameSrt(){
//Declare Variables
    int Card,mMoney=1000,bet=0,
        dSum=0,pSum=0;
    char win=4,ply;//To decide what the pay off is, 4 is default.
//Prompt the player
    cout<<"Welcome to the Black Jack table!"<<endl;
    do{
    Bet(mMoney,bet);
    cout<<"Dealing..."<<endl;
    Dealing(pSum,dSum);
    Hit(win,pSum,dSum);
    Wnnr(win,pSum,dSum,mMoney,bet);
    cout<<"Would you like to keep playing?(Y/N)"<<endl;
    cin>>ply;
    }
    while(ply=='y'||ply=='Y');
    cout<<"Returning to the menu..."<<endl<<endl;
}
//Deck Generator
int Deck(int& Card){
    Card=(rand()%14)+1;
    if(Card>10)
        (Card>13?cout<<" A ":
        (Card>12?cout<<" K ":
        (Card>11?cout<<" Q ":
                 cout<<" J ")));
    else
        cout<<" "<<Card<<" "; 
    if(Card>10)
        Card=10;
return Card;
}

//Dealing the First set of cards
void Dealing(int& pSum,int& dSum){
    int Card;//Need the deck Function
    cout<<"Player 1 | Dealer"<<endl;
    cout<<"  ";
    Deck(Card);pSum+=Card;
    cout<<"        ";
    Deck(Card);dSum+=Card;
    cout<<endl;
    cout<<"  ";
    Deck(Card);pSum+=Card;
    cout<<"        "<<" ?"<<endl;
    }
//Hit or Stay
void Hit(char& win,int& pSum,int& dSum){
//Declare Variables
    char hit;//For the hit or stay option
    int Card;//Need the deck function
//Prompt the User
    if(pSum<21){
        cout<<"Hit or Stay?(H/S)"<<endl;
        cin>>hit;
        if(hit=='H'||hit=='h'){
            Deck(Card);
            pSum+=Card;
            cout<<endl;
            if(pSum>21){
                cout<<"You Busted! You Lose!"<<endl;
                win=0;
                return;
            }
            else
                Hit(win,pSum,dSum);
        }
//Dealer
        cout<<"The Dealer's Down Card was "<<endl;
        Deck(Card);cout<<endl;
        dSum+=Card;
        while(dSum<17){//Must Hit 16 cant hit 17
            cout<<"Dealer must hit."<<endl;
            Deck(Card);
            dSum+=Card;
            cout<<endl;
        }
            return;
    }
    else{
        cout<<"Black Jack!"<<endl;
        win=3;
    }
    return;
}
//Decides who wins and how to be paid
int Wnnr(char& win,int& pSum,int& dSum,int& mMoney,int& bet){
//Declare Variables
//Who won the  Hand
    if(win==4){
        if(dSum>21){
            cout<<"Dealer Busted! You Win!"<<endl;
            win=1;
        }
        else if(dSum==pSum){
            cout<<"You Pushed!"<<endl;
            win=2;
        }
        else if(dSum>pSum){
            cout<<"You Lose!"<<endl;
            win=0;
        }
        else if(dSum<pSum){
             cout<<"You Win!"<<endl;
             win=1;
        }
    }
    switch(win){
            case 0:
                cout<<"You lost $"<<bet<<" :("<<endl;
                mMoney-=bet;break;
            case 1:
                cout<<"You Won $"<<bet<<" :)"<<endl;
                mMoney+=bet;break;
            case 2:
                cout<<"You broke even. :|"<<endl;
                break;
            case 3:
                cout<<"You hit Black Jack! You won $"<<bet*1.5<<" :("<<endl;
                mMoney+=bet*1.5;break;
    }
    cout<<mMoney<<endl<<endl;
}
//Choose the bet and checks the wallet
void Bet(int& mMoney,int& bet){
//Declare Variables
//Wallet, Place bet
    do{
    cout<<"You have "<<mMoney<<" avaliable to bet."<<endl;
    cout<<"How much would you like to bet?"<<endl;
    cin>>bet;
    if(bet>mMoney)
        cout<<"You don't have that much Green. Try Again."<<endl;
    }
    while(bet>mMoney);
    return;
    
}