#include <iostream>

using namespace std;

int N,M, arr[100][100],ck[100][100];

int Chk(){ // 남아있는 치즈개수
	int n=0;
	for(int i=0;i<N;i++) {
		for(int j=0;j<M;j++){	
			if(arr[i][j]) n++;
		}
	}
	return n;
}

int melt(int n1,int n2,int b){
	// cout << n1 << " " << n2 << "\n";
	if(n1==N||n2==M||n1<0||n2<0||ck[n1][n2]) return 0;
	if(arr[n1][n2] == 1) arr[n1][n2] = 2;
	ck[n1][n2] = 1;
	if(!arr[n1][n2]){
		if(b!=1) melt(n1+1,n2,2);
		if(b!=2) melt(n1-1,n2,1);
		if(b!=3) melt(n1,n2+1,4);
		if(b!=4) melt(n1,n2-1,3);
	}
	return 0;
}

void cut(){
	for(int i=0;i<N;i++) {
		for(int j=0;j<M;j++){	
			if(arr[i][j]==2) arr[i][j] = 0;
		}
	}
}

int main(){
	int time, plag, num;
	cin >> N >> M;
	for(int i=0;i<N;i++) for(int j=0;j<M;j++) cin >> arr[i][j];
	for(time=0;;time++){
		plag = Chk();
		if(!plag) break;
		num = plag;
		melt(0,0,-1);
		cut();
		for(int i=0;i<N;i++) for(int j=0;j<M;j++) ck[i][j] = 0;
	}
	cout << time << "\n" << num;
	
}