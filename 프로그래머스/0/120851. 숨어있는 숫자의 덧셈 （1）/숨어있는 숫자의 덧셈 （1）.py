def solution(my_string):
    answer = 0
    
    for ch in my_string:
        if ch.isdigit():
            answer += int(ch)
    return answer