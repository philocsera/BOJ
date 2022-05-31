#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string S;
int SLen;

int AB(string arr, int len){
	if(!arr.compare(S)) return 1;
	if(SLen == len) return 0;
	if(arr[len-1] == 'A') {
		arr.pop_back();
		return AB(arr, len-1);
	}
	else if(arr[len-1] == 'B'){
		arr.pop_back();
		reverse(arr.begin(),arr.end());
		return AB(arr, len-1);
	}
}

int main(){
	string T;
	getline(cin,S);
	getline(cin,T);
	SLen = S.length();
	cout << AB(T,T.length());
}