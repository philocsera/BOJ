#include <bits/stdc++.h>

using namespace std;

int main(){
	int arr[100000], n, x, rslt=0, st, ed;
	cin >> n;
	for(int i=0;i<n;i++) cin >> arr[i];
	cin >> x;
	sort(arr,arr+n);
	st=0;
	ed=n-1;
	while(st<ed){
		if(arr[st]+arr[ed]==x){
			rslt++;
			ed--;
		}
		else if(arr[st]+arr[ed]>x){
			ed--;
		}
		else{
			st++;
		}
	}
	cout << rslt;
}