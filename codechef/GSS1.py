class SegmentTree:
    def __init__(self):
        self.totalSum = None
        self.maxPrefixSum = None
        self.maxSuffixSum = None
        self.maxSubarraySum = None
    def toString(self):
        return (str(self.maxPrefixSum) + ' : ' + str(self.maxSuffixSum) + ' : ' + 
                str(self.totalSum) + ' : ' + 
                str(self.maxSubarraySum))

def mergeNode(tree, leftNode, rightNode):
    # print(('leftNode=> {}, rightNode=> {}, parent => {}, parentnode => {}').format(
    #  tree[leftNode].toString(), tree[rightNode].toString(), rightNode//2, tree[rightNode//2].toString()))
    
    tree[rightNode//2].totalSum = tree[leftNode].totalSum + tree[rightNode].totalSum
    tree[rightNode//2].maxPrefixSum = max(
        tree[leftNode].maxPrefixSum, tree[leftNode].totalSum + tree[rightNode].maxPrefixSum)
    tree[rightNode//2].maxSuffixSum = max(
        tree[leftNode].maxSuffixSum + tree[rightNode].maxPrefixSum, tree[rightNode].maxSuffixSum)
    maxPreSuf = max(tree[leftNode].maxPrefixSum, tree[rightNode].maxSuffixSum)
    tree[rightNode//2].maxSubarraySum = max(
        max(tree[leftNode].maxSuffixSum, tree[rightNode].maxPrefixSum), maxPreSuf
    )
    # print(('leftNode=> {}, rightNode=> {}, parent => {}, parentnode => {}').format(
    #  tree[leftNode].toString(), tree[rightNode].toString(), rightNode//2, tree[rightNode//2].toString()))
    return tree

def mergeNodeQuery(tree, leftNode, rightNode):
    paparentnode = SegmentTree()
    paparentnode.totalSum = leftNode.totalSum + rightNode.totalSum
    paparentnode.maxPrefixSum = max(
        leftNode.maxPrefixSum, leftNode.totalSum + rightNode.maxPrefixSum)
    paparentnode.maxSuffixSum = max(
        leftNode.maxSuffixSum + rightNode.maxPrefixSum, leftNode.maxSuffixSum)
    maxPreSuf = max(leftNode.maxPrefixSum, rightNode.maxSuffixSum)
    paparentnode.maxSubarraySum = max(
        max(leftNode.maxSuffixSum, rightNode.maxPrefixSum), maxPreSuf
    )
    # print(('leftNode=> {}, rightNode=> {}, parent => {}, parentnode => {}').format(
    #  tree[leftNode].toString(), tree[rightNode].toString(), rightNode//2, tree[rightNode//2].toString()))
    return paparentnode

def buildSegmentTree(tree, a, n, start, end, index):
    if (start == end):
        tree[index].totalSum = a[start]
        tree[index].maxSubarraySum = a[start]
        tree[index].maxPrefixSum = a[start]
        tree[index].maxSuffixSum = a[start]
        # print(('index => {} , tree[index] => {}, start => {}, end=> {}').format(
        # index, tree[index].toString(), end, end))
        return tree
    mid = (start + end)//2
    # print(('start => {}, mid=> {}').format(
    #  start, mid))
    tree = buildSegmentTree(tree, a, n, start, mid, 2*index)
    # print(('2*index => {}, mid=> {}, tree[2*index] => {}').format(
    #  2*index, mid, tree[2*index].toString()))
    tree = buildSegmentTree(tree, a, n, mid+1, end, 2*index + 1)
    # print(('2*index+1 => {}, mid=> {}, tree[2*index+1] => {}').format(
    #  2*index+1, mid, tree[2*index+1].toString()))
    tree = mergeNode(tree, 2*index, 2*index+1)
    return tree

def querySegmentTree(segTree, x, y, start, end, index):
    if (x > end or y < start):
        print(('null => x => {}, y => {},start => {}, end=> {}, index => {}').format(
        x, y, start, end, index))
        return SegmentTree()
    if (x <= start and y >= end):
        print(('x => {}, y => {},start => {}, end=> {}, index => {}').format(
        x, y, start, end, index))
        return segTree[index]
    else:
        mid = (start + end)//2
        leftNode = querySegmentTree(segTree, x, y, start, mid, 2*index)
        rightNode = querySegmentTree(segTree, x, y, mid+1, end, 2*index + 1)
        segTree = mergeNodeQuery(segTree, leftNode, rightNode)
        return segTree[index]

def getMaxSubarraySum(a, n, x, y):
    import math
    height = math.ceil(math.log(n, 2))
    maxLen = 2*pow(2,height) - 1
    segTree = [SegmentTree() for i in range(maxLen)]
    # print(('height => {}, maxLen => {}, segTree => {}').format(height, maxLen, segTree))
    segTree = buildSegmentTree(segTree, a, n, 0, n-1, 1)
    for i in range(1,maxLen):
        print(segTree[i].toString(), end="\n")
    resNode = querySegmentTree(segTree, x-1, y-1, 0, n-1, 1)
    return resNode.maxSubarraySum

def main():
    from sys import stdin, stdout 
    n = int(stdin.readline())
    a = list(map(int, stdin.readline().split()))
    m = int(stdin.readline())
    for i in range(m):
        x, y = map(int, stdin.readline().split())
        print(getMaxSubarraySum(a, n, x, y))

if __name__ == "__main__":
    main()
