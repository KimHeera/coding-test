import math
def solution(n):
    answer = 0
    fac = 1
    while(1):
        if math.factorial(fac) > n:
            answer = fac - 1
            break
        fac += 1
    return answer