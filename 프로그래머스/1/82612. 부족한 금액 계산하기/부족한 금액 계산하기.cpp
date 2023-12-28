using namespace std;

long long solution(int price, int money, int count)
{
    long long answer = -1;
    long long add = 0;
    for(int i=1;i<=count;i++)
    {
        add+=price*i;
    }
    answer = money-add;
    if(answer >= 0) 
    {   
        answer =0;
        return answer;
    }

    return -answer;
}