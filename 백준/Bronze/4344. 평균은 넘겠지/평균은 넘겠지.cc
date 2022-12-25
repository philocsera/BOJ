#include <bits/stdc++.h>

using namespace std;

int main(){
	int T, n;
	int sum, rslt;
	double ave;
	int score[1000];

	cout << fixed;
	cout.precision(3);

	cin >> T;

	while(T--){
		cin >> n;
		sum = 0;
		rslt = 0;

		for(int i=0;i<n;i++){
			cin >> score[i];
			sum += score[i];
		}

		ave = (double)sum/n;

		for(int i=0;i<n;i++){
			if(ave < (double)score[i]) rslt++;
		}

		cout << (double)rslt/n*100 << "%\n";
	}

}