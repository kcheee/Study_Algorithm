#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

// 속한 노래가 가장 많이 재생된것
struct ComparePairs {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) const {
        return a.first > b.first; // 첫 번째 요소를 기준으로 내림차순 정렬
    }
};

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string,multiset<pair<int,int>,ComparePairs>> album;
    set<int,greater<int>> cnt;
    map<int,string> cntname;
    
    for(int i=0;i<genres.size();i++)
        album[genres[i]].insert({plays[i],i});       
          
    for(auto it = album.begin();it!=album.end();it++)
    {
        int a=0;
        for(auto it2 : it->second)
            a+=it2.first;           
        
        cnt.insert(a);
        cntname[a] =it->first;
    }
    
    for(auto it : cnt)
    {
        int i=0;
        for(auto it2 : album[cntname[it]])
        {
            if(i==2) break;
            answer.push_back(it2.second);
            i++;
        }     
    }
    
    return answer;
}