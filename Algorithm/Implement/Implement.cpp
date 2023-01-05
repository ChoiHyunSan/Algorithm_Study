#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void solution(int N)
{
    string str = to_string(N);

    int front =0 ;
    int back = 0;

    for (int i = 0; i < str.length()/2; i++)
    {
        front += str[i] - '0';
    }
    for (int i = str.length() / 2; i < str.length(); i++)
    {
        back += str[i] - '0';
    }

    if (front == back)
        cout << "LUCKY" << endl;
    else
        cout << "READY" << endl;
}

void solution1(string S)
{
    vector<char> str;
    int sum = 0;

    for (int i = 0; i < S.length(); i++)
    {
        if (S[i] > '9')
            str.push_back(S[i]);
        else
            sum += S[i] - '0';
    }
    sort(str.begin(), str.end());

    for (const auto& index : str)
    {
        cout << index;
    }
    cout << sum << endl;
}

int main()
{
    solution(123402);
    solution(7755);
    solution1("K1KA5CB7");
    solution1("AJKDLSI412K4JSJ9D");
}
