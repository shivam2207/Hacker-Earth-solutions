import random
n=1000
f1=open("testcase","wb")
f1.write(str(n)+"\n")
for x in range(n):
	f1.write(str(random.randint(1,100000))+"\n")