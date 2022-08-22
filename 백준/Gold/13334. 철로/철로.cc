#include <bits/stdc++.h>
#define PII pair<int, int>
#define INF 100'000'001

using namespace std;

struct front{
	bool operator()(PII a, PII b){
		return a.first > b.first;
	}
};

struct back{
	bool operator()(PII a, PII b){
		return a.second > b.second;
	}
};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N, d;
	int a, b;
	int rslt, st, ed;
	priority_queue< PII, vector<PII>, front> possible;
	priority_queue< PII, vector<PII>, back> sweep;

	cin >> N;

	for(int i=0;i<N;i++){
		cin >> a >> b;
		if(a<b) sweep.push({a,b});
		else sweep.push({b,a});
	}
	cin >> d;

	for(int i=0;i<N;i++){
		st = sweep.top().first;
		ed = sweep.top().second;
		sweep.pop();
		if(ed-st > d) continue;
		possible.push({st,ed});
		while(!possible.empty()){
			if(possible.top().first < ed-d){
				possible.pop();
			}
			else break;
		}

		if(possible.size() > rslt) rslt = possible.size();
	}

	cout << rslt;

}