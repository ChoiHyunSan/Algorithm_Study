#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
using std::vector;

int solution_0(int); // 예제 3-1 거스름돈
int solution_1(int, int, int, vector<int> list); // chap 2. 큰 수의 법칙
int solution_2(int, int, vector<vector<int>> list); // chap 2. 숫자 카드 게임
int solution_3(int, int); // chap 2. 1이 될 때까지

int main()
{
	cout << solution_0(1280) << endl;
	cout << solution_1(5, 8, 3, { 2,4,5,4,6 }) << endl;
	cout << solution_2(2, 4, { {7,3,1,8},{3,3,3,4} }) << endl;
	cout << solution_3(25, 5) << endl;
	return 0;
}

// 예제 3-1 거스름돈
int solution_0(int money)
{
	int count = 0;

	int coin[4] = { 500,100,50,10 };

	for (int i = 0; i < 4; i++)
	{
		while (coin[i] <= money)
		{
			money -= coin[i];
			count++;
		}
	}
	return count;
}

// chap 2. 큰 수의 법칙
int solution_1(int N, int M, int K, vector<int> list)
{
	int result = 0;

	sort(list.begin(), list.end());

	int first = list[N - 1];
	int second = list[N - 2];
	
	int count = K;

	for (int i = 0; i < M; i++)
	{
		if (count == 0)
		{
			result += second;
			count = K;
		}
		else
		{
			result += first;
			count--;
		}
	}
	return result;
}

// chap 2. 숫자 카드 게임
int solution_2(int N , int M, vector<vector<int>> lists)
{
	vector<int> minList;

	for (auto list : lists)
	{
		sort(list.begin(), list.end());
		minList.push_back(list[0]);
	}
	sort(minList.begin(), minList.end());

	return minList[N - 1];

	//int result(0);
	//for (int i = 0; i < N; i++)
	//{
	//	sort(lists.at(i).begin(), lists.at(i).end());
	//	if (lists.at(i).at(0) > result)
	//	{
	//		result = lists.at(i).at(0);
	//	}
	//}
	//return result;
}

// chap 2. 1이 될 때까지
int solution_3(int N, int K)
{
	int count = 0;
	
	while (N >= K)
	{
		if (N % K == 0)
		{
			N /= K;
		}
		else
		{
			N--;
		}
		count++;
	}
	return count + (N - 1);
}