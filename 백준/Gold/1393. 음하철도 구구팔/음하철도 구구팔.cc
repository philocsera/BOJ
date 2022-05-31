#include <iostream>

#define INF 1e9

using namespace std;

int main(){
	double d[2], m, now[2], temp;
	int ori[2], goal[2], dis=INF, last, go;
	cin >> goal[0] >> goal[1] >> now[0] >> now[1] >> d[0] >> d[1];
	m = d[1]/d[0];
	ori[0] = now[0];
	ori[1] = now[1];
	go = d[0]>0?1:-1;
	if(!d[0]){
		cout << now[0] << " " << goal[1];
		return 0;
	}
	while(1){
		if(now[0] >= 500 || now[0] <= -500) break;
		now[1] = m*(now[0]-ori[0])+ori[1];
		if(now[1]!=int(now[1])) {
			now[0]+=go;
			continue;
		}
		temp = (goal[0]-now[0])*(goal[0]-now[0])+(goal[1]-now[1])*(goal[1]-now[1]);
		if(dis>temp) {
			dis = temp;
			last = now[0];
		}
		else break;
		now[0]+=go;
	}
	cout << last << " " << m*(last-ori[0])+ori[1];	
	
}