#include <iostream>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N, two=0, five=0, j;
	cin >> N;

	for(int i=1;i<=N;i++){
		j = i;
		while(!(j%2)){
			two += 1;
			j /= 2;
		}
		while(!(j%5)){
			five += 1;
			j /= 5;
		}
	}
	
	cout << ((two>five)?five:two);
	
}