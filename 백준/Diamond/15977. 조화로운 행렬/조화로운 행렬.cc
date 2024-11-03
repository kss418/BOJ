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
using ld = long double;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 201010;
constexpr ll MOD = 998244353;
map <ll, ll> xm, ym, zm;
vector <ll> xv, yv, zv;
ll seq;

class _mxseg {
public:
    ll n; vector <ll> arr, seg;
    _mxseg(ll n) {
        this->n = n;
        arr.resize(n + 1); seg.resize(4 * n + 1);
    }

    void con(ll idx, ll val) { arr[idx] = val; }

    void init() { init(1, n); }
    ll init(ll l, ll r, ll node = 1) {
        if (l == r) return seg[node] = arr[l];
        ll mid = (l + r) >> 1;
        seg[node] = max(init(l, mid, node * 2), init(mid + 1, r, node * 2 + 1));
        return seg[node];
    }

    ll query(ll st, ll en) { return query(st, en, 0, n); }
    ll query(ll st, ll en, ll l, ll r, ll node = 1) {
        if (en < l || st > r) return -INF;
        if (st <= l && en >= r) return seg[node];
        ll mid = (l + r) >> 1;
        return max(query(st, en, l, mid, node * 2), query(st, en, mid + 1, r, node * 2 + 1));
    }

    ll update(ll idx, ll val) { return update(idx, val, 0, n); }
    ll update(ll idx, ll val, ll l, ll r, ll node = 1) {
        if (idx < l || idx > r) return seg[node];
        if (l == r) return seg[node] = val;
        ll mid = (l + r) >> 1;

        seg[node] = max(update(idx, val, l, mid, node * 2), update(idx, val, mid + 1, r, node * 2 + 1));
        return seg[node];
    }
};

class node{
public:
    ll x, y, z;
    bool operator <(node& ot){
        return x < ot.x;
    }
};
node a[MAX];

void init(){
    for(int i = 1;i <= m;i++) {
        xv.push_back(a[i].x);
        yv.push_back(a[i].y);
        if(n == 3) zv.push_back(a[i].z);
    }
    sort(all(xv)); sort(all(yv)); sort(all(zv));

    for(auto& i : xv) if(!xm.count(i)) xm[i] = ++seq; seq = 0;
    for(auto& i : yv) if(!ym.count(i)) ym[i] = ++seq; seq = 0;
    for(auto& i : zv) if(!zm.count(i)) zm[i] = ++seq;

    for(int i = 1;i <= m;i++){
        a[i].x = xm[a[i].x];
        a[i].y = ym[a[i].y];
        if(n == 3) a[i].z = zm[a[i].z];
    }
}

int main() {
    fastio;

    cin >> n >> m; _mxseg seg(m);
    for(int i = 1;i <= m;i++) cin >> a[i].x;
    for(int i = 1;i <= m;i++) cin >> a[i].y;
    if(n == 3) for(int i = 1;i <= m;i++) cin >> a[i].z;
    init();
    
    sort(a + 1, a + m + 1);
    ll result = 0;
    for(int i = 1;i <= m;i++){
        ll cur = seg.query(0, a[i].y - 1);
        seg.update(a[i].y, cur + 1);
        result = max(result, cur + 1);
    }

    cout << result;

    
    return 0;
}