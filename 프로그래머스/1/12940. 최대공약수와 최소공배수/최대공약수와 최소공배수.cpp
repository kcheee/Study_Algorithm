#include <string>
#include <vector>
#include <iostream>

using namespace std;

// 유클리드 호제법
// 최대 공약수
int G_div(int a,int b)
{
    int n;
    while(b != 0)
    {
        n =a%b;
        a=b;
        b=n;
    }
        return a;
}

// 최소 공배수
int L_Mul(int a,int b)
{
    return (a*b) / G_div(a,b);
}

vector<int> solution(int n, int m) {
    vector<int> answer;

    answer.push_back(G_div(n,m));
    answer.push_back(L_Mul(n,m));
        
    return answer;
}