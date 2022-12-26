#include <bits/stdc++.h>

using namespace std;

int main(){
	int info[50][2];
	int rslt[50] = {0};
	int n;

	cin >> n;
	for(int i=0;i<n;i++){
		cin >> info[i][0] >> info[i][1];
	}

	for(int i=0;i<n;i++){	
		for(int j=i+1;j<n;j++){
			if(info[i][0] < info[j][0] && info[i][1] < info[j][1]){
				rslt[i]++;
			}
			else if(info[i][0] > info[j][0] && info[i][1] > info[j][1]){
				rslt[j]++;
			}

		}
		cout << rslt[i] + 1 << " ";
	}
}