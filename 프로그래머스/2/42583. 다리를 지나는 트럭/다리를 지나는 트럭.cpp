#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

// 1초에 한대
// 
//  auto it_h = find_if(str.begin(), str.end(), [](char c) {
//            return isdigit(c);
//        });

int Weight = 0;
bool compare(int a,int b)
{
    return (a+b)>=Weight;
}

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int t=1;
    queue<pair<int,int>> q;
    Weight=weight;
    int cur_weight=0;
      

 // 트럭이 모두 다리를 건널 때까지 반복
    while (!truck_weights.empty() || !q.empty()) {
        answer++;

        // 다리 위의 트럭을 빼고 무게 갱신
        if (!q.empty() && answer - q.front().second == bridge_length) {            
            cur_weight -= q.front().first;
            q.pop();
            
        }
        // 다음 트럭을 다리에 올릴 수 있는지 확인
        if (!truck_weights.empty() && cur_weight + truck_weights.back() <= weight) {
            q.push({truck_weights.back(),answer});
            
            cout<<answer;
            cur_weight += truck_weights.back();
            truck_weights.pop_back();
        }
       
    }

    
    return answer;
}