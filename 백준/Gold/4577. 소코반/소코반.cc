#include <bits/stdc++.h>

using namespace std;

typedef struct pos{
	int x;
	int y;
}POS;

int main(){
	char map[15][15];	
	int r, c, gameNum = 1;
	pos me;
	string input;

	while(1){
		cin >> r >> c;
		if(!r && !c) break;

		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++){
				cin >> map[i][j];
				if(map[i][j] == 'w' || map[i][j] == 'W'){
					me.x = i;
					me.y = j;
				}
			}
		}
		cin >> input;
		int len = input.length();
		pos delta;

		function<void(int,int)> move = [&](int deltaX, int deltaY){
			if(map[me.x][me.y] == 'W') map[me.x][me.y] = '+';
			else map[me.x][me.y] = '.';
			me.x += deltaX;
			me.y += deltaY;
		};

		for(int i=0;i<len;i++){

			if(input[i] == 'U'){
				delta.x = -1;
				delta.y = 0;
			}
			else if(input[i] == 'D'){
				delta.x = 1;
				delta.y = 0;
			}
			else if(input[i] == 'L'){
				delta.x = 0;
				delta.y = -1;
			}
			else if(input[i] == 'R'){
				delta.x = 0;
				delta.y = 1;
			}

			char& frontOfMe = map[me.x + delta.x][me.y + delta.y]; 
			if(frontOfMe == '.'){
				move(delta.x,delta.y);
				frontOfMe = 'w';
			}
			else if(frontOfMe == '+'){
				move(delta.x,delta.y);
				frontOfMe = 'W';
			}
			else if(frontOfMe == 'b' || frontOfMe == 'B'){
				char& frontOfBox = map[me.x + 2*delta.x][me.y + 2*delta.y];

				if(frontOfBox == '.'){
					move(delta.x,delta.y);
					if(frontOfMe == 'B') frontOfMe = 'W';
					else frontOfMe = 'w';
					frontOfBox = 'b';
				}
				else if(frontOfBox == '+'){
					move(delta.x,delta.y);
					if(frontOfMe == 'B') frontOfMe = 'W';
					else frontOfMe = 'w';
					frontOfBox = 'B';
				}

			}

			bool plag = true;
			for(int i=0;i<r&&plag;i++){
				for(int j=0;j<c&&plag;j++){
					if(map[i][j] == 'b'){
						plag = false;
					}
				}
			}
			if(plag) break;

		}

		bool plag = true;
		for(int i=0;i<r&&plag;i++){
			for(int j=0;j<c&&plag;j++){
				if(map[i][j] == 'b'){
					plag = false;
				}
			}
		}
	
		cout << "Game " << gameNum++ << ": ";
		if(plag) cout << "complete";
		else cout << "incomplete";
		cout << "\n";

		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++){
				cout << map[i][j];
			}
			cout << "\n";
		}

	}
}