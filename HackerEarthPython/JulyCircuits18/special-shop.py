
def main():
    t = int(input())
    for i in range(0, t):
        n, a, b = map(int, input().split())
        minY = round((n*a)/(a+b))
        # print('minY', minY)
        minX = n - minY
        # print('minX', minX)
        print(pow(minX, 2)*a + pow(minY, 2)*b)

if __name__ == "__main__":
    main()
    
