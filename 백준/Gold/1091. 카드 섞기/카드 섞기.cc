#include <bits/stdc++.h>

using namespace std;

map<string, int> memo;
int N;

int same(vector<int> A,vector<int> B){
	for(int i=0;i<N;i++){
		if(A[i]!=B[i]) return 0;
	}
	return 1;
}

int main(){
	int rslt=0;
	cin >> N;
	vector <int> P(N),S(N),now(N),temp(N);
	string code = "";

	for(int i=0;i<N;i++) cin >> P[i];
	for(int i=0;i<N;i++) cin >> S[i];
	for(int i=0;i<N;i++) now[i] = i%3;
	

	while(!same(P,now)){
		if(memo.find(code) != memo.end()){
			rslt=-1;
			break;
		}	
		memo.insert({code,1});
		code.clear();
		for(int i=0;i<N;i++) temp[i] = now[S[i]];
		for(int i=0;i<N;i++) {
			now[i] = temp[i];
			code.append(to_string(now[i]));
		}
		rslt++;
	}
	cout << rslt;
}