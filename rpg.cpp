#include <iostream>
#include <string>

#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

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

void displayPlayerStats(int playerStats[], int playerClassValue)
{
    string classContainer;
    classContainer = convertToClassName(playerClassValue);

    switch (playerClassValue)
    {
        case 1: //warrior
            playerStats[1] += 2;
            playerStats[4] += 1;
            cout << "Your choice to play a " << classContainer << " grants you +2 to Defense, and +1 to Stamina" << endl;
            break;
        case 2: //mage
            playerStats[3] += 2;
            playerStats[5] += 1;
            cout << "Your choice to play a " << classContainer << " grants you +2 to Magic Power, and +1 to Mana" << endl;
            break;
        case 3: //assassin
            playerStats[0] += 2;
            playerStats[2] += 1;
            cout << "Your choice to play a " << classContainer << " grants you +2 to Attack, and +1 to Speed" << endl;
            break;
        default:
            cout << "ERROR in stat generation." << endl;
    }

    cout << "Your stats for [ Attack | Defense | Speed | Magic Power | Stamina | Mana ]" << endl;
    cout << " [ " << playerStats[0] << " | " << playerStats[1] << " | " << playerStats[2] << " | " << playerStats[3] << " | " << playerStats[4] << " | " << playerStats[5] << " ] " << endl;
}

void sumPlayerStats(int playerStats[])
{
    int sum = 0;

    for(int i=0; i<6; i++)
    {
        sum+= playerStats[i];
    }

    cout << "Your current stats TOTAL is " << sum << endl;
}

int findLargestStat(int playerStats[], int statLocationBuffer[])
{
    int max = playerStats[0];

    for (int i=0;i<6;i++)
    {
        if(max < playerStats[i])
            max = playerStats[i];
    }

    cout << "Your BEST stat value is " << max << endl;
    return max;
}

int findSmallestStat(int playerStats[], int statLocationBuffer[])
{
    int min = playerStats[0];

    for (int i=0;i<6;i++)
    {
        if(min > playerStats[i])
            min = playerStats[i];
    }

    cout << "Your WORST stat value is " << min << endl;

    return min;
}

void statValueLocation(int playerStats[], int statLocationBuffer[], int statValue)
{
    //Finding WHERE precisely the stat value is in the stats Array so we can output the stat name.
    for(int i=0;i<6;i++)
    {
        if(playerStats[i]==statValue)
        {
            statLocationBuffer[i] = statValue;
            //cout << "Buffer Value at [" << i << "] = " << statValue << endl;
        }
    }

}

void statValueFormatting(int statLocationBuffer[], int statValue)
{
    int numberOfMatches = 0;
    
    //The number of stats that match statValue, for purposes of establishing a counter.
    for(int i=0; i<6; i++)
    {
        if(statLocationBuffer[i] > -1)
        {
            numberOfMatches++;
        }
    }

    //cout << "Number of matching Stats: " << numberOfMatches << endl;

    //Only if we have multiple stats do we inform the user.
    if(numberOfMatches > 1)
        cout << "You have multiple stats of this level! " << endl;
    
    //The actual switch for outputting which stats by name and their values.
    for(int i=0; i<6; i++)
    {
        if(statLocationBuffer[i] > -1 )
        {
            switch(i)
            {
                case 0:
                    cout << "ATTACK: " << statLocationBuffer[i] << endl;
                    break;
                case 1:
                    cout << "DEFENSE: " << statLocationBuffer[i] << endl;
                    break;
                case 2:
                    cout << "SPEED: " << statLocationBuffer[i] << endl;
                    break;
                case 3:
                    cout << "MAGIC POWER: " << statLocationBuffer[i] << endl;
                    break;
                case 4:
                    cout << "STAMINA: " << statLocationBuffer[i] << endl;
                    break;
                case 5:
                    cout << "MANA: " << statLocationBuffer[i] << endl;
                    break;
                default:
                    cout << "An ERROR occured during statValueFormatting()." << endl;
            }
        }
    }
}

void clearStatLocationBuffer(int statLocationBuffer[])
{
    for(int i=0; i<6; i++)
    {
        statLocationBuffer[i] = -1;
    }
}



//======================================================================================
//  Combine Functions - Multiple components combined for cleaner code.
//======================================================================================
void outputLargestStats(int playerStats[], int statLocationBuffer[])
{
    int maxStat = findLargestStat(playerStats, statLocationBuffer);
    statValueLocation(playerStats, statLocationBuffer, maxStat);
    statValueFormatting(statLocationBuffer, maxStat);
    clearStatLocationBuffer(statLocationBuffer);
    cout << endl;
}
void outputSmallestStats(int playerStats[], int statLocationBuffer[])
{
    int minStat = findSmallestStat(playerStats, statLocationBuffer);
    statValueLocation(playerStats, statLocationBuffer, minStat);
    statValueFormatting(statLocationBuffer, minStat);
    clearStatLocationBuffer(statLocationBuffer);
    cout << endl;
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

