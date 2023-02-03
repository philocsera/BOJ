#include <iostream>

using namespace std;

bool arr[101][101] = { false }, check[101] = { 0 };
int num;

int virus(int now){
	static int rslt = 0;
	for(int j=2;j<=num;j++){
		if(arr[now][j] && !check[j]){
			check[j] = 1;
			virus(j);
			rslt++;
		}
	}
	return rslt;
}

int main(){
	int n1, n2, i;
	cin >> num >> i;
	while(i--){
		cin >> n1 >> n2;
		arr[n1][n2] = true;
		arr[n2][n1] = true;
	}
	check[1] = 1;
	cout << virus(1);
}