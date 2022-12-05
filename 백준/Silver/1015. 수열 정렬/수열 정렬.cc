#include <bits/stdc++.h>

using namespace std;

int main(){
    pair<int,int> arr[1000],input[1000];
    int N;

    cin >> N;

    for(int i=0;i<N;i++){
        cin >> input[i].first;
        arr[i] = {input[i].first,i};
    }

    sort(arr, arr+N);

    for(int i=0;i<N;i++){
        input[arr[i].second].second = i;
    }

    for(int i=0;i<N;i++){
	cout << input[i].second << " ";
    }
}