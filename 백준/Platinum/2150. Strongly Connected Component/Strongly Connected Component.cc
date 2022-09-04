#include <bits/stdc++.h>
#define MAX 10001

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int id = 0;
	int V, E;
	int nodeId[MAX];
	int sccNum = 0;
	int groupId[MAX];
	vector<int> connect[MAX];
	bool finished[MAX];

	stack<int> stk;
	vector< vector<int> > SCC;
	
	function<void()> init = [&](){
		int a, b;

		cin >> V >> E;
		
		for(int i=1;i<=V;i++){
			nodeId[i] = 0;
			finished[i] = false;
		}
		while(E--){
			cin >> a >> b;
			connect[a].push_back(b);
		}
	};

	init();

	function<int(int)> DFS = [&](int now){
		nodeId[now] = ++id;
		stk.push(now);

		int rslt = nodeId[now];
		for(int next : connect[now]){
			if(!nodeId[next]) rslt = min(rslt, DFS(next));
			else if(!finished[next]) rslt = min(rslt, nodeId[next]);
		}

		if( rslt == nodeId[now] ){
			vector<int> temp;
			while(1){
				int node = stk.top();
				stk.pop();
				temp.push_back(node);
				finished[node] = true;
				groupId[node] = sccNum;
				if(node == now) break; 
			}
			
			sort(temp.begin(),temp.end());
			SCC.push_back(temp);
			sccNum++;
		}

		return rslt;
	};

	for(int i=1;i<=V;i++){
		if(!nodeId[i]) DFS(i);
	}

	sort(SCC.begin(), SCC.end());

	cout << sccNum << "\n";
	for(auto arr : SCC){
		for(auto i : arr){
			cout << i << " ";
		}
		cout << "-1\n";
	}
	
}