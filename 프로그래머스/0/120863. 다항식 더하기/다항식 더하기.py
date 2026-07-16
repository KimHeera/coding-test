def solution(polynomial):
    answer = ''
    alpha = 0
    num = 0
    
    inst = polynomial.split()
    
    for ch in inst:
        if ch.isdigit():
            num += int(ch)
        else:
            if ch == "+":
                continue
            ch = ch.replace("x", "")
            alpha += int(ch) if ch else 1
        
    if alpha > 0:
        if alpha == 1:
            answer = "x"
        else:
            answer = str(alpha) + "x"
        
    if num > 0:
        if alpha >0:
            answer += " + " + str(num)
        else:
            answer = str(num)
    return answer