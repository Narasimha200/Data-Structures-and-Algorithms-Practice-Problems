#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    if(n == 1) cout << 0 << endl;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr, arr + n);
    int minDiff = INT_MAX;
    for(int i = 1; i < n; i++){
        minDiff = min(arr[i] - arr[i-1]);
    }

    cout << minDiff + arr[n-2] + arr[n-1] << endl;
}

int main(){
    int t; cin >> t;
    while(t--){
        solve();
    }
}