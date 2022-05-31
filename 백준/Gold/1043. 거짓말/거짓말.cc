#include <bits/stdc++.h>

using namespace std;

int PickPerson(int N, vector<int> &check, vector<int> &know){
	for(int i=1;i<=N;i++){
		if(!check[i]&&know[i]) return i;
	}
	return 0;
}


int main(){
	int N,M,input,Pnum,attend,invite,infection,nowP=1,output=0;
	cin >> N >> M;
	vector<int> know(N+1), check(N+1), rslt(M+1);
	vector< vector<int> > party(M+1), people(N+1);
	queue<int> await;
	
	cin >> Pnum;
	for(int i=0;i<Pnum;i++){
		cin >> input;
		know[input] = 1;
	}
	for(int P=1;P<=M;P++){
		cin >> Pnum;
		for(int i=0;i<Pnum;i++){
			cin >> input;
			party[P].push_back(input);
			people[input].push_back(P);
		}
	}
	while(1){
		if(await.empty()){
			nowP = PickPerson(N,check,know);
		}	 
		else{
			while(1){
				nowP = await.front();
				await.pop();
				if(!check[nowP]) break;
			}
		}
		if(!nowP) break;
		check[nowP] = 1;
		attend = people[nowP].size();
		for(int i=0;i<attend;i++){
			if(rslt[people[nowP][i]]) continue;
			rslt[people[nowP][i]] = 1;
			invite = party[people[nowP][i]].size();
			for(int j=0;j<invite;j++){
				infection = party[people[nowP][i]][j];
				if(!know[infection]&&infection!=nowP&&!check[infection]){
					await.push(infection);
					know[infection] = 2;
				}
			}
		}
				
	}
	for(int i=1;i<=M;i++){
		if(!rslt[i]){
			output++;
		}
	}
	cout << output;
}