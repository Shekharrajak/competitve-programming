def main():
    from sys import stdin, stdout
    t = int(input())
    for i in range(0, t):
        s = input()
        mid = (len(s) + 1) // 2
        first = ''.join(sorted(s[:mid - (len(s)%2)]))
        second = ''.join(sorted(s[mid:]))
        if first == second:
            print('YES')
        else:
            print('NO')
 
if __name__ == "__main__":
    main()
 
