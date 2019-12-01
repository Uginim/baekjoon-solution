#include <iostream>
#include <string>

std::string reverseString(std::string &str);
int main(int argc, char* argv[])
{
	using namespace std;
	string str1, str2, bigger;
	cin >> str1 >> str2;	
	str1 = reverseString(str1);
	str2 = reverseString(str2);
	bigger = stoi(str1) > stoi(str2) ? str1 : str2;
		
	
	cout << bigger << endl;

	return 0;
}

std::string reverseString(std::string &str)
{
	std::string result;
	for (int i = 0; i < str.size(); i++)
	{
		result.push_back ( str[str.size() - 1 - i] );
	}
	return result;
}