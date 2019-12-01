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
		printf("%d %d\n", moveTrace[i][0], moveTrace[i][1]);//맨 마지막 원판 옮기기
	return 0;
}

void moveHanoiDisks(int src, int dst, int height) 
{
	int theOtherStickNum;
	vector<int> move;
	theOtherStickNum = getTheOtherRod(src, dst);
	if (1 != height)//맨밑의 원판 빼고 나머지를 목적지가 아닌 기둥에 옮기기
	{		
		moveHanoiDisks(src, theOtherStickNum,height-1);
	}
	//printf("%d %d\n", src, dst);//맨 마지막 원판 옮기기
	move.push_back(src);
	move.push_back(dst);
	moveTrace.push_back(move);
	if (1 != height)//맨밑의 원판 옮긴 뒤 목적지 기둥에 옮기기
	{		
		moveHanoiDisks(theOtherStickNum, dst, height - 1);
	}
}

//나머지 기둥 번호 구하기
int getTheOtherRod(int src, int dst)
{
	return 6 - (src + dst);//1+2+3의 합이므로
}