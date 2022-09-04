#include <bits/stdc++.h>
#define MAX 1000001
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	int tree[4000004];
	int a, b, c;

	cin >> n;

	function<void(int,int,int,int,int)> update = [&](int index, int target, int diff, int start, int end){
		if(target < start || target > end) return;
		tree[index] += diff;
		if(start == end) return;

		int mid = (start + end) / 2;
		update(index * 2, target, diff, start, mid);
		update(index * 2 + 1, target, diff, mid + 1, end);
	};

	function<int(int,int,int,int)> query = [&](int index, int target, int start, int end){
		if(start == end) return start;
		int mid = (start + end) / 2;

		if(target <= tree[index * 2]) return query(index * 2, target, start, mid);
		else return query(index * 2 + 1, target - tree[index*2], mid + 1, end);
	};


	while (n--) {
		cin >> a;
		if (a == 1) {
			cin >> b;
			int favor = query(1, b, 1, MAX);
			cout << favor << '\n';
			update(1, favor, -1, 1, MAX);
		}
		else {
			cin >> b >> c;
			update(1, b, c, 1, MAX);
		}
	}
	return 0;
}
