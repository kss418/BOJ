#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;

const ll MAX = 201010;
ll n, m, l, black;
pair <ll, ll> a[MAX];

bool decision(ll cur){
    ll cnt = 0, last = -1e12;
    for(int i = 1;i <= black;i++){
        if(a[i].second > cur) return 0;
        if(a[i].first - last + 1 <= cur) continue;
        last = a[i].first; cnt++;
    }

    return cnt <= l;
}

ll minimization(){
    ll lo = 1, hi = 2e6;
    while(lo < hi){
        ll mid = (lo + hi) / 2;
        if(decision(mid)) hi = mid;
        else lo = mid + 1;
    }

    return lo;
}

int main(){
    ios::sync_with_stdio(0); // fastio
    cin.tie(0), cout.tie(0); // fastio

    cin >> n >> m >> l >> black;
    for(int i = 1;i <= black;i++) cin >> a[i].second >> a[i].first;
    sort(a + 1, a + black + 1); 

    cout << minimization();

    return 0;
}





