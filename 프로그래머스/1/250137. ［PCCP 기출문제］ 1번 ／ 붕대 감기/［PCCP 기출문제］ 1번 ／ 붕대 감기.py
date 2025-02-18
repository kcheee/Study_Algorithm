def solution(bandage, health, attacks):
    max_health = health  # 최대 체력 저장
    current_health = health  # 현재 체력
    bandage_time, heal_per_sec, bonus_heal = bandage  # 붕대 정보 분리
    
    last_attack_time = attacks[-1][0]  # 마지막 공격 시간
    attack_times = {attack[0]: attack[1] for attack in attacks}  # 공격 시간:피해량 딕셔너리
    
    consecutive_healing = 0  # 연속 힐링 시간
    
    # 첫 공격부터 마지막 공격까지 시간 순회
    for current_time in range(1, last_attack_time + 1):
        # 공격받는 시간인 경우
        if current_time in attack_times:
            current_health -= attack_times[current_time]  # 피해
            consecutive_healing = 0  # 연속 힐링 초기화
            
            # 체력이 0 이하면 사망
            if current_health <= 0:
                return -1
                
        # 공격받지 않는 시간인 경우
        else:
            consecutive_healing += 1  # 연속 힐링 증가
            current_health += heal_per_sec  # 초당 회복
            
            # 연속 힐링 성공시 추가 회복
            if consecutive_healing == bandage_time:
                current_health += bonus_heal
                consecutive_healing = 0
            
            # 최대 체력 초과 방지
            current_health = min(current_health, max_health)
    
    return current_health
