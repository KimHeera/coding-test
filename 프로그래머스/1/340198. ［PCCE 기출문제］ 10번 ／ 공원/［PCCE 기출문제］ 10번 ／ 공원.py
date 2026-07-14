def solution(mats, park):
    mats = sorted(mats, reverse=True)
    
    for size in mats:
        for r in range(len(park) - size + 1):
            for c in range(len(park[r]) - size + 1):
                possible = True
                for dr in range(size):
                    for dc in range(size):
                        if park[r+dr][c+dc] != "-1":
                            possible = False
                    if not possible:
                        break
                if possible:
                    return size
    
    return -1