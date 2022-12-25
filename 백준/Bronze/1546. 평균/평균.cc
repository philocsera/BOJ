#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, m = -1;
	double rslt = 0;
	int score[1000];
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> score[i];
		if(m < score[i]) m = score[i];
	}

	for(int i=0;i<n;i++){
		rslt += (double)score[i]/m*100;
	}

	cout << rslt/n;
}