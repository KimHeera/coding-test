def solution(n):
    answer = 0
    
    for i in range(n+1):
        tmp = 0 
        for j in range(1, i+1):
            if (i % j == 0):
                tmp +=1
            
        if tmp >= 3:
            answer += 1
                
    return answer