def solution(n):
    answer = set()
    soinsu = 2
    while(n > 1):
        if n % soinsu == 0:
            n = n // soinsu
            answer.add(soinsu)
        else:
            soinsu += 1
    
    answer = sorted(answer)
    return answer