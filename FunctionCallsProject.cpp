
// include iostream library for basic console input and output
#include <iostream>
// include string library
#include <string>
// include windows header file for more advanced windows console functions
#include <windows.h>
// include C standard library
#include <cstdlib>
// include time functions library
#include <ctime>
// namespace std for cout and cin allowing cout, cin instead of std::cout std::cin
using namespace std; // std::cout, std::cin

// Global variable definitions for playerHealth, playerScore, day and string aray playerInventory
// Made these global as functions will have to change them
int playerHealth = 100, playerScore = 0, day = 4;
string playerInventory[10];
string playerName;

// Function prototypes for Intro and Chapters might not need return values, but will leave int in case I need to add it later.
string intro();
int chapter1();
int chapter2();
int chapter3();
// Function prototype for playerStats display function
void playerStats();

// Function prototype to change console text color
void consoleColor(const int);

int main()
{

    //create string variables playerName and playerChoice
    string playerName, playerChoice, reset;
    


    // call intro function to start the game & return playerName
    playerName = intro();
    
    playerStats();
    // prompt user for input
    cout << " \n\t You can go N, S, or (P)pickup the Plex\n\n";
    //take input from player and assign to string variable playerChoice
    getline(cin, playerChoice);
    // if else 
    if (playerChoice == "P") 
    {
        chapter1();
        playerStats();
    }else if (playerChoice == "N")
    {
        chapter2();
        playerStats();
    }
    else if (playerChoice == "S")
    {
        chapter3();
    }else
    { 
        //change color to red
        consoleColor(4);
            //output invalid input to user
        cout << "\n\t No valid input given...";
        //change color back to white
        consoleColor(15);
        cout << "\n\t Reset Game? Y/N";
        cin >> reset;
        if (reset == "Y") main();

    }


    cout << "\n\n\t As the day ends. You find that your car starts and you can go home for another day.\n";
    //update variable day for next day
    day++;
    playerStats();


    cout << "\n\nTo be continued... End of Program\n";
        
    


 }

// Function definition of playerStats
void playerStats() 
{
    // change color to blue
    consoleColor(1);
    // display player information current day health and points
    cout << "\n\t Current Day: " << day << "   Health: " << playerHealth << "   Points: " << playerScore;
    // return color to white
    consoleColor(15);
}
// Function definition of consoleColor to change text color
void consoleColor(int color) 
{
    // colors are 0=black 1=blue 2=green and so on to 15=white
    // colorattribute = foreground + background * 16
    // to get red text on yellow use 4 + 14*16 = 228
    // light red on yellow would be 12 + 14*16 = 236
    // 
    //Create Handle to refer to GetStdHandle labelled hConsole
    HANDLE hConsole;
    //set hConsole to GetStdHandle thing, to obtain C standard console colors
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
 }

string intro() 
{
    //change color to green
    consoleColor(2);
    //console output of title card
    cout << "\n\n\n\t Welcome to the Mystery of the Plex \n\n";
    //Set colors back to original
    consoleColor(15);
    //Prompt user for name
    cout << "\t Please enter your name\n";
    //Use getline function with parameters of type of input cin & variable to hold string
    getline(cin, playerName);
    //cout of welcome message with variable of playerName inserted
    cout << "\n Welcome " + playerName + " to the beginning of your adventure\n";
    cout << "\n\n An unusual event happened worldwide. Small thin pieces of black material appeared at random locations.\n Unusually the material has one strange property. For most people they forget about it and other things every 3 days.\n Resulting in a loop of news stories about the \"new discovery\". Some everyday technology doesn't always work.\n And the world itself is shutdown in a strange form of self denial. Stuck awaiting news on the strange phenomenon, which never comes. \n";
    cout << "\nPress any key to continue\n";
    //using cin.get() to create press anykey delay
    cin.get();
    cout << "\n\n You, the player, have no special skills or abilities, except one. \n You are immune to the effects of the phenomenon.\n";
    cout << "\nPress any key to continue\n";
    cin.get();
    cout << "\n\n When the phenomenon first happened there were many theories, and even multiple different results from similar tests. \n The material was referred to by it's multiplex properties. Or as it's called on the news, the \"Plex\"\n";
    cout << "\nPress any key to continue\n";
    cin.get();
    cout << "\n\n You are in a park, near a university to the north. To the south is a parking lot with your car. Nearby is a piece of Plex on the ground.\n";

    return playerName;
}

int chapter1(void)
{
    cout << "\n\t You reach down and pickup the Plex. It's looks a bit like a small piece of black eggshell.\n";
    cout << "\t Feeling it, is is cool to the touch, and slightly vibrating. You put in in your pocket.\n";
    //add to score variable for correct answer
    playerScore += 100;
    return 0;
}

int chapter2(void)
{
    cout << "\n\t You travel north into the University. There's a great commotion around the labs.\n";
    cout << "\t Some of the teachers and students are gathered around an electron microscope excitedly.\n";
    cout << "\t On the screen the surface of the sample is shimmering and moving while being imaged\n";
    cout << "\t The teacher remarks \"It's as if it's reacting to the electron beam\"\n";
    //add to score variable for correct answer
    playerScore += 100;
    return 0;

}

int chapter3(void)
{

    cout << "\n\t You travel south to the parking lot and look for your car. After a little while you find it. \n";
    cout << "\t Turning the key the cars radio turns on, but the car won't start.\n";
    cout << "\t The \"breaking news\" is of course about the discovery of the strange black material.\n";
    cout << "\t Local scientists are baffled as to why the material is already in their labs and how it got there.\n";
    
    return 0;

}