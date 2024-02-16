#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(vector<int> number) {
    
    // 세개의 숫자를 더했을때 0이 되는 숫자
    // 방법을 생각해보자
    // 두개의 숫자를 기준으로 계속 잡고
    // find(number.begin(),number.end())찾고자 하는 숫자)를 사용한다. 
    // (find 함수는 값이 있으면 number.end()를 return)
    // *주의* 기준으로 잡은 숫자는 find에서 찾지 못하게 해야한다.
    // find를 통한 인덱스 가져오는법 find(number.begin(),number.end()) - number();
    
    int answer = 0;  
    for(int i=0;i<number.size()-1;i++)
    {
        for(int j=i+1;j<number.size();j++)
        {
            for(int k=j+1;k<number.size();k++)
            {
                if(number[i]+number[j]+number[k]==0)
                    answer++;
            }
                        
        }
    }
    
    return answer;
}