#include <bits/stdc++.h>

using namespace std;

int main(){
	char input;
	int arr[10], n = 0;
	while(cin >> input){
		arr[n++] = input-'0';
	}
	sort(arr,arr+n);
	for(int i=n-1;i>=0;i--){
		cout << arr[i];
	}
}