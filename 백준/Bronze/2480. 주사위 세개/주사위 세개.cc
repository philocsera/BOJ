#include <iostream>

using namespace std;

int main(){
	int dice[3], rslt[3];
	for(int i=0;i<3;i++) cin >> dice[i];
	rslt[0] = (dice[0]==dice[1])?dice[0]:0;
	rslt[1] = (dice[1]==dice[2])?dice[1]:0;
	rslt[2] = (dice[0]==dice[2])?dice[0]:0;
	if(rslt[0]&&rslt[1]&&rslt[1]) cout << 10000 + rslt[0]*1000;
	else if(rslt[0]) cout << 1000 + rslt[0]*100;
	else if(rslt[1]) cout << 1000 + rslt[1]*100;
	else if(rslt[2]) cout << 1000 + rslt[2]*100;
	else{
		int max = dice[0]>dice[1]?dice[0]:dice[1];
		max = max>dice[2]?max:dice[2];
		cout << max*100;
	}
}