import math
# gcd = 최대공약수 구하는 함수?

def solution(numer1, denom1, numer2, denom2):
    lcm = denom1 * denom2 // math.gcd(denom1, denom2)
    
    numer = numer1 * (lcm // denom1) + numer2 * (lcm // denom2)
    denom = lcm
    
    g = math.gcd(numer, denom)
    answer = [numer // g, denom // g]
    #denom1과 denom2의 최소공배수를 구한다. 그리고 각 값을 numer1과 numer2에 곱한다.
    
    # 구한 값들을 토대로 denom1 + denom2, numer1 + numer2 한 뒤, 약분한다.
    return answer