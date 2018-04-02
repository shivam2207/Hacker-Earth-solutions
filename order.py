n = input()
calling = map(int,raw_input().split(' '))
ideal = map(int,raw_input().split(' '))
count = 0
while (len(calling)!=0):
	ind = ideal.index(calling[0])
	print 'ind: ', ind 
	for j in range(0,ind):
		t = calling[j]
		del calling[j]
		calling.append(t)
		count += 1
	print calling
	del calling[0]
	count +=1
	print calling
print count
