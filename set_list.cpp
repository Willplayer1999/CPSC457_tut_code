// Example: fast access to a list using a set of iterators.  
// Xining Chen
//// ----------
#include <list>         // list library
#include <iostream>
#include <string>
#include <iterator>     // iterator library
#include <algorithm>
#include <set>          // set library
#include <stdlib.h>     // rand

using namespace std;

// structure Player. 
struct Player
{
    int id;
    string name;
    Player(int playerId, string playerName) :
            id(playerId), name(playerName)
    {
    }
};

typedef list<Player>::iterator playerRef;    // !!!

struct CustomCompare {                          // !!!
    bool operator()(const playerRef & p1, const playerRef & p2) 
    {
        if (p1->id == p2->id) // if two players have the same id, sort based on name 
            return p1->name < p2->name;
        else
            return p1->id < p2->id;
    }

};

// helper function for printing a list of player
void printList(list<Player> &playerList){
    for (list<Player>::iterator it = playerList.begin(); it != playerList.end(); it++)
    {
        cout << it->id << ", " << it->name << endl;
    }
}

// helper function for printing a set
void printSet(set<playerRef,CustomCompare> &playerSet){
     for (set<playerRef, CustomCompare>::iterator it = playerSet.begin(); it != playerSet.end(); ++it)
    {
        cout << (*it)->id << ", " << (*it)->name << endl;
    }
}

// main function
int main()
{
    // create a list of players. 
    list<Player> listofPlayers =
    { Player(22, "Sid"), Player(3, "Alice"), Player(43, "Bob"), Player(30,
            "Ben"), Player(2, "Laura") };

    // a set of available ids
    set<playerRef,CustomCompare> available_players;             // !!!

    // fill some available ids 
    for (int i = 1; i <= 5; i++)
    {
        auto random_id = rand() % 100 + 1;

        Player available_player = Player(random_id, "N/A");
        list<Player>::iterator it = listofPlayers.begin();
        listofPlayers.insert(it,available_player);

        // update it to the new beginning 
        it = listofPlayers.begin();
        // track these available player (empty players) in a set for quick access. 
        available_players.insert(it);                                  
    }

    // print out both the list of players and set of available players. Is it what you'd expect?
    cout << "********* List of players (includes empty players) **********" << endl;
    printList(listofPlayers);

    cout << "********* Set of available players (only empty players) **********" << endl;
    printSet(available_players);


    cout << "----------------------------------------------" << endl;
    // Notice: ++it !!!
    // Create a new player - assign them the smallest available player id << how to get smallest available id?
    set<playerRef, CustomCompare>::iterator newPlayerIt = available_players.begin();
    (*newPlayerIt)->name = "Charlie";
    
    // erase this available id from available_players since it is now taken 
    available_players.erase(newPlayerIt);

    // print list and set. Did it work?
    cout << "********* List of players (includes empty players) **********" << endl;
    printList(listofPlayers);

    cout << "********* Set of available players (only empty players) **********" << endl;
    printSet(available_players);


    cout << "----------------------------------------------" << endl;
    // There could be multiple unfilled players between each filled player. Let's merge unfilled players together so that there is at most 1 unfilled player between each filled player. 
    playerRef currentPlayer = listofPlayers.begin();
    playerRef nextPlayer = next(currentPlayer);
    
    // Note: while you update the list of players, we also have to update the set of available players. 
    while (nextPlayer != listofPlayers.end()) {
        //next player is also empty. Merge. 
        if(((currentPlayer->name).compare("N/A") == 0) && ((nextPlayer->name).compare("N/A") == 0)){
            nextPlayer->id += currentPlayer->id;
            listofPlayers.erase(currentPlayer);         
        }

        // Update the player iterators
        currentPlayer = nextPlayer;  
        nextPlayer = next(currentPlayer);
    }

    cout << "************ Updated list of players *************" << endl;
    printList(listofPlayers);

    return 0;
}
