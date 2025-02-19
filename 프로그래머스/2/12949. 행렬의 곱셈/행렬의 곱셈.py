def solution(arr1, arr2):
    # 결과 행렬의 크기: arr1의 행 개수 x arr2의 열 개수
    rows = len(arr1)
    cols = len(arr2[0])
    
    # 결과 행렬 초기화
    answer = [[0] * cols for _ in range(rows)]
    
    # 행렬 곱셈 수행
    for i in range(rows):  # arr1의 행
        for j in range(cols):  # arr2의 열
            # arr1의 i번째 행과 arr2의 j번째 열의 각 원소를 곱해서 더함
            for k in range(len(arr2)):  # arr1의 열 = arr2의 행
                answer[i][j] += arr1[i][k] * arr2[k][j]
    
    return answer