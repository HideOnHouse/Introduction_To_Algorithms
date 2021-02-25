def solution(n, words):
    answer = [0, 0]
    used = set()
    post = words[0][0]
    for i in words:
        if i[0] != post or i in used:
            answer[0] += 1
            answer[1] = answer[1] // n + 1
            return answer
        else:
            post = i[-1]
            used.add(i)
            answer[0] = (answer[0] + 1) % n
            answer[1] += 1
    return [0, 0]


if __name__ == '__main__':
    print(solution(3, ['tank', 'kick', 'know', 'wheel', 'land', 'dream', 'mother', 'robot', 'tank']))
    print(solution(5,
                   ['hello', 'observe', 'effect', 'take', 'either', 'recognize', 'encourage', 'ensure', 'establish',
                    'hang', 'gather', 'refer',
                    'reference', 'estimate', 'executive']))
    print(solution(2, ['hello', 'one', 'even', 'never', 'now', 'world', 'draw']))
