def solution(n):
    answer = ''
    while n > 0:
        n -= 1  # 1을 빼주는 것이 핵심입니다
        remainder = n % 3
        n = n // 3
        answer = '124'[remainder] + answer
    return answer