# not completed
def totalValidPartition(str, t, n):
    totolCount = 0
    if len(str) == 0:
        totolCount = 0
    if str in t and len(str) != n:
        totolCount = 1
    for i in range(1, len(str)):
        s1 = str[0:i]
        s2 = str[i:len(str)]
        s1Count = totalValidPartition(s1, t, n)
        s2Count = totalValidPartition(s2, t, n)
        totolCount += s1Count*s2Count
        print(' str :' , str, ' :  s1 => ', s1, ' : s1count ' , s1Count, 
             ' : s2 => ', s2, ' ; s2Count => ', s2Count, ' ; totolCount => ', totolCount )
    return totolCount

def main():
    inputList = list(input().split())
    str = inputList[0]
    # print('str => ', str)
    n = int(inputList[1])
    t = []
    for i in range(n):
        s = input()
        t.append(s)
    # print('t => ', t)
    print(totalValidPartition(str, t, n))

if __name__ == "__main__":
    main()

