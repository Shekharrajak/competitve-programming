def getMaxMoney():
    n = int(input())
    a = []
    for i in range(n):
        a.append(int(input()))
    done = [False for i in range(n)]
    ans = 0
    start = 0
    end = n - 1
    # print(("n => {}, a => {}, done => {}").format(n, a, done))
    for i, v in enumerate(a):
        if a[start] < a[end] and done[start] == False and start < n:
            done[start] = True
            ans += a[start]*(i+1)
            start = start + 1
        else:
            done[end] = True
            ans += a[end]*(i+1)
            end = end - 1
    print(ans)
if __name__ == '__main__':
    getMaxMoney()
