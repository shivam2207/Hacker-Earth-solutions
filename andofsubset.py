import sys
t = input()
i = 1
while (i<=t):
	N = input()
	l = map(int,raw_input().split(' '))
	flag = 0
	for j in range(0,32):
		num = 1<<j
		res = 1<<32
		res -=1 
		#print res
		for k in l:
			if k & num !=0:
				res = res & k
		if res == num:
			#print res
			flag = 1
			print 'YES'
			break
	if flag==0:
		print 'NO'
	i+=1
		
