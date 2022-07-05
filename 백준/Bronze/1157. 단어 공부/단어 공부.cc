#include <bits/stdc++.h>

using namespace std;

int main(){
	char input;
	int max=0, many=0, idx;
	int alpha[26]={0};
	int gap = 'a'-'A';
	
	while(cin >> input){
		if(input >= 'a') input -= gap;
		idx = input-'A';
		alpha[idx]++;

		if(alpha[idx] == alpha[max]){
			if(idx != max) many = 1;
			else many = 0;
		}
		if(alpha[idx] > alpha[max]){
			many=0;
			max = idx;
		}
	}
	if(many) cout << "?";
	else cout << (char)(max+'A'); 
}