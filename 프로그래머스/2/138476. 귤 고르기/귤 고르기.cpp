#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

    // 크기가 서로 다른 종류   
    // 중복된것을 먼저 추가    
    // 일단 sort 해줌
    // 전역 변수로 등장 횟수를 저장할 맵을 선언

map<int, int> frequency;

bool compare(int a, int b) {
    // 먼저 등장 횟수로 비교
    if (frequency[a] != frequency[b])
        return frequency[a] > frequency[b];
    // 숫자 자체를 비교하여 정렬
    return a < b;
}
int solution(int k, vector<int> tangerine) {
    
    int answer = 1;
  
    for(int i=0;i<tangerine.size();i++)
    {
        frequency[tangerine[i]]++;
    }
    
    sort(tangerine.begin(), tangerine.end(), compare);
        
    for (int i=1;i<k;i++) {
        
        if(tangerine[i-1]!=tangerine[i]) answer++;
    }
    
    return answer;
}