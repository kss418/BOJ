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
using i128 = __int128_t; using f128 = __float128; 
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t = 1; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MINF = 0xc0c0c0c0c0c0c0c0;
constexpr ll MAX = 101010; // SET MAX SIZE
constexpr ll MOD = 998244353;
vector <pll> adj[MAX];
bool v[MAX];

class node{
public:
    ll a, b;
    node() : node(0, 0){} 
    node(ll a, ll b) : a(a), b(b){}
    node op(ll num){
        return {-a, num - b};
    }

    node operator + (const node& ot) const{
        return {a + ot.a, b + ot.b};
    }
    
    ll f(ll x){ return a * x + b; }
} arr[MAX];

vector <tll> cycle;
void dfs(ll cur, ll pre = -1){
    v[cur] = 1;
    for(auto& nn : adj[cur]){
        auto[nxt, co] = nn;
        if(nxt == pre) continue;
        if(v[nxt]) cycle.push_back({cur, nxt, co});
        else{
            arr[nxt] = arr[cur].op(co);
            dfs(nxt);
        }  
    }
}

void run(){
    cin >> n >> m;
    while(m--){
        ll s, e, c; cin >> s >> e >> c;
        adj[s].push_back({e, c});
        adj[e].push_back({s, c});
    }

    arr[1] = {1, 0}; dfs(1);
    bool fix = 0; ll v = 0;
    for(auto& i : cycle){
        auto[s, e, c] = i;
        auto[a, b] = arr[s] + arr[e];

        if(a){
            if((c - b) % a){ cout << "NO"; return; }
            if(fix && v != (c - b) / a){ cout << "NO"; return; }
            v = (c - b) / a; fix = 1;
        }
        else if(b != c){ cout << "NO"; return; }
    }

    cout << "Yes\n";
    if(!fix){
        vector <ll> vec;
        for(int i = 1;i <= n;i++){
            auto[a, b] = arr[i];
            vec.push_back(b * (a >= 1 ? -1 : 1));
        }
        sort(all(vec));
        v = vec[(vec.size() - 1) / 2];
    }
    
    for(int i = 1;i <= n;i++) cout << arr[i].f(v) << " ";
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}