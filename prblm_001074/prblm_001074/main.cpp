#include <iostream>
#include <cmath>

using namespace std;

int searchQuadrantNum(int x, int y, int center);
int orderOfVisit(int x, int y, int N);

int main(int argc, char * argv[])
{
	int N, r, c,result;
	cin >> N >> r >> c;
	result = orderOfVisit(c, r, (int)pow(2,N)/2);
	cout << result;
	return 0;
}



int orderOfVisit(int x, int y, int N)
{
	int result = 0;
	int nextX, nextY;

	nextX = x % N;
	nextY = y % N;

	result = searchQuadrantNum(x, y, N)*N*N;
	if(N>1)
		result += orderOfVisit(nextX, nextY, N / 2);
	return result;
}


/*
return :
0 1
2 3
위 넘버로 구성
그래야 계산이 편함
*/
//사분면 위치 찾기
int searchQuadrantNum(int x, int y, int center)
{
	int result = 0;
	result |= center <= x;
	result |= (center <= y) ? 0x2 : 0;
	return result;
}