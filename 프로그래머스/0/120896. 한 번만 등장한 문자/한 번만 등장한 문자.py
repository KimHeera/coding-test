from collections import Counter
def solution(s):
    cnt = Counter(s)
    answer = ""
    for char, count in cnt.items():
        if count == 1:
            answer += char
    
    answer = "".join(sorted(answer))
    return answer