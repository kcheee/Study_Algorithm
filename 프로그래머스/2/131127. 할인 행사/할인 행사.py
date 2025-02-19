def solution(want, number, discount):
    answer = 0
    
    # want 리스트의 제품들을 dictionary로 변환하여 원하는 수량 저장
    want_dict = dict(zip(want, number))
    
    # discount 리스트를 10일씩 슬라이딩하면서 확인
    for i in range(len(discount) - 9):
        # 현재 10일간의 할인 품목들을 카운트
        current_dict = {}
        for j in range(10):
            item = discount[i + j]
            current_dict[item] = current_dict.get(item, 0) + 1
        
        # 원하는 제품의 수량과 일치하는지 확인
        is_possible = True
        for item, count in want_dict.items():
            if current_dict.get(item, 0) != count:
                is_possible = False
                break
        
        if is_possible:
            answer += 1
            
    return answer