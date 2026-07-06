def solution(s):
    answer = 0
    slist = s.split(" ")
    tmp = 0
    for i in slist:
        if(i.isalpha()):
            answer -= tmp
        else:
            tmp = int(i)
            answer += tmp
        
    return answer
