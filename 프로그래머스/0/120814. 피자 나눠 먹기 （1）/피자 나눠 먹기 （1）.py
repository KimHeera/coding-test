def solution(n):
    answer = n // 7
    if(n%7 != 0):
        answer = answer + 1
    return answer