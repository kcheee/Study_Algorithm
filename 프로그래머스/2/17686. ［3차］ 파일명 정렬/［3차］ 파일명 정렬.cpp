#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <tuple>
using namespace std;

// 대소문자 구별 안함
// 숫자 하나 이상 포함
// Head 부분이 사전 순으로 정렬
// 같을경우 숫자 순으로 정렬 앞에 있는 0은 무시 됌
// Head와 number가 같을 경우 원래 입력에 주어진 순서 유지

// '-', 숫자가 나올 경우 구별한다
// sort를 해줘야하는데

// compare 함수에서 비교하고 정렬해준다.
// Head와 number 
bool compare(tuple<string,string,string> a, tuple<string,string,string> b)
{
   // 비교할때 대소문자 구별 (참조 안되는 매개변수)
    transform(get<0>(a).begin(),get<0>(a).end(),get<0>(a).begin(), :: tolower);
    transform(get<0>(b).begin(),get<0>(b).end(),get<0>(b).begin(), :: tolower);
    
    if(get<0>(a) == get<0>(b))
    {
        if (stoi(get<1>(a)) == stoi(get<1>(b))) return false;
        else
            return stoi(get<1>(a)) < stoi(get<1>(b));
    }      
    return get<0>(a) < get<0>(b);     
}
vector<string> solution(vector<string> files) {
    vector<string> answer;
    vector<tuple<string,string,string>> ans;
    
    for(auto str : files)
    {
        
        // head: 숫자가 나오기 전까지의 값을 넣어줌
        auto it_h = find_if(str.begin(), str.end(), [](char c) {
            return isdigit(c);
        });
        int H_dis = distance(str.begin(), it_h);
        string h = str.substr(0, H_dis);
        cout<<h<<" ";
        // number: 숫자인 경우의 값을 넣어줌
        // 여기서 주의할점 5자리를 넘어가지 않는다는점
        auto it_n = find_if(it_h, str.end(), [](char c) {
            return !isdigit(c);
        });
        int N_dis = distance(it_h, it_n) > 5 ? 5 : distance(it_h, it_n);
        string n = str.substr(H_dis, N_dis);
         cout<<n<<" ";
        // 문자열 끝까지
        string t = str.substr(distance(str.begin(), it_n));  
        cout<<t<<endl;
        ans.push_back({h,n,t});            
    }
    stable_sort(ans.begin(),ans.end(),compare);
    cout<<endl;
    for(auto n : ans)
    {
        answer.push_back(get<0>(n)+get<1>(n)+get<2>(n));
        cout<<get<0>(n)+get<1>(n)+get<2>(n)<<endl;
    }
           
    return answer;
}
