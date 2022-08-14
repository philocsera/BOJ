import sys
import heapq
N, M = map(int, sys.stdin.readline().split())   # N, M 입력

heap_lst = []
for i in range(N):
    city_i = list(sys.stdin.readline().rstrip())
    for j in range(i+1, N):
        if city_i[j] == 'Y':
            heapq.heappush(heap_lst, (i, j))    # Y인 도로를 heap에 추가

origin = [-1] * N  # 각 도시와 연결된 가장 작은 숫자의 도시를 저장

def _find(city):    # 매개면수 city가 본인보다 더 작은 숫자의 도시와 연결 돼 있는지 여부 check
    if origin[city] < 0 :
        return city
    else :
        origin[city] = _find(origin[city])  # 더 작은 도시 있다면 연결된 도시중 가장 작은 수 갱신
        return origin[city]

def union(city1, city2):
	origin1, origin2 = _find(city1), _find(city2)
	if origin1 == origin2 :  # 두 도시가 이미 연결 된 상태라면 False
		return False
	else:
		if origin1 < origin2 :
			origin[origin1] += origin[origin2]
			origin[origin2] = origin1
		else :
			origin[origin2] += origin[origin1]
			origin[origin1] = origin2	
		return True

if len(heap_lst)<M: # 도로의 개수가 M보다 작으면 -1 print
    print(-1)
    exit()
ans = [0 for _ in range(N)]
cnt = 0
heap_lst2 = []

while heap_lst: # MST 구성으로 모든 도시 연결 먼저 하고 이후 도로 추가 구성
    city1, city2 = heapq.heappop(heap_lst)  #heap을 통해 우선순위가 높은 도로부터 check
    if union(city1, city2):
        ans[city1] += 1
        ans[city2] += 1
        cnt += 1
    else:
        heapq.heappush(heap_lst2, (city1, city2))   

if cnt != N-1: 
    print(-1)
else:
    for _ in range(M-cnt):  # MST 구성에 사용하고 남은 횟수 만큼 heap에서 꺼내어 우선순위대로 구성
        city1, city2 = heapq.heappop(heap_lst2)
        ans[city1] += 1
        ans[city2] += 1
        cnt += 1

    if cnt == M:
        print(*ans)
    else:
        print(-1)