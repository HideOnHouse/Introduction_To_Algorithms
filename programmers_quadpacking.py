def compress(arr, x, y, n, answer):
    init = arr[x][y]
    for i in range(x, x + n):
        for j in range(y, y + n):
            if arr[i][j] != init:
                new_n = n // 2
                compress(arr, x, y, new_n, answer)
                compress(arr, x, y + new_n, new_n, answer)
                compress(arr, x + new_n, y, new_n, answer)
                compress(arr, x + new_n, y + new_n, new_n, answer)
                return
    answer[init] += 1


def solution(arr):
    answer = [0, 0]
    n = len(arr)
    compress(arr, 0, 0, n, answer)
    return answer


if __name__ == '__main__':
    solution([[1, 1, 0, 0], [1, 0, 0, 0], [1, 0, 0, 1], [1, 1, 1, 1]])
    solution([[1, 1, 1, 1, 1, 1, 1, 1], [0, 1, 1, 1, 1, 1, 1, 1], [0, 0, 0, 0, 1, 1, 1, 1], [0, 1, 0, 0, 1, 1, 1, 1],
              [0, 0, 0, 0, 0, 0, 1, 1], [0, 0, 0, 0, 0, 0, 0, 1], [0, 0, 0, 0, 1, 0, 0, 1], [0, 0, 0, 0, 1, 1, 1, 1]])
