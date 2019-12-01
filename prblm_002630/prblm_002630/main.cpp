#include <iostream>
#include <vector>
#include <utility>
#define MAX_SIZE 128
using namespace std;
//vector쓰고 안쓰고 차이크다...

//int countColorPaper(vector<vector<int>> map, int &blueCnt, int &whiteCnt, pair<int, int> start, int size);
//int countColorPaper(int map[][], int &blueCnt, int &whiteCnt, pair<int, int> start, int size);
int countColorPaper(int map[][MAX_SIZE], int &blueCnt, int &whiteCnt, int startX, int startY, int size);
int main(int argc,char * argv[])
{
	int N,value,blueCnt,whiteCnt;
	//vector<vector<int>> map;
	int map[MAX_SIZE][MAX_SIZE];
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		//map.push_back(vector<int>());
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &value);
			//map[i].push_back(value);
			map[i][j] = value;
		}
	}
	blueCnt= whiteCnt= 0;
	//value = countColorPaper(map, blueCnt, whiteCnt, pair<int, int>(0, 0), N);
	value = countColorPaper(map, blueCnt, whiteCnt, 0, 0, N);
	if (1==value)
	{
		blueCnt = 0;
	}
	else if (0 == value)
	{
		whiteCnt = 1;
	}
	cout << whiteCnt<<endl <<blueCnt <<endl;
	return 0;
}
//1 : all is blue
//0 : all is white
//-1: all is different
//int countColorPaper( vector<vector<int>> map,int &blueCnt,int &whiteCnt,pair<int,int> start, int size)
int countColorPaper(int map[][MAX_SIZE], int &blueCnt, int &whiteCnt, int startX,int startY, int size)
{
	int colors[4];
	int index[4][2] = { {0,0},{0,1},{1,0},{1,1} };
	int half = size/2;
	
	bool isAllsame=true;

	if (size == 1)
	{
		//return map[start.first][start.second];
		return map[startX][startY];
	}
	for (int i = 0; i < 4; i++)
	{
		colors[i] = countColorPaper(map, blueCnt, whiteCnt,
			//pair<int,int>(start.first+ half *index[i][0], start.second+ half * index[i][1])
			startX+ half * index[i][0],startY +half *index[i][1]
			, size/2);
	}
	//모두 같은값인지 판단
	for (int i = 0; i < 3; i++)
		if (colors[i] ^ colors[i + 1])
		{
			isAllsame = false;
			break;
		}
	if (!isAllsame)
	{
		for (int i = 0; i < 4; i++)
			if (1 == colors[i])
				blueCnt++;
			else if (0 == colors[i])
				whiteCnt++;
		return -1;
	}
	else
		return colors[0];
}