//***********************************************
//***		Created By: Luc Gaupin		      ***
//***		Date......: Jan. 16th 2019	      ***
//***		Purpose...: 2DArrays	          ***
//***********************************************

#include "C:\Users\juluc\Desktop\Files\School\myTemplate.h"
#define ROWS 5
#define COLS 2

//	== P. FUNCTIONS ==
int displayAllResultsFromGamesWon(int myArray[][COLS], int eSize);
int displayOpponentScoreLowToHigh(int myArray[][COLS], int eSize);
void displayMenu();
void gameResults(int myArray[ROWS][COLS], int eSize);
int getCurrentRecord(int myArray[][COLS], int eSize);
int getChoice();

int main()
{
	//===This is a 2D array, you hate these Luc===//
	int myArray[ROWS][COLS] = { 0 };

	//===eSize is basically a counter that will help count the places in the array. eSize = 0 means the 'counter' starts at index 0.===//
	int eSize = 0;
	int choice;
	
	do
	{
		choice = getChoice();
		switch (choice)
		{
		case 1:
			gameResults(myArray[ROWS][COLS], eSize);
			break;
		case 2:
			getCurrentRecord(myArray[ROWS][COLS], eSize);
			break;
		case 3:
			displayAllResultsFromGamesWon(myArray[ROWS][COLS], eSize);
			break;
		case 4:
			displayOpponentScoreLowToHigh(myArray[ROWS][COLS], eSize);
			break;
		case 5:
			CLS;
			printf("Have A Great Day!\n");
			PAUSE;
			break;
		default:
			break;
		}
		eSize++;
	} while (choice != 5);
}


// == R. FUNCTIONS ==

int displayAllResultsFromGamesWon(int myArray[][COLS], int eSize)
{
	CLS;

	printf("You WON these games: \n\n");

	for (int r = 0; r < 5; r++)
	{
		for (int c = 0; c < 2; c++)
		{
			if (myArray[r][0] > myArray[r][1])
			{
				printf("GAME #[%d] TEAM[%d] = Score[%d]\n", r, c, myArray[r][c]);
			}
		}
	}
	PAUSE;
	CLS;
}

int displayOpponentScoreLowToHigh(int myArray[][COLS], int eSize)
{
	CLS;

	int temp, l;

	for (int r = 0; r < 5; r++)
	{
		for (int c = 1; c < 2; c++)
		{
			temp = myArray[r][c];
			l = c + 1;
			for (int k = r; k < 5; k++)
			{
				while (l < 5)
				{
					if (temp > myArray[k][l])
					{
						temp = myArray[k][l];
						myArray[k][l] = myArray[r][c];
						myArray[r][c] = temp;
					}
					l++;
				}
				l = 0;
			}
		}
	}

	printf("Sorted List: \n");

	for (int r = 0; r < 5; r++)
	{
		for (int c = 1; c < 2; c++)
		{
			printf("GAME[%d] TEAM[%d] = %d\n", r, c, myArray[r][c]);
		}
	}
	PAUSE;
	CLS;
}

void displayMenu()
{
	printf("1. Enter Game Results\n");
	printf("2. Current Record (# of WINS, LOSSES, & TIES)\n");
	printf("3. Display ALL results from all WON games\n");
	printf("4. Display ALL results ordered by OPPONENT score from LOW to HIGH\n");
	printf("5. Quit\n\n");
	printf("Enter Choice: ");
}

void gameResults(int myArray[][COLS], int eSize)
{
	CLS;
	//===These nested for loops is for user input to be 'put into the next row in the array. Use eSize for the first one===//
	//===Then use COLS for the second for-loop.===//

	printf("[GAME #][TEAM #] = SCORE\n");
	for (int r = 0; r < 5; r++)
	{
		for (int c = 0; c < 2; c++)
		{
			printf("ENTER SCORE at GAME# [%d] TEAM# [%d] SCORE: ", r, c);
			scanf("%d", &myArray[r][c]);
		}
	}

	//===This for loop will display the array in the program.===//
	//===It will look like===//
	//===[1][0] = 3 (our score)===//
	//===[1][1] = 2 (their score)===//
	//=== the first box represents the game number, the second box represents the team. And the = # is the score.===//
	
	printf("\nThe Game Scores Were: \n\n");

	for (int r = 0; r < 5; r++)
	{
		printf("\nGAME %d :  ", r);
		for (int c = 0; c < 2; c++)
		{
			printf("%d ", myArray[r][c]);
		}
		printf("\n---------------------------\n");
	}
	PAUSE;
	CLS;
}

int getCurrentRecord(int myArray[][COLS], int eSize)
{
	CLS;
	int countWins = 0;
	int countTies = 0;
	int countLosses = 0;


	for (int r = 0; r < 5; r++)
	{
		for (int c = 0; c < 2; c++)
		{
			if (myArray[r][0] > myArray[r][1])
			{
				countWins++;
			}
			else if (myArray[r][0] == myArray[r][1])
			{
				countTies++;
			}
			else
			{
				countLosses++;
			}
		}
	}

	printf("Won %d games\n", countWins / 2);
	printf("Tied %d games\n", countTies / 2);
	printf("Lost %d games\n", countLosses / 2);
	PAUSE;
	CLS;

}

int getChoice()
{
	int result;
	displayMenu();
	scanf_s("%i", &result);
	return result;
}