#include <string>
#include <vector>
#include <iostream>

using namespace std;

// 1번 1 2 3 4 5
// 2번 2 1 2 3 2 4 2 5
// 3번 3 3 1 1 2 2 4 4 5 5

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int a[5] = {1,2,3,4,5};    int b[8] = {2,1,2,3,2,4,2,5};    int c[10] = {3,3,1,1,2,2,4,4,5,5};
    int n[3]={0};
    
    for(int i=0;i<answers.size();i++)
    {
        if(a[i%5]==answers[i]) n[0]++;
        if(b[i%8]==answers[i]) n[1]++;
        if(c[i%10]==answers[i]) n[2]++;       
    }
    int cnt = max(max(n[0],n[1]),n[2]);
    for(int i=0;i<3;i++) if(n[i]==cnt) answer.push_back(i+1);
    
    return answer;
}