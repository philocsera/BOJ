#include <bits/stdc++.h>

using namespace std;

bool compare(string a, string b){
	return a+b > b+a;
}

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(0);
    	
	int n, a;
	cin >> n;
	vector<string> v;

	for(int i=0;i<n;i++){
		cin >> a;
		v.push_back(to_string(a));
	}

	sort(v.begin(),v.end(),compare);

	string rslt = "";

	if(v[0]=="0"){
		cout << "0";
		return 0;
	}

	for(int i=0;i<v.size();i++){
		rslt += v[i];
	}

	cout << rslt;
	return 0;
}
