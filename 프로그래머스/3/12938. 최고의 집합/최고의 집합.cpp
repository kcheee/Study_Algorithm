#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// 자연수 n개로 이루어진 집합 중 합이 s가 되는 집합에서 곱이 가장 큰 것
// 집합 사이의 값들이 가장 작은 것을 찾으면 됌
// 만약 n이 s보다 크다면 -1 리턴

// ex 8일때 3인경우 
// n,n-1 ...  n-a 만큼 나눠줌
// 이때 몫이 있을경우 1만큼 더해서 나눠줌
// 나눈 n값만큼 s에서 빼줌
// 8/3 = 3
// 5/2 = 3
// 2
vector<int> solution(int n, int s) {
    if(s<n) return vector<int> {-1};   
    vector<int> answer;
    
    while(n!=0)
    {
        if(n==1) { answer.push_back(s); break;}
        // 몫이 있을경우
        if(s%n!=0)
        {
            answer.push_back(s/n + 1);
            s -= s/n + 1;
        }
        else
        {            
            answer.push_back(s/n);
            s-=s/n;
        }
        n--;
    }
    
    sort(answer.begin(),answer.end());
    return answer;
}