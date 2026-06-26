def solution(my_string):
    mo = {"a", "e", "i", "o", "u"}
    answer = ''
    
    for ch in my_string:
        if ch not in "aeiou":
            answer += ch
    return answer