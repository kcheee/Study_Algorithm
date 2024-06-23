#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string cipher, int code) {
    string answer = "";
    
    for(int i=code-1;i<cipher.length();i+=code)
    {
        answer+= cipher[i];
    }
    return answer;
}