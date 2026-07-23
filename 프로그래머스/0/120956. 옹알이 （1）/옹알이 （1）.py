def solution(babbling):
    baleum = ["aya", "ye", "woo", "ma"]
    answer = 0
    
    for word in babbling:
        for sound in baleum:
            word = word.replace(sound, " ", 1)
            
        if " ".join(word.split()) == "":
            answer += 1
    return answer