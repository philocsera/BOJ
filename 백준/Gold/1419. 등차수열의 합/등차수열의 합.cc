#include <bits/stdc++.h>

using namespace std;

int main(){

	ios_base::sync_with_stdio(false);
   	cin.tie(0);

	int  left, right, k, rslt=0;

	cin >> left >> right >> k;

	switch(k){
		case 2:
			cout << max(right - max(left,3) + 1, 0);
			break;
		case 3:
			left = max(left,6);
			for(;left<=right;left++){
				if(!(left%3)) rslt++;
			}
			cout << rslt;
			break;
		case 4:
			left = max(left,10);
			for(;left<=right;left++){
				if(!(left%2) && left != 12) rslt++;
			}
			cout << rslt;
			break;
		case 5:
			left = max(left,15);
			for(;left<=right;left++){
				if(!(left%5)) rslt++;
			}
			cout << rslt;
			break;
	}
}