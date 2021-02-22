from itertools import combinations


def solution(land):
    for i in range(len(land) - 1):
        for idx, p in enumerate(combinations((0, 1, 2, 3), 3)):
            land[i + 1][3 - idx] += max(land[i][p[0]], land[i][p[1]], land[i][p[2]])
    answer = max(land[-1])
    return answer


if __name__ == '__main__':
    print(solution([[1, 2, 3, 5], [5, 6, 7, 8], [4, 3, 2, 1]]))
    print(solution([[1, 2, 3, 5], [5, 6, 7, 100], [4, 3, 2, 1]]))
