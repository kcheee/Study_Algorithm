#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int result = 0;
    int cnt =1;
    vector<int> ans;

    for(int i=0;i<progresses.size();i++)
    {
        int n = ((100-progresses[i]) % speeds[i])>0 ? 
            (100-progresses[i]) / speeds[i]+1 : (100-progresses[i]) / speeds[i];

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
    answer.push_back(cnt);
       
    return answer;
}