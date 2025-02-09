#include <bits/stdc++.h>
#include <ext/rope>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; typedef long long ll;
using ld = long double; using pld = pair<ld, ld>;
using ull = unsigned long long; 
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t = 1; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MINF = 0xc0c0c0c0c0c0c0c0;
constexpr ll MAX = 10101; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], p[MAX], result;
vector <ll> adj[MAX];
ll idx, mx;

void init(ll cur, ll sum){
    sum += a[cur];
    for(auto& nxt : adj[cur]) init(nxt, sum);
    
    if(adj[cur].empty()){
        if(mx >= sum) return;
        mx = sum; idx = cur;
    }
}

void erase(ll cur){
    if(!cur) return;
    a[cur] = 0; erase(p[cur]);
}

void run(){
    cin >> n >> m;
    for(int i = 1;i <= n;i++) {
        cin >> p[i] >> a[i];
        adj[p[i]].push_back(i);
    }

    while(m--){
        mx = 0; init(0, 0);
        result += mx;
        erase(idx);
    }

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}