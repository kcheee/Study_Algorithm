#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <set>
using namespace std;

    // 하나만 입는경우 : clothes.size()
    // 2개 입는 경우 : n*n
    // 3개 입는경우 : n*n*n
    // n개 입는경우 : n*n..*n 15
    // 다입는경우

        

int solution(vector<vector<string>> clothes) {
    
    int answer = 1;
        
    map<string,int> clo;
    set<string> a;
    for(int i=0;i<clothes.size();i++)  
    {
        clo[clothes[i][1]]++;
    }
    
    for(auto n : clo)
    {       
        answer*=(n.second+1);
        cout<<answer<<" ";
    }
    
    return answer-1;
}