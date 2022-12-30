#include <bits/stdc++.h>

using namespace std;

int main(){
	int input, sum = 0;

	for(int i=0;i<5;i++){
		cin >> input;
		if(input < 40) input=40;
		sum += input;
	}

	cout << sum/5;
}