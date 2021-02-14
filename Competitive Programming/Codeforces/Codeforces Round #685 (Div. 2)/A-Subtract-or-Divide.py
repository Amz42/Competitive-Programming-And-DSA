# Question: https://codeforces.com/contest/1451/problem/A
# Solution: https://codeforces.com/contest/1451/submission/99124800

def main():
    test = 1
    test = int(input().strip(" "))
    for _ in range(test):
        n = int(input().strip(" "))
        if n>3 and n%2:
            print(3)
        if n>3 and n%2==0: 
            print(2)
        if n==1: print(0)
        if n==2: print(1)
        if n==3: print(2)


if __name__ == "__main__":
    main()