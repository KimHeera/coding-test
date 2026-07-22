def solution(spell, dic):
    for word in dic:
        if all(c in word for c in spell):
            return 1
            
    return 2