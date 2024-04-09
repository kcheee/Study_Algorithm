#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<string> Board;
bool flag = false;

// 가장 낮은 위치를 리턴시켜주자
void check_puzzle(int x, int y, vector<string>& board_, vector<vector<bool>>& check_)
{
    char c = board_[y][x];
    if(c == board_[y][x+1] && c == board_[y+1][x] && c == board_[y+1][x+1])
    {
        check_[y][x] = true;
        check_[y+1][x] = true;
        check_[y][x+1] = true;
        check_[y+1][x+1] = true;
        
        flag = true;
    }
}

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    Board = board;
    
    // 퍼즐을 모두 제거할 때까지 반복
    do
    {
        flag=false;
        vector<vector<bool>> check(m,vector<bool>(n,false));
        // 보드 전체를 탐색하면서 퍼즐을 찾고, 제거 대상으로 표시
        for(int i=0;i<m-1;i++)
        {
            for(int j=0;j<n-1;j++)
            {
                // i = y, j = x
                // "0"인 값은 continue;
                if(Board[i][j]!='0')
                check_puzzle(j,i,Board,check);
            }
        }
        // 퍼즐이 하나라도 제거되었다면
        if(flag)
        {
            // 제거된 퍼즐의 수를 증가시킴
            for(auto n : check)
                for(auto m : n) if(m) answer++;
            
            // 제거된 퍼즐의 아래 블록을 위로 올려줌
            for(int i=0;i<n;i++)
            {
                for(int j=0; j<m;j++)
                {
                    if(!check[j][i]) continue;
                    else
                    {
                        // 내려줘야함   
                        for(int k=j;k>0;k--)
                        {
                            Board[k][i] = Board[k-1][i];
                            Board[k-1][i] = '0';
                        }
                    }
                }
            }           
        }
    } while(flag);
    
    
    return answer;
}
