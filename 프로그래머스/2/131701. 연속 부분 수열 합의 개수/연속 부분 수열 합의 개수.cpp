#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
using namespace std;

// 마지막에 sort하고 unique하고 erase 해줌

int solution(vector<int> elements) {
    
    vector<int> a;

    long long add=0;
    for(int i=0;i<elements.size();i++)
    {
        for(int j=0;j<elements.size();j++)
        {
            for(int k=0;k<i+1;k++)
            {
                add +=elements[(j+k)%elements.size()];
            }
            a.push_back(add);
            add=0;
        }       
    }
    
    sort(a.begin(),a.end());
    a.erase(unique(a.begin(),a.end()),a.end());
    
    //원형 수열을 일단 만들자
     
    return a.size();
}