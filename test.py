import sys

def dig(c):
	for i in '0123456789':
		if c == i:
			return int(c)
	return ord(c) - 55

def cvrt(B,s):
	ans = 0;
	n = len(s)
	for i in range(n):
		#print(dig(s[n-1-i]))
		ans += dig(s[n-i-1])*(B**i)
	return ans
#print(cvrt(26,'ZA'))
T = int(input())

for t in range(T):
	N = int(input())
	num = []
	for i in range(N):
		z = input()
		B,s = int(z.split()[0]),z.split()[1]
		num.append((B,s))
	mega = {}
	for i in num:
		#print(i[1])
		if(i[0]==-1):
			mx = 1
			for j in i[1]:
				if(mx < dig(j)):
					mx = dig(j)
			#print(mx)
			rep = []
			for j in range(mx+1,37):
				p = cvrt(j,i[1])
				if(p>10**12):
					continue
				#print(p)
				if p in rep:
					continue
				else:
					rep.append(p)
				#print(p)
				if(mega.get(p) == None):
					mega[p] = 1
				else:
					mega[p] += 1
		else:
			p = cvrt(i[0],i[1])
			if(p>10**12):
				continue
			if(mega.get(p) == None):
				mega[p] = 1
			else:
				mega[p] += 1
	res = []
	for i in mega.items():
		#print(i)
		if(i[1]==N):
			res.append(i[0])
	if len(res)!=0:
		print(min(res))
	else:
		print(-1)
	sys.stdout.flush()
		