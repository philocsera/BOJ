#include <iostream>

using namespace std;

int main(){
	int h, m;
	cin >> h >> m;
	if(m<45){
		m = 60+m-45;
		if(h) h--;
		else h=23;
	}
	else{
		m-=45;
	}
	cout << h << " " << m;
}