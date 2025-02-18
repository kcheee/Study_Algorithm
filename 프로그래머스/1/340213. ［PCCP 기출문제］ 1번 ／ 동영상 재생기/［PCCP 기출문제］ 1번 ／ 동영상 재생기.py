def time_convert(str) :
    s = str.split(':')
    return int(s[0])*60 + int(s[1])

def solution(video_len, pos, op_start, op_end, commands):
    answer = ''
    
    # 시간을 분 단위로 변환
    video = time_convert(video_len)
    pos = time_convert(pos)
    op_s = time_convert(op_start)
    op_e = time_convert(op_end)
    
    for c in commands :
        # 현재 위치가 오프닝 구간인지 먼저 확인
        if op_s <= pos <= op_e:
            pos = op_e
            
        # 명령어 처리
        if c == "next":
            pos += 10
            # 영상 길이를 넘어가면 마지막으로 조정
            pos = min(pos, video)
            
        elif c == "prev":
            pos -= 10
            # 0보다 작아지면 처음으로 조정
            pos = max(pos, 0)
        
        # 명령어 처리 후 다시 오프닝 구간 체크
        if op_s <= pos <= op_e:
            pos = op_e
    
    # 시간 형식으로 변환
    hours = str(pos // 60).zfill(2)  # 두 자리 수로 맞추기
    minutes = str(pos % 60).zfill(2)  # 두 자리 수로 맞추기
    answer = f"{hours}:{minutes}"
    
    return answer