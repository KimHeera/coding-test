import math

def solution(a, b):
    def soinsu(num):
        nums = set()
        
        i = 2
        while num != 1:
            if num % i == 0:
                nums.add(i)
                num //= i
            else:
                i += 1
        return nums
    
    num = math.gcd(a, b)
    up = a // num
    down = b // num
    
    if down == 1:
        return 1
    
    nums = soinsu(down)
    if nums.issubset({2, 5}):
        return 1
    
    return 2