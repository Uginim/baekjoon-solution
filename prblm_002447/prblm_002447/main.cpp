#include <iostream>

#define MAX_LENGTH 6561 //3^8
char starMatrix[MAX_LENGTH][MAX_LENGTH];
char divisionSpace[3][3][2] = { {{0,0},{0,1},{0,2}}
							  , {{1,0},{1,1},{1,2}}
							  , {{2,0},{2,1},{2,2}} };


using namespace std;
void printStars(int n);
void putSpace(int startX, int startY, int unit);
void makeStarPattern(int startX, int startY, int endX, int endY);
int main(int argc,char*argv[])
{
	int N;
	cin >> N;
	//initialize
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			starMatrix[i][j] = '*';
		}
	}

	makeStarPattern(0, 0, N - 1, N - 1);




	printStars(N);
	return 0;
}
//패턴 만들기
void makeStarPattern(int startX, int startY, int endX,int endY)
{
	int unit;
	if (startX == endX)
		return;
	
	unit = (endX + 1 - startX) / 3;
	putSpace(startX + unit, startY + unit, unit);
	for (int unitRow = 0; unitRow< 3; unitRow++)
	{
		for (int unitCol = 0; unitCol < 3; unitCol++)
		{
			if (1 == unitRow && 1 == unitCol)
				continue;
			makeStarPattern(startX + unit * unitCol
				, startY + unit * unitRow
				, startX + unit * (unitCol + 1)-1
				, startY + unit * (unitRow + 1)-1);
		}
	}


}
//빈칸 넣기
void putSpace(int startX, int startY, int unit)
{
	for (int i = 0; i < unit; i++)
	{
		for (int j = 0; j < unit; j++)
		{
			starMatrix[startY+i][startX+j] = ' ';
		}
	}
}


//별 출력
void printStars(int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%c", starMatrix[i][j]);
		}
		printf("\n");
	}
}