#include <iostream>
#include <vector>
#include <stack>
#include <deque>
#include <algorithm>
#include <utility>
int main(int argc, char* argv[])
{
	//입력
	int nItems, item;
	char direction;
	int setLength;
	int nOrderDrt;
	std::vector<int> vItems,vResult;
	std::deque<std::pair<int, char>> orderDrtDeque;
	std::cin >> nItems;
	for (int i = 0; i < nItems; i++)
	{
		scanf("%d", &item);
		vItems.push_back(item);
	}
	std::cin >> setLength;
	nOrderDrt = setLength * 2;
	for (int i = 0; i < nOrderDrt; i++)
	{
		scanf("%d", &item);
		direction = (i % 2 == 0) ? 'a' : 'd';
		while (!orderDrtDeque.empty() && orderDrtDeque.back().first <= item)
			orderDrtDeque.pop_back();
		orderDrtDeque.push_back(std::pair<int, char>(item, direction));
	}	
	
	int left, right,preIdx,length,curIdx;
	char preDir,curDir;
	left = 0;
	right = orderDrtDeque.front().first - 1;
	preIdx = right;
	preDir = orderDrtDeque.front().second;
	orderDrtDeque.pop_front();
	for (int i = vItems.size() - 1; i > right; i--)
	{
		vResult.push_back(vItems[i]);
	}
	sort(vItems.begin(), vItems.end() - (vItems.size() - 1 - right));


	while (left <= right)
	{
		if (orderDrtDeque.empty())
		{
			if (preDir == 'a')//오름차순(거꾸로기 때문에 큰수부터 넣어야함...)
				while (left <= right)
					vResult.push_back(vItems[right--]);
			else
				while(left<= right)
					vResult.push_back(vItems[left++]);
			break;
		}
		//else
		curIdx = orderDrtDeque.front().first - 1;
		curDir = orderDrtDeque.front().second;
		orderDrtDeque.pop_front();
		length = preIdx - curIdx;
		if('a'==preDir)
			for(int i=0;i<length;i++)
				vResult.push_back(vItems[right--]);
		else 
			for(int i=0;i<length;i++)
				vResult.push_back(vItems[left++]);
		preDir = curDir; preIdx = curIdx;
	}
	//출력
	for (int i = vResult.size()-1; i>=0; i--)
	{
		printf("%d ", vResult[i]);
	}
	return 0;
}