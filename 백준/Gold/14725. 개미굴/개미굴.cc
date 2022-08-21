#include <bits/stdc++.h>
using namespace std;

typedef struct _trie{
	string food;
	vector<_trie*> next;

	_trie(string foodName) : food(foodName) {}
}TRIE; 

TRIE* ground = new TRIE("ground");

bool compare(TRIE* a, TRIE* b){
	return ( a->food < b->food );
}

void insert(int n, TRIE* now){
	if(!n) return;

	int idx = -1;
	string to;
	cin >> to;

	for(int i=0;i<now->next.size();i++){
		if(now->next[i]->food == to){
			idx = i;
			break;
		}
	}

	if(idx == -1){
		now->next.push_back(new TRIE(to));
		idx = now->next.size() - 1;
	}

	insert(n-1,now->next[idx]);

}

void print(TRIE* now, int n){
	for(int i=0;i<n;i++) cout << "--";
	if(n >= 0) cout << now->food << "\n";

	sort(now->next.begin(), now->next.end(), compare);

	for(int i=0;i<now->next.size();i++){
		print(now->next[i], n+1);
	}
}

void solve(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, layer;
	string input;

	cin >> N;


	while(N--){
		cin >> layer;
		insert(layer, ground);	
	}

	print(ground,-1);
}

int main(){
	solve();
}