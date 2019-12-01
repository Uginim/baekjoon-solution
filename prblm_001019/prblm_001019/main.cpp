#include <iostream>
#include <string>
#include <string.h> //memset����� ����
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
//	char tempBuf[12];//test��
//	for(int num=1;num<50000;num++)//for test
//	{									//for test
//		sprintf(tempBuf, "%d",num);//for test
//		N = tempBuf;//for test
	map<string, SumsOfAllDigit> memoMap;
	SumsOfAllDigit result = sumAlldigit(N, memoMap);

	//result.m_sumsOfDigit[0] -= 1;//������ �� ���ϰ� 0 �Ѱ��� ������..(1�������������� ������ 0���� ����)
	//�׸��� ���ڸ����� ä������ �ʾ����� 0 ���� ���ؾ���..
	//"������ 0����" = "��ü�ڸ����� 0���� ä���� N��ŭ �ݺ�" -  "�Ѽ���";
	int numZeroIfAllIsZero = ((N.length())*(atoi(N.c_str())+1));
	int headZeroWhileIncreasing = 0;//�պκ�
	string tempStr;

	

	//0���� ���� �� : "�ڸ���" * "limt����" - "0~9�� sum"
	//0�� ���� ���ϱ�
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
	//headZeroWhileIncreasing - N.length();//0��°������
	
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
	//Memoization Ȱ��
	map<string, SumsOfAllDigit>::iterator iter =memoMap.find(strLimitNum);
	if (iter != memoMap.end())
	{		
		return iter->second;
	}
	SumsOfAllDigit result;
	//���ڸ����� ���
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
	//---------------������� ����
	char tempBuf[11];

	//"ù�ڸ������ְ� ������ 0�� �հ�" + "�״��� �ڸ��� ���� ���� ������ �հ�"
	//�״��� �ڸ��� �հ豸�ϱ�
	string subDigits= strLimitNum.substr(1, strLimitNum.length() - 1);
	int subDigitsNum =atoi(subDigits.c_str());//�Ǿ��ڸ��� ������ ����
	int firstDigitNum = strLimitNum.at(0) - '0';//�Ǿ��ڸ� ����
	if (0 == subDigitsNum)//�� ���ڸ� ���� �� 0�� ���
	{
		string digitsOfNines;//�� �ڸ����� ���� 9�� �̷��� ���� �����
		for (int i = 0; i < subDigits.size(); i++)
			digitsOfNines.push_back('9');
		SumsOfAllDigit sumsOfNumberWithStartingOne;//�� �ڸ��� ���� 9�� �̷��� ������ �հ�
		int numberWithStartingOne = atoi(digitsOfNines.c_str()) + 1;
		sumsOfNumberWithStartingOne = sumAlldigit(digitsOfNines, memoMap);//9...�� �� ���ϱ�
		//sumsOfNumberWithStartingOne.m_sumsOfDigit[0] += subDigits.length();//0���� ���ϱ�		
		
		//�Ǿ��ڸ� ���� �� ���ϱ�
		//for (int i = 1; i < firstDigitNum; i++)//1������ ������ �Ǿ��ڸ��� 0�� ������ �ʾƼ�
		for (int i = 0; i < firstDigitNum; i++)//
		{
			result.m_sumsOfDigit[i] += numberWithStartingOne;//
		}
		result.m_sumsOfDigit[firstDigitNum] += 1;
		result = result + (sumsOfNumberWithStartingOne * firstDigitNum) ;//�Ǿ��ڸ����� �ٲ�鼭 �ݺ��Ǳ� ����
		result.m_sumsOfDigit[0] += subDigits.length();//0���� ���ϱ�		
	}
	else
	{
		string digitsWithAllZeroExceptFirst;//�Ǿ��ڸ� ���� 0�� �̷��� ���� �����
		digitsWithAllZeroExceptFirst.push_back(strLimitNum.at(0));
		for (int i = 0; i < subDigits.size(); i++)
			digitsWithAllZeroExceptFirst.push_back('0');
		//subDigits�� ���ڸ��� 0�� �����
		sprintf(tempBuf, "%d", atoi(subDigits.c_str()));
		//SumsOfAllDigit subDigitsSum = sumAlldigit(subDigits, memoMap);
		SumsOfAllDigit subDigitsSum = sumAlldigit(string(tempBuf), memoMap);
		result = sumAlldigit(digitsWithAllZeroExceptFirst, memoMap) + subDigitsSum;

		sprintf(tempBuf, "%d", subDigitsNum);
		
		result.m_sumsOfDigit[0] += ((subDigitsNum )* ((int)subDigits.length() - (int)string(tempBuf).length()))- (int)string(tempBuf).length();//-1�� 0�� �ߺ��Ǳ� ����
		
		result.m_sumsOfDigit[firstDigitNum] += subDigitsNum;//0�϶��� �������� �´�.������ ����
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
	//�ʱ�ȭ
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
