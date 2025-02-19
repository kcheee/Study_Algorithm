def solution(n):
    dp = []
    # dp 문제
    # 점화식 dp[i] = dp[i-2] + dp[i-1]
    
    dp.append(0) 
    dp.append(1) 
    dp.append(2) 
    dp.append(3) 
    dp.append(5)
    
    for i in range(5,2001,1) :
        dp.append((dp[i-2] + dp[i-1])%1234567)
        
    return dp[n]