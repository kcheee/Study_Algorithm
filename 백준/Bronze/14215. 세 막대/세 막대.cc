#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int a, b, c;
    vector<int> vec(3);

    // 입력 받기
    cin >> vec[0] >> vec[1] >> vec[2];

    // 오름차순 정렬
    sort(vec.begin(), vec.end());

    // 삼각형 조건 확인
    if (vec[2] >= vec[0] + vec[1]) {
        // 가장 큰 변을 나머지 두 변의 합보다 작게 만들어야 하므로, 
        // vec[2] = vec[0] + vec[1] - 1로 수정
        vec[2] = vec[0] + vec[1] - 1;
    }

    // 최대 둘레 출력
    cout << vec[0] + vec[1] + vec[2] << endl;

    return 0;
}
