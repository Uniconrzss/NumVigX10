#include <iostream>
#include <string>
#include <cstring>
#include <Windows.h> //I only wish that there was a universtal way of running stuff...

using namespace std;

//Function that i totally didn't steal off the internet.
std::string GetCurrentDirectory()
{
	char buffer[MAX_PATH];
	GetModuleFileNameA(NULL, buffer, MAX_PATH);
	std::string::size_type pos = std::string(buffer).find_last_of("\\/");
	return std::string(buffer).substr(0, pos);
}

int main(int argc, char** argv)
{
	int num;
	int key;
	string userIn;
	string NVX10dir = GetCurrentDirectory() + "\\NumVigX10_win.exe"; //Gets the directory of NumVigX10_win.exe
	string number;
	string numberAll = "";
	string result = ""; //return value in string form.
	int res; //return value in int form.

	//Check if there are any arguments.
	if (argc == 1)
	{
		try
		{
			cout << "Input numbers: ";
			cin >> userIn;
			cout << "Input key: ";
			cin >> key;

			//Loop through all of the induvidual numbers the user has provided.
			for (int i = 0; i < userIn.length(); i++)
			{
				//I hate doing this why cant i just do this:
				//num = atoi(userIn[i].c_str());
				//but NO! Because we are C++! And we hate you!
				number = userIn[i];
				num = atoi(number.c_str()); //Converts the induvidual number from string to int.

				//Prepares the execution command.
				NVX10dir = GetCurrentDirectory() + "\\NumVigX10_win.exe" + " " + std::to_string(num) + " " + std::to_string(key) + " 9" + " r"; 
				//res gets the return code from NumVigX10_win.exe
				res = system(NVX10dir.c_str());
				result += std::to_string(res); //Converts return code to string form.
			}
		}
		catch(string userIn)
		{
			//What happens when you dont input numbers as the arguments.
			cout << "\nError: User input cannot be converted to INT!";
		}
	}
	else
	{
		//Converts the arguments from command line characters to int.
		key = (int)*argv[1] - 48;
		int maxval = (int)*argv[2] - 48;
		
		//Loops through everything after the 1st two arguments and adds them to a list of numbers.
		for (int i = 3; i < argc; i++)
		{
			numberAll = numberAll + argv[i];
		}

		//Loops through each number induvidually.
		for (int i = 0; i < numberAll.length(); i++)
		{
			//Again, i hate doing this but C++.
			number = numberAll[i];
			num = atoi(number.c_str());

			NVX10dir = GetCurrentDirectory() + "\\NumVigX10_win.exe" + " " + std::to_string(num) + " " + std::to_string(key) + " " + std::to_string(maxval) + " r";
			res = system(NVX10dir.c_str());
			result += std::to_string(res);
		}
		//Prints out the result incase you ran the app through a command line anyways.
		cout << result;
	}
	return atoi(result.c_str());
}

//Made by: Unibit
//Discord Uni#3819