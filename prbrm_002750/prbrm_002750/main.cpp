#include <iostream>
#include <vector>
void quickSort(std::vector<int> &items, int firstIdx, int endIdx);
int getMedianIdx(std::vector<int> &items, int firstIdx, int endIdx);
void swap(std::vector<int> &items, int a, int b);
int main(int argc, char* argv[])
{
	std::vector<int> items;
	int N, inputNum;

	std::vector<int> testVector;
	std::cin >> N;
	for (int i=0; i < N; i++)
	{
		std::cin >> inputNum;
		items.push_back(inputNum);
	}
	quickSort(items, 0, items.size() - 1);
	for (int i=0; i < N; i++)
		std::cout << items[i] << std::endl;

	return 0;
}
void quickSort(std::vector<int> &items,int firstIdx,int endIdx) 
{
	if (endIdx - firstIdx < 1)
		return;

	int pivot = getMedianIdx(items, firstIdx, endIdx);
	swap(items, firstIdx, pivot);
	pivot = firstIdx;
	int left, right;	
	left = firstIdx ;
	right = endIdx;
	while (left < right)
	{
		while (items[right] > items[pivot])
			right--;
		while (items[left] < items[pivot] && left < right)
			left++;
		swap(items, left, right);
	}
	swap(items, left, pivot);
	quickSort(items, firstIdx , left-1);
	quickSort(items, left+1, endIdx);

} 
//맨앞 중앙 맨끝 중 중간값 인덱스 찾기
int getMedianIdx(std::vector<int> &items, int firstIdx, int endIdx)
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
void swap(std::vector<int> &items, int a, int b)
{
	int temp;
	temp = items[a];
	items[a] = items[b];
	items[b] = temp;
}