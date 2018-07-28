
def main():
    n = int(input())
    a = list(map(int, input().split()))
    m = int(input())
    c = list(map(int, input().split()))
    b = set()
    for i in range(0, m):
        for j in range(0, n):
            e = c[i] - a[j]
            add = True
            for k in range(0, n):
                if (e + a[k] not in c):
                    # print('for e ', e, ' : e + a[k]', e + a[k], ' is presnt in c ', c)
                    add = False
            if (add and (e > 0)):
                b.add(e)
    print(*b)

if __name__ == "__main__":
    main()
