#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int dinary_(int a){
    
    string din;
    int cnt=0;
    while(a!=0)
    {
        din+=to_string(a%2);
        if(a%2==1) cnt++;
        a/=2;
    }
    return cnt;
}

int solution(int n) {
    
    int answer = n;
    int n_cnt = dinary_(n);
    int answer_cnt = 0;
    
    while(n_cnt!=answer_cnt)
    {        
        answer++;
        answer_cnt = dinary_(answer);
        cout<<answer;
    }

    return answer;
}