def solution(price):
    discount = 0
    
    if price >= 500000:
        discount = price * 20 / 100
    elif price >= 300000:
        discount = price * 10 / 100
    elif price >= 100000:
        discount = price * 5 / 100
        
    answer = int(price - discount)
    return answer