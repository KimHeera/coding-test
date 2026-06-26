def solution(my_string):
    answer = []
    
    for ch in my_string:
        if ch in "1234567890":
            answer.append(int(ch))
            
    answer = sorted(answer)
    return answer