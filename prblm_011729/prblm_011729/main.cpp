#include<iostream>
#include<vector>
using namespace std;
void moveHanoiDisks(int src, int dst, int height);
int getTheOtherRod(int src, int dst);
vector<vector<int>> moveTrace;

int main(int argc, char * argv[])
{
	int N,moveN;
	cin >> N;
	moveHanoiDisks(1, 3, N);
	moveN = moveTrace.size();
	printf("%d\n", moveN);
	for(int i=0;i<moveN;i++)
		printf("%d %d\n", moveTrace[i][0], moveTrace[i][1]);//�� ������ ���� �ű��
	return 0;
}

void moveHanoiDisks(int src, int dst, int height) 
{
	int theOtherStickNum;
	vector<int> move;
	theOtherStickNum = getTheOtherRod(src, dst);
	if (1 != height)//�ǹ��� ���� ���� �������� �������� �ƴ� ��տ� �ű��
	{		
		moveHanoiDisks(src, theOtherStickNum,height-1);
	}
	//printf("%d %d\n", src, dst);//�� ������ ���� �ű��
	move.push_back(src);
	move.push_back(dst);
	moveTrace.push_back(move);
	if (1 != height)//�ǹ��� ���� �ű� �� ������ ��տ� �ű��
	{		
		moveHanoiDisks(theOtherStickNum, dst, height - 1);
	}
}

//������ ��� ��ȣ ���ϱ�
int getTheOtherRod(int src, int dst)
{
	return 6 - (src + dst);//1+2+3�� ���̹Ƿ�
}