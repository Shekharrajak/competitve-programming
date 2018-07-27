class Stack:
    def __init__(self):
        self.stack = []
    
    def push(self, el):
        self.stack.append(el)
    
    def pop(self):
        return self.stack.pop()
    
    def isEmpty(self):
        # print('len(self.stack) == 0 => ', len(self.stack) == 0)
        return (len(self.stack) == 0)
    
    def top(self):
        if len(self.stack) > 0:
            return self.stack[-1]
        else:
            raise Exception('no element in stack')

def main():
    while(True):
        n = int(input())
        #print(' n => ', n)
        if n == 0:
            #print(' n is 0')
            break
            return
        a = list(map(int, input().split()))
        # a_sorted = sorted(a)
        # print(('a => {}, a_sorted => {}').format(a, a_sorted))
        j = 0
        stack = Stack()
        need = 1
        can = True
        for i in range(n):
            if a[i] == need:
                # print('a[i] ', a[i])
                need += 1
            elif stack.isEmpty() == True:
                stack.push(a[i])
            elif stack.top() > a[i]:
                stack.push(a[i])
                # print('stack => ', stack.stack)
            else:
                while stack.isEmpty() == False and stack.top() < a[i]:
                    p = stack.pop()
                    if need != p:
                        break
                    # else:
                    # print('stack.pop, ', p)
                    need += 1
                stack.push(a[i])
                #  stack itself must be ordered
        while stack.isEmpty() == False:
            p = stack.pop()
            # print('stack.pop, ', p)
            need += 1
            
        # print('need ', need)
        if(need-1 == n):
            print('yes')
        else:
            print('no')
        
if __name__ == "__main__":
    main() 

# 6
# 5 1 2 3 4 6
# 3
# 1 2 3
# 5
# 5 4 1 2 3
# 5
# 5 1 3 2 4
# 5
# 5 3 1 4 2
# 0

# yes
# yes
# yes
# yes
# no
