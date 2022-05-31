#include <bits/stdc++.h>

using namespace std;

#define INF 0x3f3f3f3f

int main(){
	int V,E,start,from,to,value,dis[20001];
	cin >> V >> E >> start;
	vector< pair<int, int> > con[V+1];
	priority_queue< pair<int,int> > q;
	for(int i=0;i<E;i++){
		cin >> from >> to >> value;
		con[from].push_back({to,value});
	}
	
	for(int i=1;i<V+1;i++) dis[i] = INF;
	
	dis[start] = 0;
	q.push({0,start});

	while(!q.empty()){
		int cost = -q.top().first;
		int now = q.top().second;

		q.pop();
		
		for(int i=0;i<con[now].size();i++){
			int next = con[now][i].first;
			int nextCost = con[now][i].second;

			if( dis[now] + nextCost < dis[next] ){
				dis[next] = dis[now] + nextCost;
				q.push({-dis[next],next});
			}
	
		}
		
	}

	for(int i=1;i<=V;i++) {
		if(dis[i]!=INF){ cout << dis[i] << "\n"; }
		else { cout << "INF\n"; }
	}
	
}