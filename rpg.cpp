#include <iostream>
#include <string>

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

    return playerClassValue;
}


int main()
{
    string playerName = getPlayerName();
    int playerClassValue = getPlayerClass();
    string playerClassName;
    int infoFlag = 0;
    int selectionFlag = 1;

    //Will probably need to have separate flags for this logic process, whiteboard it out.
    while(infoFlag == 0)
        {
            if (selectionFlag == 1)
            {
                cout << "So " << playerName << ", you've chosen to play a ";
                switch (playerClassValue)
                {
                    case 1:
                        playerClassName = "Warrior";
                        cout << playerClassName << endl;
                        break;
                    case 2:
                        playerClassName = "Mage";
                        cout << playerClassName << endl;
                        break;
                    case 3:
                        playerClassName = "Assassin";
                        cout << playerClassName << endl;
                        break;
                    default:
                        cout << "There was an error at validating class name." << endl;
                }
                cout << endl;
                cout << "Is this information correct?" << endl;
                cout << "[ 1 - YES | 0 - NO ]" << endl;
                cin >> selectionFlag;
            }
            else
            {
                playerName = getPlayerName();
                playerClassValue = getPlayerClass();
            }

            if (selectionFlag == 1)
            {
                cout << "Are you sure you are ok with this information " << playerName << "?" << endl;
                cout << "[ 1 - YES | 0 - NO ]" << endl;
                cin >> selectionFlag;

                if(selectionFlag == 1)
                {
                    selectionFlag = 0;
                }
                else
                {
                    selectionFlag = 1;
                }
                
            }
        }


    return 0;
}

