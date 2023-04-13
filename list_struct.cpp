// Example 2: traversing through a list of Player objects. 
// 
//// ----------
#include <list>         // list library
#include <iostream>
#include <string>
#include <iterator>     // iterator library
#include <algorithm>

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

// main function
int main()
{
    // create a list of players. 
    list<Player> listofPlayers =
    { Player(22, "Sid"), Player(3, "Alice"), Player(43, "Bob"), Player(30,
            "Ben"), Player(2, "Laura") };
    

    cout << "*******Iterate a list using Iterators*******" << endl;
    //Create an iterator of std::list
    list<Player>::iterator it;
    
    // Make iterate point to begining and incerement it one by one till it reaches the end of list.
    for (it = listofPlayers.begin(); it != listofPlayers.end(); it++)
    {
        // Access the object through iterator
        int id = it->id;
        string name = it->name;
        //Print the contents
        cout << id << " :: " << name << endl;
    }
    
    cout << "*******Iterate list using references  *********" << endl;
    for (const Player & player : listofPlayers)
    {
        cout << player.id << " :: " << player.name << endl;
    }
 

    cout << "******* Add a new player into the MIDDLE of the list *********" << endl;
    // Create a new person 
    Player newPlayer = Player(7, "Charlie");

    // Insert this new player between Alice and Bob. (More precisely, after Alice) 
    // To do this, we need to determine where Alice is in the list. 
    for (it = listofPlayers.begin(); it != listofPlayers.end(); it++)
    {
        // Access the object through iterator
        string name = it->name;
        if (name == "Alice"){
            listofPlayers.insert (++it,newPlayer);             // Notice: ++it !!!! Why?!
            break;
        }    
    }

    // print updated list of players. Is it correct? 
    for (const Player & player : listofPlayers)
    {
        cout << player.id << " :: " << player.name << endl;
    }

    cout << "******* Remove a player that is in the MIDDLE of the list *********" << endl;
    // Let's remove Bob from the list. 
    for (it = listofPlayers.begin(); it != listofPlayers.end(); it++)
    {
        // Access the object through iterator
        string name = it->name;
        if (name == "Bob"){
            listofPlayers.erase(it);        
            break;
        }    
    }

    for (const Player & player : listofPlayers)
    {
        cout << player.id << " :: " << player.name << endl;
    }

    // What is a draw back / concern of using list to add and remove elements? 

    return 0;
}
