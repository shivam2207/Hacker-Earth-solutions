def func(n):
	sol=2*n
	for i in range(1,n+1):
		temp=max(i*(i+1)/2,n-i)+n-i
		sol=min(sol,temp)
	return sol
t=input()
while(t):
	n=input()
	print func(n)
	t=t-1
