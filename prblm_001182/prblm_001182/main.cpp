#include <iostream>
//N
using namespace std;
#define MAX_SIZE 20
int main(int argc, char * argv)
{
	int N,S,value;//N:���� ����, S:��
	int nums[MAX_SIZE];

	unsigned int powSet, universalSet;
	powSet = 0x0;
	//for (int i = 0; i < MAX_SIZE; i++)
		//powSet[i] = 0;
	cin >> N >> S;//�Է�

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &value);
		nums[i] = value;
	}
	universalSet =0x1;
	universalSet <<= N;
	int sum,agreeCnt;//sum : �հ� ,agreeCnt ��ġ�ϴ� �� ���� 
	unsigned int setFlag;//�κ������� ���ϱ����� flag
	agreeCnt = 0;//ī��Ʈ �ʱ�ȭ
	//�κ����� case�� ��ȸ�ϴ� for��
	for (unsigned int setIdx = 0x1; setIdx < universalSet; setIdx++)
	{
		sum = 0;
		//�κ������� �� ���ϱ�.
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