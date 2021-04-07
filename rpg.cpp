#include <iostream>
#include <string>

#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

using namespace std;

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

int generateplayerStats(int playerClassValue)
{
    string classContainer;
    //Initialize the random seed:
    srand (time(NULL));

    //The actual stat values: Attack, Defense, Speed, Magic Power, Stamina, Mana
    int playerAttack = rand() % 10 + 1;
    int playerDefense = rand() % 10 + 1;
    int playerSpeed = rand() % 10 + 1;
    int playerMP = rand() % 10 + 1;
    int playerStamina = rand() % 10 + 1;
    int playerMana = rand() % 10 + 1;


//convert class value to string name for output purposes.
    classContainer = convertToClassName(playerClassValue);
    

    switch (playerClassValue)
    {
        case 1: //warrior
            playerDefense += 2;
            playerStamina += 1;
            cout << "Your choice to play a " << classContainer << " grants you +2 to Defense, and +1 to Stamina" << endl;
            break;
        case 2: //mage
            playerMP += 2;
            playerMana += 1;
            cout << "Your choice to play a " << classContainer << " grants you +2 to Magic Power, and +1 to Mana" << endl;
            break;
        case 3: //assassin
            playerAttack += 2;
            playerSpeed += 1;
            cout << "Your choice to play a " << classContainer << " grants you +2 to Attack, and +1 to Speed" << endl;
            break;
        default:
            cout << "ERROR in stat generation." << endl;
    }

    cout << "Your stats for [ Attack | Defense | Speed | Magic Power | Stamina | Mana ]" << endl;
    cout << " [ " << playerAttack << " | " << playerDefense << " | " << playerSpeed << " | " << playerMP << " | " << playerStamina << " | " << playerMana << " ] " << endl;

    return 1;
}


int main()
{
    //Prompt for player info.
    string playerName = getPlayerName();
    int playerClassValue = getPlayerClass();

    //Validation of player info.
    playerName = validatePlayerName(playerName);
    playerClassValue = validatePlayerClass(playerClassValue);    

    //Generate player stats.
    int returnedStats = generateplayerStats(playerClassValue);

    return 0;
}

