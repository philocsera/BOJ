N = int(input())
list = input().split()
rslt = 0
v = input()
for i in range(0,N):
	if(list[i] == v):
		rslt+=1
print(rslt)
