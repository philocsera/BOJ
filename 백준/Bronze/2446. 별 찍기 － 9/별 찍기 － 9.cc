#include <iostream>

using namespace std;

int main(){
	int N, emp=0, star;
	cin >> N;
	
	star=2*(N-1)+1;
	emp=0;
	while(star>0){
		for(int i=emp;i;i--) cout << " ";
		for(int j=0;j<star;j++) cout << "*";
		emp++;
		star-=2;
		cout << "\n";
	}

	star=3;
	emp = N-2;
	for(int i=N-1;i;i--){
		for(int i=0;i<emp;i++) cout << " ";
		for(int j=0;j<star;j++) cout << "*";
		emp--;
		star+=2;
		cout << "\n";
	}
}