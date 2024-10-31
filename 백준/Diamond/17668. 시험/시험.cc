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
constexpr ll MAX = 101010;
constexpr ll MOD = 998244353;

class _sseg {
public:
    ll n; vector <ll> arr, seg;
    _sseg() {}
    _sseg(ll n) {
        this->n = n;
        arr.resize(n + 1); seg.resize(4 * n + 1);
    }

    void con(ll idx, ll val) { arr[idx] = val; }

    void init() { init(1, n); }
    ll init(ll l, ll r, ll node = 1) {
        if (l == r) return seg[node] = arr[l];
        ll mid = (l + r) >> 1;
        seg[node] = init(l, mid, node * 2) + init(mid + 1, r, node * 2 + 1);
        return seg[node];
    }

    ll query(ll st, ll en) { return query(st, en, 0, n); }
    ll query(ll st, ll en, ll l, ll r, ll node = 1) {
        if (en < l || st > r) return 0;
        if (st <= l && en >= r) return seg[node];
        ll mid = (l + r) >> 1;
        return query(st, en, l, mid, node * 2) + query(st, en, mid + 1, r, node * 2 + 1);
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

    ll update(ll idx, ll val) { return update(idx, val, 0, n); }
    ll update(ll idx, ll val, ll l, ll r, ll node = 1) {
        if (idx < l || idx > r) return seg[node];
        if (l == r) return seg[node] = val;
        ll mid = (l + r) >> 1;

        seg[node] = update(idx, val, l, mid, node * 2);
        seg[node] += update(idx, val, mid + 1, r, node * 2 + 1);
        return seg[node];
    }

    ll cnt(ll val) { return cnt(val, 1, n); }
    ll cnt(ll val, ll l, ll r, ll node = 1){
        if(l == r) return r;
        ll mid = (l + r) >> 1;

        if(seg[node * 2] < val) return cnt(val - seg[node * 2], mid + 1, r, node * 2 + 1);
        else return cnt(val, l, mid, node * 2);
    }
};
map <ll, ll> an, bn;
ll result[MAX];

class node{
public:
    ll a, b, c, num, idx;
    bool operator <(node& ot){
        return c < ot.c;
    }
};
vector <ll> av, bv;
vector <node> query;

void comp(){
    sort(all(av)); sort(all(bv)); 
    ll seq = 0;
    for(auto& i : av) if(!an.count(i)) an[i] = ++seq;

    seq = 0;
    for(auto& i : bv) if(!bn.count(i)) bn[i] = ++seq;

    for(auto& i : query){
        auto&[a, b, c, num, idx] = i;
        a = an[a]; b = bn[b];
    }
}

bool cmp(node a, node b){
    return a.a < b.a;
}

_sseg seg;
void dnc(ll s, ll e){
    if(s == e) return;
    ll mid = (s + e) >> 1;
    dnc(s, mid); dnc(mid + 1, e);
 
    vector <node> uv, qv;
    for(int i = mid + 1;i <= e;i++){
        if(!query[i].num) uv.push_back(query[i]);
    }

    for(int i = s;i <= mid;i++){
        if(query[i].num) qv.push_back(query[i]);
    }
    sort(all(uv), cmp); sort(all(qv), cmp);

    ll idx = 0; 
    for(auto& nxt : qv){
        while(idx < uv.size() && uv[idx].a <= nxt.a){
            seg.add(uv[idx].b, 1); idx++;
        }
        
        result[nxt.idx] += seg.query(0, nxt.b) * nxt.num;
    }
    while(idx < uv.size()) seg.add(uv[idx].b, 1), idx++;
    for(auto& back : uv) seg.add(back.b, -1);
}

int main() {
    fastio;

    cin >> n >> m; seg = {MAX};
    for(int i = 1;i <= n;i++) {
        ll a, b, c; cin >> a >> b; c = a + b;
        query.push_back({a, b, c, 0, 0});
        av.push_back(a); bv.push_back(b); 
    }
    
    for(int i = 1;i <= m;i++){
        ll a, b, c; cin >> a >> b >> c; c--;
        query.push_back({INF, INF, c, 1, i});
        query.push_back({a - 1, b - 1, c, 1, i});
        query.push_back({INF, b - 1, c, -1, i});
        query.push_back({a - 1, INF, c, -1, i});
        av.push_back(a - 1); bv.push_back(b - 1);
    }
    av.push_back(INF); bv.push_back(INF);
    comp();
    
    sort(all(query)); dnc(0, query.size() - 1);

    for(int i = 1;i <= m;i++) cout << result[i] << "\n";
    
    
    return 0;
}