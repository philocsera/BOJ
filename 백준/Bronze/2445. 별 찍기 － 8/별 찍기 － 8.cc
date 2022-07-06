#include <iostream>

using namespace std;

int main(){
	int N, emp=0, star=1;
	cin >> N;
	emp = 2*N-2;
	for(int i=N;i;i--){
		for(int i=0;i<star;i++) cout << "*";
		for(int j=0;j<emp;j++) cout << " ";
		for(int k=0;k<star;k++) cout << "*";
		emp-=2;
		star++;
		cout << "\n";
	}
	
	emp+=4;
	star-=2;
	while(N--){
		for(int i=0;i<star;i++) cout << "*";
		for(int j=0;j<emp;j++) cout << " ";
		for(int k=0;k<star;k++) cout << "*";
		emp+=2;
		star--;
		cout << "\n";
	}
}