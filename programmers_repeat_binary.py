def solution(s):
    answer = [0, 0]
    while s != '1':
        answer[1] += s.count("0")
        s = s.replace("0", "")
        answer[0] += 1
        s = bin(len(s))[2:]
    return answer


if __name__ == '__main__':
    print(solution("110010101001"))
