#include <iostream>
#include <string>
#include <string.h> //memset사용을 위함
#include <map>
#define MAX_DIGIT_NUM 10


using namespace std;

class SumsOfAllDigit
{
public:
	long long m_sumsOfDigit[MAX_DIGIT_NUM];
	SumsOfAllDigit();
	SumsOfAllDigit operator +(SumsOfAllDigit operand2);
	SumsOfAllDigit operator =(SumsOfAllDigit operand2);
	SumsOfAllDigit operator *(int digit);
	bool operator ==(SumsOfAllDigit operand2);
	long long getSumOfTotalDigit();
	void printAllSums();
};
SumsOfAllDigit sumByBruteforce(int limit);
SumsOfAllDigit sumAlldigit(string strLimitNum, map<string, SumsOfAllDigit> &memoMap);
int main(int argc, char * argv[])
{

	string N;
	cin >> N;
	int abnomalCaseCnt = 0;
//	char tempBuf[12];//test용
//	for(int num=1;num<50000;num++)//for test
//	{									//for test
//		sprintf(tempBuf, "%d",num);//for test
//		N = tempBuf;//for test
	map<string, SumsOfAllDigit> memoMap;
	SumsOfAllDigit result = sumAlldigit(N, memoMap);

	//result.m_sumsOfDigit[0] -= 1;//무조건 다 구하고 0 한개를 빼야함..(1페이지부터지만 로직은 0부터 셈함)
	//그리고 앞자리수가 채워지지 않았을때 0 갯수 구해야함..
	//"빼야할 0갯수" = "전체자릿수를 0으로 채워서 N만큼 반복" -  "총숫자";
	int numZeroIfAllIsZero = ((N.length())*(atoi(N.c_str())+1));
	int headZeroWhileIncreasing = 0;//앞부분
	string tempStr;

	

	//0개수 세는 법 : "자릿수" * "limt숫자" - "0~9의 sum"
	//0의 개수 구하기
	//if (N.length() > 1)
		tempStr.push_back(N.at(0) - 1);
	//else
		//tempStr.push_back(N.at(0));
	for (int i = 1; i < N.length(); i++)
	{
		tempStr.push_back(N.at(i));
	}
	for (int i = 0; i < N.length() - 1; i++)
	{
		int digitLength= N.length() - (1 + i);
		int num=9;
		for (int j = 0; j < digitLength - 1; j++)
		{
			num *= 10;
		}
		headZeroWhileIncreasing += num * digitLength;
	}
	headZeroWhileIncreasing += (atoi(tempStr.c_str())+1)*N.length();
	//headZeroWhileIncreasing - N.length();//0번째꺼빼기
	
	//SumsOfAllDigit resultByBruteForce =sumByBruteforce(atoi(N.c_str()));//for test
	result.m_sumsOfDigit[0] -= numZeroIfAllIsZero - headZeroWhileIncreasing;
	//if (!(resultByBruteForce == result)) {//for test
		result.printAllSums();
	//	abnomalCaseCnt++;//for test
	//}//for test
	//}//for test


	//result.printAllSums();
	return 0;
}
SumsOfAllDigit sumAlldigit(string strLimitNum,map<string,SumsOfAllDigit> &memoMap)
{	
	//Memoization 활용
	map<string, SumsOfAllDigit>::iterator iter =memoMap.find(strLimitNum);
	if (iter != memoMap.end())
	{		
		return iter->second;
	}
	SumsOfAllDigit result;
	//한자릿수일 경우
	if (strLimitNum.length() == 1)
	{
		//int num = strLimitNum.at(0)-'0';
		int num = atoi(strLimitNum.c_str());
		for (int i = 0; i <= num; i++)
		{
			result.m_sumsOfDigit[i] += 1;
		}
		return result;
	}
	//---------------여기까지 기저
	char tempBuf[11];

	//"첫자릿수만있고 나머지 0의 합계" + "그다음 자릿수 부터 만든 숫자의 합계"
	//그다음 자릿수 합계구하기
	string subDigits= strLimitNum.substr(1, strLimitNum.length() - 1);
	int subDigitsNum =atoi(subDigits.c_str());//맨앞자리를 제외한 숫자
	int firstDigitNum = strLimitNum.at(0) - '0';//맨앞자리 숫자
	if (0 == subDigitsNum)//맨 앞자리 빼고 다 0일 경우
	{
		string digitsOfNines;//한 자릿수가 작은 9로 이뤄진 숫자 만들기
		for (int i = 0; i < subDigits.size(); i++)
			digitsOfNines.push_back('9');
		SumsOfAllDigit sumsOfNumberWithStartingOne;//한 자릿수 작은 9로 이뤄진 숫자의 합계
		int numberWithStartingOne = atoi(digitsOfNines.c_str()) + 1;
		sumsOfNumberWithStartingOne = sumAlldigit(digitsOfNines, memoMap);//9...의 것 구하기
		//sumsOfNumberWithStartingOne.m_sumsOfDigit[0] += subDigits.length();//0개수 더하기		
		
		//맨앞자리 수를 다 더하기
		//for (int i = 1; i < firstDigitNum; i++)//1부터인 이유는 맨앞자리는 0을 셈하지 않아서
		for (int i = 0; i < firstDigitNum; i++)//
		{
			result.m_sumsOfDigit[i] += numberWithStartingOne;//
		}
		result.m_sumsOfDigit[firstDigitNum] += 1;
		result = result + (sumsOfNumberWithStartingOne * firstDigitNum) ;//맨앞자리수만 바뀌면서 반복되기 때문
		result.m_sumsOfDigit[0] += subDigits.length();//0개수 더하기		
	}
	else
	{
		string digitsWithAllZeroExceptFirst;//맨앞자리 제외 0로 이뤄진 숫자 만들기
		digitsWithAllZeroExceptFirst.push_back(strLimitNum.at(0));
		for (int i = 0; i < subDigits.size(); i++)
			digitsWithAllZeroExceptFirst.push_back('0');
		//subDigits의 앞자리가 0일 경우대비
		sprintf(tempBuf, "%d", atoi(subDigits.c_str()));
		//SumsOfAllDigit subDigitsSum = sumAlldigit(subDigits, memoMap);
		SumsOfAllDigit subDigitsSum = sumAlldigit(string(tempBuf), memoMap);
		result = sumAlldigit(digitsWithAllZeroExceptFirst, memoMap) + subDigitsSum;

		sprintf(tempBuf, "%d", subDigitsNum);
		
		result.m_sumsOfDigit[0] += ((subDigitsNum )* ((int)subDigits.length() - (int)string(tempBuf).length()))- (int)string(tempBuf).length();//-1은 0이 중복되기 때문
		
		result.m_sumsOfDigit[firstDigitNum] += subDigitsNum;//0일때는 더해져서 온다.셈하지 말것
	}

	
	
	//Memoization 
	memoMap.insert(pair<string, SumsOfAllDigit>(strLimitNum, result));
	return result;
}



SumsOfAllDigit sumByBruteforce(int limit )
{
	SumsOfAllDigit result;
	//char buf[11];
	int curVal;
	
	for (int i = 1; i <= limit; i++)
	{
		curVal = i;
		while (curVal > 0)
		{
			result.m_sumsOfDigit[curVal % 10]+=1;
			curVal /= 10;
		}
	}

	return result;
}
SumsOfAllDigit::SumsOfAllDigit()
{
	//초기화
	memset(m_sumsOfDigit, 0, sizeof(long long)*MAX_DIGIT_NUM);
}
SumsOfAllDigit SumsOfAllDigit::operator +(SumsOfAllDigit operand2)
{
	SumsOfAllDigit result;
	for (int i = 0; i < MAX_DIGIT_NUM; i++)
	{
		result.m_sumsOfDigit[i] = m_sumsOfDigit[i] + operand2.m_sumsOfDigit[i];
	}
	return result;
}
SumsOfAllDigit SumsOfAllDigit::operator =(SumsOfAllDigit operand2)
{
	SumsOfAllDigit result;
	for (int i = 0; i < MAX_DIGIT_NUM; i++)
	{
		m_sumsOfDigit[i] = operand2.m_sumsOfDigit[i];
	}
	return result;
}
SumsOfAllDigit SumsOfAllDigit::operator *(int digit)
{
	SumsOfAllDigit result;
	for (int i = 0; i < MAX_DIGIT_NUM; i++)
	{
		result.m_sumsOfDigit[i] = m_sumsOfDigit[i] * digit;
	}
	return result;
}

bool SumsOfAllDigit::operator==(SumsOfAllDigit operand2)
{
	bool bResult;
	bResult = true;
	for (int i = 0; i < MAX_DIGIT_NUM; i++)
	{
		if (m_sumsOfDigit[i] != operand2.m_sumsOfDigit[i])
			return false;
	}

	return bResult;
}

long long SumsOfAllDigit::getSumOfTotalDigit()
{
	long long resultSum = 0;
	for (int i = 0; i < MAX_DIGIT_NUM; i++)
	{
		resultSum += m_sumsOfDigit[i];
	}


	return resultSum;
}

void SumsOfAllDigit::printAllSums()
{
	for (int i = 0; i < MAX_DIGIT_NUM; i++)
	{
		cout << m_sumsOfDigit[i] << ' ';
	}
}
