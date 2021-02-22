import re


def solution(expression):
    answer = []
    for prior in ["*+-", "*-+", "+*-", "+-*", "-+*", "-*+"]:
        temp = re.split('([+-/*])', expression)
        for operator in prior:
            for _ in range(temp.count(operator)):
                operator_idx = temp.index(operator)
                temp[operator_idx] = str(eval(temp[operator_idx - 1] + temp[operator_idx] + temp[operator_idx + 1]))
                temp.pop(operator_idx - 1)
                temp.pop(operator_idx)
        answer.append(abs(int(temp[0])))
    return max(answer)


if __name__ == '__main__':
    print(solution("100-200*300-500+20"))
    print(solution("50*6-3*2"))
    print(solution("1000"))
    print(solution("2-990-5+2"))
    print(solution("2-990-5+2+3*2"))
    print(solution("0*1+3"))
