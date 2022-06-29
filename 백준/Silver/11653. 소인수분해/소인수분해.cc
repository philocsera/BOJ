#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	for(int i=2;n!=1;){
		if(n%i) i++;
		else{
			cout << i << "\n";
			n /= i;
		}
	}
}