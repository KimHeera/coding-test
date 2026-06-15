def solution(n, k):
    service = n // 10
    answer = n * 12000 + (k - service) * 2000
    
    return answer