#include <iostream>
#include <vector>
#include <queue> 
using namespace std;
using ll = long long;

const ll MAX = 201010;
const ll INF = 1e12;
ll n, m, d[MAX];
vector <pair<ll, ll>> adj[MAX];
ll a[MAX], b[MAX];

using pll = pair<ll, ll>;
priority_queue <pll, vector<pll>, greater<pll>> pq;

int main(){
    ios::sync_with_stdio(0); // fastio
    cin.tie(0), cout.tie(0); // fastio

    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 1;i <= n;i++) cin >> b[i];

    for(int i = 1;i <= n;i++){
        ll nx = i - a[i];
        // 다음 정점이 0 이하면 0과 연결
        if(nx <= 0) adj[0].push_back({i, b[i]});
        // 아니면 다음 정점과 연결
        else adj[nx].push_back({i, b[i]});

        nx = i + a[i];
        // 다음 정점이 n 초과면 0과 연결
        if(nx > n) adj[0].push_back({i, b[i]});
        // 아니면 다음 정점과 연결
        else adj[nx].push_back({i, b[i]});
    }


    for(int i = 0;i < MAX;i++) d[i] = INF;
    pq.push({0, 0});

    while(!pq.empty()){
        auto[cd, cur] = pq.top(); pq.pop();
        if(d[cur] <= cd) continue;
        d[cur] = cd;

        for(auto& [nxt, co] : adj[cur]){
            if(d[nxt] <= cd + co) continue;
            pq.push({cd + co, nxt});
        }
    }

    for(int i = 1;i <= n;i++) cout << d[i] << " ";

    return 0;
}