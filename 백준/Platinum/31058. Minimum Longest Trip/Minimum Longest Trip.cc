#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; using ll = long long;
using ld = long double; using pld = pair<ld, ld>;
using i128 = __int128_t; using f128 = __float128; 
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t = 1; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MINF = 0xc0c0c0c0c0c0c0c0;
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], ind[MAX];
ll len[MAX], sum[MAX], r[MAX];
vector <pll> adj[MAX], rev[MAX];
deque <ll> q;
vector <ll> top, arr[MAX];

void run(){
    cin >> n >> m;
    while(m--){
        ll s, e, c; cin >> s >> e >> c;
        adj[s].push_back({e, c});
        rev[e].push_back({s, c});
        ind[s]++;
    }

    for(int i = 1;i <= n;i++) if(!ind[i]) q.push_back(i);
    while(!q.empty()){
        auto cur = q.front(); q.pop_front();
        top.push_back(cur);
        for(auto& [nxt, co] : rev[cur]){
            len[nxt] = max(len[nxt], len[cur] + 1);
            if(!--ind[nxt]) q.push_back(nxt);
        }
    }

    for(int i = 1;i <= n;i++) arr[len[i]].push_back(i);

    ll cnt = 0;
    for(int i = 1;i <= n;i++){
        vector <pair<pll, ll>> tmp;
        for(auto& cur : arr[i]){
            pair<pll, ll> now = {{INF, INF}, -1};
            ll idx = -1;
            for(auto& [nxt, co] : adj[cur]){
                if(len[nxt] != i - 1) continue;
                pair <pll, ll> num = {{co, r[nxt]}, cur};
                if(now < num) continue;
                now = num; idx = nxt;
            }

            sum[cur] += sum[idx] + now.x.x;
            tmp.push_back(now);
        }

        sort(all(tmp));
        pll pre = {-1, -1};
        for(auto& [node, cur] : tmp){
            auto& [co, rank] = node;
            if(pre != pll(co, rank)) ++cnt;
            r[cur] = cnt;
            pre = {co, rank};
        }
    }

    for(int i = 1;i <= n;i++) cout << len[i] << " " << sum[i] << "\n";
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}