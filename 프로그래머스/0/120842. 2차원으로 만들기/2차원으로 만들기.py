def solution(num_list, n):
    answer = []
    for i in range(0, len(num_list), n):
        tmp = num_list[i:i+n]
        answer.append(tmp)
        
    return answer