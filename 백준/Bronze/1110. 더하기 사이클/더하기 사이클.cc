#include <bits/stdc++.h>

using namespace std;

int main(){
	int N,cycle=0,goal,a,b;
	cin >> N;
	goal=N;
	do{
		a = N/10;
		b = N%10;
		N = 10*b + (a+b)%10;
		cycle++;
	}while(N!=goal);
	cout << cycle; 
}