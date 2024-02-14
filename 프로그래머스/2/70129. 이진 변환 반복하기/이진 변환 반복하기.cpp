#include <string>
#include <vector>
#include <iostream>

using namespace std;

// 이진변환하는 함수 구현
string binary(int t) {
    // 재귀로 이진변환하기.
    if (t == 0)
        return ""; // 기저 조건
    else
        return binary(t / 2) + (t % 2 == 0 ? "0" : "1");
}

int binary_cnt=0;
vector<int> solution(string s) {
    
    // 1. 0의 개수를 찾는다(개수를 찾고 계속 더해줌.)
    // 2. 개수를 이진변환한다 ( 반복한 횟수 가져옴)
    // 3. 1이 될때까지 반복
    
    vector<int> answer;
    int Zero =0;
    // 이진변환한 값이 "1"일때 멈춤
     while(s != "1")
     {
        int zero_cnt=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='0') zero_cnt++;
        }
        Zero+=zero_cnt;
        s=binary(s.length()-zero_cnt);
        binary_cnt++;      
     }
    
    
    answer.push_back(binary_cnt);
    answer.push_back(Zero);
    
    return answer;
}