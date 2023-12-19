#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> numbers) {

    int answer=0;
    bool flag = false;
    for(int i=0;i<10;i++)
    {
        flag = false;
        for(int k=0;k<numbers.size();k++)
        {
            if(i==numbers[k]){
                flag =true;
                break;
            }
        }
        if(!flag) answer +=i;
    }
    return answer;
}