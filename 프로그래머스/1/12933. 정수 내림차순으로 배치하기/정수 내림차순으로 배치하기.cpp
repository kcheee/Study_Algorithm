#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

long long solution(long long n) {
    long long answer = 0;
    vector<int> result;
    
    // vector을 써서 앞에
    while(n){
        result.push_back(n%10);
        n=n/10;
    }
    sort(result.begin(),result.end());
    
    for(int i=0;i<result.size();i++){
        if(i==0)
            answer=result[i];
        else{
            answer += result[i]*pow(10,i);
            cout<< result[i]*pow(10,i) << endl;
        }            
    }
    return answer;
}