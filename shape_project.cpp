#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

void square(int line);
void triangle(int line);
void rectangle (int line);
void diamond (int line);
void space ();
void introduction();
void shapeDisplay(int one, int two, int three, int four);
void generateCards(int compCards[]);
void getGuesses(int playerCards[], int guessAmount);
void match(int* correctGuesses, int* closeGuesses, int compCards[], int playerCards[]);
void playAgain(char* continueGame);

int main()
{
	int compCards[4]; 
	int playerCards[4];
	int correctGuesses, closeGuesses, guessesLeft;
	char continueGame;
	
	srand(time(NULL));

	introduction();
	
	do
	{
		guessesLeft=8;
		generateCards(compCards);
		while (guessesLeft > 0) 
		{
//			for(int i = 0; i<4;i++)
//				cout << compCards[i] << " ";
//			cout << endl;
			
			getGuesses(playerCards, guessesLeft);
						
			correctGuesses=0;
			closeGuesses=0;
			match(&correctGuesses, &closeGuesses, compCards, playerCards);
			cout << "You have " << correctGuesses << " guesses correct!\tYou have " << closeGuesses << " cards with the right shape,"
			<< " but in\nthe wrong order.\n\n";
			if(correctGuesses >= 4)
				break;
			guessesLeft--;
		} 
		if(guessesLeft>0)
			cout << "You win!\n\n";
		else
			cout << "You lost.\n\n";
		shapeDisplay(compCards[0], compCards[1], compCards[2], compCards[3]);
		
		playAgain(&continueGame);
	} while (continueGame == 'Y' || continueGame == 'y'); 
	
	return 0;
}

void square(int line)
{
	if(line==1)
		cout << "**********";
	else if (line>=2 && line<=5)
		cout << "*        *";
	else if (line==6)
		cout << "**********";
}

void triangle(int line)
{
	if(line==1)
		cout << "     *     ";
	else if(line==2)
		cout << "    * *    ";
	else if(line==3)
		cout << "   *   *   ";
	else if(line==4)
		cout << "  *     *  ";
	else if(line==5)
		cout << " *       * ";
	else if(line==6)
		cout << "***********";	
	
}

void rectangle(int line)
{
	if(line>=1 && line<=3)
		cout << "                 ";
	else if(line==4 || line==6)
		cout << "*****************";
	else if(line==5)
		cout << "*               *";
}

void diamond(int line)
{
	if(line==1)
		cout << "           ";
	else if(line==2 || line==6)
		cout << "     *     ";
	else if(line==3 || line==5)
		cout << "  *     *  ";
	else if(line==4)
		cout << "*         *";
}

void space()
{
	cout << "     ";
}

void introduction()
{
	cout << "\t\t\tGUESS THE SHAPES!" << endl;
	shapeDisplay(1,2,3,4);
	cout << "\nPlay the game and guess the shapes!  There are four cards face down in front of\nyou.  Each card has a shape, and shapes CAN repeat.  ";
	cout << "Using the clues you're\ngiven, can you guess all four cards successfully?";
}

void shapeDisplay(int one, int two, int three, int four)
{

	for (int x=1; x<=6; x++)
	{
		for (int n=1; n<=4;n++)
			switch (n){
				case 1: 
					if(one==1)
						square(x);
					else if(one==2)
						triangle(x);
					else if(one==3)
						rectangle(x);
					else if(one==4)
						diamond(x);
					space();
					break;
				case 2:
					if(two==1)
						square(x);
					else if(two==2)
						triangle(x);
					else if(two==3)
						rectangle(x);
					else if(two==4)
						diamond(x);
					space();
					break;
				case 3:
					if(three==1)
						square(x);
					else if(three==2)
						triangle(x);
					else if(three==3)
						rectangle(x);
					else if(three==4)
						diamond(x);
					space();
					break;
				case 4:
					if(four==1)
						square(x);
					else if(four==2)
						triangle(x);
					else if(four==3)
						rectangle(x);
					else if(four==4)
						diamond(x);
					space();
					cout << endl;
					break;
			}
		
	}
	
}
void generateCards(int cards[])
	{
		cout <<endl;
		for(int i = 0; i<4; i++)
		{
			cards[i] = rand()%4+1;
		}
	}
	
void getGuesses(int playerCards[], int guessAmount)
{	
	cout << "\n\nEnter your guesses, one at a time.\nEnter 1 for square, 2 for triangle, 3 for rectangle, or 4 for diamond.\n"
		 << "You have " << guessAmount << " guesses left.\n";
	for(int i=0; i<4;i++)
		cin >> playerCards[i];
}

void match(int* correctGuesses, int* closeGuesses, int compCards[], int playerCards[])
{
//	for(int i = 0; i<4;i++)
//	{
//		for(int j = 0; j<4; j++)
//		{
//			if(playerCards[i] == compCards[j])
//			{
//				if(i==j)
//				{
//					(*correctGuesses)++;
//					playerCards[i]=5;
//				}
//				else
//				{
//					(*closeGuesses)++;
//					playerCards[i]=5;	
//				}
//			}
//		}
//	}
	
	int tempCards[4];
	
	for(int i=0; i<4; i++)
		tempCards[i]=compCards[i];
		
	for(int i=0; i<4; i++)
	{
		if(tempCards[i]==playerCards[i])
		{
			(*correctGuesses)++;
			tempCards[i]=5;
			playerCards[i]=6;	
		}
	}
	
	for(int i=0; i<4; i++)
	{
		if(playerCards[i]==6);
		else
		{
			for(int j=0; j<4; j++)
			{
				if(playerCards[i]==tempCards[j])
				{
					(*closeGuesses)++;
					tempCards[j]=5;
					playerCards[i]=6;
				}
			}
		}
	}
}

void playAgain(char* continueGame)
{
	cout << "Do you want to play again?  Y/N\n";
	cin >> *continueGame;
}
