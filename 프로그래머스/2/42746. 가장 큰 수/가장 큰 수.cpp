#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool compare(string a, string b)
{
    return a + b > b + a;   
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> s;
    for(auto n : numbers)
        s.push_back(to_string(n));
    
    sort(s.begin(),s.end(),compare);
    
    for(auto n : s)  answer+=n;
    
    if(answer[0] == '0') return "0";
    
    return answer;
}