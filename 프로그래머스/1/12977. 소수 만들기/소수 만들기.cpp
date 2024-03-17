#include <vector>
#include <iostream>
#include <set>
#include <map>
using namespace std;

bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int solution(vector<int> nums) {
    int answer = 0;
    
    map<int, bool> primes;

    // 1부터 1000까지의 수 중 소수인 경우만 map에 삽입
    for (int i = 2; i <= 3000; i++) {
        if (isPrime(i)) {
            primes[i] = true;
        }           
    }
       
    for(int i=0;i<nums.size()-2;i++)
    {
        for(int j=i+1;j<nums.size()-1;j++)
        {
            for(int k=j+1;k<nums.size();k++)
            {
                if(primes[nums[i]+nums[j]+nums[k]])   answer++;               
            }
        }
    }

    return answer;
}