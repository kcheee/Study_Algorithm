#include <string>
#include <vector>
#include <iostream>

using namespace std;

// 나누는 수
int a=1;
int factorial(int n)
{    
    cout<<n<<" ";
    if(n<=a) return a;
    a++;
    return factorial(n/a);    
}

int solution(int n) {
    int answer = 0;
    
    answer = factorial(n);
    return answer;
}