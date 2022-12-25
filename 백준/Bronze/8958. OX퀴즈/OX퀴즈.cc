#include <bits/stdc++.h>

using namespace std;

int main(){
	int T, len, combo, rslt;
	string quiz;
	cin >> T;
	while(T--){
		cin >> quiz;
		len = quiz.length();
		rslt = 0;
		combo = 0;

		for(int i=0;i<len;i++){
			if(quiz[i] == 'O'){
				rslt += ++combo;
			}
			else{
				combo = 0;
			}
		}

		cout << rslt << endl;
	}
}