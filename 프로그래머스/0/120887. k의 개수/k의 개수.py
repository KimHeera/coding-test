def solution(i, j, k):
    answer = 0
    
    for i in range(i, j+1):
        st = str(i)
        
        for ch in st:
            if int(ch) == k:
                answer += 1
    return answer