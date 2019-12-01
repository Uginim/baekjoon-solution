#include<iostream>
#include<vector>
#include<algorithm>
/*
typedef struct {
	int x;
	int y;
} CoordItem;
*/
class CoordItem {
public :
	int x;
	int y;
	bool operator>(const CoordItem& coord) const;
	bool operator<(const CoordItem& coord) const;
};

void swapCoord(CoordItem items[], int a, int b);
void quickSort(CoordItem items[], int firstIdx, int endIdx);
int getMedianIdx(CoordItem items[], int firstIdx, int endIdx);
int main(int argc, char* argv[])
{
	int N;
	//std::vector<CoordItem> vCoords;
	CoordItem arrCoord[100000];
	std::cin >> N;
	for (int i = 0; i < N; i++)
	{		
		//CoordItem newCoord;
		//std::cin >> newCoord.x >> newCoord.y;
		//vCoords.push_back(newCoord);
		//std::cin >> arrCoord[i].x >> arrCoord[i].y;
		scanf("%d %d", &arrCoord[i].x ,&arrCoord[i].y);
	}
	//sort(vCoords.begin(), vCoords.end() , compareCoord);
	//quickSort(vCoords,0,N-1);
	quickSort(arrCoord, 0, N - 1);
	for (int i = 0; i < N; i++)
	{
		//std::cout << arrCoord[i].x << " " << arrCoord[i].y<<'\n';
		printf("%d %d\n",arrCoord[i].x ,arrCoord[i].y );
	}
	return 0;
}
void quickSort(CoordItem items[], int firstIdx, int endIdx)
//void quickSort(std::vector<CoordItem> &items, int firstIdx, int endIdx)
{
	if (endIdx - firstIdx < 1)
		return;

	int pivot = getMedianIdx(items, firstIdx, endIdx);
	swapCoord(items, firstIdx, pivot);
	pivot = firstIdx;
	int left, right;
	left = firstIdx;
	right = endIdx;
	while (left < right)
	{
		while (items[right] > items[pivot])
			right--;
		while (items[left] < items[pivot] && left < right)
			left++;
		swapCoord(items, left, right);
	}
	swapCoord(items, left, pivot);
	quickSort(items, firstIdx, left - 1);
	quickSort(items, left + 1, endIdx);

}

//맨앞 중앙 맨끝 중 중간값 인덱스 찾기
//int getMedianIdx(std::vector<CoordItem> &items, int firstIdx, int endIdx)
int getMedianIdx(CoordItem items[], int firstIdx, int endIdx)
{
	int midIdx = (firstIdx + endIdx) / 2;
	if (items[firstIdx] > items[midIdx])
	{
		if (items[midIdx] > items[endIdx])
			return midIdx;
		else if (items[firstIdx] > items[endIdx])
			return endIdx;
		else
			return firstIdx;

	}
	else
	{
		if (items[firstIdx] > items[endIdx])
			return firstIdx;
		if (items[midIdx] > items[endIdx])
			return endIdx;
		else
			return midIdx;
	}

}

//스왑
//void swapCoord(std::vector<CoordItem> &items, int a, int b)
void swapCoord(CoordItem items[], int a, int b)
{
	CoordItem temp;
	temp = items[a];
	items[a] = items[b];
	items[b] = temp;
}

bool CoordItem::operator>(const CoordItem & coord) const
{
	if (x > coord.x)
		return true;
	else if (x < coord.x)
		return false;
	else
		return y > coord.y;
}

bool CoordItem::operator<(const CoordItem & coord) const
{

	if (x < coord.x)
		return true;
	else if (x > coord.x)
		return false;
	else
		return y < coord.y;
}
