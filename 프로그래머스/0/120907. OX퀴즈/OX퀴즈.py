def solution(quiz):
    answer = []
    
    for question in quiz:
        inst = question.split()
        result = 0
        
        if inst[1] == "+":
            result = int(inst[0]) + int(inst[2])
        else:
            result = int(inst[0]) - int(inst[2])
        
        if(result == int(inst[4])):
            answer.append("O")
        else:
            answer.append("X")
    return answer