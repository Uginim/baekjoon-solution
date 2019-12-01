#include <iostream>
#include <vector>
#include <string>
#define MAX_LENGTH 64


using namespace std;
char image[MAX_LENGTH][MAX_LENGTH];
string compressBitMap(int startX, int startY, int length);
int main(int argc, char * argv[])
{
	int N;
	char c;
	cin >> N;
	for (int i = 0; i < N; i++)
	{ 
		scanf("%s", image[i]);
		for (int j = 0; j < N; j++)
		{
			//scanf("%c", &c);
			//image[i][j] = c;
		}
	}
	'0'^'1';
	printf("%s",compressBitMap(0, 0,N).c_str());
	return 0;
}
//압축
//return값 ' '빈칸이면 4개 다름
string compressBitMap(int startX,int startY, int length)
{
	string result;
	if (1 == length)
	{
		result.push_back(image[startY][startX]);
		return result;
	}
	//
	/*
	z형태로
	0 1
	2 3
	*/
	vector<string> zArr  ;
//	zArr[0] = compressBitMap(startX, startY, length / 2);
	zArr.push_back(compressBitMap(startX, startY, length / 2));
	zArr.push_back(compressBitMap(startX + length / 2, startY, length / 2));
	zArr.push_back(compressBitMap(startX, startY + length / 2, length / 2));
	zArr.push_back(compressBitMap(startX + length / 2, startY + length / 2, length / 2));

	if (4 == zArr[0].size() + zArr[1].size() + zArr[2].size() + zArr[3].size()
		&& zArr[0][0] == zArr[1][0] 
		&& zArr[1][0] == zArr[2][0] 
		&& zArr[2][0] == zArr[3][0] )//1글자로 모두 같은경우
	{
		return zArr[0];
	}

	//printf("(");
	result.push_back('(');
	for (int i = 0; i < 4; i++)
		result.append(zArr[i]);
	//printf(")");
	result.push_back(')');
	return result;//4개가 다 다르므로 
}