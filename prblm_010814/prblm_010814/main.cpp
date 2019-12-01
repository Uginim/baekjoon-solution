#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef struct {
	int age;
	int regOrder;
	string name;
}Member;
bool compare(Member a, Member b);
int main(int argc, char* argv[])
{
	int N;
	vector<Member> vMems;
	char buf[100];
	cin >> N;
	Member member;

	for (int i = 0; i < N; i++)
	{
		
		scanf("%d %s", &member.age,buf);
		member.name = buf;
		member.regOrder = i;
		vMems.push_back(member);		
	}


	sort(vMems.begin(), vMems.end(),compare);
	
	for (int i = 0; i < N; i++)
		printf("%d %s\n", vMems[i].age, vMems[i].name.c_str());
	return 0;
}
bool compare(Member a,Member b) 
{
	if (a.age < b.age)
		return true;
	else if (a.age > b.age)
		return false;
	else
		return a.regOrder < b.regOrder;
}