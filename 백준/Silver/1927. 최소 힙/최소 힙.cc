#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	priority_queue<int, vector<int>, greater<int> > minH;
	int N, x;
	cin >> N;
	while(N--){
		cin >> x;
		if(x) minH.push(x);
		else{
			if(minH.empty()){
				cout << "0\n";
				continue;				
			}
			cout << minH.top() << "\n";
			minH.pop();
		}
	}
}