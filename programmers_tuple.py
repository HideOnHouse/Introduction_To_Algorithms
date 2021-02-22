def solution(s):
    answer = []
    s = eval(s.replace("{", "[").replace("}", "]"))
    for i in sorted(s, key=lambda x: len(x)):
        for num in i:
            if num not in answer:
                answer.append(num)
    return answer


if __name__ == '__main__':
    print(solution("{{2},{2,1},{2,1,3},{2,1,3,4}}"))
    print(solution("{{1,2,3},{2,1},{1,2,4,3},{2}}"))
    print(solution("{{20,111},{111}}"))
    print(solution("{{123}}"))
    print(solution("{{4,2,3},{3},{2,3,4,1},{2,3}}"))
