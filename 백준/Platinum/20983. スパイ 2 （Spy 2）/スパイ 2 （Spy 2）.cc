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
constexpr ll MAX = 301010; // SET MAX SIZE
constexpr ll MOD = 998244353;
constexpr ll MID = 300010;
ll a[MAX], nxt[MAX], ind[MAX], result[MAX];
vector <ll> adj[MAX];
deque <ll> q;

void add(ll s, ll e){
    ind[e]++;
    adj[s].push_back(e);
}

void run(){
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        if(a[i] == 3) continue;
        result[i] = a[i];
        if(a[i] == 1) q.push_back(i);
    }

    for(int i = 1;i <= m;i++){
        ll a, b, c; cin >> a >> b >> c;
        add(a, i); add(b, i);
        nxt[i] = c;
    }

    while(!q.empty()){
        auto cur = q.front(); q.pop_front();
        for(auto& v : adj[cur]){
            if(--ind[v] || result[nxt[v]] == 1) continue;
            if(result[nxt[v]] == 2){ cout << -1; return; }
            result[nxt[v]] = 1; q.push_back(nxt[v]);
        }
    }

    for(int i = 1;i <= n;i++){
        cout << (result[i] ? result[i] : 2) << "\n";
    }
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}