#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	priority_queue<int> device;
	int N, M, input;
	ull rslt = 0;
	int socket[10];
	cin >> N >> M;
	for(int i=0;i<N;i++){
		cin >> input;
		device.push(input);
	}
	while(!device.empty()){
		for(int i=0;i<M;i++){
			socket[i] = device.top();
			device.pop();
			if(device.empty()){
				M = i+1;
				break;
			}
		}
		for(int i=0;i<M;i++){
			if(socket[i]-socket[M-1]){
				device.push(socket[i]-socket[M-1]);
			}
		}

		rslt += socket[M-1];
		
	}

	cout << rslt;
}