#include <bits/stdc++.h>

using namespace std;

int main(){
	int input;
	int chessSet[] = {1,1,2,2,2,8};

	for(int i=0;i<6;i++){
		cin >> input;
		cout << chessSet[i] - input << " ";
	}
}