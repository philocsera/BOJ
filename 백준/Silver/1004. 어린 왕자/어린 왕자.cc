#include <bits/stdc++.h>

using namespace std;

int main(){
    int T,begin[2],goal[2],c[2],r,n,min;
    long double d;
    vector<bool> rslt; 
    cin >> T;
    while(T--){
        cin >> begin[0] >> begin[1] >> goal[0] >> goal[1];
        cin >> n;
	rslt.assign(n,0);
	min=0;
        for(int i=0;i<n;i++){
          	cin >> c[0] >> c[1] >> r;
		r*=r;
           	d=(begin[0]-c[0])*(begin[0]-c[0]) + (begin[1]-c[1])*(begin[1]-c[1]);
		if(d<r) rslt[i] = !rslt[i];
		d=(goal[0]-c[0])*(goal[0]-c[0]) + (goal[1]-c[1])*(goal[1]-c[1]);
		if(d<r) rslt[i] = !rslt[i];
		if(rslt[i]) min++;
        }
	cout << min << "\n";
    }
}