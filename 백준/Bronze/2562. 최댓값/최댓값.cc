#include <bits/stdc++.h>

using namespace std;

int main(){
	int input;
	int max = -1e9, idx;
	for(int i=1;i<=9;i++){
		cin >> input;
		if(max < input){
			max = input;
			idx = i;
		}
	}
	cout << max << "\n" << idx;
}