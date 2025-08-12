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
constexpr ll MAX = 101010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], b[MAX], cnt, result;
vector <pll> adj[MAX]; 
priority_queue <pll, vector<pll>, greater<pll>> pq;
bool v[MAX];

void run(){
    cin >> n >> m;
    for(int i = 1;i <= n;i++) cin >> a[i], b[i] = a[i];

    cin >> k;
    while(k--){
        ll s, e, c; cin >> s >> e >> c;
        b[e] += c; adj[s].push_back({e, c});
    }

    for(int i = 1;i <= n;i++) pq.push({b[i], i});
    while(!pq.empty()){
        auto[num, cur] = pq.top(); pq.pop();
        if(v[cur]) continue; v[cur] = 1; cnt++;
        result = max(result, num); if(cnt == m) break;

        for(auto& [nxt, co] : adj[cur]){
            b[nxt] -= co;
            pq.push({b[nxt], nxt});
        }
    }

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}