def solution(board):
    direction = [[-1, 0], [-1, 1], [0, 1], [1, 1],
                 [1, 0], [1, -1], [0, -1], [-1, -1]]
    answer = 0
    
    for i in range(len(board)):
        for j in range(len(board)):
            current = board[i][j]
            
            if current == 1:
                for k in range(len(direction)):
                    nexti = i + direction[k][0]
                    nextj = j + direction[k][1]
                    
                    if -1 < nexti < len(board) and -1 < nextj < len(board):
                        if board[nexti][nextj] != 1 and board[nexti][nextj] == 0:
                            board[nexti][nextj] = 2
    
    for i in range(len(board)):
        for j in range(len(board)):
            if board[i][j] == 0:
                answer += 1
    return answer