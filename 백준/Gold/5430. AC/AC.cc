#include <bits/stdc++.h>

using namespace std;

int main(){
	char unpack;
	int T, n, pLen, input[100001], st, ed, plag;
	string p;
	cin >> T;
	for(int i=0;i<T;i++){
		cin >> p >> n >> unpack;
		pLen = p.length();

		st = 0;
		ed = n-1;
		plag = 0;

		if(!n) cin >> unpack;
		for(int j=0;j<n;j++) cin >> input[j] >> unpack;
		
		for(int j=0;j<pLen;j++){
			if(p[j] == 'R'){
				plag = plag?0:1;
			}
			else{
				if(!n){
					cout << "error\n";
					n = -1;
					break;
				}
				if(!plag) st++;	
				else ed--;
				n--;				
			}
		}
		if(n==-1) continue;
		if(n){
			cout << "[";
			if(n!=1){
				if(!plag){
					for(int j=st;j<ed;j++) cout << input[j] << ",";
					cout << input[ed] << "]\n";
				}
				else{
					for(int j=ed;j>st;j--) cout << input[j] << ",";
					cout << input[st] << "]\n";
				}
			}
			else{
				cout << input[st] << "]\n";
			}
		}
		else{
			cout << "[]\n";
		}
	}
}