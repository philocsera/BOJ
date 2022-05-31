#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	string input;
	map<int,string> NumToName;
	map<string,int> NameToNum;
	int N, M;
	cin >> N >> M;
	for(int i=1;i<=N;i++){
		cin >> input;
		NumToName.emplace(i,input);
		NameToNum.emplace(input,i);
	}
	for(int i=0;i<M;i++){
		cin >> input;
		if(49<=int(input[0])&&int(input[0])<=57) cout << NumToName.find(stoi(input))->second;
		else cout << NameToNum.find(input)->second;
		cout << "\n";
	}
}