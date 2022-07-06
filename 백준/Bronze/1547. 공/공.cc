#include <bits/stdc++.h>

using namespace std;

int main(){
	int now = 1;
	int a,b;
	int M;
	cin >> M;
	while(M--){
		cin >> a >> b;
		if(a==now) now = b;
		else if(b==now) now = a;
	}
	cout << now;
}	