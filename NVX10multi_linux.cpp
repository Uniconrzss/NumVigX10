#include <iostream>
#include <string>
#include <filesystem>
#include <unistd.h>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
using std::filesystem::current_path;

//Function that i totally didn't steal off the internet.
std::string GetCurrentDirectory()
{
	char tmp[256];
	getcwd(tmp, 256);
	return tmp;
}

//For converting the NumVigX10 return value to a normal number.
//Doing this because FUCKING LINUX AHRGIOAEUHGIOUAEUHR.
string paininator(int n)
{
	// ans string to store hexadecimal number
	string ans = "";

	while (n != 0) {
			int rem = 0;
			char ch;
			rem = n % 16;
			if (rem < 10) {
				ch = rem + 48;
			}
			else {
				ch = rem + 55;
			}
				ans += ch;
				n = n / 16;
		}
		int i = 0, j = ans.size() - 1;
		while(i <= j)
		{
			swap(ans[i], ans[j]);
			i++;
			j--;
		}
		return ans;
}

int main(int argc, char** argv)
{
	int num;
	int key;
	string userIn;
	string NVX10dir = GetCurrentDirectory() + "/" + "NumVigX10.exe";
	string number;
	string numberAll = "";
	string result = ""; //return value in string form.
	string hexval;
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
				NVX10dir = GetCurrentDirectory() + "/" + "NumVigX10.exe" + " " + std::to_string(num) + " " + std::to_string(key) + " 9" + " r"; 
				//res gets the return code from NumVigX10_win.exe
				res = system(NVX10dir.c_str());
				hexval = paininator(res);
				res = atoi(hexval.c_str()) / 100;
				result += std::to_string(res);
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

			NVX10dir = GetCurrentDirectory() + "/NumVigX10.exe" + " " + std::to_string(num) + " " + std::to_string(key) + " " + std::to_string(maxval) + " r";
			res = system(NVX10dir.c_str());
			hexval = paininator(res);
			res = atoi(hexval.c_str()) / 100;
			result += std::to_string(res);
		}
		//Prints out the result incase you ran the app through a command line anyways.
		cout << "Res: " <<result << "\n";
	}
	return atoi(result.c_str());
}

//Made by: Unibit
//Discord Uni#3819