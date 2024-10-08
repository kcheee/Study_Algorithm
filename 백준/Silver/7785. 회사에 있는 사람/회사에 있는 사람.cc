#include <iostream>
#include <set>
#include <string>

using namespace std;

int main() {
    int n; // 로그의 수
    cin >> n;
    
    set<string> company; // 현재 회사에 있는 사람들

    for (int i = 0; i < n; ++i) {
        string name, action;
        cin >> name >> action;
        
        if (action == "enter") {
            company.insert(name); // 출근: 회사에 추가
        } else {
            company.erase(name); // 퇴근: 회사에서 제거
        }
    }
    
    // 회사에 남아 있는 사람들을 역순으로 출력
    for (auto it = company.rbegin(); it != company.rend(); ++it) {
        cout << *it << '\n';
    }
    
    return 0;
}
