import math

def solution(n):
    answer = n // 6
    if(n % 6 != 0):
        answer = 6 * n // math.gcd(6, n) / 6
    
    return answer