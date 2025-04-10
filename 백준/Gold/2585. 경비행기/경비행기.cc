#include <iostream>
#include <queue>
using namespace std;
using ll = long long;

const ll MAX = 1010;
const ll INF = 1e9;
ll n, m, d[MAX];
pair <ll, ll> a[MAX];

ll dist(pair <ll, ll> a, pair <ll, ll> b){
    ll dx = a.first - b.first;
    ll dy = a.second - b.second;
    return dx * dx + dy * dy;
}

bool decision(ll num){
    num *= 10;
    queue <ll> q;
    for(int i = 1;i <= n + 1;i++) d[i] = INF;
    d[0] = 0; q.push(0);

    while(!q.empty()){
        ll cur = q.front(); q.pop();
        for(auto nxt = 1;nxt <= n + 1;nxt++){
            if(dist(a[nxt], a[cur]) > num * num) continue;
            if(d[nxt] != INF) continue;
            
            q.push(nxt);
            d[nxt] = d[cur] + 1;
        }
    }

    return d[n + 1] - 1 <= m;
}

ll minimization(){
    ll lo = 0, hi = 1e5;
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
    for(int i = 1;i <= n;i++) cin >> a[i].first >> a[i].second;
    a[n + 1] = { 10000, 10000 };

    cout << minimization();

    return 0;
}