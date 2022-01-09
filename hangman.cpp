#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;


void figure(int t)
{
	switch (t)
	{
		case 0:
			cout << " _________     \n";
			cout << "|         |    \n";
			cout << "|         0    \n";
			cout << "|          \n";
			cout << "|          \n";
			cout << "|              \n";
			cout << "|              \n";
			break;
		case 1:
			cout << " _________     \n";
			cout << "|         |    \n";
			cout << "|         0    \n";
			cout << "|         |  \n";
			cout << "|          \n";
			cout << "|              \n";
			cout << "|              \n";
			break;
		case 2:
			cout << " _________     \n";
			cout << "|         |    \n";
			cout << "|         0    \n";
			cout << "|        /|  \n";
			cout << "|         \n";
			cout << "|              \n";
			cout << "|              \n";
			break;
		case 3:
			cout << " _________     \n";
			cout << "|         |    \n";
			cout << "|         0    \n";
			cout << "|        /|\\  \n";
			cout << "|          \n";
			cout << "|              \n";
			cout << "|              \n";
			break;
		case 4:
			cout << " _________     \n";
			cout << "|         |    \n";
			cout << "|         0    \n";
			cout << "|        /|\\  \n";
			cout << "|        /   \n";
			cout << "|              \n";
			cout << "|              \n";
			break;
		case 5:
			cout << " _________     \n";
			cout << "|         |    \n";
			cout << "|         0    \n";
			cout << "|        /|\\  \n";
			cout << "|        / \\  \n";
			cout << "|              \n";
			cout << "|              \n";
	}
}

int main()
{
	void figure(int t);
	ifstream items;
	srand((int)time(0));
	items.open("items.txt");
	string word[100];
	int count = 0;
	if (!items)
	{
		cout << "Problem with file \n";
		system("pause");
		return 0;
	}
	while (items.good())
	{
		getline(items, word[count++]);
	}
	int ch = rand() % count;
	string arg = word[ch];
	int detect_count = 0; string detect = "                                                                                              ";
	int loss_test = 0, win_test = 0;
	cout << "Guess the string or watch him swing! Welcome to Hangman, developed by Sidzzz.\n";
	cout << "The word is: \n";
	for (int i = 0; arg[i] != '\0'; ++i)
	{
		switch (arg[i])
		{
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
		case 'A':
		case 'E':
		case 'I':
		case 'O':
		case 'U':
		case ' ':
			cout << arg[i] << " ";
			break;
		default:
			win_test++;
			cout << "_ ";
		}
	}
	cout << endl;
	int flag2 = 0;
	do 
	{
		char inp;
		if (!win_test)
		{
			cout << "Game Over! You Won! \n";
			break;
		}
		cout << "Input your next character to be checked: \n";
		cin >> inp;
		int flag = 0;
		for (int i = 0; arg[i] != '\0'; ++i)
		{
			if (inp == arg[i])
			{
				flag = 1;
				win_test = 0;
				break;
			}
		}
		if (flag)
		{
			cout << "You got one!\n";
			detect[detect_count++] = inp;
			for (int i = 0; arg[i] != '\0'; ++i)
			{
				if (arg[i] == 'a' or arg[i] == 'e' or arg[i] == 'i' or arg[i] == 'o' or arg[i] == 'u' or arg[i] == 'A' or arg[i] == 'E' or arg[i] == 'I' or arg[i] == 'O' or arg[i] == 'U' or arg[i] == ' ')
				{
					cout << arg[i] << " ";
					flag2 = 1;
				}
				else
				{
					for (int j = 0; detect[j] != '\0'; ++j)
					{
						flag2 = 0;
						if (arg[i] == detect[j])
						{
							cout << detect[j] << " ";
							flag2 = 1;
							break;
						}
					}
				}
				if (flag2 == 0)
				{
					win_test++;
					cout << '_' << " ";
				}
			}
			cout << endl;
		}
		else
		{
			cout << "Uh oh! \n";
			figure(loss_test++);
			cout << "The word is: \n";
			for (int i = 0; arg[i] != '\0'; ++i)
			{
				if (arg[i] == 'a' or arg[i] == 'e' or arg[i] == 'i' or arg[i] == 'o' or arg[i] == 'u' or arg[i] == 'A' or arg[i] == 'E' or arg[i] == 'I' or arg[i] == 'O' or arg[i] == 'U' or arg[i] == ' ')
				{
					cout << arg[i] << " ";
					flag2 = 1;
				}
				else
				{
					for (int j = 0; detect[j] != '\0'; ++j)
					{
						flag2 = 0;
						if (arg[i] == detect[j])
						{
							cout << detect[j] << " ";
							flag2 = 1;
							break;
						}
					}
				}
				if (flag2 == 0)
				{
					cout << '_' << " ";
				}
			}
			cout << endl;
		}
	} while (loss_test < 6);
	if (loss_test == 6)
	{
		cout << "Game Over! You Lost! \n";
		cout << "The word was: " << arg << endl;
	}
	system("pause");
}