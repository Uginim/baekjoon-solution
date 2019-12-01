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
	stack<int> numStack;//10���� ��ȣ ��Ÿ����.(10�� ���ø� ����)
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

//idx : ��ȣ�� �ε���
// max : ��ȣ�� �ִ� (N-1)�� �ִ�
void printZeroMathExpression(stack<int> numStack,char expression[],int idx,int max)
{
	if (idx == max)
	{
		int topNum,preNum,sum;
		preNum = numStack.top();
		numStack.pop();
		sum = 0;
		//����ϰ� ���� ���
		while (!numStack.empty())//���ڻ��̿��� �ݵ�� ��ȣ�� ������..
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
			//���
			for (int i = 0; i<max;i++)
			{
				printf("%d%c", i + 1, expression[i]);
			}
			printf("%d\n",max+1);
		}
		return;

	}
	
	//' ' (����)

	int topNum = numStack.top();
	numStack.pop();//���� ó�� ����
	numStack.push(topNum * 10 + idx + 2);
	expression[idx] = ' ';
	printZeroMathExpression(numStack, expression, idx + 1, max);


	// +
	numStack.pop();//����
	numStack.push(topNum);
	numStack.push(+10);
	numStack.push(idx + 2);
	expression[idx] = '+';
	printZeroMathExpression(numStack, expression, idx + 1, max);

	// -	
	numStack.pop();//����
	numStack.pop();//��ȣ
	numStack.push(-10);
	numStack.push(idx + 2);
	expression[idx] = '-';
	printZeroMathExpression(numStack, expression, idx + 1, max);
	


}
