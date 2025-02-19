def solution(n):
    answer = 1
    max = 10000

    # 투 포인터 알고리즘사용
    
    for i in range(1,(n+1)//2) :
        sum =0
        for j in range(i,10001,1) :
            sum+=j
            if n<sum : break
            elif n==sum : 
                answer+=1
                break 
    
    
    return answer