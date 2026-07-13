def solution(my_string):
    inst = my_string.split()
    answer = int(inst[0])
    for i in range(1, len(inst), 2):  # 연산자는 홀수 인덱스
        if inst[i] == "+":
            answer += int(inst[i+1])
        else:
            answer -= int(inst[i+1])
    return answer