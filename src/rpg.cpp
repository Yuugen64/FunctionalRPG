#include <iostream>
#include <string>

#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

#include "outputStats.h"    /* My header for output */
#include "area.h"       /* My header */

using namespace std;


//======================================================================================
//  Function Components
//======================================================================================

string getPlayerName()
{
    string playerName;
    
    cout << "Hello! What is your name?" << endl;
    
    getline (cin, playerName);

    return playerName;
}

int getPlayerClass()
{
    int playerClassValue;

    cout << "And what class would you like to play? (please enter number)" << endl;
    cout << "[ 1 - Warrior | 2 - Mage | 3 - Assassin ]" << endl;
    cin >> playerClassValue;
    cin.ignore();

    return playerClassValue;
}

string convertToClassName(int classValue)
{
    string className;

    switch (classValue)
    {
        case 1:
            className = "Warrior";
            break;
        case 2:
            className = "Mage";
            break;
        case 3:
            className = "Assassin";
            break;
        default:
            cout << "ERROR at converToClassName(), provided class number doesn't exist." << endl;
            cin >> classValue;
            exit(0);
    }
    return className;
}

string validatePlayerName(string playerName)
{
    int exitCondition = 0;
    int nameFlag = 1;
    string nameContainer = playerName;

    while(exitCondition == 0)
    {
        if (nameFlag == 1)
        {
            cout << "Is the name " << nameContainer << " correct?" << endl;
            cout << "[ 1 - YES | 0 - NO ]" << endl;
            cin >> nameFlag;
            cin.ignore();

            if(nameFlag == 1)
            {
                exitCondition = 1;
            }
        }
        else
        {
            nameContainer = getPlayerName();
            nameFlag = 1;
        }
    }
    cout << "Ok " << nameContainer << ", nice to meet you!" << endl;
    return nameContainer;
}

int validatePlayerClass(int playerClassValue)
{
    int exitCondition = 0;
    int classFlag = 1;
    int classContainer = playerClassValue;
    string className = convertToClassName(classContainer);

    while(exitCondition == 0)
    {
        if (classFlag == 1)
        {
            cout << "Is the class " << className << " correct?" << endl;
            cout << "[ 1 - YES | 0 - NO ]" << endl;
            cin >> classFlag;
            cin.ignore();

            if(classFlag == 1)
            {
                exitCondition = 1;
            }
        }
        else
        {
            classContainer = getPlayerClass();
            className = convertToClassName(classContainer);
            classFlag = 1;
        }
    }
    cout << "Ok, you've chosen to play " << className << "!" << endl;
    return classContainer;
}

void generateplayerStats(int playerStats[])
{
    //Initialize the random seed for number generation.
    srand (time(NULL));

    //Generate all of the stats as the array is ticked through.
    for (int i = 0; i < 6; i++)
    {
        playerStats[i] = rand() % 10 + 1;
    }
    
}




int main()
{
    //Initialize the stats array since scoping won't allow us to create it anywhere else and manipulate it after.
    //  I know pointers can work around this but I haven't reached those yet.
    int playerStats[] = {0,0,0,0,0,0};

    //This is the more straightforward way of returning locations of matching linear searched stats without getting
    //  into some typecasting nightmare that has a bunch of scope weirdness. These are initialized to -1 because they
    //  will hold array indexes, thus anything less than 0 we can throw away.
    int statLocationBuffer[] = {-1, -1, -1, -1, -1, -1};

    //Prompt for player info.
    string playerName = getPlayerName();
    int playerClassValue = getPlayerClass();

    //Validation of player info.
    playerName = validatePlayerName(playerName);
    playerClassValue = validatePlayerClass(playerClassValue);    

    //Generate player stats.
    generateplayerStats(playerStats);

    displayPlayerStats(playerStats, playerClassValue);

    sumPlayerStats(playerStats);

    cout << endl;

    outputLargestStats(playerStats, statLocationBuffer);
    outputSmallestStats(playerStats, statLocationBuffer);

    //Need to implement a while loop here for the game

    /* 3 steps for game loop 
    1. Prompt + get input
    2. Update the game state
    3. 'Render' the changes (In this case output via text.)
    */

   //I want to limit the number of things that the while loop is passed, but for the ability to run a help loop or menus
   // I may need to pass more than I thought.

    outputHeaderStuff();
    
    cin >> playerClassValue;
    cin.ignore();


    return 0;
}

