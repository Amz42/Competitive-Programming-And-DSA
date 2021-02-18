# Question: https://codeforces.com/contest/1440/problem/A
# Solution: https://codeforces.com/contest/1440/submission/98693550

def main():
    tests = int(input())
    for _ in range(tests):
        n, c0, c1, xx = [int(x) for x in input().split(" ")]
        s = input()
        ll = list(s)
        zero, one = ll.count('0'), ll.count('1')
        
        if(c0==c1): print(n*c0);
        elif(c1>c0):
            if(xx+c0<c1): print(one*(xx+c0)+ zero*c0);
            else: print(one*c1 + zero*c0);
        else:
            if(xx+c1<c0): print(zero*(xx+c1)+one*c1);
            else: print(one*c1 + zero*c0);

if __name__ == "__main__":
    main()