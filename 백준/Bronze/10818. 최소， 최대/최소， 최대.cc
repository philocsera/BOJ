#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, input;
	int max = -1e9, min = 1e9;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> input;
		if(max < input) max = input;
		if(min > input) min = input;
	}
	cout << min << " " << max;
}