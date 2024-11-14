#include <bits/stdc++.h>
#include <ext/rope>
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
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX];

template <typename T = ll> //query type
class _hld { // 구간 예외 처리하기
public:
    vector <vector <ll>> adj;
    vector <ll> sz, top, d, in, out, p;
    ll n, cnt = 0;
    class node{
    public:
        T v;
        node() : node(0){}
        node(ll v) {
            this->v = v;
        }

        node operator + (node ot){ // update, query
            T now = max(v, ot.v);
            return node(now);
        }

        node operator += (T ot){ // add
            v += ot;
            return node(v);
        }

        operator T(){ // update -> query
            return v;
        }
    };
    vector <node> seg;

    _hld(ll n){
        this->n = n;
        adj.resize(n + 1); sz.resize(n + 1);
        in.resize(n + 1); out.resize(n + 1);
        d.resize(n + 1); p.resize(n + 1);
        top.resize(n + 1); seg.resize(4 * n + 1);
    }

    void add(ll s, ll e){
        addsol(s, e); addsol(e, s);
    }   
    void addsol(ll s, ll e, ll c = 1){ adj[s].push_back(e); }

    void dfs1(ll cur, ll pre){
        sz[cur] = 1;
        for(auto& nxt : adj[cur]){
            if(nxt == pre) continue;
            d[nxt] = d[cur] + 1; p[nxt] = cur;
            dfs1(nxt, cur); sz[cur] += sz[nxt];
            if(sz[nxt] > sz[adj[cur][0]]) swap(nxt, adj[cur][0]);
        }
    }

    void dfs2(ll cur, ll pre){
        in[cur] = ++cnt;
        for(auto& nxt : adj[cur]){
            if(nxt == pre) continue;
            top[nxt] = (nxt == adj[cur][0] ? top[cur] : nxt);
            dfs2(nxt, cur);
        }
        out[cur] = cnt;
    }

    void init(ll cur = 1){
        dfs1(cur, -1); dfs2(cur, -1);
    }

    node query(ll st, ll en, ll l, ll r, ll node = 1) {
        if (en < l || st > r) return _hld::node();
        if (st <= l && en >= r) return seg[node];
        ll mid = (l + r) >> 1;
        return query(st, en, l, mid, node * 2) + query(st, en, mid + 1, r, node * 2 + 1);
    }
    T query(ll st, ll en) { 
        node ret;
        while(top[st] != top[en]){
            if(d[top[st]] < d[top[en]]) swap(st, en);
            ll cur = top[st];
            ret = ret + query(in[cur], in[st], 0, n);
            st = p[cur];
        }

        if(d[st] > d[en]) swap(st, en);
        ret = ret + query(in[st] + 1, in[en], 0, n);
        return ret; 
    }

    void update(ll idx, ll val) { update(in[idx], val, 0, n); }
    node update(ll idx, ll val, ll l, ll r, ll node = 1) {
        if (idx < l || idx > r) return seg[node];
        if (l == r) return seg[node] = val;
        ll mid = (l + r) >> 1;

        seg[node] = update(idx, val, l, mid, node * 2) + update(idx, val, mid + 1, r, node * 2 + 1);
        return seg[node];
    }

    void segadd(ll idx, ll val) { segadd(in[idx], val, 0, n); }
    void segadd(ll idx, ll val, ll l, ll r, ll node = 1) {
        if (idx < l || idx > r) return;
        seg[node] += val;
        if (l == r) return;
        ll mid = (l + r) >> 1;

        segadd(idx, val, l, mid, node * 2);
        segadd(idx, val, mid + 1, r, node * 2 + 1);
    }
};

int main() {
    fastio;

    cin >> n >> m; _hld hld(n);
    for(int i = 2;i <= n;i++){
        ll p; cin >> p;
        hld.add(p, i);
    }
    hld.init();

    while(m--){
        ll s, e, com; cin >> s >> e >> com;
        ll q = hld.query(s, e);
        if(!q){
            cout << "YES\n";
            if(com) hld.update(s, 1);
        }
        else {
            cout << "NO\n";
            if(com) hld.update(e, 1);
        }
    }


    return 0;
}

