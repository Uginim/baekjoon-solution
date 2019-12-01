#include <iostream>
//N
using namespace std;
#define MAX_SIZE 20
int main(int argc, char * argv)
{
	int N,S,value;//N:숫자 개수, S:합
	int nums[MAX_SIZE];

	unsigned int powSet, universalSet;
	powSet = 0x0;
	//for (int i = 0; i < MAX_SIZE; i++)
		//powSet[i] = 0;
	cin >> N >> S;//입력

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &value);
		nums[i] = value;
	}
	universalSet =0x1;
	universalSet <<= N;
	int sum,agreeCnt;//sum : 합계 ,agreeCnt 일치하는 것 개수 
	unsigned int setFlag;//부분집합을 더하기위한 flag
	agreeCnt = 0;//카운트 초기화
	//부분집합 case를 순회하는 for문
	for (unsigned int setIdx = 0x1; setIdx < universalSet; setIdx++)
	{
		sum = 0;
		//부분집합의 합 구하기.
		for (int i = 0; i < N; i++)
		{
			setFlag = 0x1;
			setFlag <<= i;
			if (setFlag & setIdx)
				sum += nums[N - (1+i )];
		}
		if (sum == S)
			agreeCnt++;
	}

	cout << agreeCnt << endl;
	
	

	return 0;
}