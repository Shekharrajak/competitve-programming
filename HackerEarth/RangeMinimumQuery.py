segTree = [None]*(2*pow(10,6) + 1)

def buildTree(node, start, end, a):
    if(start == end):
        segTree[node] = a[start]
    else:
        mid = (start + end) // 2
        buildTree(2*node, start, mid, a)
        buildTree(2*node + 1, mid + 1, end, a)
        segTree[node] = min(segTree[2*node], segTree[2*node + 1])
    
def query(node, start, end, l, r):
    if start == end :
        return segTree[node]
    if (l == start and end == r):
        # print('l == start and end == r : ', l ,'  :  ', r)
        return segTree[node]
    mid = (start + end) // 2
    if (start <= l and r <= mid):
        # print(' 1 => l ', l, ' : r ', r, ' , start ' , start, ' , end ', end )
        return query(2*node, start, mid, l, r)
    elif (mid < l and r <= end ):
        # print(' 2 => l ', l, ' : r ', r, ' , start ' , start, ' , end ', end )
        return query(2*node + 1, mid+1, end, l, r)
    else:
        # print(' 3 => l ', l, ' : r ', r, ' , start ' , start, ' , end ', end )
        return min(query(2*node, start, mid, l, mid), query(2*node + 1, mid+1, end, mid+1, r))

def update(node , start, end, idx, val, a):
    if start == end:
        a[idx] = val
        segTree[node] = val
    else:
        mid = (start + end) // 2
        if (start <= idx and idx <= mid):
            # print(' 1 => l ', l, ' : r ', r, ' , start ' , start, ' , end ', end )
            update(2*node, start, mid, idx, val, a)
        elif (mid < idx and idx <= end ):
            # print(' 2 => l ', l, ' : r ', r, ' , start ' , start, ' , end ', end )
            update(2*node + 1, mid+1, end, idx, val, a)
        segTree[node] = min(segTree[2*node] , segTree[2*node + 1])

def main():
    n, q = map(int, input().split())
    a = list(map(int, input().split()))
    buildTree(1, 0, n-1, a)
    # print('segTree , ' , segTree)
    for i in range(0, q):
        inp = list(input().split())
        if inp[0] == 'q':
            print(query(1, 0, n-1, int(inp[1]) - 1, int(inp[2]) - 1))
        elif inp[0] == 'u':
            update(1, 0, n-1, int(inp[1]) - 1, int(inp[2]), a)
            # print('a => ,', a)

if __name__ == "__main__":
    main()

##############################
# 5 5
# 1 5 2 4 3
# q 1 5
# q 1 3
# q 3 5
# u 3 6
# q 1 5
#
# output
# 1
# 1
# 2
# 1
