#include <bits/stdc++.h>

using namespace std;

int main(){
	int arr[100000], n, min=2000000001, st, ed, minV[2];
	cin >> n;
	for(int i=0;i<n;i++) cin >> arr[i];
	sort(arr,arr+n);
	st=0;
	ed=n-1;
	while(st<ed){
		if(abs(arr[st]+arr[ed])<min){
			minV[0] = arr[st];
			minV[1] = arr[ed];
			min = abs(arr[st]+arr[ed]);
		}
		if(arr[st]+arr[ed]>0){
			ed--;
		}
		else{
			st++;
		}
	}
	cout << minV[0] << " " << minV[1];
}