#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main(int argc, char** argv)
{
	if (argc == 5)
	{
		//Reading command options.
		int maxVal = (int)*argv[3] - 48; //Maximum value the given value can reach before looping over to <minVal>.
		int key = (int)*argv[2] - 48; //Key used for encryption.
		int givenVal = (int)*argv[1] - 48; //Given value.
		int minVal = 0; //I don't see a point to change this.

		//Debugging section.
		if (*argv[4] == 'd')
		{
			cout << "Given max value is: " << *argv[3] << "\n"; 
			cout << "Given key is: " << *argv[2] << "\n";
			cout << "Given value is: " << *argv[1] << "\n";
			cout << "Numbers after typecasting: " << maxVal << " " << key << " " << givenVal << "\n"; 
		}

		for (int i = 1; i<key; i++)
		{
			givenVal = givenVal + 1;
			if (givenVal > maxVal)
			{
				givenVal = minVal;
			}
		}

		cout << "Result: " << givenVal << "\n";
		return givenVal;
	}
	else
	{
		printf("Not enough arguments given!\n");
		cout << "Given arguments: " << argc;
		return 0;
	}
}

//Made by: Unibit
//Discord: Uni#3819