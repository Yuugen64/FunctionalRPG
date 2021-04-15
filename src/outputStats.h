#include <iostream>
#include <string>

//This function displays the stats currently in Stats Array
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


//=============================================================================================
//Combined Functions for showing BEST and WORST stats in more user-friendly style.
//Preferably use these for outputting to the user.
//=============================================================================================
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