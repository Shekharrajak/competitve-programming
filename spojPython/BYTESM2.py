def getMaxStone(tiles, w, h):
    dp = [[None for k in range(w)] for q in range(h)]
    for i in range(h):
        for j in range(w):
            if i == 0:
                dp[i][j] = tiles[i][j]
            else:
                prevColn = j - 1 if (j-1 >= 0) else j
                nextColn = j + 1 if (j+1 <= w - 1) else j
                dp[i][j] = max(max(dp[i-1][prevColn], dp[i-1][j]), dp[i-1][nextColn]) + tiles[i][j]
    # print(dp[h-1])
    return max(dp[h-1])

def main():
    t = int(raw_input())
    for i in range(t):
        h, w = map(int, raw_input().split())
        tiles = [[None for k in range(w)] for q in range(h)]
        # print('tiles => ' )
        # print(tiles)
        for j in range(h):
            tiles[j] = list(map(int, raw_input().split()))
        # print('tiles => ' )
        # print(tiles)
        print(getMaxStone(tiles, w, h))

if __name__== "__main__":
    main()


# input:
# 2
# 6 5
# 3 1 7 4 2
# 2 1 3 1 1
# 1 2 2 1 8
# 2 2 1 5 3
# 2 1 4 4 4
# 5 2 7 5 1
# 3 3
# 12 11 54
# 1 2 3
# 99 1 1

# output : 
# 32
# 155
