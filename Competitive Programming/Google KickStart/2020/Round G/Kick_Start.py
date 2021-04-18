g=1
for _ in range(int(input())):
    s = input()
    kick = 0
    ans = 0
    n = len(s)
    for i in range(n):
        if i+3<n and s[i]+s[i+1]+s[i+2]+s[i+3]=="KICK":          kick+=1;
        if i+4<n and s[i]+s[i+1]+s[i+2]+s[i+3]+s[i+4]=="START":  ans+=kick;
    
    print("Case #",g,": ",ans, sep="")
    g+=1