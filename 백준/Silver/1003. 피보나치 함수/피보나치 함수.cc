#include <iostream>
#include <vector>

using namespace std;

int main(){

    int n;
    cin >> n;
    
    vector<pair<int, int>> test;
    test.push_back({ 1,0 });
    test.push_back({ 0,1 });

    for (int i = 2; i < 41; i++)
    {
        test.push_back({ (test[i - 2].first + test[i - 1].first),(test[i - 2].second + test[i - 1].second) });

    }
    int a;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        cout << test[a].first << " " << test[a].second << endl;
    }
}