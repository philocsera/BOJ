#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;

ull histo[100000];

ull max(ull a, ull b){
	return a>b?a:b;
}

ull solve(int st, int ed){
	if(st==ed) return histo[st];

	int mid = (st+ed)/2;
	int left = mid;
	int right = mid;
	ull midMax = histo[mid];
	ull height = histo[mid];

	while(1){
		if(st==left && ed==right) break;

		if( st < left && (right == ed || histo[left-1] > histo[right+1])){
			left--;
			if(height > histo[left]) height = histo[left];
			if(midMax < (right-left+1)*height) midMax = (right-left+1)*height;
		}
		else{
			right++;
			if(height > histo[right]) height = histo[right];
			if(midMax < (right-left+1)*height) midMax = (right-left+1)*height;
		}
	}

	ull leftMax = solve(st,mid);
	ull rightMax = solve(mid+1,ed);
	ull sideMax = max(leftMax,rightMax);

	return max(midMax,sideMax);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N;
	while(1){
		cin >> N;
		if(!N) break;
		for(int i=0;i<N;i++) cin >> histo[i];

		cout << solve(0,N-1) << "\n";
		for(int i=0;i<N;i++) histo[i] = 0;
	}
}