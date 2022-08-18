#include <bits/stdc++.h>
#define getMax(a,b) ((a>b)?a:b)
using namespace std;

int histo[100000];

int solve(int st, int ed){
	if(st==ed) return histo[st];

	int mid = (st+ed)/2;
	int left = mid;
	int right = mid;
	int max = histo[mid];
	int height = histo[mid];

	while(1){
		if(st==left && ed==right) break;

		if( st < left && (right == ed || histo[left-1] > histo[right+1])){
			left--;
			if(height > histo[left]) height = histo[left];
			if(max < (right-left+1)*height) max = (right-left+1)*height;
		}
		else{
			right++;
			if(height > histo[right]) height = histo[right];
			if(max < (right-left+1)*height) max = (right-left+1)*height;
		}
	}

	int leftMax = solve(st,mid);
	int rightMax = solve(mid+1,ed);
	int sideMax = getMax(leftMax,rightMax);

	return getMax(max,sideMax);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;

	for(int i=0;i<N;i++) cin >> histo[i];

	cout << solve(0,N-1);
}