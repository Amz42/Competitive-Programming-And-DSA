# Question: https://codeforces.com/contest/1452/problem/A
# Solution: https://codeforces.com/contest/1452/submission/98903835

def main():
    tests = 1
    tests = int(input())
    for _ in range(tests):
        a,b = [int(x) for x in input().split(" ")]
        a,b = abs(a),abs(b);
        if a==b: print(2*a);
        else: print(2*max(a,b)-1);


if __name__ == "__main__":
    main()