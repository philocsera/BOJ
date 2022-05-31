#include <bits/stdc++.h>
#define name(v) v+'A'-1
#define idx(v) v-'A'+1
using namespace std;

void pre(int now, int max, int left[27], int right[27]){
	cout << char(name(now));
	if(left[now]) pre(left[now],max,left,right);
	if(right[now]) pre(right[now],max,left,right);
}

void in(int now, int max, int left[27], int right[27]){
	if(left[now]) in(left[now],max,left,right);
	cout << char(name(now));
	if(right[now]) in(right[now],max,left,right);
}

void post(int now, int max, int left[27], int right[27]){
	if(left[now]) post(left[now],max,left,right);
	if(right[now]) post(right[now],max,left,right);
	cout << char(name(now));
}

int main(){
	char root, inputL,inputR;
	int N, left[27], right[27];

	cin >> N;
	for(int i=0;i<N;i++){
		cin >> root >> inputL >> inputR;

		if(inputL == '.') left[idx(root)] = 0;
		else left[idx(root)] = idx(inputL);

		if(inputR == '.') right[idx(root)] = 0;
		else right[idx(root)] = idx(inputR);

	
	}

	pre(1,N,left,right);
	cout << "\n";
	in(1,N,left,right);
	cout << "\n";
	post(1,N,left,right);
	cout << "\n";
}