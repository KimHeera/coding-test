def solution(numbers):
    max1 = numbers[0]
    max2 = numbers[1]
    
    for i in numbers:
        if i > max1:
            max2 = max1
            max1 = i
        elif i < max1 and i > max2:
            max2 = i
            
    answer = max1 * max2
    return answer