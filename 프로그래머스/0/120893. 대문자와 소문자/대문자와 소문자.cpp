#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

string solution(string my_string) {
    string answer = "";
    
    for(int i=0;i<my_string.length();i++)
    {
       
        if(64<my_string[i]&& 91>my_string[i]) answer+=(my_string[i]+32);
        else  answer+=(my_string[i]-32);
    }
    return answer;
}