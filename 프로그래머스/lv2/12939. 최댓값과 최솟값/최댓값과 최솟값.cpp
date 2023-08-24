#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iostream>

using namespace std;

// 1. 공백으로 구분 split 하기
// 2. 배열이나 list에 넣기.
// 3. sort 하기.

// 음수 조건문 붙여주기.
bool compare(string a, string b) {
  //이름이 같으면, 나이가 적은순
        return stoi(a) < stoi(b);
}

string solution(string s) {

    string result;
    stringstream stream(s);

    // 공백 분리 결과를 저장할 배열
    vector<string> words;

    string word;
    // 스트림을 한 줄씩 읽어, 공백 단위로 분리한 뒤, 결과 배열에 저장
    while (getline(stream, word, ' ')) {
        words.push_back(word);
    }
    
    sort(words.begin(), words.end(),compare);

    cout << words.front() << words.back();

    result = words.front() + " " + words.back();
    return result;
}