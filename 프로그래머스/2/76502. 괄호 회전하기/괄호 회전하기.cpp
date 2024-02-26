#include <string>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

// 문자열을 회전하는 함수
string rotate(string& str) {
    if (str.empty()) return str;
    return str.substr(1) + str[0];
}

// 괄호 문자열이 올바른지 검사하는 함수
bool isValid(string& s) {
    stack<char> stk;
    for (char ch : s) {
        if (ch == '(' || ch == '{' || ch == '[') {
            stk.push(ch);
        } else {
            if (stk.empty()) return false;
            if (ch == ')' && stk.top() != '(') return false;
            if (ch == '}' && stk.top() != '{') return false;
            if (ch == ']' && stk.top() != '[') return false;
            stk.pop();
        }
    }
    return stk.empty();
}

int solution(string s) {
    int answer = 0;
    
    for(int i = 0; i < s.size(); ++i) {
        if (isValid(s)) ++answer;
        s = rotate(s); // 문자열을 회전
    }
    
    return answer;
}