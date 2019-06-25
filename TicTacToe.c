/*******************************************************************************************************************************
* Program name      : Tic-Tac-Toe
*
* Authors           : Anshuman Dubey        [13000118123]
*
* Date created      : 30-03-2019
*
* Purpose           : A playable 3x3 Tic-Tac-Toe game simulator.
*
*********************************************************************************************************************************/




#include <stdio.h>
#include <stdlib.h>
#include <String.h>
#include <time.h>
#include <windows.h>                                          //For MS-Windows system
//#include <unistd.h>                                           //For UNIX system
char player1[100], player2[100], symbol1, symbol2, gameBoard[3][3];
int centralAllignment(char s[])                               //Creates central allignment for given text.
{
	int l = strlen(s), i;
	if(l>=100)                                   //If the line has more than a hundred words
	{
		for(i=0; i < 100; i++)                  //Printing 1st 100 characters
			printf("%c", s[i]);
		printf("\n");
		centralAllignment(s+100);               //Sending after removing the 1st 100 characters.
		return 0;
	}
	for(i = 0; i < (50 - l/2); i++)             //Printing the necessary spaces
		printf(" ");
	printf("%s\n", s);
}
int stLine(char c)                                           //Printing a hundred character long line.
{
	int i;
	for(i = 0; i < 100; i++)                                  
		printf("%c", c);
	printf("\n");
	return 0;
}
int intro()                                                   //1st few lines of the program
{
	int i;
	stLine('=');
	centralAllignment(" TIC - TAC - TOE ");
	stLine('=');

	printf("\n");
	centralAllignment("Welcome to the game of TIC-TAC-TOE!");
	printf("\n");
	centralAllignment(" Before we begin, please check that each of the 2 horizontal bars above begin with being printed in single lines, i.e. the command prompt is taking more than 100 characters per line.");
	centralAllignment("If not, try increasing the width of the window or reducing the font size and restart the program.");
	printf("\n");
	centralAllignment("All Set? Let's Begin!");
	printf("\n");
	return 0;
}
int credits()                                                 //End Credits
{
	printf("\n");
	centralAllignment("Thanks for playing :)");
	printf("\n");
	stLine('-');
	centralAllignment("--: CREDITS :--");
	stLine('-');	
	centralAllignment("Anshuman Dubey");	
	stLine('-');
	return 0;
}
int input2()                                                  //Input for 2 player mode
{
	char newLine;
	printf("Enter your name player 1        : ");
	scanf("%[^\n]%*c", player1);            //String input untill '\n' occurs, and then ignoring '\n'
	printf("Enter a single character symbol : ");
	while(1){                               //Untill their's a valid symbol
		scanf("%c", &symbol1);
		scanf("%c", &newLine);               //Dumping the '\n' character
		if((symbol1>32) && (symbol1<127))
			break;
		printf("Please enter a valid symbol : ");
	}
	while(1)                                 //Untill its a different name
	{
		printf("Enter your name player 2        : ");

		scanf("%[^\n]%*c", player2);
		if(strcmp(player1,player2) == 0)                        //Checking if its a different name
			printf("Sorry, the name is already taken.\n");
		else
			break;
	}
	while(1)                                                   //Untill its a different and valid symbol
	{
		printf("Enter a single character symbol : ");
		scanf("%c", &symbol2);
		scanf("%c", &newLine);
		if((symbol2<33) || (symbol2>126))
		{
			printf("Please enter a valid symbol.\n");
			continue;
		}
		if(symbol1 == symbol2)
			printf("Sorry, the symbol is already taken.\n");
		else
			break;
	}
	return 0;
}
int input1()                                                  //Input for single player mode
{
	char newLine;
	printf("Enter your name                 : ");
	scanf("%[^\n]%*c", player1);
	printf("Enter a single character symbol : ");
	while(1){
		scanf("%c", &symbol1);
		scanf("%c", &newLine);
		if((symbol1>32) && (symbol1<127))
			break;
		printf("Please enter a valid symbol : ");
	}
	if(symbol1=='*')                                   //The computer chooses between '*' & '+' based on availability
		symbol2='+';
	else
		symbol2 = '*';
	return 0;
}
int printGameBoard()                                         //Printing playable gameboard
{
	stLine('-');
	printf("\n\t %c | %c | %c \t\t\t\t\t\t\t(0,0)|(0,1)|(0,2)\n", gameBoard[0][0], gameBoard[0][1], gameBoard[0][2]);
	printf("\t---+---+---\t\t\t\t\t\t\t-----+-----+-----\n");
	printf("\t %c | %c | %c \t\t\t\t\t\t\t(1,0)|(1,1)|(1,2)\n", gameBoard[1][0], gameBoard[1][1], gameBoard[1][2]);
	printf("\t---+---+---\t\t\t\t\t\t\t-----+-----+-----\n");
	printf("\t %c | %c | %c \t\t\t\t\t\t\t(2,0)|(2,1)|(2,2)\n\n", gameBoard[2][0], gameBoard[2][1], gameBoard[2][2]);
	stLine('-');
	return 0;
}
int printWinningGameBoard()                                 //Printing gameboard after a win or a draw
{
	char pr[] = "   |   |   ";
	pr[1] = gameBoard[0][0];
	pr[5] = gameBoard[0][1];
	pr[9] = gameBoard[0][2];
	centralAllignment(pr);
	centralAllignment("---+---+---");
	pr[1] = gameBoard[1][0];
	pr[5] = gameBoard[1][1];
	pr[9] = gameBoard[1][2];
	centralAllignment(pr);
	centralAllignment("---+---+---");
	pr[1] = gameBoard[2][0];
	pr[5] = gameBoard[2][1];
	pr[9] = gameBoard[2][2];
	centralAllignment(pr);
	return 0;
}
int example()                                               //To give the user an idea of how it's done.
{
	printf("\n");
	stLine('~');
	centralAllignment("--: EXAMPLE :--");
	printf("\n");
	centralAllignment("If the user wants to place his symbol at lower left corner, The input should go as follows :");
	printf("\n");
	printf("%s, Enter the co-ordinates of where you want to place your luck[starting from (0,0)].\nX = 2\nY = 0\n", player1);
	gameBoard[2][0] = symbol1;
	printGameBoard();
	stLine('~');
	printf("\n");
	return 0;
}
int sleeper(int time)                                        //For Waitings
{
	int i;
	for(i = 0; i < 47; i++)
			printf(" ");
	for(i = 0; i < 3; i++)
	{
		Sleep(time);                                     //For MS-Windows system 
		//usleep(time*1000);                               //For UNIX system 
		printf(". ");
	}
	printf("\n");
	return 0;
}
int isWinner()                                              //Checks if we have a winner
{
	int i;
	for(i = 0; i < 3; i++)
	{
		if(gameBoard[0][i]==gameBoard[1][i] && gameBoard[0][i]==gameBoard[2][i] && gameBoard[0][i]!=' ')    //Vertical Check
			return 1;
		if(gameBoard[i][0]==gameBoard[i][1] && gameBoard[i][0]==gameBoard[i][2] && gameBoard[i][0]!=' ')    //Horizontal Check
			return 1;
	}
	if(gameBoard[0][0]==gameBoard[1][1] && gameBoard[0][0] == gameBoard[2][2] && gameBoard[0][0]!=' ')      //1st Diagonal Check
		return 1;
	if(gameBoard[0][2]==gameBoard[1][1] && gameBoard[0][2] == gameBoard[2][0] && gameBoard[0][2]!=' ')      //2nd Diagonal Check
		return 1;
	return 0;
}
int moveInput(char player[], char symbol)                   //Takes input of the next move the player wants to make
{
	char newLine;
	int x, y;
	printf("%s, Enter the co-ordinates of where you want to place your luck[starting from (0,0)].\n", player);
	while(1)                                                  //Untill the player gives a correct co-ordinate
	{
		printf("X = ");
		scanf("%d", &x);
		scanf("%c", &newLine);
		printf("Y = ");
		scanf("%d", &y);
		scanf("%c", &newLine);
		if(gameBoard[x][y]==' ')                               //If choosen space was empty
			break;
		if(x<0||x>2||y<0||y>2)
			printf("Invalid co-ordinates. Try Again.\n");
		else
			printf("That place is already taken. Try again.\n");
	}
	gameBoard[x][y] = symbol;
}
int randomMove(int limit)                                   //Let's the computer make a random move.
{
	srand(time(0));                                         //To randomize the rand function with current time
	int choosenBox = rand()%(9-limit) + 1;
	int i, j;
	sleeper(500);
	for(i = 0; i < 3; i++)
	{
		for(j = 0; j < 3; j++)
		{
			if(gameBoard[i][j]==' ')
				choosenBox--;
			if(choosenBox==0)                                //Untill we have reached the choosen box
			{
				gameBoard[i][j] = symbol2;
				return 0;
			}
		}
	}
	return 0;
}
int stratergicMove()                                        //More sensible move
{
	
	int i, j;
	sleeper(750);
	for(i = 0; i < 3; i++)                                  //If it can win
	{
		for(j = 0; j < 3; j++)
		{
			if(gameBoard[i][j]==' ')
			{
				gameBoard[i][j] = symbol2;
				if(isWinner())                              //Place where it can win
					return 0;
				else
					gameBoard[i][j] = ' ';
			}
			
		}
	}

	for(i = 0; i < 3; i++)                                     //If opponent can win
	{
		for(j = 0; j < 3; j++)
		{
			if(gameBoard[i][j]==' ')
			{
				gameBoard[i][j] = symbol1;
				if(isWinner())
				{
					gameBoard[i][j] = symbol2;                 //Place where the opponent can win
					return 0;
				}
				else
					gameBoard[i][j] = ' ';
			}
			
		}
	}

	for(i = 0; i < 3; i++)                                     //If no winning scenario, place near opponent's character
	{
		for(j = 0; j < 3; j++)
		{
			if(gameBoard[i][j]==symbol1)                       //If current i,j, holds opponent's symbol
			{
				if(gameBoard[1][1]==' ')                       //Center
				{
					gameBoard[1][1] = symbol2;
					return 0;
				}
				if(i>0 && j>0 && gameBoard[i-1][j-1]==' ')     //Upper-Left
				{
					gameBoard[i-1][j-1] = symbol2;
					return 0;
				}
				if(i<2 && j<2 && gameBoard[i+1][j+1]==' ')    //Lower-Right
				{
					gameBoard[i+1][j+1] = symbol2;
					return 0;
				}
				if(i<2 && j>0 && gameBoard[i+1][j-1]==' ')    //Lower-Left
				{
					gameBoard[i+1][j-1] = symbol2;
					return 0;
				}
				if(i>0 && j<2 && gameBoard[i-1][j+1]==' ')    //Upper-Right
				{
					gameBoard[i-1][j+1] = symbol2;
					return 0;
				}
				if(i>0 && gameBoard[i-1][j]==' ')             //Up
				{
					gameBoard[i-1][j] = symbol2;
					return 0;
				}
				if(j>0 && gameBoard[i][j-1]==' ')            //Left
				{
					gameBoard[i][j-1] = symbol2;
					return 0;
				}
				
				if(i<2 && gameBoard[i+1][j]==' ')            //Down
				{
					gameBoard[i+1][j] = symbol2;
					return 0;
				}
				if(j<2 && gameBoard[i][j+1]==' ')           //Right
				{
					gameBoard[i][j+1] = symbol2;
					return 0;
				}
				
			}
			
		}
	}
	return 0;
}
int gamePlay2()                                             //2 player gaming system
{
	int i,j, round = 0, x, y;
	char playAgain, newLine, tag[100] = "The WINNER is : ", vs[100] = "--: ";
	strcat(vs, player1);
	strcat(vs, " vs ");
	strcat(vs, player2);
	strcat(vs, " :--");
	for(i = 0; i < 3; i++)
	{
		for(j = 0; j < 3; j++)
			gameBoard[i][j] = ' ';                         //Creating a blank 3x3 Game Board
	}
	stLine('-');
	centralAllignment(vs);
	while(round<9)                                         //Maximum of 9 rounds possible
	{
		printGameBoard();
		if(round%2 == 0)
		{
			moveInput(player1, symbol1);               //Input for player 1
			if(isWinner())
			{
				stLine('*');
				centralAllignment("CONGRACTULATIONS!!!");
				stLine('*');
				printWinningGameBoard();
				stLine('*');
				centralAllignment(strcat(tag, player1));
				stLine('*');
				printf("\nYou guys wanna play again?(Y/Any other key) : ");
				scanf("%c", &playAgain);
				scanf("%c", &newLine);
				if(playAgain=='Y' || playAgain=='y') 
					gamePlay2();
				return 0;
			}
		}
		else
		{
			moveInput(player2, symbol2);              //Input for player 2
			if(isWinner())
			{
				stLine('*');
				centralAllignment("CONGRACTULATIONS!!!");
				stLine('*');
				printWinningGameBoard();
				stLine('*');
				centralAllignment(strcat(tag, player2));
				stLine('*');
				printf("\nYou guys wanna play again?(Y/Any other key) : ");
				scanf("%c", &playAgain);
				scanf("%c", &newLine);
				if(playAgain=='Y' || playAgain=='y')
					gamePlay2();
				return 0;
			}
		}
		round++;
	}
	printWinningGameBoard();                        //If it's a draw
	printf("Sorry folks, it's a draw. You guys wanna play again?(Y/Any other key) : ");
	scanf("%c", &playAgain);
	scanf("%c", &newLine);
	if(playAgain=='Y' || playAgain=='y')
		gamePlay2();
	return 0;
}
int gamePlay1(int difficulty)                               //Single player gaming system
{
	int i,j, round = 0, x, y;
	char playAgain, newLine, tag[100], vs[100] = "--: ";
	strcpy(tag, player1);
	strcat(tag, ", you WON!!!");
	strcat(vs, player1);
	strcat(vs, " vs ME :--");
	for(i = 0; i < 3; i++)                                  //Creating a 3x3 blank Game Board
	{
		for(j = 0; j < 3; j++)
			gameBoard[i][j] = ' ';
	}
	stLine('-');
	centralAllignment(vs);
	while(round<9)
	{
		 printGameBoard();
		if(round%2 == 0)
		{
			moveInput(player1, symbol1);               //Player's input
			if(isWinner())
			{
				stLine('*');
				centralAllignment("CONGRACTULATIONS!!!");
				stLine('*');
				printWinningGameBoard();
				stLine('*');
				centralAllignment(tag);
				stLine('*');
				printf("One more round?(Y/Any other key) : ", player1);
				scanf("%c", &playAgain);
				scanf("%c", &newLine);
				if(playAgain=='Y' || playAgain=='y')
					gamePlay1(difficulty);
				return 0;
			}
		}
		else                                              //Computer's turn
		{
			printf("Now here's my move!\n");
			if(difficulty==1)                             //Easy
				randomMove(round);
			else if(difficulty==3)                        //Hard
				stratergicMove();
			else if((round-1)%4==0)                       //Medium
				randomMove(round);
			else
				stratergicMove();
			if(isWinner())
			{
				printf("No Hard Feelings Mate, But :\n");
				stLine('*');
				printWinningGameBoard();
				stLine('*');
				centralAllignment("I WON!!!");
				stLine('*');
				printf("Wanna try your luck again?(Y/Any other key) : ");
				scanf("%c", &playAgain);
				scanf("%c", &newLine);
				if(playAgain=='Y' || playAgain=='y')
					gamePlay1(difficulty);
				return 0;
			}
		}
		round++;
	}                                                     //In case of a Draw
	printWinningGameBoard();
	printf("Sorry Buddy, it's a draw. You wanna play again?(Y/Any other key) : ");
	scanf("%c", &playAgain);
	scanf("%c", &newLine);
	if(playAgain=='Y' || playAgain=='y')
		gamePlay1(difficulty);
	return 0;
}
int main()
{
	int mode, difficulty, i, j;
	for(i = 0; i < 3; i++)                                  //Creating a 3x3 blank Game Board
	{
		for(j = 0; j < 3; j++)
			gameBoard[i][j] = ' ';
	}
	char newLine;
	intro();                                            //Introduction
	centralAllignment("1.Play against me.             2. Play against a friend.");
	printf("Enter your choice : ");
	while(1)                                                //Until a valid input is present
	{
		scanf("%d", &mode);
		scanf("%c", &newLine);                              //Removing newLine character
		if(mode==1||mode==2)
			break;
		printf("Either 1 or 2, Sir. Let's try this again : ");
	}

	if(mode==2)
	{
		printf("\n");
		stLine('-');
		centralAllignment("Hello Players. Let's get to know each other : ");
		stLine('-');
		input2();
		example();
		sleeper(3333);
		gamePlay2();
	}

	else                                                   //Single Player Mode
	{
		printf("\n");
		stLine('-');
		centralAllignment("Hello Player! What level do you choose?");
		stLine('-');
		centralAllignment("1. Easy                 2. Medium                 3. Hard");
		printf("Enter your choice : ");
		while(1)                                          //Until valid difficulty level is given
		{
			scanf("%d", &difficulty);
			scanf("%c", &newLine);
			if(difficulty>0 && difficulty<4)
				break;
			printf("Invalid Input. Let's try again : ");
		}
		stLine('-');
		centralAllignment("Introduction Time :");
		stLine('-');
		input1();
		example();
		sleeper(3333);
		gamePlay1(difficulty);
	}
	credits();
	sleeper(3333);                                       //To delay the exit of program by 10 seconds
	return 0;
}