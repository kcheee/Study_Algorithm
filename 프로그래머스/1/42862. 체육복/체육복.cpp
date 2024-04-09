#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n - lost.size();
    
    // 정렬
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());
    
    // 여벌 체육복을 가져온 학생이 도난당한 경우 처리
    for(int i = 0; i < lost.size(); ++i) {
        auto it = find(reserve.begin(), reserve.end(), lost[i]);
        if(it != reserve.end()) {
            reserve.erase(it);
            lost.erase(lost.begin() + i);
            ++answer;
            --i;
        }
    }
    
    // 체육복 빌려주기
    for(int i = 0; i < reserve.size(); ++i) {
        auto it = find(lost.begin(), lost.end(), reserve[i] - 1);
        if(it != lost.end()) {
            lost.erase(it);
            ++answer;
        } else {
            it = find(lost.begin(), lost.end(), reserve[i] + 1);
            if(it != lost.end()) {
                lost.erase(it);
                ++answer;
            }
        }
    }
    
    return answer;
}
