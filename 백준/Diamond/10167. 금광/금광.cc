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
constexpr ll MAX = 3010; // SET MAX SIZE
constexpr ll MOD = 998244353;
pll a[MAX]; ll co[MAX];


template <typename T = ll> // query type
class _seg { // 구간 예외 처리하기
public:
    ll n;
    class node{
    public:
        ll lmx, rmx, sum, ret;
        node() : node(0, 0, 0, 0){}
        node(ll lmx, ll rmx, ll sum, ll ret) : lmx(lmx), rmx(rmx), sum(sum), ret(ret) {}
        
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

    node merge(node l, node r){
        return{
            max(l.lmx, l.sum + r.lmx),
            max(r.rmx, r.sum + l.rmx),
            l.sum + r.sum,
            max({l.ret, r.ret, l.rmx + r.lmx })
        };
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
            seg[node].sum += val;
            seg[node].lmx += val;
            seg[node].rmx += val;
            seg[node].ret += val;
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

    void clear(){
        seg.clear(); seg.resize(4 * n + 1, node());
    }
};

vector <ll> xv, yv;
vector <pll> arr[MAX];
map <ll, ll> xc, yc;
void comp(vector<ll>& v, map <ll, ll>& c){
    sort(all(v)); ll cnt = 0;
    for(auto& i : v){
        if(!c.count(i)) c[i] = ++cnt;
    }
}   

void run(){
    cin >> n; _seg seg(n);
    for(int i = 1;i <= n;i++) {
        cin >> a[i].x >> a[i].y >> co[i];
        xv.push_back(a[i].x);
        yv.push_back(a[i].y);
    }

    comp(xv, xc); comp(yv, yc); 
    for(int i = 1;i <= n;i++){
        a[i] = {xc[a[i].x], yc[a[i].y]};
        arr[a[i].x].push_back({a[i].y, co[i]});
    }

    ll result = MINF;
    for(int i = 1;i <= n;i++){
        seg.clear();
        for(int j = i;j <= n;j++){
            for(auto& k : arr[j]) seg.update(k.x, k.y);
            result = max(result, seg.query(1, n));
        }
    }

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

