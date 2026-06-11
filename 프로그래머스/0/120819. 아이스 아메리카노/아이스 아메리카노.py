def solution(money):
    cup = money // 5500
    answer = [cup, money - (cup * 5500)]
    
    return answer