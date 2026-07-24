from collections import deque
def solution(maps):
    n, m = len(maps), len(maps[0])
    directions = [[0,1], [1,0], [0, -1], [-1, 0]]
    answer = -1
    
    visited = [[False]*m for _ in range(n)]
    visited[0][0] = True
    queue = deque([(0, 0, 1)]) # 행, 열, 거리

    while(queue):
        r, c, dist = queue.popleft()
                   
        if r == n-1 and c == m-1:
            return dist

        for dr, dc in directions:
            nr = r + dr
            nc = c + dc
            
            if 0 <= nr < n and 0 <= nc < m and maps[nr][nc] == 1 and visited[nr][nc] == False:
                   visited[nr][nc] = True
                   queue.append((nr, nc, dist+1))
        
    return answer