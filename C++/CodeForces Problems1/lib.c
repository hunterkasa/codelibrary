#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


void init();
void welcomePage();

void viewrPage();
void adminPage();
void demoPage();

void showTeam();
void showTournament();
void showAdminPanel();
void showPlayer( int isComingFromTeam );

void modifyTeam();
void modifyPlayer();
void modifyTournament();
void modifyScoreBoardAdmin();


int main()
{
    init();
    welcomePage();
}



// ------------------------- values and parameters ------------------------- //
int isTournamentIdTaken[1000];
int isTeamIdTaken[1000];
int isPlayerIdTaken[1000];

struct player
{
    char name[50];
    int id;
    int age;
    int run;
    int totalBall;
    int totalSix;
    int totalFour;
    int isOut;
    double strickRate;
    double Average;
} player[1000];

struct team
{
    char teamName[50];
    int  teamId;
    int teamRun;
    int teamWicket;
    int playerIds[11];
} team[1000];

struct tournament
{
    char tournamentName[50];
    int tournamentId;
    int numberOfTeams; // have to be always a power of 2
    int idOfTeamsInThisTournament[1000];
    int winnerTeamId;
} tournament[1000];



// ------------------------- Welcome section ------------------------- //

int isLoggedin = 0;
void adminLogin()
{
    system("cls");
    char pasS[50];
    printf("\t\t\tEnter admin Pass: ");
    //printf("\t\t\t");
    scanf("%s", pasS);

    char adminPass[50] = "Pass";
    int result = strcmp(pasS, adminPass);
    if (result == 0)
    {
        printf("\n\t\t\tLogin successful\n");
        isLoggedin = 1;
    }
    else
    {
        printf("\t\t\tLogin Faild! Press any key to continue....");
    }
}

void welcomePage()
{
    system("cls");
    printf("");
    printf("\t\t\t Cricket ScoreBoard\t\t\t\n");
    printf("\t\t ===================================\t\t\n\n");
    printf("\t\t\tWelcome to the main menu, \n\t\tpress the corrosponding key to enter: \n");
    printf("\t =======================================================\t\n\n");

    isLoggedin = 0;

    while ( 1 )
    {
        printf("\t\t\t1. Admin.\n");
        printf("\t\t\t2. User.\n");
        printf("\t\t\t3. Demo.\n");
        printf("\t\t\t4. Exit.\n");
        printf("\t\t\t");

        int input;
        if (scanf("%d", &input) != 1)
        {
            while (getchar() != '\n');
            printf("Invalid input. Please enter a valid number.\n");
            continue;
        }

        switch (input)
        {
        case 1:
            adminLogin();
            if ( isLoggedin == 1 )
                adminPage();
            else
            {
                getch();
                welcomePage();
            }
            return;
        case 2:
            viewrPage();
            return;
        case 3:
            demoPage();
            return;
        case 4:
            system("cls");
            printf("Thank you! comeback next time.\n");
            return;
        default:
            system("cls");
            printf("Error! please enter a valid option.\n");
            break;
        }
    }

}

void init()
{
    for ( int i = 0; i < 1000; i++ )
    {
        isTournamentIdTaken[i] = 0;
        isTeamIdTaken[i] = 0;
        isPlayerIdTaken[i] = 0;
    }

    for ( int i = 0; i < 44; i++ )
        isPlayerIdTaken[i] = 1;

    // Player 1
    strcpy(player[0].name, "Player 1");
    player[0].id = 1;
    player[0].age = 25;
    player[0].run = 120;
    player[0].totalBall = 100;
    player[0].totalSix = 6;
    player[0].totalFour = 15;
    player[0].isOut = 0;
    player[0].strickRate = 120.0;
    player[0].Average = 30.0;

    // Player 2
    strcpy(player[1].name, "Player 2");
    player[1].id = 2;
    player[1].age = 28;
    player[1].run = 80;
    player[1].totalBall = 70;
    player[1].totalSix = 4;
    player[1].totalFour = 10;
    player[1].isOut = 1;
    player[1].strickRate = 114.29;
    player[1].Average = 20.0;

    // Player 3
    strcpy(player[2].name, "Player 3");
    player[2].id = 3;
    player[2].age = 23;
    player[2].run = 200;
    player[2].totalBall = 150;
    player[2].totalSix = 12;
    player[2].totalFour = 20;
    player[2].isOut = 0;
    player[2].strickRate = 133.33;
    player[2].Average = 66.67;

    // Player 4
    strcpy(player[3].name, "Player 4");
    player[3].id = 4;
    player[3].age = 26;
    player[3].run = 50;
    player[3].totalBall = 40;
    player[3].totalSix = 1;
    player[3].totalFour = 7;
    player[3].isOut = 1;
    player[3].strickRate = 125.0;
    player[3].Average = 16.67;

    // Player 5
    strcpy(player[4].name, "Player 5");
    player[4].id = 5;
    player[4].age = 30;
    player[4].run = 180;
    player[4].totalBall = 120;
    player[4].totalSix = 8;
    player[4].totalFour = 18;
    player[4].isOut = 0;
    player[4].strickRate = 150.0;
    player[4].Average = 45.0;

    // Player 6
    strcpy(player[5].name, "Player 6");
    player[5].id = 6;
    player[5].age = 22;
    player[5].run = 90;
    player[5].totalBall = 60;
    player[5].totalSix = 5;
    player[5].totalFour = 12;
    player[5].isOut = 1;
    player[5].strickRate = 150.0;
    player[5].Average = 18.0;

    // Player 7
    strcpy(player[6].name, "Player 7");
    player[6].id = 7;
    player[6].age = 27;
    player[6].run = 220;
    player[6].totalBall = 160;
    player[6].totalSix = 11;
    player[6].totalFour = 25;
    player[6].isOut = 0;
    player[6].strickRate = 137.5;
    player[6].Average = 44.0;

    // Player 8
    strcpy(player[7].name, "Player 8");
    player[7].id = 8;
    player[7].age = 24;
    player[7].run = 70;
    player[7].totalBall = 50;
    player[7].totalSix = 3;
    player[7].totalFour = 10;
    player[7].isOut = 1;
    player[7].strickRate = 140.0;
    player[7].Average = 17.5;

    // Player 9
    strcpy(player[8].name, "Player 9");
    player[8].id = 9;
    player[8].age = 29;
    player[8].run = 160;
    player[8].totalBall = 110;
    player[8].totalSix = 9;
    player[8].totalFour = 14;
    player[8].isOut = 0;
    player[8].strickRate = 145.45;
    player[8].Average = 40.0;

    // Player 10
    strcpy(player[9].name, "Player 10");
    player[9].id = 10;
    player[9].age = 21;
    player[9].run = 30;
    player[9].totalBall = 25;
    player[9].totalSix = 0;
    player[9].totalFour = 4;
    player[9].isOut = 1;
    player[9].strickRate = 120.0;
    player[9].Average = 7.5;

    // Player 11
    strcpy(player[10].name, "Player 11");
    player[10].id = 11;
    player[10].age = 23;
    player[10].run = 110;
    player[10].totalBall = 80;
    player[10].totalSix = 7;
    player[10].totalFour = 15;
    player[10].isOut = 1;
    player[10].strickRate = 137.5;
    player[10].Average = 22.0;

    // Player 12
    strcpy(player[11].name, "Player 12");
    player[11].id = 12;
    player[11].age = 29;
    player[11].run = 210;
    player[11].totalBall = 150;
    player[11].totalSix = 11;
    player[11].totalFour = 25;
    player[11].isOut = 0;
    player[11].strickRate = 140.0;
    player[11].Average = 52.5;

    // Player 13
    strcpy(player[12].name, "Player 13");
    player[12].id = 13;
    player[12].age = 25;
    player[12].run = 50;
    player[12].totalBall = 40;
    player[12].totalSix = 2;
    player[12].totalFour = 5;
    player[12].isOut = 1;
    player[12].strickRate = 125.0;
    player[12].Average = 12.5;

    // Player 14
    strcpy(player[13].name, "Player 14");
    player[13].id = 14;
    player[13].age = 28;
    player[13].run = 70;
    player[13].totalBall = 60;
    player[13].totalSix = 3;
    player[13].totalFour = 9;
    player[13].isOut = 1;
    player[13].strickRate = 116.67;
    player[13].Average = 17.5;

    // Player 15
    strcpy(player[14].name, "Player 15");
    player[14].id = 15;
    player[14].age = 22;
    player[14].run = 180;
    player[14].totalBall = 120;
    player[14].totalSix = 8;
    player[14].totalFour = 15;
    player[14].isOut = 0;
    player[14].strickRate = 150.0;
    player[14].Average = 45.0;

    // Player 16
    strcpy(player[15].name, "Player 16");
    player[15].id = 16;
    player[15].age = 24;
    player[15].run = 90;
    player[15].totalBall = 70;
    player[15].totalSix = 5;
    player[15].totalFour = 10;
    player[15].isOut = 1;
    player[15].strickRate = 128.57;
    player[15].Average = 18.0;

    // Player 17
    strcpy(player[16].name, "Player 17");
    player[16].id = 17;
    player[16].age = 27;
    player[16].run = 160;
    player[16].totalBall = 110;
    player[16].totalSix = 9;
    player[16].totalFour = 14;
    player[16].isOut = 0;
    player[16].strickRate = 145.45;
    player[16].Average = 40.0;

    // Player 18
    strcpy(player[17].name, "Player 18");
    player[17].id = 18;
    player[17].age = 21;
    player[17].run = 120;
    player[17].totalBall = 80;
    player[17].totalSix = 6;
    player[17].totalFour = 12;
    player[17].isOut = 1;
    player[17].strickRate = 150.0;
    player[17].Average = 24.0;

    // Player 19
    strcpy(player[18].name, "Player 19");
    player[18].id = 19;
    player[18].age = 26;
    player[18].run = 30;
    player[18].totalBall = 25;
    player[18].totalSix = 0;
    player[18].totalFour = 4;
    player[18].isOut = 1;
    player[18].strickRate = 120.0;
    player[18].Average = 7.5;

    // Player 20
    strcpy(player[19].name, "Player 20");
    player[19].id = 20;
    player[19].age = 30;
    player[19].run = 260;
    player[19].totalBall = 180;
    player[19].totalSix = 13;
    player[19].totalFour = 30;
    player[19].isOut = 0;
    player[19].strickRate = 144.44;
    player[19].Average = 65.0;

    // Player 21
    strcpy(player[20].name, "Player 21");
    player[20].id = 21;
    player[20].age = 25;
    player[20].run = 110;
    player[20].totalBall = 90;
    player[20].totalSix = 7;
    player[20].totalFour = 14;
    player[20].isOut = 1;
    player[20].strickRate = 122.22;
    player[20].Average = 22.0;

    // Player 22
    strcpy(player[21].name, "Player 22");
    player[21].id = 22;
    player[21].age = 28;
    player[21].run = 130;
    player[21].totalBall = 110;
    player[21].totalSix = 6;
    player[21].totalFour = 18;
    player[21].isOut = 0;
    player[21].strickRate = 118.18;
    player[21].Average = 32.5;

    // Player 23
    strcpy(player[22].name, "Player 23");
    player[22].id = 23;
    player[22].age = 23;
    player[22].run = 90;
    player[22].totalBall = 80;
    player[22].totalSix = 4;
    player[22].totalFour = 10;
    player[22].isOut = 1;
    player[22].strickRate = 112.5;
    player[22].Average = 22.5;

    // Player 24
    strcpy(player[23].name, "Player 24");
    player[23].id = 24;
    player[23].age = 29;
    player[23].run = 70;
    player[23].totalBall = 60;
    player[23].totalSix = 2;
    player[23].totalFour = 8;
    player[23].isOut = 1;
    player[23].strickRate = 116.67;
    player[23].Average = 17.5;

    // Player 25
    strcpy(player[24].name, "Player 25");
    player[24].id = 25;
    player[24].age = 22;
    player[24].run = 130;
    player[24].totalBall = 100;
    player[24].totalSix = 5;
    player[24].totalFour = 15;
    player[24].isOut = 0;
    player[24].strickRate = 130.0;
    player[24].Average = 43.33;

    // Player 26
    strcpy(player[25].name, "Player 26");
    player[25].id = 26;
    player[25].age = 24;
    player[25].run = 40;
    player[25].totalBall = 30;
    player[25].totalSix = 0;
    player[25].totalFour = 7;
    player[25].isOut = 1;
    player[25].strickRate = 133.33;
    player[25].Average = 10.0;

    // Player 27
    strcpy(player[26].name, "Player 27");
    player[26].id = 27;
    player[26].age = 27;
    player[26].run = 160;
    player[26].totalBall = 130;
    player[26].totalSix = 10;
    player[26].totalFour = 18;
    player[26].isOut = 0;
    player[26].strickRate = 123.08;
    player[26].Average = 53.33;

    // Player 28
    strcpy(player[27].name, "Player 28");
    player[27].id = 28;
    player[27].age = 21;
    player[27].run = 100;
    player[27].totalBall = 70;
    player[27].totalSix = 4;
    player[27].totalFour = 12;
    player[27].isOut = 1;
    player[27].strickRate = 142.86;
    player[27].Average = 25.0;

    // Player 29
    strcpy(player[28].name, "Player 29");
    player[28].id = 29;
    player[28].age = 26;
    player[28].run = 30;
    player[28].totalBall = 20;
    player[28].totalSix = 0;
    player[28].totalFour = 5;
    player[28].isOut = 1;
    player[28].strickRate = 150.0;
    player[28].Average = 7.5;

    // Player 30
    strcpy(player[29].name, "Player 30");
    player[29].id = 30;
    player[29].age = 30;
    player[29].run = 180;
    player[29].totalBall = 150;
    player[29].totalSix = 8;
    player[29].totalFour = 20;
    player[29].isOut = 0;
    player[29].strickRate = 120.0;
    player[29].Average = 60.0;

    // Player 31
    strcpy(player[30].name, "Player 31");
    player[30].id = 31;
    player[30].age = 25;
    player[30].run = 90;
    player[30].totalBall = 70;
    player[30].totalSix = 5;
    player[30].totalFour = 14;
    player[30].isOut = 1;
    player[30].strickRate = 128.57;
    player[30].Average = 18.0;

    // Player 32
    strcpy(player[31].name, "Player 32");
    player[31].id = 32;
    player[31].age = 28;
    player[31].run = 110;
    player[31].totalBall = 90;
    player[31].totalSix = 7;
    player[31].totalFour = 12;
    player[31].isOut = 0;
    player[31].strickRate = 122.22;
    player[31].Average = 27.5;

    // Player 33
    strcpy(player[32].name, "Player 33");
    player[32].id = 33;
    player[32].age = 23;
    player[32].run = 60;
    player[32].totalBall = 50;
    player[32].totalSix = 3;
    player[32].totalFour = 10;
    player[32].isOut = 1;
    player[32].strickRate = 120.0;
    player[32].Average = 20.0;

    // Player 34
    strcpy(player[33].name, "Player 34");
    player[33].id = 34;
    player[33].age = 29;
    player[33].run = 80;
    player[33].totalBall = 70;
    player[33].totalSix = 5;
    player[33].totalFour = 12;
    player[33].isOut = 1;
    player[33].strickRate = 114.29;
    player[33].Average = 16.0;

    // Player 35
    strcpy(player[34].name, "Player 35");
    player[34].id = 35;
    player[34].age = 22;
    player[34].run = 120;
    player[34].totalBall = 100;
    player[34].totalSix = 7;
    player[34].totalFour = 15;
    player[34].isOut = 0;
    player[34].strickRate = 120.0;
    player[34].Average = 30.0;

    // Player 36
    strcpy(player[35].name, "Player 36");
    player[35].id = 36;
    player[35].age = 24;
    player[35].run = 40;
    player[35].totalBall = 30;
    player[35].totalSix = 1;
    player[35].totalFour = 5;
    player[35].isOut = 1;
    player[35].strickRate = 133.33;
    player[35].Average = 10.0;

    // Player 37
    strcpy(player[36].name, "Player 37");
    player[36].id = 37;
    player[36].age = 27;
    player[36].run = 70;
    player[36].totalBall = 60;
    player[36].totalSix = 2;
    player[36].totalFour = 9;
    player[36].isOut = 1;
    player[36].strickRate = 116.67;
    player[36].Average = 17.5;

    // Player 38
    strcpy(player[37].name, "Player 38");
    player[37].id = 38;
    player[37].age = 21;
    player[37].run = 100;
    player[37].totalBall = 80;
    player[37].totalSix = 4;
    player[37].totalFour = 10;
    player[37].isOut = 1;
    player[37].strickRate = 125.0;
    player[37].Average = 25.0;

    // Player 39
    strcpy(player[38].name, "Player 39");
    player[38].id = 39;
    player[38].age = 26;
    player[38].run = 30;
    player[38].totalBall = 25;
    player[38].totalSix = 0;
    player[38].totalFour = 3;
    player[38].isOut = 1;
    player[38].strickRate = 120.0;
    player[38].Average = 7.5;

    // Player 40
    strcpy(player[39].name, "Player 40");
    player[39].id = 40;
    player[39].age = 30;
    player[39].run = 150;
    player[39].totalBall = 110;
    player[39].totalSix = 6;
    player[39].totalFour = 16;
    player[39].isOut = 0;
    player[39].strickRate = 136.36;
    player[39].Average = 37.5;

    // Player 41
    strcpy(player[40].name, "Player 41");
    player[40].id = 41;
    player[40].age = 25;
    player[40].run = 90;
    player[40].totalBall = 70;
    player[40].totalSix = 5;
    player[40].totalFour = 12;
    player[40].isOut = 1;
    player[40].strickRate = 128.57;
    player[40].Average = 18.0;

    // Player 42
    strcpy(player[41].name, "Player 42");
    player[41].id = 42;
    player[41].age = 28;
    player[41].run = 110;
    player[41].totalBall = 90;
    player[41].totalSix = 7;
    player[41].totalFour = 10;
    player[41].isOut = 0;
    player[41].strickRate = 122.22;
    player[41].Average = 27.5;

    // Player 43
    strcpy(player[42].name, "Player 43");
    player[42].id = 43;
    player[42].age = 23;
    player[42].run = 60;
    player[42].totalBall = 50;
    player[42].totalSix = 3;
    player[42].totalFour = 9;
    player[42].isOut = 1;
    player[42].strickRate = 120.0;
    player[42].Average = 20.0;

    // Player 44
    strcpy(player[43].name, "Player 44");
    player[43].id = 44;
    player[43].age = 29;
    player[43].run = 80;
    player[43].totalBall = 70;
    player[43].totalSix = 5;
    player[43].totalFour = 12;
    player[43].isOut = 1;
    player[43].strickRate = 114.29;
    player[43].Average = 16.0;

    // Initialize team information
    strcpy(team[0].teamName, "Team A");
    team[0].teamId = 1;
    team[0].teamRun = 0;
    team[0].teamWicket = 0;

    strcpy(team[1].teamName, "Team B");
    team[1].teamId = 2;
    team[1].teamRun = 0;
    team[1].teamWicket = 0;

    strcpy(team[2].teamName, "Team C");
    team[2].teamId = 3;
    team[2].teamRun = 0;
    team[2].teamWicket = 0;

    strcpy(team[3].teamName, "Team D");
    team[3].teamId = 4;
    team[3].teamRun = 0;
    team[3].teamWicket = 0;

    for ( int i = 0; i < 4; i++ ){
        isTeamIdTaken[i] = 1;
        // for ( int j = 0; j < 11; j++ ){
        //     team[i].playerIds[(i*11) + j] = player[(i*11) + j].id;
        // }
    }

    int j = 0;
    for ( int i = 0; i < 44; i++ ){
        j = i/11;
        team[j].playerIds[i%11] = player[i].id;
    }

    for (int i = 0; i < 4; i++) {
        int teamRun = 0;
        int teamWicket = 0;

        for (int j = 0; j < 11; j++) {
            int playerId = team[i].playerIds[j];
            teamRun += player[playerId].run;
            if (player[playerId].isOut) {
                teamWicket++;
            }
        }

        team[i].teamRun = teamRun;
        team[i].teamWicket = teamWicket;
    }

    // Initialize tournament information
    strcpy(tournament[0].tournamentName, "Tournament A");
    tournament[0].tournamentId = 1;
    tournament[0].numberOfTeams = 4; // Assuming 4 teams
    tournament[0].idOfTeamsInThisTournament[0] = 1; // Team A
    tournament[0].idOfTeamsInThisTournament[1] = 2; // Team B
    tournament[0].idOfTeamsInThisTournament[2] = 3; // Team C
    tournament[0].idOfTeamsInThisTournament[3] = 4; // Team D
    tournament[0].winnerTeamId = -1; // Initialize winnerTeamId to -1, indicating no winner yet

    // Update isTournamentIdTaken array
    isTournamentIdTaken[0] = 1; // Marking tournament ID 1 as taken

    // Update team runs and determine the winning team
    int maxTeamRun = -1;
    int winningTeamId = -1;

    for (int i = 0; i < tournament[0].numberOfTeams; i++) {
        int teamId = tournament[0].idOfTeamsInThisTournament[i];
        int teamIndex = teamId - 1;

        // Calculate total team run
        int totalTeamRun = 0;
        for (int j = 0; j < 11; j++) {
            int playerId = team[teamIndex].playerIds[j];
            totalTeamRun += team[teamIndex].teamRun;
        }

        // Update winner information
        if (totalTeamRun > maxTeamRun) {
            maxTeamRun = totalTeamRun;
            winningTeamId = teamId;
        }

        // Update tournament team run
        tournament[0].idOfTeamsInThisTournament[i] = teamId;
    }

    tournament[0].winnerTeamId = winningTeamId;

}

// ------------------------- admin ------------------------- //
void adminPage()
{
    system("cls");
    printf("\n\t\t\tWelcome Admin!\n");
    printf("\t\t  ===========================\n\n");
    printf("\t\t\t   Options: \n\n");

    while ( 1 )
    {
        printf("\t\t\t1. ScoreBoard\n");
        printf("\t\t\t2. Modify ScoreBoard\n");
        printf("\t\t\t3. Exit\n");
        printf("\t\t\t");

        int input;
        if (scanf("%d", &input) != 1)
        {
            while (getchar() != '\n');
            printf("\t\t\tInvalid input. Please enter a valid number.\n");
            continue;
        }

        switch (input)
        {
            case 1:
                showAdminPanel();
                return;
            case 2:
                modifyScoreBoardAdmin();
                return;
            case 3:
                system("cls");
                printf("\t\t\tThank you! comeback next time.\n");
                return;
            default:
                system("cls");
                printf("Error! please enter a valid option.\n");
                break;
        }
    }

}


// ------------------------- viewer ------------------------- //

void viewrPage()
{
    system("cls");
    printf("\n\n\t\t\tWhat do you like to see: \n\n");

    while ( 1 )
    {
        printf("\t\t\t1. Player Info\n");
        printf("\t\t\t2. Team Info\n");
        printf("\t\t\t3. Tournament Info\n");
        printf("\t\t\t4. Go Back\n");
        printf("\t\t\t5. Exit\n");
        printf("\t\t\t");


        int input;
        if (scanf("%d", &input) != 1)
        {
            while (getchar() != '\n');
            printf("\t\t\tInvalid input. Please enter a valid number.\n");
            continue;
        }

        switch (input)
        {
            case 1:
                printf("\t\t\tEnter the id of the player you want to see: \n");
                printf("\t\t\t");
                int id;
                scanf("%d", &id);
                while ( isPlayerIdTaken[id] != 1 ){
                    printf("\t\t\tSorry! invalid id: \n");
                    printf("\t\t\t");
                    scanf("%d", &id);
                }
                showPlayer(id);
                return;
            case 2:
                showTeam();
                return;
            case 3:
                showTournament();
                return;
            case 4:
                viewrPage();
                return;
            default:
                system("cls");
                printf("\t\t\tError! please enter a valid option.\n");
                break;
        }
    }
}


// ------------------------- demo page ------------------------- //

void demoPage()
{
    system("cls");
    // Display tournament information
    printf("Tournament: %s\n", tournament[0].tournamentName);
    printf("Tournament ID: %d\n", tournament[0].tournamentId);
    printf("Number of Teams: %d\n", tournament[0].numberOfTeams);
    printf("Teams in this Tournament:\n");
    for (int i = 0; i < tournament[0].numberOfTeams; i++) {
        printf("Team %d\n", tournament[0].idOfTeamsInThisTournament[i]);
    }
    printf("Winner Team Name: %s\n", team[tournament[0].winnerTeamId].teamName);

    for (int i = 0; i < 4; i++) {
        printf("\nTeam Name: %s\n", team[i].teamName);
        printf("Team ID: %d\n", team[i].teamId);
        printf("Team Run: %d\n", team[i].teamRun);
        printf("Team Wicket: %d\n", team[i].teamWicket);
        printf("Player IDs: ");
        for (int j = 0; j < 11; j++) {
            printf("%d ", team[i].playerIds[j]);
        }
        printf("\n");
    }
}

// ------------------------- main page ------------------------- //

void showAdminPanel()
{
    system("cls");
    printf("\n\n\t\t\tWhat do you like to see: \n\n");

    while ( 1 )
    {
        printf("\t\t\t1. Player Info\n");
        printf("\t\t\t2. Team Info\n");
        printf("\t\t\t3. Tournament Info\n");
        printf("\t\t\t4. Go Back\n");
        printf("\t\t\t5. Exit\n");
        printf("\t\t\t");


        int input;
        if (scanf("%d", &input) != 1)
        {
            while (getchar() != '\n');
            printf("\t\t\tInvalid input. Please enter a valid number.\n");
            continue;
        }

        switch (input)
        {
            case 1:
                showPlayer(0);
                return;
            case 2:
                showTeam();
                return;
            case 3:
                showTournament();
                return;
            case 4:
                adminPage();
                return;
            default:
                system("cls");
                printf("\t\t\tError! please enter a valid option.\n");
                break;
        }
    }
}


void showPlayer( int isComingFromTeam )
{
    system("cls");
    if ( isComingFromTeam == 0 )
    {

        struct player p;
        printf("\n\t\t\tEnter the id of the player you want to see: \n\n");
        printf("\t\t\t");

        int id;
        scanf("%d", &id);

        while ( isPlayerIdTaken[id] != 1 )
        {
            system("cls");
            printf("\t\t\tInvalid id! please enter again: ");
            printf("\t\t\t");
            scanf("%d",&id);
        }

        p = player[id];
        isPlayerIdTaken[id] = 1;
        printf("\n\t\t\t\t     Welcome to players scoreboard! \n");
        printf("\t\t\t\t ======================================\n\n");
        printf(" Name ");
        printf("\t\t\t\t\t\tAge \n");
        printf(" %s", p.name);
        printf("\t\t\t\t\t%d\n", p.age);
        if ( p.isOut == 1 ){
            printf(" (Out)\n\n");
        } else {
            printf(" (NOT Out)\n\n");
        }
        printf(" ID ");
        printf("\t\tRuns ");
        printf("\t\tBalls");
        printf("\t\t6s");
        printf("\t\t4s");
        printf("\t\tStrike Rate");
        printf("\t\tAverage\n\n");
        printf(" %d", p.id);
        printf("\t\t%d", p.run);
        printf("\t\t %d", p.totalBall);
        printf("\t\t %d", p.totalSix);
        printf("\t\t %d", p.totalFour);
        printf("\t\t%.2f", p.strickRate);
        printf("\t\t\t %.2f\n\n", p.Average);

        printf("Press any key to continue. . . .\n");
        char x;  
        while(1){
            scanf("%d", &x);
            if ( x )    break;
        }
        showAdminPanel();
    }
    else
    {
        struct player p = player[isComingFromTeam];
        printf("\n\t\t\t\t     Welcome to players scoreboard! \n");
        printf("\t\t\t\t ======================================\n\n");
        printf(" Name ");
        printf("\t\t\t\t\t\tAge \n");
        printf(" %s", p.name);
        printf("\t\t\t\t\t%d\n", p.age);
        if ( p.isOut == 1 ){
            printf(" (Out)\n\n");
        } else {
            printf(" (NOT Out)\n\n");
        }
        printf(" ID ");
        printf("\t\tRuns ");
        printf("\t\tBalls");
        printf("\t\t6s");
        printf("\t\t4s");
        printf("\t\tStrike Rate");
        printf("\t\tAverage\n\n");
        printf(" %d", p.id);
        printf("\t\t%d", p.run);
        printf("\t\t %d", p.totalBall);
        printf("\t\t %d", p.totalSix);
        printf("\t\t %d", p.totalFour);
        printf("\t\t%.2f", p.strickRate);
        printf("\t\t\t %.2f\n\n", p.Average);
    }

}


void showTeam()
{
    system("cls");
    struct team t;
    printf("\n\t\t\tEnter the id of the team you want to see: \n\n");
    printf("\t\t\t");

    int id;
    scanf("%d", &id);

    while ( isTeamIdTaken[id] != 1 )
    {
        system("cls");
        printf("\t\t\tInvalid id! please enter again: ");
        printf("\t\t\t");
        scanf("%d",&id);
    }

    isTeamIdTaken[id] = 1;

    // updates total run of the team
    for ( int i = 0; i < 11; i++ ){
        team[id].teamRun += player[ team[id].playerIds[i] ].run;
    }

    // updates total wicket of the team
    for ( int i = 0; i < 11; i++ ){
        team[id].teamWicket += player[ team[id].playerIds[i] ].isOut;
    }

    t = team[id];
    printf("\n\t\t\t\t     Welcome to Team scoreboard! \n");
    printf("\t\t\t\t ======================================\n\n");
    printf(" Team Name");
    printf("\t\t\tTeam ID");
    printf("\t\t\t Score\n");
    printf(" %s",t.teamName);
    printf("\t\t\t\t %d",t.teamId);
    printf("\t\t\t%d/%d\n\n",t.teamRun,t.teamWicket);
    printf("\n\n");
    //printf("\t\t\tTotal Wickets: %d\n", t.teamWicket);
    printf("\t Player Name ");
    printf("\tTotal Runs ");
    printf("\t  SR \n");
    printf("\t=============");
    printf("\t=========== ");
    printf("\t=====\n\n");
    for ( int i = 0; i < 11; i++ )
    {
        struct player p = player[ t.playerIds[i] ];
        printf("\t %s", p.name);
        printf("\t %d", p.run);
        // printf("Total Balls Faced: %d\n", p.totalBall);
        // printf("Total Sixes: %d\n", p.totalSix);
        // printf("Total Fours: %d\n", p.totalFour);
        printf("\t\t%.2f\n", p.strickRate);
        if ( p.isOut == 1 ){
            printf("\t (Out)\n\n");
        } else {
            printf("\t (NOT Out)\n\n");
        }
        printf("\n");
    }
}


void showTournament(){
    system("cls");
    struct tournament tour;
    printf("\n\t\t\tEnter the id of the tournament you want to see: \n\n");
    printf("\t\t\t");

    int id;
    scanf("%d", &id);

    while ( isTournamentIdTaken[id] != 1 )
    {
        system("cls");
        printf("\t\t\tInvalid id! please enter again: ");
        printf("\t\t\t");
        scanf("%d",&id);
    }

    isTournamentIdTaken[id] = 1;
    tour = tournament[id];
    printf("\n\t\t\t     Welcome to players scoreboard! \n");
    printf("\t\t\t ======================================\n\n");
    printf(" Name of the tournament");
    printf("\t\t\tperticipated team number\n\n");
    printf(" %s", tour.tournamentName);
    printf("\t\t\t\t\t%d\n\n\n", tour.numberOfTeams);

    printf("\t\t\t    Name of the teams in the tournament \n");
    printf("\t\t\t==========================================\n\n");

    for ( int i = 0; i < tour.numberOfTeams; i++ ){
        printf("\t\t\t\t\t%s\n", team[tour.idOfTeamsInThisTournament[i]].teamName);
    }

}


void modifyScoreBoardAdmin(){
    system("cls");
    printf("\n\t\t\tWhat score do you want to modify: \n\n");

    while ( 1 ){
        printf("\t\t\t1. Modify Player Info\n");
        printf("\t\t\t2. Modify Team Info\n");
        printf("\t\t\t3. Change Tournament Info\n");
        printf("\t\t\t4. Go Back\n");
        printf("\t\t\t5. Exit\n");
        printf("\t\t\t");
        int input;
        if (scanf("%d", &input) != 1)
        {
            while (getchar() != '\n');
            printf("\t\t\tInvalid input. Please enter a valid number.\n");
            continue;
        }

        switch (input)
        {
            case 1:
                modifyPlayer();
                return;
            case 2:
                modifyTeam();
                return;
            case 3:
                modifyTournament();
                return;
            case 4:
                adminPage();
                return;
            default:
                system("cls");
                printf("\t\t\tError! please enter a valid option.\n");
                break;
        }
    }
}


void modifyPlayer(){
    system("cls");
    printf("\n\t\t\tEnter the id of the player you want to change: \n\n");
    printf("\t\t\t");
    int id;
    scanf("%d", &id);

    while ( isPlayerIdTaken[id] != 1 )
    {
        system("cls");
        printf("\t\t\tInvalid id! please enter again: ");
        scanf("%d",&id);
    }

    isPlayerIdTaken[id] = 1;
    printf("\n\t\t\tWhat parameters do you want to change for this player: \n\n");

    while ( 1 ){
        printf("\t\t\t1. Change Player Name: \n");
        printf("\t\t\t2. Change Player ID: \n");
        printf("\t\t\t3. Change Player Age: \n");
        printf("\t\t\t4. Change Player Runs: \n");
        printf("\t\t\t5. Change Player Balls Faced: \n");
        printf("\t\t\t6. Change Player Sixes: \n");
        printf("\t\t\t7. Change Player Fours: \n");
        printf("\t\t\t8. Change Player Strike Rate: \n");
        printf("\t\t\t9. Change Player Batting Average: \n");
        printf("\t\t\t10. Change Player Wicket: \n");
        printf("\t\t\t11. Go Back\n");
        printf("\t\t\t12. Exit\n");
        printf("\t\t\t");
        int input;
        if (scanf("%d", &input) != 1)
        {
            while (getchar() != '\n');
            printf("\t\t\tInvalid input. Please enter a valid number.\n");
            continue;
        }

        switch (input)
        {
            case 1:
                printf("\t\t\tPlease enter a Name\n\n");
                fgets(player[id].name, sizeof(player[id].name), stdin);
                modifyScoreBoardAdmin();
                return;
            case 2:
                printf("\t\t\tPlease enter an ID\n");
                printf("\t\t\t");
                int pid;
                scanf("%d", &pid);
                while ( isPlayerIdTaken[pid] != 0 )
                {
                    printf("\t\t\tThe id is already taken! please enter another one!\nPress -1 to exit. . .\n");
                    printf("\t\t\t");
                    scanf("%d", &pid);
                    if ( pid == -1 ){
                        modifyTournament();
                    }
                }
                isPlayerIdTaken[pid] = 1;
                player[id].id = pid;
                modifyScoreBoardAdmin();
                return;
            case 3:
                printf("\t\t\tPlease enter an Age\n");
                printf("\t\t\t");
                scanf("%d", &player[id].age);
                modifyScoreBoardAdmin();
                return;
            case 4:
                printf("\t\t\tUpdate Runs: \n");
                printf("\t\t\t");
                int runs;
                scanf("%d", &runs);
                player[id].run += runs;
                modifyScoreBoardAdmin();
                return;
            case 5:
                printf("\t\t\tUpdate Balls Faced: \n");
                printf("\t\t\t");
                int ballfaced;
                scanf("%d", &ballfaced);
                player[id].totalBall += ballfaced;
                modifyScoreBoardAdmin();
                return;
            case 6:
                printf("\t\t\tUpdate Sixes: \n");
                printf("\t\t\t");
                int six;
                scanf("%d", &six);
                player[id].totalSix += six;
                modifyScoreBoardAdmin();
                return;
            case 7:
                printf("\t\t\tUpdate Fours: \n");
                printf("\t\t\t");
                int four;
                scanf("%d", &four);
                player[id].totalFour += four;
                modifyScoreBoardAdmin();
                return;
            case 8:
                printf("\t\t\tUpdate Runs: \n");
                printf("\t\t\t");
                int runss;
                scanf("%d", &runss);
                player[id].run += runss;
                modifyScoreBoardAdmin();
                return;
            case 9:
                printf("\t\t\tUpdate Batting Average: \n");
                player[id].Average = player[id].run/player[id].totalBall;
                modifyScoreBoardAdmin();
                return;
            case 10:
                printf("\t\t\tupdate the wicket ""1 for out, 0 for not out."" \n");
                printf("\t\t\t");
                int wicket;
                scanf("%d", &wicket);
                while ( wicket != 0 || wicket != 1 ){
                    printf("\t\t\tPlease enter the above mentioned value!\nPress -1 to exit. . .");
                    scanf("%d", &wicket);
                    if ( wicket == -1 ){
                        modifyTournament();
                    }
                }
                modifyScoreBoardAdmin();
                return;
            case 11:
                modifyScoreBoardAdmin();
                return;
            case 12:
                exit;
                return;
            default:
                system("cls");
                printf("\t\t\tError! please enter a valid option.\n");
                break;
        }
    }

}


void modifyTeam(){
    system("cls");
    printf("\n\t\t\tEnter the id of the team you want to change: \n\n");

    int id;
    scanf("%d", &id);

    while ( isTeamIdTaken[id] != 1 )
    {
        system("cls");
        printf("\t\t\tInvalid id! please enter again: ");
        printf("\t\t\t");
        scanf("%d",&id);
    }

    isTeamIdTaken[id] = 1;
    printf("\n\t\t\tWhat parameters do you want to change for this team: \n\n");

    while ( 1 ){
        printf("\t\t\t1. Change Team Name: \n");
        printf("\t\t\t2. Change Team ID: \n");
        printf("\t\t\t3. Go Back\n");
        printf("\t\t\t4. Exit\n");
        printf("\t\t\t");
        int input;
        if (scanf("%d", &input) != 1)
        {
            while (getchar() != '\n');
            printf("\t\t\tInvalid input. Please enter a valid number.\n");
            continue;
        }

        switch (input)
        {
            case 1:
                printf("\t\t\tPlease enter a Name\n");
                fgets(team[id].teamName, sizeof(team[id].teamName), stdin);
                modifyScoreBoardAdmin();
                return;
            case 2:
                printf("\t\t\tPlease enter an ID\n");
                printf("\t\t\t");
                int tid;
                scanf("%d", &tid);
                while ( isTeamIdTaken[tid] != 0 ){
                    printf("\t\t\tSorry! this id is taken. try again: \nPress -1 to exit. . .\n");
                    printf("\t\t\t");
                    scanf("%d", &tid);
                    if ( tid == -1 ){
                        modifyTournament();
                    }
                }
                team[id].teamId = tid;
                modifyScoreBoardAdmin();
                return;
            case 3:
                modifyScoreBoardAdmin();
                return;
            case 4:
                exit;
                return;
            default:
                system("cls");
                printf("\t\t\tError! please enter a valid option.\n");
                break;
        }
    }
}

int num;
void modifyTournament(){
    system("cls");
    printf("\n\t\t\tEnter the id of the Tournament you want to change: \n\n");
    printf("\t\t\t");
    int id;
    scanf("%d", &id);

    while ( isTournamentIdTaken[id] != 1 )
    {
        system("cls");
        printf("\t\t\tInvalid id! please enter again: ");
        scanf("%d",&id);
    }

    isTournamentIdTaken[id] = 1;
    printf("\n\t\t\tWhat parameters do you want to change for this team: \n\n");

    while ( 1 ){
        printf("\t\t\t1. Change Tournament Name: \n");
        printf("\t\t\t2. Change Tournament ID: \n");
        printf("\t\t\t3. Change total number of teams: \n");
        printf("\t\t\t4. Change id of a team in the tournament: \n");
        printf("\t\t\t5. Go Back\n");
        printf("\t\t\t6. Exit\n");

        int input;
        if (scanf("%d", &input) != 1)
        {
            while (getchar() != '\n');
            printf("\t\t\tInvalid input. Please enter a valid number.\n");
            continue;
        }

        switch (input)
        {
            case 1:
                printf("\t\t\tPlease enter a Name\n");
                fgets(tournament[id].tournamentName, sizeof(tournament[id].tournamentName), stdin);
                modifyScoreBoardAdmin();
                return;
            case 2:
                printf("\t\t\tPlease enter an ID\n");
                printf("\t\t\t");
                int pid;
                scanf("%d", &pid);
                while ( isTournamentIdTaken[pid] != 0 )
                {
                    printf("\t\t\tThe id is already taken! please enter another one!\n Press -1 to quit. . .\n");
                    printf("\t\t\t");
                    scanf("%d", &pid);
                    if ( pid == -1 ){
                        modifyTournament();
                    }
                }
                isTournamentIdTaken[pid] = 1;
                tournament[id].tournamentId = pid;
                modifyScoreBoardAdmin();
                return;
            case 3:

                scanf("%d", &num);
                while ( pow(2,log2(num)) != num ){
                    printf("\t\t\tError! team size must be a power of 2!");
                    printf("\t\t\t");
                    scanf("%d", &num);
                }
                tournament[id].numberOfTeams = num;
                modifyScoreBoardAdmin();
                return;
            case 4:
                printf("\n\t\t\tPlease enter a team id that you want to change.");
                printf("\t\t\t");
                int teamid;
                scanf("%d", &teamid);
                int ok = 0;
                while ( !ok ){
                    for ( int i = 0; i < tournament[id].numberOfTeams; i++ ){
                        if ( tournament[id].idOfTeamsInThisTournament[i] == teamid ){
                            ok = i;
                            break;
                        }
                    }
                    if ( !ok ){
                        printf("\t\t\tsorry team not found please try again!");
                        scanf("%d", &teamid);
                    } else {
                        break;
                    }
                }

                printf("\n\t\t\tPlease enter a new id for this team: ");
                printf("\t\t\t");
                scanf("%d", &teamid);
                while ( isTeamIdTaken[teamid] != 0 ){
                    printf("\t\t\tThis id is already taken!, try again: \nPress -1 to quit. . .");
                    scanf("%d", &teamid);
                    if ( teamid == -1 ){
                        modifyTournament();
                    }
                }

                tournament[id].idOfTeamsInThisTournament[ok] = teamid;
                isTeamIdTaken[teamid] = 1;
                modifyScoreBoardAdmin();
                return;
            case 5:
                modifyScoreBoardAdmin();
                return;
            case 6:
                exit;
                return;
            default:
                system("cls");
                printf("\t\t\tError! please enter a valid option.\n");
                break;
        }
    }
}
