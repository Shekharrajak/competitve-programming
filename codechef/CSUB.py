# cook your dish here
def main():
    from sys import stdin, stdout
    t = input()
    t = int(t)
    for line in range(0, t):
        n = stdin.readline()
        s= stdin.readline()
        c = s.count('1')
        res = int(c*(c+1)/2)
        print(res)
 
if __name__ == "__main__":
    main() 
    
