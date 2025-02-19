from collections import deque

def solution(s):
    answer = 0
    a = deque(s)
    
    for n in range(len(a)):
        stack = deque()  # 하나의 스택으로 통합
        flag = False
        
        for i in a:
            if i in '[{(':  # 여는 괄호는 모두 스택에 추가
                stack.append(i)
            else:  # 닫는 괄호일 경우
                if not stack:  # 스택이 비어있으면 잘못된 경우
                    flag = True
                    break
                
                # 괄호 쌍 검사
                if i == ']' and stack[-1] != '[':
                    flag = True
                    break
                elif i == '}' and stack[-1] != '{':
                    flag = True
                    break
                elif i == ')' and stack[-1] != '(':
                    flag = True
                    break
                
                stack.pop()  # 쌍이 맞으면 pop
        
        # 모든 괄호가 올바르게 닫혔는지 확인
        if not flag and not stack:  # 스택이 비어있어야 함
            answer += 1
        
        # 회전
        a.append(a.popleft())
    
    return answer