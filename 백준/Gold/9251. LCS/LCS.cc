#include <bits/stdc++.h>

using namespace std;

int main(){
	int lcs[1001][1001], rslt=0, len[2];
	string a,b;
	
	cin >> a >> b;
	
	len[0] = a.length();
	len[1] = b.length();
	
	for(int i=0;i<=len[0];i++) lcs[i][0] = 0;
	for(int j=0;j<=len[1];j++) lcs[0][j] = 0;

	for(int i=1;i<=len[0];i++){
		for(int j=1;j<=len[1];j++){
			if(a[i-1] == b[j-1]){
				lcs[i][j] = lcs[i-1][j-1] + 1;
			}
			else{
				lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
			}
			if(lcs[i][j] > rslt) rslt = lcs[i][j];
		}
	}
	
	cout << rslt;
}