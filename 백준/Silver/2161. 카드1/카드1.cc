#include <bits/stdc++.h>

using namespace std;

int main(){
	int N, tmp;
	queue<int> q;

	cin >> N;

	for(int i=1;i<=N;i++){
		q.push(i);
	}

	for(int i=0;i<N;i++){
		cout << q.front() << " ";
		q.pop();
		tmp = q.front();
		q.pop();
		q.push(tmp);
	}
}