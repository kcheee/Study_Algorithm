#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<long long> solution(int x, int n) {
    vector<long long> answer;
    int result=0;
    for(int i=0;i<n;i++)
    {
        result += x;
        answer.push_back(result);
    }
    
    
    
    return answer;
}