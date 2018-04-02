n = input()
l = []
skip = []
for i in range(n):
	name = raw_input()
	name = name.strip('\n')
	l.append(name)
for i in range(n-1):
	for j in range(i+1,n):
		if l[i] not in skip:
			if l[i][0] == l[j][0] and len(l[i]) == len(l[j]):
				if l[i][len(l[i])-1] == l[j][len(l[i])-1]:
					l1 = list(l[i])
					l1.sort()
					l2 = list(l[j])
					l2.sort()
					if(l1 == l2):
						skip.append(l[j])
print n-len(skip)