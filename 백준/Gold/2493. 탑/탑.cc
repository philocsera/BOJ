#include <bits/stdc++.h>

using namespace std;

int main(){
	// FAST IO
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// Declaration
	stack< pair <int, int> > tower;
	int N, input, qNum=0;

	// Input and Initialization
	cin >> N;
	for(int i=1;i<=N;i++){
		cin >> input;
		tower.push( make_pair(input, i) );
	}

	priority_queue< pair<int, int> > q; // ( value, idx )
	vector< int > rslt(N+1);

	// Compare
	for(int i=0;i<N;i++){
		int nowV = tower.top().first;
		int nowI = tower.top().second;
		if(qNum){
			for(int j=0;j<qNum;j++){ 
				if( -q.top().first < nowV ) {
					rslt[q.top().second] = nowI;
					q.pop();
					qNum--;
					j--;
				}
				else break;
			}
		}
		q.push( { -nowV, nowI } );
		qNum++;
		tower.pop();
		
	}
	
	// Output
	for(int i=1;i<=N;i++) cout << rslt[i] << " ";

}