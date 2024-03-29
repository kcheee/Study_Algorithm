#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <tuple>

using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
    map<int,tuple<int,string,int>> ans;
    
    for(auto n : records)
    {
        // 시간
        int time= stoi(n.substr(0,2))*60 + stoi(n.substr(3,2));
        
        // 차량번호
        int number=  stoi(n.substr(6,4));
        
        // 내역
        string in_out= n.substr(11,n.size()-11);
        
        // 초기값
        if(ans.find(number)==ans.end())
            ans[number] = {time,in_out,0};
        else
        {            
            if(in_out=="IN")            
                ans[number] = {time,in_out,get<2>(ans[number])};
            
            else if((in_out=="OUT"))                            
                ans[number] = {time,in_out,get<2>(ans[number]) +time-get<0>(ans[number])};            
        }             
    }
    
    vector<int> answer;
    for(auto n : ans)
    {      
        get<2>(n.second) += get<1>(n.second)=="IN" ? 1439-get<0>(n.second):0;
                   
        if(get<2>(n.second) < fees[0])  answer.push_back(fees[1]);         
        else     
            answer.push_back(fees[1] + (((get<2>(n.second) - fees[0]) % fees[2] == 0 ) ? 
                           (get<2>(n.second) - fees[0]) /fees[2] : 
                           ((get<2>(n.second) - fees[0]) /fees[2])+1) *fees[3]);                           
    }
    
    return answer;
}