import math

def solution(array, n):
    array = sorted(array)
    
    cha = abs(array[0] - n)
    answer = array[0]
    for i in array:
        if cha > abs(i - n):
            cha = abs(i - n)
            answer = i
    
    return answer