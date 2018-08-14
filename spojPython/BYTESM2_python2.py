def getMaxStone(tiles, w, h):
    dp = [[None for k in range(w)] for q in range(h)]
    for i in range(h):
        for j in range(w):
            if i == 0:
                dp[i][j] = tiles[i][j]
            else:
                prevColn = j-1 if (j-1 >= 0) else j
                nextColn = j + 1 if (j+1 <= w - 1) else j
                dp[i][j] = max(max(dp[i-1][prevColn], dp[i-1][j]), dp[i-1][nextColn]) + tiles[i][j]
    # print(dp)
    return max(dp[h-1])

def main():
    t = raw_input().strip()
    t = int(t)
    for i in range(t):
        h, w = raw_input().strip().split(" ")
        h = int(h)
        w = int(w)
        tiles = [[None for k in range(w)] for q in range(h)]
        # print('tiles => ' )
        # print(tiles)
        for j in range(h):
            str = raw_input().strip()
            tiles[j] = list(map(int, str.split(" ")))
        # print('tiles => ' )
        # print(tiles)
        print(getMaxStone(tiles, w, h))

if __name__== "__main__":
    main()
