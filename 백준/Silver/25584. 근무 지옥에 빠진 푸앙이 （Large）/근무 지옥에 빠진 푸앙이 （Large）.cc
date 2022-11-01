#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N;
	int idx = 0;
	string name;
	map<string,int> worker;
	int hour[5000];
	int time[4] = {4,6,4,10};

	cin >> N;
	for(int i=0;i<N;i++){
		for(int j=0;j<4;j++){
			for(int k=0;k<7;k++){
				cin >> name;
				if(name != "-"){
					if(worker.find(name) == worker.end()){
						hour[idx] = time[j];
						worker.insert({name,idx++});
					}
					else{
						hour[worker.find(name)->second] += time[j];
					}
				}
			}
		}
	}
	
	int min = 1e8;
	int max = -1e8;
	for(int i=0;i<idx;i++){		
		if(min > hour[i]) min = hour[i];
		if(max < hour[i]) max = hour[i];
	}

	if(max - min > 12 && idx) cout << "No";
	else cout << "Yes";
}