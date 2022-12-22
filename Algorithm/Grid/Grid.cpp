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
    cout << solution_1(5, { 2,2,2,2,4 }) << endl;
    cout << solution_2("02984") << endl;
    cout << solution_3("0001110011010110") << endl;
    cout << solution_4(5, {3,2,1,1,9}) << endl;
    cout << solution_5(8, 5, {1,5,4,3,2,4,5,2}) << endl;
    cout << solution_6({3,1,2},5) << endl;
}

int solution_1(int N, vector<int> list)
{
    int result = 0;

    sort(list.begin(), list.end());

    for (int i = 0; i < list.size();)
    {
        // 남은 사람중 맨 뒤의 숫자가 남은 사람의 수보다 작거나 같다면 해당 수 만큼을 같은 그룹으로 묶는다.
        if (list[N - 1 - i] <= list.size() - i)
        {
            i += list[N - 1 - i];
            result++;
        }
        // 남은 사람의 수가 맨 뒤의 숫자보다 작다면 가장 최근에 묶은 그룹으로 해당 사람을 묶는다.
        else
        {
            i++;
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
        int plus = result + list[i];
        int Mulitple = result * list[i];
        result = (plus > Mulitple) ? plus : Mulitple;
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

    int sum = 0;
    for (const auto& time : food_times)
    {
        sum += time;
    }
    if (sum <= k) return -1;

    while (k > 0)
    {
        int sum = 0;
        for (const auto& time : food_times)
        {
            sum += time;
        }
        if (sum <= 0) return -1;

        if (food_times[result] > 0)
        {
            k--;
            food_times[result]-= 1;
        }

        result++;
        if (result >= food_times.size())
        {
            result = 0;
        }
    }

    return result + 1;
}