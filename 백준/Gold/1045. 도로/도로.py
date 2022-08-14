import sys
import heapq
N, M = map(int, sys.stdin.readline().split())

heap_lst = []
for i in range(N):
    city_i = list(sys.stdin.readline().rstrip())
    for j in range(i+1, N):
        if city_i[j] == 'Y':
            heapq.heappush(heap_lst, (i, j))

origin = [i for i in range(N)]

def _find(city): 
    if origin[city] == city :
        return city
    else :
        origin[city] = _find(origin[city]) 
        return origin[city]

def union(city1, city2):
	origin1, origin2 = _find(city1), _find(city2)
	if origin1 == origin2 : 
		return False
	else:
		origin[origin1] = origin2
		return True

if len(heap_lst)<M: 
    print(-1)
    exit()
ans = [0 for _ in range(N)]
cnt = 0
heap_lst2 = []

while heap_lst:
    city1, city2 = heapq.heappop(heap_lst)
    if union(city1, city2):
        ans[city1] += 1
        ans[city2] += 1
        cnt += 1
    else:
        heapq.heappush(heap_lst2, (city1, city2))   

if cnt != N-1 : 
    print(-1)
else:
    for _ in range(M-cnt): 
        city1, city2 = heapq.heappop(heap_lst2)
        ans[city1] += 1
        ans[city2] += 1
    print(*ans)