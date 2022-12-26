#include <bits/stdc++.h>
#define toN(x) (x-'0')
using namespace std;

int main(){
	string origin[2];
	int reverse[2] = {0};

	cin >> origin[0] >> origin[1];

	reverse[0] = toN(origin[0][0]) + toN(origin[0][1])*10 + toN(origin[0][2])*100;
	reverse[1] = toN(origin[1][0]) + toN(origin[1][1])*10 + toN(origin[1][2])*100;

	if(reverse[0] > reverse[1]) cout << reverse[0];
	else cout << reverse[1];
}