#include <string>
#include <vector>
#include <iostream>
#include <climits> // INT_MAX, INT_MIN 사용을 위해 추가
#include <sstream>

using namespace std;

string solution(string s) {
    string answer = "";
    stringstream ss(s);
    int maxNum = INT_MIN; // 최솟값을 구하기 위해 INT_MIN으로 초기화
    int minNum = INT_MAX; // 최댓값을 구하기 위해 INT_MAX으로 초기화

    int num;
    while (ss >> num) { // stringstream에서 숫자를 읽어옴
        maxNum = max(maxNum, num); // 최댓값 갱신
        minNum = min(minNum, num); // 최솟값 갱신
    }

    answer = to_string(minNum) + " " + to_string(maxNum);
    
    return answer;
}