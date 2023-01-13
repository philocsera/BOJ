#include <iostream>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	string command;
	bool S[21];
	int M, x;
	for(int i=1;i<21;i++) S[i] = false;
	cin >> M;

	for(int i=0;i<M;i++){
		cin >> command;
		if(command == "all"){
			for(int i=1;i<21;i++) S[i] = true;
			continue;
		}
		if(command == "empty"){
			for(int i=1;i<21;i++) S[i] = false;
			continue;
		}
		
		cin >> x;
		if(command == "add") S[x] = true;
		else if(command == "remove") S[x] = false;
		else if(command == "check") cout << ((S[x])?1:0) << "\n";
		else S[x] = !S[x];
	}
	
}