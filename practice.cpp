#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define read(v) for(auto &ele: v) cin >> ele;
long long gcd(long long a, long long b){
    return b == 0? a: gcd(b, a % b);
}

void solve(){

    int n; cin >> n;
    vi v(n+1);
    read(v);
    int last = v[n];
    sort(v.begin(), v.end());
    int i = 0;
    long long sum = 0;
    for(auto ele: v){
        sum += ele;
    }
    
    while(i <= n && v[i] <= last) i++;
    while(i <= n && v[i] <= 2 * v[i-1]) i++;

    sum -= v[i-1];
    // cout << i << endl;

    cout << sum << endl;
}

int main() {
    int t; cin >> t;
    while(t--) solve();
}
