#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;

int main(){
	pair<int, char> chat[10001];
	int user[26] = {0};
	int N, K, Q;
	
	cin >> N >> K >> Q;
	
	user[0] = 1;
	for(int i=1;i<=K;i++){
		cin >> chat[i].first >> chat[i].second;
		if(i==Q && !chat[i].first){
			cout << "-1";
			return 0;
		}
		if(i>=Q) user[chat[i].second-'A'] = 1;
	}

	for(int i=Q-1;i>=0;i--){
		if(chat[Q].first == chat[i].first)
			user[chat[i].second-'A'] = 1;
	}

	for(int i=0;i<N;i++){
		if(!user[i]) cout << (char)(i+'A') << " ";
	}
}