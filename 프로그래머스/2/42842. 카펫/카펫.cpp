#include <string>
#include <vector>
#include <iostream>

using namespace std;

// yellow의 최소공배수 =n
// brown = (n+2)*2+2*(yellow/n)

vector<int> solution(int brown, int yellow) {
    
    vector<int> answer;
    for(int i=1; i<=yellow; i++){
        if(yellow % i == 0){ // i가 yellow의 약수일 때
            int y = i;
            int x = yellow / i;
            if((x + 2) * (y + 2) - yellow == brown){ // 전체 카펫의 크기에서 노란색 부분을             뺀 값이 갈색 격자의 수와 일치하는지 확인
                answer.push_back(x + 2); // 가로 길이
                answer.push_back(y + 2); // 세로 길이
                break; // 조건을 만족하는 첫 번째 조합을 찾으면 반복문 탈출
            }
        }
    }
    return answer;
}