#include <iostream>

using namespace std;

int main(){
	int N;
	cin >> N;
	for(int i=N;i;i--) {
		for(int k=N-i;k;k--) cout << " ";
		for(int j=i;j;j--) cout << "*";
		cout << "\n";
	}
}