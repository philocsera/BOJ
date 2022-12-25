#include <bits/stdc++.h>

using namespace std;

bool compare(string a, string b){
	if(a.length() < b.length()) return true;
	else if(a.length() > b.length()) return false;
	else{
		return a < b;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string arr[20000];
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> arr[i];
	}
	sort(arr, arr+n, compare);
	for(int i=0;i<n;i++){
		if(arr[i-1] != arr[i]) cout << arr[i] << endl;
	}
}