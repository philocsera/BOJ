#include <iostream>

using namespace std;

int main(){
	int N, emp=0, star;
	cin >> N;
	
	star=1;
	emp = N-1;
	for(int i=N;i;i--){
		for(int i=0;i<emp;i++) cout << " ";
		for(int j=0;j<star;j++) cout << "*";
		emp--;
		star+=2;
		cout << "\n";
	}

	star=2*(N-1)-1;
	emp=1;
	while(star>0){
		for(int i=emp;i;i--) cout << " ";
		for(int j=0;j<star;j++) cout << "*";
		emp++;
		star-=2;
		cout << "\n";
	}
}