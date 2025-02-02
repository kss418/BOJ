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
constexpr ll MAX = 101010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll p[MAX], c[MAX];
set <ll> cnt;
bool v[MAX];
vector <ll> tr;

ll lca(ll a, ll b){
    tr.clear();
    for(int i = 0;i < 1000;i++){
        v[a] = 1; tr.push_back(a);
        if(!a) break; a = p[a];
    }

    for(int i = 0;i < 1000;i++){
        if(v[b]) {
            for(auto& i : tr) v[i] = 0;
            return b; 
        }
        b = p[b];
    }
    
    for(auto& i : tr) v[i] = 0;
    return 0;
}

void paint(ll a, ll b, ll v){
    ll l = lca(a, b);
    while(b != l){ c[b] = v; b = p[b]; }
    while(a != l){ c[a] = v; a = p[a]; }
}

ll count(ll a, ll b){
    cnt.clear(); ll l = lca(a, b);
    while(b != l){ cnt.insert(c[b]); b = p[b]; }
    while(a != l){ cnt.insert(c[a]); a = p[a]; }

    return cnt.size();
}

void run(){
    cin >> n >> m;
    while(m--){
        ll op, a, b; cin >> op >> a >> b;
        if(op == 1){
            ll v; cin >> v;
            paint(a, b, v);
        }
        else if(op == 2) p[a] = b;
        else cout << count(a, b) << "\n";
    }
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

