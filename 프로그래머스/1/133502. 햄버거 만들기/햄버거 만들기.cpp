#include <vector>
#include <stack>

using namespace std;

int solution(vector<int> ingredient) {
    stack<int> s;
    int burger_count = 0;

    for (int i = 0; i < ingredient.size(); i++) {
        s.push(ingredient[i]);

        // 스택의 최상단이 1일 때만 뒤의 3, 2, 1을 체크
        if (s.size() >= 4 && s.top() == 1) {
            int fourth = s.top(); s.pop();
            int third = s.top(); s.pop();
            int second = s.top(); s.pop();
            int first = s.top(); s.pop();
            
            // 햄버거가 완성되었을 경우
            if (first == 1 && second == 2 && third == 3 && fourth == 1) {
                burger_count++;
            } else {
                // 조건이 맞지 않으면 다시 스택에 요소들을 넣어줍니다.
                s.push(first);
                s.push(second);
                s.push(third);
                s.push(fourth);
            }
        }
    }
    
    return burger_count;
}
