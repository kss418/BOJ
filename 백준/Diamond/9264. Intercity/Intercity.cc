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
constexpr ll MAX = 501010; // SET MAX SIZE
constexpr ll MOD = 998244353;
vector <ll> adj[MAX];
map <pll, bool> cnt;
deque <ll> q;
ll d[MAX];
set <ll> num;

void run(){
    ll a, b; cin >> n >> m >> a >> b;
    while(m--){
        ll s, e; cin >> s >> e;
        adj[s].push_back(e);
        adj[e].push_back(s);
        cnt[{s, e}] = 1;
        cnt[{e, s}] = 1;
    }

    memset(d, 0x3f, sizeof(d));
    if(a == b) cout << a;
    else if(a < b){
        if(cnt[{1, n}]) cout << a;
        else{
            q.push_back(1); d[1] = 0;
            while(!q.empty()){
                auto cur = q.front(); q.pop_front();
                
                for(auto& nxt : adj[cur]){
                    if(d[nxt] <= d[cur] + 1) continue;
                    q.push_back(nxt);
                    d[nxt] = d[cur] + 1;
                }
            }

            if(d[n] == INF) cout << b;
            else cout << min(d[n] * a, b);
        }
    }
    else{
        if(!cnt[{1, n}]) cout << b;
        else{
            q.push_back(1); d[1] = 0;
            for(int i = 2;i <= n;i++) num.insert(i);
            while(!q.empty()){
                auto cur = q.front(); q.pop_front();

                for(auto& nxt : num){
                    if(d[nxt] <= d[cur] + 1) continue;
                    if(cnt.count({cur, nxt})) continue;
                    q.push_back(nxt);
                    d[nxt] = d[cur] + 1;
                    num.erase(num.find(nxt));
                }
            }

            if(d[n] == INF) cout << a;
            else cout << min(d[n] * b, a);
        }
    }
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

