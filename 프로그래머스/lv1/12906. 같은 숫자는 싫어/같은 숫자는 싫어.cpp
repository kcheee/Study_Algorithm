#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// stack을 사용해서 back 숫자가 같으면 쌓지 않음.
vector<int> solution(vector<int> arr)
{

    vector<int> answer;

    answer.push_back(arr[0]);
    // 첫번째 숫자는 어차피 앞에 숫자가 없으니 1부터 시작.
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i - 1] != arr[i])
            answer.push_back(arr[i]);
    }


    return answer;

}
