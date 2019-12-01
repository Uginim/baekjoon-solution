#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <stack>
#define MAX_SIMBOL 8

using namespace std;
void printZeroMathExpression(stack<int> numStack, char expression[], int idx, int max);
int main(int argc, char * argv[])
{

	int N,caseNum;
	char expression[MAX_SIMBOL];
	stack<int> numStack;//10으로 기호 나타내기.(10은 나올리 없음)
	cin >> caseNum;
	numStack.push(1);
	for (int iCase = 0; iCase < caseNum; iCase++)
	{
		cin >> N;
		memset(expression, 0, sizeof(char)*MAX_SIMBOL);				
		printZeroMathExpression(numStack, expression, 0, N - 1);
		printf("\n");
	}

	return 0;
}

//idx : 기호의 인덱스
// max : 기호의 최대 (N-1)이 최대
void printZeroMathExpression(stack<int> numStack,char expression[],int idx,int max)
{
	if (idx == max)
	{
		int topNum,preNum,sum;
		preNum = numStack.top();
		numStack.pop();
		sum = 0;
		//계산하고 수식 출력
		while (!numStack.empty())//숫자사이에는 반드시 기호가 있을것..
		{
			topNum = numStack.top();
			numStack.pop();
			if (topNum == -10)
				sum += preNum * -1;
			else if (topNum == 10)
				sum += preNum;
			else 
				preNum = topNum;
			
		}
		sum += preNum;
		if (sum == 0)
		{
			//출력
			for (int i = 0; i<max;i++)
			{
				printf("%d%c", i + 1, expression[i]);
			}
			printf("%d\n",max+1);
		}
		return;

	}
	
	//' ' (공백)

	int topNum = numStack.top();
	numStack.pop();//제일 처음 숫자
	numStack.push(topNum * 10 + idx + 2);
	expression[idx] = ' ';
	printZeroMathExpression(numStack, expression, idx + 1, max);


	// +
	numStack.pop();//숫자
	numStack.push(topNum);
	numStack.push(+10);
	numStack.push(idx + 2);
	expression[idx] = '+';
	printZeroMathExpression(numStack, expression, idx + 1, max);

	// -	
	numStack.pop();//숫자
	numStack.pop();//기호
	numStack.push(-10);
	numStack.push(idx + 2);
	expression[idx] = '-';
	printZeroMathExpression(numStack, expression, idx + 1, max);
	


}
