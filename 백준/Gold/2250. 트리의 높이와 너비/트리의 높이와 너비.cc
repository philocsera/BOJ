#include <bits/stdc++.h>
#define MAX 10001

using namespace std;

int N;
int nodeLevel[MAX];
int Level[MAX][2]; // Min Max
int tree[MAX][2]; // L R
int LineNum[MAX];

void init(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	for(int i=1;i<=N+1;i++){
		Level[i][0] = MAX;
		Level[i][1] = -MAX;
	}
}

int input(){
	int root, left, right;
	cin >> N;

	int getRoot[MAX], rootNode;
	for(int i=1;i<=N;i++) getRoot[i] = 1;
	for(int i=1;i<=N;i++){
		cin >> root >> left >> right;
		tree[root][0] = left;
		tree[root][1] = right;
		if(left != -1) getRoot[left] = 0;
		if(right != -1) getRoot[right] = 0;
	}

	for(int i=1;i<=N;i++){
		if(getRoot[i]){
			rootNode = i;
			break;
		}
	}

	return rootNode;
}

int getLineNum(int now, int lastNum, int level){
	nodeLevel[now] = level;
	
	if(tree[now][0] != -1) lastNum = getLineNum(tree[now][0], lastNum, level+1);
	LineNum[now] = ++lastNum;
	if(tree[now][1] != -1) lastNum = getLineNum(tree[now][1], lastNum, level+1);
	
	return lastNum;
}

void output(){
	int nowL;
	for(int i=1;i<=N;i++){
		nowL = nodeLevel[i];
		if(Level[nowL][0] > LineNum[i]) Level[nowL][0] = LineNum[i];
		if(Level[nowL][1] < LineNum[i]) Level[nowL][1] = LineNum[i];
	}

	int gap;
	int LevelN = 1;
	int maxLevel[2];
	maxLevel[0] = -1;
	while(1){
		if(Level[LevelN][0] == MAX) break;
		gap = Level[LevelN][1] - Level[LevelN][0] + 1;
		if(maxLevel[0] < gap){
			maxLevel[0] = gap;
			maxLevel[1] = LevelN;
		}
		LevelN++;
	}
	cout << maxLevel[1] << " " << maxLevel[0];
}

void solve(){
	int rootNode = input();
	init();
	getLineNum(rootNode,0,1);
	output();
}

int main(){
	solve();
}