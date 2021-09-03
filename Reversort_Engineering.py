def createL(n):
    v = []
    for i in range(1,n+1):
        v.append(i)
    return v

def operationL(n, c):
    if c < n-1:
        return []
    v = []
    koita = 0
    taka = 1
    for i in range(n-1, 0, -1):
        taka += 1

        if koita+taka+i-1 >= c:
            r = c-koita-i+1
            v.append(r)
            for k in range(i-1):
                v.append(1)
            koita = c
            break

        koita += taka
        v.append(taka)
    if koita<c:
        return []
    return v

def operate(v, tmp):
    length = len(tmp)
    for i in range(length):
        t = len(v)-(i+2)
        sp = t+tmp[i]
        v = v[:t]+ list(reversed(v[t:sp])) + v[sp:]
    return v

def solve():
    inp = input().split()
    n = int(inp[0])
    p = int(inp[1])
    v = createL(n)
    tmp = operationL(n,p)
    v = operate(v, tmp)
    result = ""
    if tmp:
        for item in v:
            result += str(item)+ " "
    else:
        result =" IMPOSSIBLE"
    print("Case #"+str(i+1)+": "+ str(result))

for i in range(int(input())):
    solve()