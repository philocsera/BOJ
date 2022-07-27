#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int LCS[4001][4001];
	int lenA, lenB;
	int max = 0;
	string a,b;
	
	cin >> a >> b;
	lenA = a.length();
	lenB = b.length();
	
	for(int i=0;i<=lenA;i++) LCS[i][0] = 0;
	for(int i=0;i<=lenB;i++) LCS[0][i] = 0;
    
	for(int i=1;i<=lenA;i++){
		for(int j=1;j<=lenB;j++){
			if(a[i-1] == b[j-1]){
				LCS[i][j] = LCS[i-1][j-1] + 1;
				if(LCS[i][j] > max) max = LCS[i][j];
			}
			else{
				LCS[i][j] = 0;	
			}
		}
	}
    
	cout << max;
}