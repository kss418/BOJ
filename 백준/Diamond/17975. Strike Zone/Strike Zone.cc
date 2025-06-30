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
constexpr ll MAX = 1010; // SET MAX SIZE
constexpr ll MOD = 998244353;
pll a[MAX], b[MAX];
vector <pll> arr[2 * MAX];

vector <ll> yv, xv;
map <ll, ll> ym, xm;
ll c1, c2;

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
        seg.clear(); seg.assign(4 * n + 1, node());
    }
};

void run(){
    cin >> n; _seg seg(2010);
    for(int i = 1;i <= n;i++){
        cin >> a[i].x >> a[i].y;
        yv.push_back(a[i].x);
        xv.push_back(a[i].y);
    }

    cin >> m;
    for(int i = 1;i <= m;i++){
        cin >> b[i].x >> b[i].y;
        yv.push_back(b[i].x);
        xv.push_back(b[i].y);
    }
    cin >> c1 >> c2;

    sort(all(yv)); sort(all(xv));
    ll cnt = 0;
    for(auto& i : yv){
        if(!ym.count(i)) cnt++;
        ym[i] = cnt;
    }

    cnt = 0;
    for(auto& i : xv){
        if(!xm.count(i)) cnt++;
        xm[i] = cnt;
    }

    for(int i = 1;i <= n;i++) arr[ym[a[i].x]].push_back({xm[a[i].y], c1});
    for(int i = 1;i <= m;i++) arr[ym[b[i].x]].push_back({xm[b[i].y], -c2});

    ll result = MINF;
    for(int i = 1;i < 2010;i++){
        seg.clear();
        for(int j = i;j < 2010;j++){
            for(auto& [k, co] : arr[j]) seg.update(k, co);
            result = max(result, seg.query(1, 2005));
        }
    }

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

