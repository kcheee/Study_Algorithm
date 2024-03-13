#include <string>
#include <vector>
#include <iostream>

using namespace std;

// 배포될때 같이 배포가 되는 작업들
// 앞에 있는 작업보다 뒤에 있는 작업이 오래 걸리면 오래걸리는 작업 앞에 있는 것 까지 카운트
// 작업이 언제 끝나는지 카운트

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int result = 0;
    int cnt =1;
    vector<int> ans;
    // 작업이 하나일때도 체크 해줘야 함.
   if(progresses.size()==1) 
   {
       int n = ((100-progresses[0]) % speeds[0])>0 ? 
            (100-progresses[0]) / speeds[0]+1 : (100-progresses[0]) / speeds[0];
       answer.push_back(n);
       return answer;
   }
    for(int i=0;i<progresses.size();i++)
    {
        int n = ((100-progresses[i]) % speeds[i])>0 ? 
            (100-progresses[i]) / speeds[i]+1 : (100-progresses[i]) / speeds[i];
        // cout<<n<<" ";
        if(i==0) result=n;
        else
        {
            if(result < n)
            {
                cout<<cnt<<" ";
                answer.push_back(cnt);
                cnt =1;
                result = n;
            }
            else
            {
                cnt++;
            }
        }

    }
    // 마지막 값
    answer.push_back(cnt);
       
    return answer;
}