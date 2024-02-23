#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    
    vector<int> answer;
    int ans=0;
    for(int i=0;i<photo.size();i++)
    {
        for(int j=0;j<photo[i].size();j++)
        {
            for(int k=0;k<name.size();k++)
            {                
                if(name[k]==photo[i][j]) ans+= yearning[k];
            }
        }
        // push
        answer.push_back(ans);
        ans=0;       
    }
    return answer;
}