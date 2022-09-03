#include <bits/stdc++.h>

#define node first
#define dis second
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, M;
	int a,b,cost;
	vector< pair<int, int> > connect[40001];
	int depth[40001];
	pair<int,int> parent[40001]; // (parent, dis)

	cin >> N;

	for(int i=1;i<N;i++){
		cin >> a >> b >> cost;
		connect[a].push_back({b,cost});
		connect[b].push_back({a,cost});
	}

	function<void(int, int, int)> init = [&](int before, int now, int depthN){
			parent[now].node = before;
			depth[now] = depthN;
			
			for(int i=0;i<connect[now].size();i++){
				if(connect[now][i].node != before){
					init(now,connect[now][i].node,depthN+1);
				}
				else{
					parent[now].dis = connect[now][i].dis;
				}
			}
	};

	depth[1] = 0;
	init(-1,1,1);

	function<int(int,int)> getDis = [&](int a, int b){
		if(a == b) return 0;
		if(parent[a].node == parent[b].node) return parent[a].dis + parent[b].dis;
		if(depth[a] == depth[b]) return parent[a].dis + parent[b].dis + getDis(parent[a].node,parent[b].node);
		else if(depth[a] > depth[b]) return parent[a].dis + getDis(parent[a].node,b);
		else return parent[b].dis + getDis(a,parent[b].node);
	};

	cin >> M;

	while(M--){
		cin >> a >> b;
		cout << getDis(a,b) << "\n";
	}

}