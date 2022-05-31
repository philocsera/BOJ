#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	priority_queue<string, vector<string>, greater<string> > rslt;
	map<string,bool> name;
	string input;
	int N, M, num=0;
	cin >> N >> M;
	for(int i=0;i<N;i++){
		cin >> input;
		name.emplace(input,true); 
	}
	for(int i=0;i<M;i++){
		cin >> input;
		if(name.find(input) != name.end()){
			rslt.push(input);
			num++;
		}
	}
	cout << num << "\n";
	while(!rslt.empty()){
		cout << rslt.top() << "\n";
		rslt.pop();
	}
}	