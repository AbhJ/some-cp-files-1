printer=1
def prin():
    global printer
    s="Case #"+str(printer)+":"
    print s,
    printer+=1
for _ in range(input()):
    n=input()
    a=[int(i) for i in raw_input().split()]
    prin()
    bam_hat=[2 for i in range(n)]
    dan_hat=[2 for i in range(n)]
	dan_hat[-1]=1
    bam_hat[0]=1
    bam_hat[1]=2
    dan_hat[-2]=2
    if n<=3:
        print n
        continue
    for i in range(1,n-1):
        if a[i]-a[i-1]==a[i+1]-a[i]:
            bam_hat[i+1]=bam_hat[i]+1
    for i in range(n-2,0,-1):
        if a[i]-a[i-1]==a[i+1]-a[i]:
            dan_hat[i-1]=dan_hat[i]+1
    value=max(bam_hat[-1],dan_hat[0],bam_hat[-2]+1,dan_hat[1]+1)
    for i in range(1,n-1):
        if i == 1:
            if a[i+1]-a[i-1]==2*(a[i+2]-a[i+1]):
                value=max(value,dan_hat[2]+2)
            else:
                value=max(value,dan_hat[2]+1)
        elif i != n-2:
			 if a[i+1]-a[i-1]==2*(a[i+2]-a[i+1]):
                value=max(value,dan_hat[i+1]+2)
            if a[i+1]-a[i-1]==2*(a[i-1]-a[i-2]):
                value=max(value,bam_hat[i-1]+2)
            value=max(value,max(dan_hat[i+1], bam_hat[i - 1]) +1)
            if a[i+1]-a[i-1]==2*(a[i+2]-a[i+1]) and a[i+1]-a[i-1]==2*(a[i-1]-a[i-2]):
                value=max(value,dan_hat[i+1]+bam_hat[i-1]+1)
        else:
            if a[i+1]-a[i-1]==2*(a[i-1]-a[i-2]):
                value=max(value,bam_hat[n-3]+2)
            else:
                value=max(value,bam_hat[n-3]+1)
    print value