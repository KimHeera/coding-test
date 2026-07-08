def solution(my_string):
    answer = ''
    chrs = ''
    for ch in my_string:
        if ch not in chrs:
            answer += ch
            chrs += ch
        
    return answer