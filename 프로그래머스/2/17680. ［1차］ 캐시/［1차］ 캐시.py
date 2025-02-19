def solution(cacheSize, cities):
    answer = 0
    
    # LRU 알고리즘
    # hit = 1 miss =5
    
    # 캐시 크기 0인경우
    if cacheSize == 0 : return len(cities)*5
    
    c_l = []
    
    for c in cities :
        c = c.lower()
        # hit
        if c in c_l :
            answer+=1
            c_l.remove(c)  # 현재 위치에서 제거
            c_l.append(c)  # 가장 최근 위치로 이동
                
        #miss
        else :
            answer+=5
            if cacheSize > len(c_l) :
                c_l.append(c)           
            elif c_l : 
                c_l.pop(0)
                c_l.append(c)


    return answer