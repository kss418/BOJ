#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;

const ll MAX = 201010;
ll a[MAX], n, m;

bool decision(ll cur){
    ll cnt = 0, last = -1e12;
    for(int i = 1;i <= n;i++){
        if(a[i] - last < cur) continue;
        last = a[i]; cnt++;
    }

    return cnt >= m;
}

ll maximization(){
    ll lo = 1, hi = 2e9;
    while(lo < hi){
        ll mid = (lo + hi + 1) / 2;
        if(decision(mid)) lo = mid;
        else hi = mid - 1;
    }

    return lo;
}

int main(){
    ios::sync_with_stdio(0); // fastio
    cin.tie(0), cout.tie(0); // fastio

    cin >> n >> m;
    for(int i = 1;i <= n;i++) cin >> a[i];
    sort(a + 1, a + n + 1);

    cout << maximization();

    return 0;
}



