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
ll sum, flag = 1;
vector <pll> adj;

void run(){
    cin >> n >> m;
    while(m--){
        ll s, e; cin >> s >> e;
        adj.push_back({s, e});
        sum += e - s + 1;
    }

    sort(all(adj), [](pll a, pll b){
        if(a.x != b.x) return a.x > b.x;
        return a.y > b.y;
    });
    
    flag &= (sum == n - 1);
    if(flag){
        for(auto& [s, e] : adj) cout << s << " " << e << "\n";
    }
    else cout << -1;
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}