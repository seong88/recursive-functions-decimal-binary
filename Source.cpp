
#include <iostream>
#include <string>
#include <sstream>//stringstream()
using namespace std;


string dec2bin(int a)
{
	if (a == 0) {
		return "0";
	}
	else if (a == 1)
	{
		//if last value, return 1
		return "1";
	}
	else
	{
		string remnant = to_string(a % 2);
		return dec2bin(a / 2) + remnant;
	}

}

int bin2dec(string input) {
	if (input.length() == 0)
		return 0;
	if (input.length() == 1)
	{
		//if this is last value of string, return 1 or 0
		return (input == "1") ? 1 : 0;

	}
	else
	{
		//check current position to determine factor to multiply by
		// ie in length 4 = [8][4][2][1]
		int power = pow(2, input.length() - 1);
		//check if current substr value is 1 or 0
		int answer = (input.substr(0, 1) == "1") ? 1 : 0;
		//return decimal translation of current pos + recursive value
		return (answer*power) + bin2dec(input.substr(1, input.length() - 1));
	}
}
template <class T>
bool checkInput(string userinput, T &validated) {
	if (userinput.length() == 0)
		return false; //nothing on userinput
	else if (userinput.length() ==1)//if on userinput[last]
	{
		stringstream inputstream(userinput.substr(0, 1));
		if (inputstream >> validated)//if last value is validated
		{
			return 1;
			/*
			since all previous recursion(if any) must be true  to check for userinput[last]
			returning true will cascade return true until origin function
			*/
		}
		else
			return 0;
			/*
			likewise if userinput[last] validates to be false
			it will cascade to return false;
			*/
	}
	else//if on userinput[x]
	{
		stringstream inputstream(userinput.substr(0, 1));
		if (inputstream >> validated)
			return checkInput(userinput.substr(1, userinput.length() - 1), validated);//RECURSION!!!
		else
			return false;
			/*
			if, at any time during the recursion, validation return false, it will cascade return false
			and no further recursion is made
			*/
	}
}

bool binarycheck(string userinput) {
	for (size_t i = 0; i < userinput.length();)
	{
		if ((userinput[i] == '0') || (userinput[i] == '1'))
			i++;
		else return false;
	}
}

int main()
{
	string binary;
	int decimal;
	string testvalue; //get userinput


	//fixed test dec2bin
	cout << "TEST dec2bin(101)" << endl;
	cout << dec2bin(101) << endl;
	//fixed test bin2dec
	cout << "TEST bin2dec(11111)" << endl;
	cout << bin2dec("11111") << endl;

	//dynamic test dec2bin
	cout << "Enter custom decimal to be converted" << endl;
	getline(cin, testvalue);
	while (!checkInput<int>(testvalue, decimal))//validate input
	{
		cout << "Wrong input" << endl;
		getline(cin, testvalue);
	}
	stringstream ss(testvalue); ss >> decimal; //save user input to decimal
	cout << decimal << " in binary is : " << dec2bin(decimal) << endl;

	//dynamic test bin2dec
	cout << "Enter custom binary to be converted" << endl;
	getline(cin, binary);
	while(!binarycheck(binary))
	{
		cout << "Wrong input" << endl;
		getline(cin, binary);
	}
	cout << binary << " in decimal is : " << bin2dec(binary) << endl;


	system("pause");
	return 0;
}
