#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
using std::vector;

int solution_1(int N, vector<int> list); // 모험가 길드
int solution_2(string N); // 곱하기 혹은 더하기
int solution_3(string N); // 문자열 뒤집기
int solution_4(int N, vector<int> list); // 만들 수 없는 금액
int solution_5(int N, int M, vector<int> list); // 볼링공 고르기
int solution_6(vector<int> food_times, long long k);

int main()
{
    std::cout << "Hello World!\n";
    cout << solution_1(5, { 2,3,1,2,2 }) << endl;
    cout << solution_2("02984") << endl;
    cout << solution_3("0001110011010110") << endl;
    cout << solution_4(5, {3,2,1,1,9}) << endl;
    cout << solution_5(8, 5, {1,5,4,3,2,4,5,2}) << endl;
    cout << solution_6({3,1,2},5) << endl;
}

int solution_1(int N, vector<int> list)
{
    int result = 0;
    int count = 1;
    sort(list.begin(), list.end());

    for (int i = 1; i < list.size(); i++)
    {
        // 현재 그룹의 가장 공포도가 높은 숫자가 구성원의 숫자보다 크다면 구성원을 더 받아야 한다.
        if (list[i-1] > count)
        {
            count++;
        }
        // 현재 그룹의 가장 공포도가 높은 숫자가 구성원의 숫자와 같거나 작다면 그룹을 끊어낸다.
        else
        {
            result++;
            count = 0;
        }
    }

    return result;
}

int solution_2(string str)
{
    vector<int> list;

    for (int i = 0; i < str.length(); i++)
    {
        list.push_back(static_cast<int>(str[i] - '0'));
    }

    int result = list[0];

    for (int i = 1; i < list.size(); i++)
    {
        int temp = list[i]; 

        // 계산하는 두 자연수 중에 0 혹은 1이 존재하는 경우 더하기 연산을 한다.
        if (temp == 0 || temp == 1 || list[i-1] == 0 || list[i-1] == 1)
            result += temp;
        else
            result *= temp;
    }

    return result;

}

int solution_3(string str)
{

    //  0->1로 변환하는 숫자와 1->0 으로변환되는 값을 비교하여 최선의 방법을 택한다.

    int s_0 = 0;
    int s_1 = 0;

    char front = str[0];

    if (str[0] == '1') s_1 += 1;
    else s_0 += 1;

    for (int i = 1; i < str.length(); i++)
    {
        if (str[i] == front)
        {
            continue;
        }
        else
        {
            if (str[i] == '1')
            {
                front = '1';
                s_1++;
            }
            else
            {
                front = '0';
                s_0++;
            }
        }
    }

    return s_0 > s_1 ? s_1 : s_0;

}

int solution_4(int N, vector<int> list)
{
    sort(list.begin(), list.end());

    int result = 1;

    for (const auto& index : list)
    {
        if (result >= index)
            result += index;
        else
            return result;
    }
}

int solution_5(int N, int M, vector<int> list)
{
    int result = 0;

    // A가 가질 수 있는 공의 개수는 N
    for (int i = 0; i< list.size(); i++)
    {
        for (int j = 0; j < list.size(); j++)
        {
            if (i == j || list[i] == list[j]) continue;
            
            result++;
        }
    }
    return result/2;
}




int solution_6(vector<int> food_times, long long k) {

    int result = 0;

    

    return result + 1;
}