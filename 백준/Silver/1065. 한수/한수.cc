#include <iostream>

using namespace std;

int main(){
	int N;
	cin >> N;

	if(N<100) cout << N;
	else{
		int rslt = 99;
		if(N==1000) N = 999;
		for(int i=100;i<=N;i++){
			if(i/100 - (i%100)/10 == (i%100)/10 - i%10) rslt++;
		}
		cout << rslt;
	}
}