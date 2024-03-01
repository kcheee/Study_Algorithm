#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(int a, int b) {
    
    string c[7] = {"FRI","SAT","SUN","MON","TUE","WED","THU"};
    string ans[13][32];
    // 1 3 5 7 8 10 12
    string store;
    string answer = "";
    int cnt=0;
    for(int i=1;i<=12;i++)
    {
        if(i==1 ||i==3||i==5||i==7
           ||i==8||i==10||i==12) {  for(int j=1;j<=31;j++) ans[i][j] = c[(cnt++)%7];    }
        if(i==4 ||i==6 ||i==9 ||i==11){   for(int j=1;j<=30;j++) ans[i][j] = c[(cnt++)%7];    }
        if(i==2){
            for(int j=1;j<=29;j++) { ans[i][j] = c[(cnt++)%7];  }
        }           
    }
    return ans[a][b];
}