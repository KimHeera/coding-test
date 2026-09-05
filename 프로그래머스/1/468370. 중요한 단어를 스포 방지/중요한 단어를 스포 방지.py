def solution(message, spoiler_ranges):
    answer = 0
    
    words = []
    idx = 0
    
    for word in message.split():
        start = message.index(word, idx)
        end = start + len(word) - 1
        words.append((word, start, end))
        
        idx = end + 1
        
    spoiler_words = set()    # 스포일러 단어 집합
    non_spoiler_words = set() # 비스포 구간에 등장한 단어 집합
    seen = set()             # 이미 공개된 스포 단어
    
    for word, start, end in words:
        is_spoiler = False
        for s, e in spoiler_ranges:
            if start <= e and end >= s:  # 겹치면
                is_spoiler = True
                break
        
        if is_spoiler:
            spoiler_words.add((word, start))
        else:
            non_spoiler_words.add(word)
            
    for word, start in spoiler_words:
        if word not in non_spoiler_words and word not in seen:
            answer += 1
            seen.add(word)
    return answer