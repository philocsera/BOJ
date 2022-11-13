#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string puzzle[20];
	int r, c;	
	string rslt = "zzzzzzzzzzzzzzzzzzzz";

	cin >> r >> c;
	for(int i=0;i<r;i++){		
		cin >> puzzle[i];
	}

	string temp = "";
	for(int i=0;i<r;i++){
		temp = "";
		for(int j=0;j<c;j++){
			if(puzzle[i][j] == '#'){
				if(temp.length() >= 2 && rslt > temp) rslt = temp;
				temp = "";
			}
			else{
				temp += puzzle[i][j];
			}
		}
		if(temp.length() >= 2 && rslt > temp) rslt = temp;
	}

	for(int j=0;j<c;j++){
		temp = "";
		for(int i=0;i<r;i++){
			if(puzzle[i][j] == '#'){
				if(temp.length() >= 2 && rslt > temp) rslt = temp;
				temp = "";
			}
			else{
				temp += puzzle[i][j];
			}		}
		if(temp.length() >= 2 && rslt > temp) rslt = temp;
	}

	cout << rslt;
}