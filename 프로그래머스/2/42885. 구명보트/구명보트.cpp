#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    
    // 최대 2명
    // 구명보트를 최대한적게 사용하여 구출 
    // 가벼운 사람과 무거운 사람을 먼저 빼는 형식으로
    // 일단 sort 해서 가장 뒤에 있는 사람과 앞에 있는 사람을 비교해서 빼준다.
    
    int answer = 0;
    int a=0;
    sort(people.begin(),people.end());
    
    int i = 0, j = people.size() - 1; // i는 가장 가벼운 사람의 인덱스, j는 가장 무거운 사람의 인덱스

    while (i <= j) { 
        if (people[i] + people[j] <= limit) {            
            i++; 
        }       
        j--;
        answer++; 
    }
    return answer;
}