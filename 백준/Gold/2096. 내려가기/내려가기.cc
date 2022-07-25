#include <bits/stdc++.h>
#define getMax(x,y) ((x>y)?x:y)
#define getMin(x,y) ((x>y)?y:x)
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int max[2][3];
	int min[2][3];
	int N;
	int input[3];

	cin >> N;
	cin >> input[0] >> input[1] >> input[2];

	for(int i=0;i<3;i++) min[0][i] = max[0][i] = input[i];

	for(int i=1;i<N;i++){
		max[1][0] = getMax(max[0][0],max[0][1]);
		max[1][2] = getMax(max[0][2],max[0][1]);
		max[1][1] = getMax(max[1][0],max[1][2]);

		min[1][0] = getMin(min[0][0],min[0][1]);
		min[1][2] = getMin(min[0][2],min[0][1]);
		min[1][1] = getMin(min[1][0],min[1][2]);


		cin >> input[0] >> input[1] >> input[2];
		for(int i=0;i<3;i++){
			min[0][i] = min[1][i] + input[i];
			max[0][i] = max[1][i] + input[i];
		}
	}
	cout << getMax(getMax(max[0][0],max[0][1]),max[0][2]) << " ";
	cout << getMin(getMin(min[0][0],min[0][1]),min[0][2]);
}