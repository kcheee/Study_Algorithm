#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string binary_(int a,int digit)
{
    string str;
    bool flag_zere =false;
    while(a!=0)
    {    
        str+=to_string(a%2);
        a/=2;
    }
    reverse(str.begin(),str.end());
    
    while(str.size()<digit) str = '0'+str;
    
    return str;
}
vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    
    // 한 변 크기 n  1<=n<=16
    // 2개의 정수 배열
    // #이 둘중에 하나라도 있으면 막힌거 공백은 두개 다 공백이여야 함.
    
    // 일단 이진 변환 부터 해야함.
    int a[17][17];
    int b[17][17];
    string arr_a[17];
    string arr_b[17];
    string str;
    vector<string> ans;
    for(int i=0;i<n;i++)
    {
        // 이진변환
        arr_a[i] =binary_(arr1[i],n);
        arr_b[i] =binary_(arr2[i],n); 

        for(int j=0;j<n;j++)
        {
            if(arr_a[i][j]=='1'|| arr_b[i][j]=='1') 
            {
                str+='#';
            }
            else str+=' ';
        }        
        ans.push_back(str);
        str.clear();
    }
    
    return ans;
}