#include <iostream>
#include <vector>
#include <queue> 
using namespace std;
using ll = long long;

const ll MAX = 1010;
const ll INF = 1e12;
ll n, m, x, d[MAX][2];
vector <pair<ll, ll>> adj[MAX][2];

using pll = pair<ll, ll>;
priority_queue <pll, vector<pll>, greater<pll>> pq;

int main(){
    ios::sync_with_stdio(0); // fastio
    cin.tie(0), cout.tie(0); // fastio

    cin >> n >> m >> x;
    while(m--){
        ll s, e, c; cin >> s >> e >> c;
        adj[s][0].push_back({e, c});
        adj[e][1].push_back({s, c});
    }

    for(int i = 0;i < MAX;i++){
        for(int j = 0;j < 2;j++) d[i][j] = INF;
    }

    for(int i = 0;i <= 1;i++){
        while(!pq.empty()) pq.pop();
        pq.push({0, x});

        while(!pq.empty()){
            auto[cd, cur] = pq.top(); pq.pop();
            if(d[cur][i] <= cd) continue;
            d[cur][i] = cd;

            for(auto& [nxt, co] : adj[cur][i]){
                if(d[nxt][i] <= cd + co) continue;
                pq.push({cd + co, nxt});
            }
        }
    }

    ll result = 0;
    for(int i = 1;i <= n;i++){
        result = max(result, d[i][0] + d[i][1]);
    }
    cout << result;

    return 0;
}

