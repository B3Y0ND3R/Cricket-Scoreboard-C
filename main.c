#include <stdio.h>
#include <stdlib.h>

struct Batsman {
    char playerName[25];
    int runs, score, balls, totalRuns, totalBalls, ones, twos, threes, fours, sixes;
    int maxSix, maxRun, maxFour;
    float strikeRate;
} playerList[100], currentPlayer;

struct Bowler {
    char playerName[25];
    int runsGiven, wicketsTaken, oversBowled;
    int maxWickets;
    float economyRate;
} bowlerList[100], currentBowler;

int main() {
    int playerCount, choice;
    int i, bowlerCount;

    printf("Enter Batsman details:\n");
    printf("Enter the number of batsmen:\n");
    scanf("%d", &playerCount);

    for (i = 0; i < playerCount; i++) {
        printf("Enter name of batsman %d:\n", i + 1);
        scanf("%s", playerList[i].playerName);

        printf("Enter the number of ones scored by %s:\n", playerList[i].playerName);
        scanf("%d", &playerList[i].ones);

        printf("Enter the number of twos scored by %s:\n", playerList[i].playerName);
        scanf("%d", &playerList[i].twos);

        printf("Enter the number of threes scored by %s:\n", playerList[i].playerName);
        scanf("%d", &playerList[i].threes);

        printf("Enter the number of fours scored by %s:\n", playerList[i].playerName);
        scanf("%d", &playerList[i].fours);

        printf("Enter the number of sixes scored by %s:\n", playerList[i].playerName);
        scanf("%d", &playerList[i].sixes);

        printf("Enter the balls played by %s:\n", playerList[i].playerName);
        scanf("%d", &playerList[i].balls);
    }

    printf("\nEnter Bowler details:\n");
    printf("Enter the number of bowlers:\n");
    scanf("%d", &bowlerCount);

    for (i = 0; i < bowlerCount; i++) {
        printf("\nEnter name of bowler %d:", i + 1);
        scanf("%s", bowlerList[i].playerName);

        printf("Enter the runs given by %s:\n", bowlerList[i].playerName);
        scanf("%d", &bowlerList[i].runsGiven);

        printf("Enter the overs bowled by %s:\n", bowlerList[i].playerName);
        scanf("%d", &bowlerList[i].oversBowled);

        printf("Enter the wickets taken by %s\n", bowlerList[i].playerName);
        scanf("%d", &bowlerList[i].wicketsTaken);
    }

    printf("Thank you, all details are recorded\n");

    do {
        printf("Enter the choice:\n 1) Batsman detail\n 2) Bowlers detail\n 3) Match summary\n 4) Record\n 5) Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the batsman number to see details\n");
                scanf("%d", &playerCount);

                playerCount--;
                printf("Player Detail\n");
                printf("==============================================\n");
                printf(" Batsman      Runs      Balls     Fours    Sixes    SR  \n");
                printf("==============================================\n");

                playerList[playerCount].runs = (1 * playerList[playerCount].ones) + (2 * playerList[playerCount].twos)
                                               + (3 * playerList[playerCount].threes) + (4 * playerList[playerCount].fours)
                                               + (6 * playerList[playerCount].sixes);
                playerList[playerCount].strikeRate = (playerList[playerCount].runs * 100.00) / playerList[playerCount].balls;
                printf(" %-15s %-10d %-10d %-8d %-8d %-6.2f\n\n", playerList[playerCount].playerName,
                       playerList[playerCount].runs, playerList[playerCount].balls,
                       playerList[playerCount].fours, playerList[playerCount].sixes, playerList[playerCount].strikeRate);

                break;

            case 2:
                printf("Enter the bowler number to see details\n");
                scanf("%d", &playerCount);

                playerCount--;
                printf("Player Detail\n");
                printf("=================================================\n");
                printf(" Bowler       Overs       Runs       Wickets       Economy\n");
                printf("=================================================\n");

                for (i = 0; i < bowlerCount; i++) {
                    bowlerList[playerCount].economyRate = bowlerList[playerCount].runsGiven / bowlerList[playerCount].oversBowled;
                    printf(" %-15s %-10d %-10d %-12d %-8.2f\n\n", bowlerList[playerCount].playerName,
                           bowlerList[playerCount].oversBowled, bowlerList[playerCount].runsGiven,
                           bowlerList[playerCount].wicketsTaken, bowlerList[playerCount].economyRate);
                }

                break;

            case 3:
                printf("Match summary\n");
                printf("============================================================\n");
                printf(" Batsman      Runs      Balls     Fours    Sixes    SR  \n");
                printf("============================================================\n");

                for (i = 0; i < playerCount; i++) {
                    playerList[i].runs = (1 * playerList[i].ones) + (2 * playerList[i].twos)
                                         + (3 * playerList[i].threes) + (4 * playerList[i].fours) + (6 * playerList[i].sixes);
                    currentPlayer.totalRuns += playerList[i].runs;
                    playerList[i].strikeRate = (playerList[i].runs * 100.00) / playerList[i].balls;
                    printf(" %-15s %-10d %-10d %-8d %-8d %-6.2f\n\n", playerList[i].playerName,
                           playerList[i].runs, playerList[i].balls,
                           playerList[i].fours, playerList[i].sixes, playerList[i].strikeRate);
                }
                printf("TOTAL RUNS:%d\n\n", currentPlayer.totalRuns);
                printf("\n\n");
                printf("====================================================\n");
                printf(" Bowler       Overs       Runs       Wickets       Economy\n");
                printf("====================================================\n");

                for (i = 0; i < bowlerCount; i++) {
                    bowlerList[i].economyRate = bowlerList[i].runsGiven / bowlerList[i].oversBowled;
                    printf(" %-15s %-10d %-10d %-12d %-8.2f\n\n\n", bowlerList[i].playerName,
                           bowlerList[i].oversBowled, bowlerList[i].runsGiven,
                           bowlerList[i].wicketsTaken, bowlerList[i].economyRate);
                }

                break;

            case 4:
                currentPlayer.maxRun = 0, currentBowler.maxWickets = 0, currentPlayer.maxFour = 0, currentPlayer.maxSix = 0;

                for (i = 0; i < playerCount; i++) {
                    playerList[i].runs = (1 * playerList[i].ones) + (2 * playerList[i].twos)
                                         + (3 * playerList[i].threes) + (4 * playerList[i].fours) + (6 * playerList[i].sixes);
                    if (currentPlayer.maxRun < playerList[i].runs) {
                        currentPlayer.maxRun = playerList[i].runs;
                    }

                    if (currentPlayer.maxSix < playerList[i].sixes) {
                        currentPlayer.maxSix = playerList[i].sixes;
                    }

                    if (currentPlayer.maxFour < playerList[i].fours) {
                        currentPlayer.maxFour = playerList[i].fours;
                    }

                    if (currentBowler.maxWickets < bowlerList[i].wicketsTaken) {
                        currentBowler.maxWickets = bowlerList[i].wicketsTaken;
                    }
                }
                printf("Highest runs scored by a batsman:%d\n", currentPlayer.maxRun);

                printf("Maximum fours scored by a batsman:%d\n", currentPlayer.maxFour);

                printf("Maximum sixes scored by a batsman:%d\n", currentPlayer.maxSix);

                printf("Maximum wickets taken by a bowler:%d\n", currentBowler.maxWickets);

                break;

            case 5:
                exit(1);

            default:
                printf("Enter the correct choice\n");
                break;
        }

    } while (choice != 5);

    return 0;
}
