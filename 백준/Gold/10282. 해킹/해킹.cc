#include <iostream>
#include <vector>
#include <queue> 
using namespace std;
using ll = long long;

const ll MAX = 10101;
const ll INF = 1e12;
ll n, m, k, d[MAX];
vector <pair<ll, ll>> adj[MAX];

using pll = pair<ll, ll>;
priority_queue <pll, vector<pll>, greater<pll>> pq;

void init(){
    while(!pq.empty()) pq.pop();
    for(int i = 1;i <= n;i++) adj[i].clear();
}

void run(){
    cin >> n >> m >> k; init();
    while(m--){
        ll s, e, c; cin >> s >> e >> c;
        adj[e].push_back({s, c});
    }

    for(int i = 0;i < MAX;i++) d[i] = INF;
    pq.push({0, k});

    while(!pq.empty()){
        auto[cd, cur] = pq.top(); pq.pop();
        if(d[cur] <= cd) continue;
        d[cur] = cd;

        for(auto& [nxt, co] : adj[cur]){
            if(d[nxt] <= cd + co) continue;
            pq.push({cd + co, nxt});
        }
    }

    ll cnt = 0, result = 0;
    for(int i = 1;i <= n;i++){
        if(d[i] == INF) continue;
        cnt++; result = max(result, d[i]);
    }

    cout << cnt << " " << result << "\n";
}

int main(){
    ios::sync_with_stdio(0); // fastio
    cin.tie(0), cout.tie(0); // fastio

    ll t; cin >> t;
    while(t--) run();

    return 0;
}

