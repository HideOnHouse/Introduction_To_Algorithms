from itertools import permutations

if __name__ == '__main__':
    for i in permutations("고노무현대통령", 7):
        temp = "".join(i)
        if "고무통" in temp:
            print(temp)