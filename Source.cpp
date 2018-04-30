
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

template<class T>
bool checkInput(string &userinput, T &validated) {
	stringstream inputstream(userinput);
	if (inputstream >> validated)//if value is inserted into T validated w/o error
		return true;
	else
	{
		cout << "Enter valid value" << endl;//ask for another input
		getline(cin, userinput);
		return checkInput<T>(userinput,validated);//call recursive fx with new input;
		/*
		if nth recursive call doesn't return true
		it will continue to call n+1th recursive fx until it does
		after which first checkInput fx will eventually return true;
		*/
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
	checkInput<int>(testvalue, decimal);
	cout << decimal << " in binary is : " << dec2bin(decimal) << endl;

	//dynamic test bin2dec
	cout << "Enter custom binary to be converted" << endl;
	getline(cin, binary);
	cout << binary << " in decimal is : " << bin2dec(binary) << endl;

	system("pause");
	return 0;
}
