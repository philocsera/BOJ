#include <bits/stdc++.h>

using namespace std;

int main(){
	int goal, stick=64, rslt=0;
	cin >> goal;
	while(goal){
		if(stick<=goal){
			goal-=stick;
			rslt++;
		}
		stick/=2;
	}
	cout << rslt;
}