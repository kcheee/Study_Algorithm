#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

long long solution(int a, int b) {
    long long answer = 0;
    // 숫자가 같을경우.
    if(a==b) return a;
    
    for(int i=min(a,b);i<=max(a,b);i++) answer+=i;
    return answer;
}