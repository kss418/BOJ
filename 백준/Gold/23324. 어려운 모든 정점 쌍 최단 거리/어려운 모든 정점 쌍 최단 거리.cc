#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; typedef long long ll;
using ld = long double;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 201010;
constexpr ll MOD = 998244353;
pll arr[MAX];
vector <ll> adj[MAX];
bool v[MAX];

class _uf { 
public:
    ll n; vector <ll> p, si;
    
    _uf(){}
    _uf(ll n) { 
        this->n = n;
        p.resize(n + 1); si.resize(n + 1);
        fill(all(p), -1);
        fill(all(si), 1);
    }

    ll find(ll num) { 
        if (p[num] == -1) return num;
        return p[num] = find(p[num]);
    }

    void merge(ll a, ll b) {
        a = find(a); b = find(b);
        if (a == b) return;
        if (a < b) swap(a, b);
        p[b] = a, si[a] += si[b];
    }

    ll size(ll num){
        return si[find(num)];
    }

    ll same(ll a, ll b) {
        if (find(a) == find(b)) return 1;
        return 0;
    }
};

_uf uf;
void dfs(ll cur, ll pre){
    if(v[cur]) return; v[cur] = 1;
    for(auto& nxt : adj[cur]){
        if(nxt == pre) continue;
        dfs(nxt, cur);
        uf.merge(nxt, cur);
    }
}

int main() {
    fastio;

    cin >> n >> m >> k; uf = {n};
    for(int i = 1;i <= m;i++){
        auto&[x, y] = arr[i];
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    auto [x, y] = arr[k];
    dfs(x, y); dfs(y, x);

    if(uf.same(x, y)) cout << 0;
    else cout << uf.size(x) * uf.size(y);


    return 0;
}