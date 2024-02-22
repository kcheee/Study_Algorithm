#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// 1번부터 번호순대로 단어
// 마지막에서 첫번째
// 앞사람이말한단어의 마지막문자로 시작하는 단어  
// 이전에 등장했던단어 사용 불가 
// 한글자는 인정 x
// 탈락자 안생기면 [0,0]
vector<int> solution(int n, vector<string> words) {
    
    vector<int> answer;
    vector<string> usedWords; // 사용된 단어들을 저장할 벡터

    for(int i=0; i<words.size(); ++i){
        // 첫 단어가 아니고 끝말잇기 규칙 위반 또는 이미 사용된 단어인 경우
        if((i > 0 && words[i-1].back() != words[i][0]) || find(usedWords.begin(), usedWords.end(), words[i]) != usedWords.end()) {
            answer.push_back(i % n + 1); // 탈락자 번호
            answer.push_back(i / n + 1); // 탈락 차례
            return answer;
        }
        usedWords.push_back(words[i]); // 사용된 단어 저장
    }

    // 탈락자가 없는 경우
    return vector<int>{0, 0};
}