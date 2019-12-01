#include<iostream>
#include<stack>
#include<string>
#include<map>

#define LEFT_BRACKET 'l'
#define NUMBER 'n'
std::map<char,int> leftBracketMap;
std::map<char,int> rightBracketMap;
void initialize();//초기화
bool matchDir(char c, std::map<char, int> bracketMap);
int getValueOfBracket(char c, std::map<char, int> bracketMap);//괄호의 값
int main(int argc, char * argv[]) {

	using namespace std;
	string inputLine;
	
	stack<pair<char,int>>bracketStack;//pair<type,int>
	pair<char, int> last;
	initialize();
	cin >> inputLine;
	int result = 0;


	for(int i=0;i<inputLine.size();i++)
	{ 
		char cBracket = inputLine.at(i);
		//왼쪽 괄호인 경우 스택에 삽입
		if (matchDir(cBracket, leftBracketMap))
		{
			bracketStack.push(pair<char,int>(LEFT_BRACKET,getValueOfBracket(cBracket,leftBracketMap)));//bracket에 맞는 값을 삽입
		}
		else//오른쪽 괄호
		{
			//불일치 케이스			
			//1.스택에 왼쪽괄호가 없는 경우 : 올바르지 않음 
			if (bracketStack.empty())
			{
				goto incorrect;
			}

			
			int rightBraVal = getValueOfBracket(cBracket, rightBracketMap);
			pair<char,int> top = bracketStack.top();
			bracketStack.pop();
			int tempVal=0;
		
			while (top.first != LEFT_BRACKET)//스택의 맨 위가 왼쪽 괄호가 아닐 경우 각 값을 더한다.
			{
				tempVal += top.second;				
				
				if (bracketStack.empty())//비어있으면//1.스택에 왼쪽괄호가 없는 경우 : 올바르지 않음 
				{
					goto incorrect;
				}
				top = bracketStack.top();//새거
				bracketStack.pop();
			} 
			
			//2.오른쪽 괄호와 짝이 맞지 않는 경우 
			if (top.second != rightBraVal) 			
				goto incorrect;			
			else
			{
				
				bracketStack.push(
					pair<char,int>
					(
						NUMBER, //숫자
						(tempVal == 0) ? rightBraVal : rightBraVal * tempVal//괄호열이 값을 포함할 경우와 아닌경우
					)
				);
			}

		}
	}
	
	//왼쪽 괄호가 남은경우...
	//if (bracketStack.size() == 1 && last.first == NUMBER)
	while (!bracketStack.empty())
	{
		
		last = bracketStack.top();
		bracketStack.pop();
		if (last.first == LEFT_BRACKET)
		{
			result = 0;
			goto incorrect;
		}
		result += last.second;

	}

	incorrect:
	cout << result << endl;


	return 0;
}

//해당 방향의 괄호인지
bool matchDir(char c, std::map<char, int> bracketMap) {
	std::map<char, int>::iterator iter;
	iter = bracketMap.find(c);
	if (iter != bracketMap.end())
		return true;
	return false;
}
//괄호의 값
int getValueOfBracket(char c, std::map<char, int> bracketMap) {
	std::map<char, int>::iterator iter;
	iter = bracketMap.find(c);
	if (iter != bracketMap.end())
	{
		return iter->second;
	}		
	return 0;
}


//초기화
void initialize()
{
	leftBracketMap.insert(std::pair<char, int>('[',3));
	leftBracketMap.insert(std::pair<char, int>('(', 2));
	rightBracketMap.insert(std::pair<char, int>(']', 3));
	rightBracketMap.insert(std::pair<char, int>(')', 2));	
}