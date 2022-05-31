#include <iostream>
#include <array>
#include <queue>
#define INF 100001
using namespace std;

int main()
{
	int S, F;
	int arr[100000];
	for (int& i : arr) i = INF;
	std::queue<int> Q;
	cin >> S >> F;
	arr[S] = 0;
	Q.push(S);
	while (!Q.empty())
	{
		int now = Q.front();
		Q.pop();
		if (arr[now] + 1 < arr[now + 1]&&now+1<INF){
			arr[now + 1] = arr[now] + 1;
			Q.push(now + 1);
		}
		if(arr[now] + 1 < arr[now - 1] && now - 1>=0) {
			arr[now - 1] = arr[now] + 1;
			Q.push(now - 1);
		}
		if (now * 2 >= INF) continue;
		if (arr[now] + 1 < arr[now*2]) {
			arr[now*2] = arr[now] + 1;
			Q.push(now*2);
		}
	}
	cout << arr[F];
	return 0;
}