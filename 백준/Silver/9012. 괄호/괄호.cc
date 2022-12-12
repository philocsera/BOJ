#include <iostream>

using namespace std;

int main(){
	string vps;
	int T,n, len;

	cin >> T;

	while(T--){
		cin >> vps;
		len = vps.length();
		n = 0;

		if(len%2) cout << "NO" << endl;
		else{
			for(int i=0;i<len;i++){
				if(vps[i] == '(') n += 1;
				else if(vps[i] == ')') n -= 1;

				if(n<0) break;
			}
			if(n) cout << "NO" << endl;
			else cout << "YES" << endl;
		}
	}

}