def solution(board, moves):
    answer = 0
    st = []
    
    for i in moves:
        for j in range(len(board)):
            if board[j][i-1] != 0:
                if len(st) != 0 and st[-1] == board[j][i-1]:
                    st.pop()
                    board[j][i-1] = 0
                    answer += 2
                else:
                    st.append(board[j][i-1])
                    board[j][i-1] = 0
                break
    
    return answer