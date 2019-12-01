#include<iostream>
#include<stack>
#include<string>
#include<map>

#define LEFT_BRACKET 'l'
#define NUMBER 'n'
std::map<char,int> leftBracketMap;
std::map<char,int> rightBracketMap;
void initialize();//�ʱ�ȭ
bool matchDir(char c, std::map<char, int> bracketMap);
int getValueOfBracket(char c, std::map<char, int> bracketMap);//��ȣ�� ��
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
		//���� ��ȣ�� ��� ���ÿ� ����
		if (matchDir(cBracket, leftBracketMap))
		{
			bracketStack.push(pair<char,int>(LEFT_BRACKET,getValueOfBracket(cBracket,leftBracketMap)));//bracket�� �´� ���� ����
		}
		else//������ ��ȣ
		{
			//����ġ ���̽�			
			//1.���ÿ� ���ʰ�ȣ�� ���� ��� : �ùٸ��� ���� 
			if (bracketStack.empty())
			{
				goto incorrect;
			}

			
			int rightBraVal = getValueOfBracket(cBracket, rightBracketMap);
			pair<char,int> top = bracketStack.top();
			bracketStack.pop();
			int tempVal=0;
		
			while (top.first != LEFT_BRACKET)//������ �� ���� ���� ��ȣ�� �ƴ� ��� �� ���� ���Ѵ�.
			{
				tempVal += top.second;				
				
				if (bracketStack.empty())//���������//1.���ÿ� ���ʰ�ȣ�� ���� ��� : �ùٸ��� ���� 
				{
					goto incorrect;
				}
				top = bracketStack.top();//����
				bracketStack.pop();
			} 
			
			//2.������ ��ȣ�� ¦�� ���� �ʴ� ��� 
			if (top.second != rightBraVal) 			
				goto incorrect;			
			else
			{
				
				bracketStack.push(
					pair<char,int>
					(
						NUMBER, //����
						(tempVal == 0) ? rightBraVal : rightBraVal * tempVal//��ȣ���� ���� ������ ���� �ƴѰ��
					)
				);
			}

		}
	}
	
	//���� ��ȣ�� �������...
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

//�ش� ������ ��ȣ����
bool matchDir(char c, std::map<char, int> bracketMap) {
	std::map<char, int>::iterator iter;
	iter = bracketMap.find(c);
	if (iter != bracketMap.end())
		return true;
	return false;
}
//��ȣ�� ��
int getValueOfBracket(char c, std::map<char, int> bracketMap) {
	std::map<char, int>::iterator iter;
	iter = bracketMap.find(c);
	if (iter != bracketMap.end())
	{
		return iter->second;
	}		
	return 0;
}


//�ʱ�ȭ
void initialize()
{
	leftBracketMap.insert(std::pair<char, int>('[',3));
	leftBracketMap.insert(std::pair<char, int>('(', 2));
	rightBracketMap.insert(std::pair<char, int>(']', 3));
	rightBracketMap.insert(std::pair<char, int>(')', 2));	
}