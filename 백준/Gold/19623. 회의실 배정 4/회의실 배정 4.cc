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
constexpr ll MAX = 101010; // SET MAX SIZE
constexpr ll MOD = 998244353;

template <typename T = ll> // query type
class _seg { // 구간 예외 처리하기
public:
    ll n;
    class node{
    public:
        ll v;
        node() : node(0){}
        node(ll v) {
            this->v = v;
        }

        node operator + (node ot){ // update
            ll now = max(v, ot.v);
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
    vector <node> seg, arr;

    _seg(){}
    _seg(ll n) {
        this->n = n;
        arr.resize(n + 1); seg.resize(4 * n + 1);
    }

    T query(ll st, ll en) { return query(st, en, 0, n); }
    node query(ll st, ll en, ll l, ll r, ll node = 1) {
        if (en < l || st > r) return _seg::node();
        if (st <= l && en >= r) return seg[node];
        ll mid = (l + r) >> 1;
        return query(st, en, l, mid, node * 2) + query(st, en, mid + 1, r, node * 2 + 1);
    }

    node update(ll idx, ll val) { return update(idx, val, 0, n); }
    node update(ll idx, ll val, ll l, ll r, ll node = 1) {
        if (idx < l || idx > r) return seg[node];
        if (l == r) return seg[node] = val;
        ll mid = (l + r) >> 1;

        seg[node] = update(idx, val, l, mid, node * 2) + update(idx, val, mid + 1, r, node * 2 + 1);
        return seg[node];
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
};

class node{
public:
    ll s, e, c;
    bool operator <(const node& ot) const{
        if(e != ot.e) return e < ot.e;
        return s < ot.s;
    }
} arr[MAX];
vector <ll> v;

void compress(){
    sort(all(v));
    map <ll, ll> cnt; ll num = 1;

    for(auto& i : v){
        if(!cnt.count(i)) cnt[i] = num++;
    }

    for(int i = 1;i <= n;i++){
        arr[i].s = cnt[arr[i].s];
        arr[i].e = cnt[arr[i].e];
    }
}

void run(){
    cin >> n; _seg seg(2 * MAX);
    for(int i = 1;i <= n;i++){
        ll s, e, c; cin >> s >> e >> c;
        arr[i] = {s, e, c};
        v.push_back(s); v.push_back(e);
    }
    compress(); sort(arr + 1, arr + n + 1);

    for(int i = 1;i <= n;i++){
        auto[s, e, c] = arr[i];
        ll q = seg.query(0, s);
        seg.update(e, max(q + c, seg.query(e, e)));
    }

    cout << seg.query(0, 2 * MAX - 1);
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}