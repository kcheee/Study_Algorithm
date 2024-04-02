#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;



int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    

    for(int i=0;i<skill_trees.size();i++)
    {
        int a=0;
        bool flag=true;
        vector<char> s;
        for(int j=0;j<skill.size();j++)
        {
            auto it = find(skill_trees[i].begin(),skill_trees[i].end(),skill[j]);
            // 값이 있는 경우
            if(it != skill_trees[i].end())
            {                
                if(s.empty()&& j>0) { flag=false; break; }
                int index = distance(skill_trees[i].begin(), it);
                if(a<=index) a=index; 
                else { flag=false; break;}             
                if(j!=0&&s.back()!=skill[j-1]) { flag=false; break; }
                
                s.push_back(skill[j]);            
            }              
        }
        if(flag)  answer++; 
    }
    
    return answer;
}