import math

def solution(sides):
    answer = 1
    sides = sorted(sides)
    
    if sides[0] + sides[1] <= sides[2]:
        answer = 2
    return answer