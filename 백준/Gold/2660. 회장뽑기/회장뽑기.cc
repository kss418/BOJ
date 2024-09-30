#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; typedef long long ll;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 101;
constexpr ll MOD = 998244353;
vector <ll> adj[MAX], result;
ll dep[MAX];

void bfs(ll cur, ll d){
    deque <pll> q;
    q.push_back({cur, d});

    while(!q.empty()){
        auto [cc, cd] = q.front(); q.pop_front();
        if(dep[cc] <= cd) continue;
        dep[cc] = cd;

        for(auto& nxt : adj[cc]) q.push_back({nxt, cd + 1});
    }
}


int main() {
    fastio;

    cin >> n;
    while(1){
        ll s, e;
        cin >> s >> e;
        if(s == -1) break;

        adj[s].push_back(e);
        adj[e].push_back(s);
    }

    ll mn = INF;
    for(int i = 1;i <= n;i++){
        memset(dep, 0x3f, sizeof(dep));
        bfs(i, 0);

        ll mx = 0;
        for(int j = 1;j <= n;j++){
            if(i == j) continue;
            mx = max(mx, dep[j]);
        }

        if(mx < mn) result.clear();
        if(mx <= mn){
            mn = mx; result.push_back(i);
        }
    }

    cout << mn << " " << result.size() << "\n";
    for(auto& i : result) cout << i << " ";
    
  
    return 0;
}