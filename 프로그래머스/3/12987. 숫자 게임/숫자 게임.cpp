#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    sort(A.begin(), A.end(), greater<int>()); // A 팀의 숫자를 내림차순으로 정렬
    sort(B.begin(), B.end(), greater<int>()); // B 팀의 숫자를 내림차순으로 정렬
    
    int b_index = 0; // B 팀의 현재 출전 순서 인덱스
    for (int a : A) {
        if (a < B[b_index]) { // A 팀의 숫자가 B 팀의 현재 순서보다 작으면
            answer++; // B 팀이 이기므로 승점을 증가시킴
            b_index++; // 다음 B 팀원이 출전하도록 인덱스를 증가시킴
        }
    }
    
    return answer;
}
