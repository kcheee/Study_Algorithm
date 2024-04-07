#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <map>
#include <queue>
using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    queue<pair<string,int>> ans;
    map<string,string> user;

    // 이름 변경 기록을 먼저 처리하여 사용자 목록을 업데이트합니다.
    for (const string& n : record) {
        string x, y, z;
        stringstream s(n);
        s >> x >> y >> z;
        if (x == "Change" || x == "Enter") {
            user[y] = z; // 사용자 이름을 갱신합니다.
        }
    }

    // "Enter" 또는 "Leave" 기록을 처리합니다.
    for (const string& n : record) {
        string x, y, z;
        stringstream s(n);
        s >> x >> y >> z;
        if (x == "Enter") {
            ans.push({y, 1});
        } else if (x == "Leave") {
            ans.push({y, 0});
        }
    }

    // 처리된 결과를 정리하여 답안을 구성합니다.
    while (!ans.empty()) {
        if (ans.front().second == 1) {
            answer.push_back(user[ans.front().first] + "님이 들어왔습니다.");
        } else if (ans.front().second == 0) {
            answer.push_back(user[ans.front().first] + "님이 나갔습니다.");
        }
        ans.pop();
    }

    return answer;
}
