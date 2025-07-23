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
ll a[MAX], result[MAX];
vector <pll> vec;

template <typename T = ll> // query type
class _seg { // 구간 예외 처리하기
public:
    ll n;
    class node{
    public:
        ll l, r, len, ret;
        node() : node(0, 0, 0, 0){}
        node(ll l, ll r, ll len, ll ret) : l(l), r(r), len(len), ret(ret) {}
        
        node operator += (node ot){ // add
            return node();
        }

        operator T(){ // update -> query
            return ret;
        }
    };
    vector <node> seg;

    _seg(){}
    _seg(ll n) { this->n = n; seg.resize(4 * n + 1, node()); }

    node merge(const node& l, const node& r){
        node ret;
        ret.l = l.l; ret.r = r.r;
        ret.len = l.len + r.len;
        if(l.l == l.len) ret.l = l.l + r.l;
        if(r.r == r.len) ret.r = r.r + l.r;
        ret.ret = max({l.ret, r.ret, l.r + r.l, ret.l, ret.r});
        return ret;
    }

    T query(ll st, ll en) { return query(st, en, 0, n); }
    node query(ll st, ll en, ll l, ll r, ll node = 1) {
        if (en < l || st > r) return _seg::node();
        if (st <= l && en >= r) return seg[node];
        ll mid = (l + r) >> 1;
        return merge(query(st, en, l, mid, node * 2), query(st, en, mid + 1, r, node * 2 + 1));
    }

    node update(ll idx, ll val) { return update(idx, val, 0, n); }
    node update(ll idx, ll val, ll l, ll r, ll node = 1) {
        if (idx < l || idx > r) return seg[node];
        if (l == r) {
            if(val) seg[node] = {1, 1, 1, 1};
            else seg[node] = {0, 0, 1, 0};
            return seg[node];
        }
        ll mid = (l + r) >> 1;
        return seg[node] = merge(update(idx, val, l, mid, node * 2), update(idx, val, mid + 1, r, node * 2 + 1));;
    }

    void add(ll idx, ll val) { add(idx, val, 0, n); }
    void add(ll idx, ll val, ll l, ll r, ll node = 1) {
        if (idx < l || idx > r) return;
        seg[node] += val;
        if (l == r) return;
        ll mid = (l + r) >> 1;
        add(idx, val, l, mid, node * 2);
        add(idx, val, mid + 1, r, node * 2 + 1);
    }

    void clear(){ for(int i = 1;i <= n;i++) update(i, 0); }
}; _seg seg;

class _pbs{
public:
    ll lo, hi;
    vector <ll> l, r;
    vector <vector <ll>> arr;

    _pbs(){}
    _pbs(ll lo, ll hi) : lo(lo), hi(hi){}

    class query{ 
    public:
        ll l, r, v;
    }; vector <query> q;
    void add(query a){ q.push_back(a); }

    void clear(){
        for(int i = lo;i <= hi;i++) arr[i].clear();
        seg.clear();
    }

    bool f(ll cur, ll idx){ // 결정 함수
        query& now = q[idx];
        auto& [l, r, v] = now;
        ll q = seg.query(l, r);

        return q >= v;
    }

    void init(){
        arr.resize(hi + 1);
        l.resize(q.size(), lo); r.resize(q.size(), hi);

        while(1){
            clear(); bool flag = 0;
            for(int i = 0;i < q.size();i++){
                if(l[i] >= r[i]) continue;
                ll mid = (l[i] + r[i]) >> 1ll;
                arr[mid].push_back(i); flag = 1;
            }
            if(!flag) break;
            
            ll num = 0;
            for(ll mid = lo;mid <= hi;mid++){
                while(num < vec.size() && num < mid){
                    auto& [x, y] = vec[num]; num++;
                    seg.update(y, 1);
                }

                for(auto& idx : arr[mid]){
                    if(f(mid, idx)) {
                        r[idx] = mid;
                        result[idx] = max(result[idx], vec[mid - 1].x);
                    }
                    else l[idx] = mid + 1;
                }
            }
        }
    }
};

void run(){
    cin >> n; seg = {n}; _pbs pbs(1, n + 1);
    for(int i = 1;i <= n;i++) cin >> a[i], vec.push_back({a[i], i});
    sort(all(vec)); reverse(all(vec));

    cin >> m;
    while(m--){
        ll l, r, v; cin >> l >> r >> v;
        pbs.add({l, r, v});
    }

    pbs.init();
    for(int i = 0;i < pbs.q.size();i++) cout << result[i] << "\n";
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

