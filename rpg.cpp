#include <iostream>
#include <string>

using namespace std;

string getPlayerName()
{
    string playerName;
    
    cout << "Hello! What is your name?" << endl;
    
    //Necessary for clearing \n characters from '>>' in cin calls
    //cin.clear();
    //cin.sync();
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


int main()
{
    string playerName = getPlayerName();
    int playerClassValue = getPlayerClass();

    playerName = validatePlayerName(playerName);
    

    return 0;
}

