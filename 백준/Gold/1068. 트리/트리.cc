#include <bits/stdc++.h>

using namespace std;

int N, tree[50];

int CountLeaf(void){
	int rslt=0;
	for(int i=0;i<N;i++){
		if(tree[i] == -2) continue;
		for(int j=0;j<N;j++){
			if(tree[j] == i){
				rslt--;
				break;
			}
		} 
		rslt++;
	}
	return rslt;
}

void Cut(int idx){
	for(int i=0;i<N;i++){
		if(tree[i] == idx){
			tree[i] = -2;
			Cut(i);
		}
	}
}

int main(){
	int input;
	cin >> N;
	for(int i=0;i<N;i++) cin >> tree[i];
	cin >> input;
	tree[input] = -2;
	Cut(input);
	cout << CountLeaf();
}