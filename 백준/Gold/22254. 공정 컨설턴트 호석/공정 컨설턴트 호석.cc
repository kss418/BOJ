#include <iostream>
#include <queue>
using namespace std;
using ll = long long;

const ll MAX = 101010;
ll n, m, a[MAX];

bool decision(ll cur){
    priority_queue <ll, vector<ll>, greater<ll>> pq;
    for(int i = 1;i <= cur;i++) pq.push(0);

    ll mx = 0;
    for(int i = 1;i <= n;i++){
        ll now = pq.top(); pq.pop();
        pq.push(now + a[i]);
        mx = max(mx, now + a[i]);
    }

    return mx <= m;
}

ll maximization(){
    ll lo = 1, hi = 2e5;
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

    cin >> n >> m;
    for(int i = 1;i <= n;i++) cin >> a[i];
    cout << maximization();

    return 0;
}

