/*-------------------------------------------
Program 6: Escape the Labyrinth
Course: CS 211, Fall 2023, UIC
System: Visual Studio Code
Author: Zaheer Safi
------------------------------------------- */

#include <utility>
#include <random>
#include <set>
#include "grid.h"
#include "maze.h"
using namespace std;

// my NetID
const string kYourNetID = "zsafi2";

// solution for the regular maze which is specefic to my netID
const string kPathOutOfRegularMaze = "EESNWSWWSSNESE";
// solution for the twisty(advanced) maze which is specefic to my netID
const string kPathOutOfTwistyMaze = "NSSNSEWE";

// function to determine if a given path which is given by moves as a parameter is correct and collects all the required items
bool isPathToFreedom(MazeCell *start, const string& moves) 
{
    bool check_spellbook = false; // veriable to check if spellbook is collected
    bool check_potion = false; // veriable to check if potion is collected
    bool check_wand = false; // veriable to check if wand is collected
    
    // check what is in the sart cell if it is spellbook then change the veriable for it to true
    if (start->whatsHere == "Spellbook")
    {
        check_spellbook = true;
    }
    
    // check what is in the sart cell if it is potion then change the veriable for it to true
    if (start->whatsHere == "Potion")
    {
        check_potion = true;
    }
    
    // check what is in the sart cell if it is Wand then change the veriable for it to true
    if (start->whatsHere == "Wand")
    {
        check_wand = true;
    }
    
    // go throuh each character in the moves string
    for (int i = 0; i < moves.length(); i++)
    {
        // if it is not one of N or S or W or E then return false
        if (moves[i] != 'N' && moves[i] != 'S' && moves[i] != 'W' && moves[i] != 'E' )
        {
            return false;
        }
        
        // if the character is N move to the north cell
        if (moves[i] == 'N')
        {
            start = start->north;
        }
        
        // if the character is S move to the south cell
        if (moves[i] == 'S')
        {
            start = start->south;
        }
        
        // if the character is W move to the west cell
        if (moves[i] == 'W')
        {
            start = start->west;
        }
        
        // if the character is E move to the east cell
        if (moves[i] == 'E')
        {
            start = start->east;
        }
        
        // if the new cell is doesnt exist then return false becuase it is not the right path
        if (start == nullptr)
        {
            return false;
        }
        
        // again check what is inside the cell and change the veriable accordingly
        if (start->whatsHere == "Spellbook")
        {
            check_spellbook = true;
        }
        
        if (start->whatsHere == "Potion")
        {
            check_potion = true;
        }
        
        if (start->whatsHere == "Wand")
        {
            check_wand = true;
        }

    }
    
    // if we come out of the loop then the path is legible check if we collected all the required metairals from the given path and return true if yes.
    if (check_spellbook == true && check_potion == true && check_wand == true)
    {
        return true;
    }
    
    return false;
}

