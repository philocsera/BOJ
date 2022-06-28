#include <bits/stdc++.h>

using namespace std;

int main(){
	int a, b, v, rslt=0;
	cin >> a >> b >> v;
	if((v-a)%(a-b)) cout << (int)((v-a)/(a-b)) + 2;
	else cout << (int)((v-a)/(a-b)) + 1;
}