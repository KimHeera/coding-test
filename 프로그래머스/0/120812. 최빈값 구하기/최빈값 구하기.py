from collections import Counter

def solution(array):
    counter = Counter(array)
    answer = counter.most_common()
    if len(answer) >= 2 and answer[0][1] == answer[1][1]:
        return -1
    return answer[0][0]