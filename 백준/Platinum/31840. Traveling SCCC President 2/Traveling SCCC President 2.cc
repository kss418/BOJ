#include <bits/stdc++.h>
#include <ext/rope>
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
constexpr ll MAX = 301010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX];
vector <pll> adj[MAX];
bool v[MAX];
deque <ll> q;

void run(){
    cin >> n >> m;
    while(m--){
        ll s, e, c; cin >> s >> e >> c;
        adj[s].push_back({e, c});
        adj[e].push_back({s, c});
    }
    
    ll result = (1ll << 60) - 1;
    for(int i = 59;i >= 0;i--){
        memset(v, 0, sizeof(v));
        result &= ~(1ll << i);

        q.push_back(1);
        while(!q.empty()){
            auto cur = q.front(); q.pop_front();
            if(v[cur]) continue; v[cur] = 1;

            for(auto& [nxt, co] : adj[cur]){
                if((co | result) == result) q.push_back(nxt);
            }
        }

        if(!v[n]) result |= (1ll << i);
    }

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

