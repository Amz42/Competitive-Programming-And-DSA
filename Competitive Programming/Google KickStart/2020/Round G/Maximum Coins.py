g = 1
for _ in range(int(input())):
    n = int(input())
    l = []
    for i in range(n):
        l.append([int(x) for x in input().split(" ")])
    
    answer = []
    
    for i in range(n):
        x,y = 0,i
        ans = 0
        while(x<n and y<n):
            ans += l[x][y]
            x+=1
            y+=1
        answer.append(ans)
    
    for i in range(n):
        x,y = i,0
        ans = 0
        while(x<n and y<n):
            ans += l[x][y]
            x+=1
            y+=1
        answer.append(ans)
    
    print("Case #",g,": ",max(answer), sep="")
    g+=1