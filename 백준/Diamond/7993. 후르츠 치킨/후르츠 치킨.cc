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
constexpr ll MAX = 1000001; // SET MAX SIZE
constexpr ll MOD = 998244353;
vector <int> adj[MAX];
int a[MAX], d[MAX];
int in[MAX], seq;

template <typename T = ll> // query type
class _seg { // 구간 예외 처리하기
public:
    ll n, sz;
    class node{
    public:
        int v;
        node() : node(0){} // identity
        node(int v) : v(v) {}
        
        node operator += (node ot){ // add
            v += ot.v;
            return *this;
        }

        operator T(){ // query
            return v;
        }
    };
    vector <node> seg;

    _seg(){}
    _seg(ll n) : n(n){ 
        sz = 1; while(sz < n) sz <<= 1ll;
        seg.assign(2 * sz, _seg::node());
    }

    node merge(node l, node r){
        if(d[l.v] < d[r.v]) return l;
        return r;
    }

    node query(ll st, ll en) {
        st = max(1ll, st); en = min(n, en);
        if(st > en) return _seg::node();

        node l = _seg::node(), r = _seg::node();
        st += sz - 1; en += sz - 1;
        while(st <= en){
            if(st & 1) l = merge(l, seg[st++]);
            if(!(en & 1)) r = merge(seg[en--], r);
            st >>= 1; en >>= 1; 
        }

        return merge(l, r);
    }

    void set(ll idx, node val){
        if(idx < 1 || idx > n) return;
        ll p = idx + sz - 1;
        seg[p] = val;
        for(p >>= 1ll; p; p >>= 1){
            seg[p] = merge(seg[p << 1], seg[p << 1 | 1]);
        }
    }

    void add(ll idx, node val){
        if(idx < 1 || idx > n) return;
        ll p = idx + sz - 1;
        seg[p] += val;
        for(p >>= 1; p; p >>= 1){
            seg[p] = merge(seg[p << 1], seg[p << 1 | 1]);
        }
    }

    void clear(){ fill(all(seg), node()); }
}; _seg seg;

void dfs1(ll cur, ll pre = -1){
    in[cur] = ++seq;
    seg.set(seq, cur);
    for(auto& nxt : adj[cur]){
        if(nxt == pre) continue;
        d[nxt] = d[cur] + 1;
        dfs1(nxt, cur);
        seg.set(++seq, cur);
    }
}

void dfs2(ll cur, ll pre = -1){
    for(auto& nxt : adj[cur]){
        if(nxt == pre) continue;
        d[nxt] = d[cur] + 1;
        dfs2(nxt, cur);
    }
}

vector <int> arr, v1, v2;
void run(){
    cin >> n >> m >> k; seg = {2 * n};
    for(int i = 1;i < n;i++){
        ll s, e; cin >> s >> e;
        adj[s].push_back(e);
        adj[e].push_back(s);
    }

    d[0] = 0x3f3f3f3f; d[n] = 0; dfs1(n);
    ll q; cin >> q; ll l = 1;
    for(int i = 1;i <= q;i++){
        cin >> a[i];
        ll s = in[l], e = in[a[i]];
        if(s > e) swap(s, e);
        l = seg.query(s, e);
    }

    d[l] = 0; dfs2(l);
    for(int i = 1;i <= q;i++) arr.push_back(d[a[i]]);
    sort(all(arr));

    int now = -1;
    for(auto& i : arr){
        now = max(now + 1, i);
        v1.push_back(now);
    }

    for(int i = n;i >= n - k + 1;i--) v2.push_back(d[i]);
    sort(all(v2));
    while(v2.size() > v1.size()) v2.pop_back();
    reverse(all(v2));

    int result = 0;
    for(int i = 0;i < v1.size();i++) result = max(result, v1[i] + v2[i]);
    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}