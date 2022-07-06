#include <iostream>

using namespace std;

int main(){
	int N, emp, star=1;
	cin >> N;
	emp = N-1;
	while(N--){
		for(int i=0;i<emp;i++) cout << " ";
		for(int j=0;j<star;j++) cout << "*";
		emp--;
		star+=2;
		cout << "\n";
	}
}