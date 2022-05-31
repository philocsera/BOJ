#include <iostream>
#include <vector>

using namespace std;

int Root[100001];
vector<int> con[100001];

void FindPa(int st){
	while(!con[st].empty()){
		int to = con[st].back();
		con[st].pop_back();
		if(Root[st] == to) continue;
		Root[to] = st;
		FindPa(to);
	}
}

int main(){
	int N, a, b;
	cin >> N;
	for(int i = N-1;i--;){
		cin >> a >> b;
		con[a].push_back(b);
		con[b].push_back(a);
	}
	Root[1] = 1;
	FindPa(1);
	for(int i=2;i<=N;i++) cout << Root[i] << "\n";
}