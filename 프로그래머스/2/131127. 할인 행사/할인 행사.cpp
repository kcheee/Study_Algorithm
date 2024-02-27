#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    
int answer = 0;
    map<string, int> ans;
    int q = 0;
    for (string str : want) {
        ans[str] = number[q++];
    }

    for (int i = 0; i <= discount.size() - 10; i++) {
        map<string, int> ans_copy = ans;
        for (int j = 0; j < 10; j++) {
            if (ans_copy.find(discount[i + j]) != ans_copy.end()) {
                ans_copy[discount[i + j]]--;
            }
        }

        bool isMatch = true;
        for (auto& pair : ans_copy) {
            if (pair.second > 0) {
                isMatch = false;
                break;
            }
        }

        if (isMatch) {
            answer++;
        }
    }
    
    return answer;
}