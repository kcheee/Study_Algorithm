#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size());
    priority_queue<pair<int,int>> a;

    for (int i = 0; i < prices.size(); ++i) {
        while (!a.empty() && a.top().first > prices[i]) {
            answer[a.top().second] = i - a.top().second;
            a.pop();
        }
        a.push({prices[i], i});
    }

    while (!a.empty()) {
        answer[a.top().second] = prices.size() - 1 - a.top().second;
        a.pop(); 
    }

    return answer;
}