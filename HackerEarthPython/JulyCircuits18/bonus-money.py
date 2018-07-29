
# not completed
def canKPartition(sanskars, used, todo, target):
    memo = [None]*(1 << len(sanskars))
    memo[-1] = True
    
    def search(used, todo):
        if memo[used] is None:
            targ = (todo - 1)%target + 1
            print(('used: {}, todo: {}, targ: {}').format(used, todo, targ))
            found = False
            for i, num in enumerate(sanskars):
                if(((used >> i & 1) == 0) and (num <= targ)):
                    if(search(used | (1 << i) , todo-num)):
                        print(('used: {}, todo: {}, targ: {}, found').format(used, todo, targ))
                        found = True
            memo[used] = found
            # memo[used] = any(
            #     search(used | (1 << i), todo-num)
            #         for i, num in enumerate(sanskars)
            #         if ((used >> i & 1 == 0) and num <= targ)
            # )
        return memo[used]
    return search(used, todo)

def divideSanskar(sanskars, n, k):
    print(('sanskars: {}, n: {}, k: {}').format(sanskars, n, k)) 
    target, rem = divmod(sum(sanskars), k)
    if(rem):
        return False
    return canKPartition(sanskars, 0, target*k, target)

def main():
    t = int(input())
    for i in range(t):
        n, k = map(int, input().split())
        sanskars = list(map(int, input().split()))
        print(divideSanskar(sanskars, n, k))

if __name__ == "__main__":
    main()
