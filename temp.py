def fib(n):
	a=0
	b=1
	total=1
	for i in range(1,n-1):
		c=a+b
		c=c%10000
		a=b
		b=c
		total=(total+c)%1000000007
	print total

t=10
while(t>0):
	t=t-1
	n=input()
	fib(n)
