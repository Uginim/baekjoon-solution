#include <iostream>
#include <string>
#include <vector>
int countSpace(char space, std::vector<char> &stack);
int main()
{
	using namespace std;
	string strNLine,strLine;
	vector<vector<char>> arr;
	


	//input
	cin >> strNLine;
	int N = stoi(strNLine);
	//vector 배열 할당
	for (int i = 0; i < N; i++) {
		vector<char> row(N);
		arr.push_back(row);
	}
	// 1 <= N  && N <= 100
	//입력받기
	for (int i = 0; i < N; i++)
	{
		cin >> strLine;
		for (int j = 0; j < N; j++)
		{
			arr[i][j] = strLine.at(j);			
		}
	}
	int cntVer=0,cntHor=0;
	vector<char> horizeStack;
	vector<char> verticalStack;
	cntVer = 0;
	for (int i = 0; i < N; i++)
	{
		horizeStack.clear(); verticalStack.clear();
		for (int j = 0; j < N; j++)
		{
			cntHor +=countSpace(arr[i][j], horizeStack);
			cntVer +=countSpace(arr[j][i], verticalStack);
		}
		//맨 마지막은 벽이라고 봐야함
		cntHor += countSpace('X', horizeStack);
		cntVer += countSpace('X', verticalStack);
	}
	cout << cntHor << ' ' << cntVer << endl;
	return 0;
}

int countSpace(char space, std::vector<char> &stack) 
{
	if ('.' == space)
	{
		stack.push_back(space);
		return 0;
	}
	else
	{
		int size = stack.size();
		stack.clear();
		if (size >= 2)
		{		
			
			return 1;
		}
		else {
			return 0;
		}
		
	}
}
