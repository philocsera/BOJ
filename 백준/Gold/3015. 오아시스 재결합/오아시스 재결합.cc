#include <bits/stdc++.h>
#define value first
#define nest second
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, input, merge;
	long long rslt = 0;
	stack< pair<int, int> > watch;
	pair<int, int> keep, temp;
	cin >> N;

	while(N--){
		cin >> input;

		merge = 0;
		while(!watch.empty()){
			temp = watch.top();
			if(input > temp.value){
				watch.pop();
				rslt += temp.nest;
			}
			else if(input < temp.value){
				rslt++;
				break;
			}
			else{
				keep = temp;
				watch.pop();
				merge = 1;
				rslt += temp.nest;
			}
		}

		if(merge){
			watch.push({keep.value, keep.nest+1});
		}
		else{
			watch.push({input,1});
		}
	}

	cout << rslt;
}