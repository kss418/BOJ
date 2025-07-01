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
constexpr ll MOD = 30013;

class node{
public:
    ll u1, u2, d1, d2;
    bool operator < (const node& ot) const{
        return u1 < ot.u1;
    }
}; node a[MAX];

template <typename T = ll> // query type
class _seg { // 구간 예외 처리하기
public:
    ll n;
    class node{
    public:
        ll v, cnt;
        node() : node(0, 0){}
        node(ll v, ll cnt) : v(v), cnt(cnt) {}
        
        node operator += (node ot){ // add
            return node();
        }

        operator T(){ // update -> query
            return {v, cnt};
        }
    };
    vector <node> seg;

    _seg(){}
    _seg(ll n) { this->n = n; seg.resize(4 * n + 1, node()); }

    node merge(node l, node r){
        ll mx = max(l.v, r.v);
        ll cnt = 0;
        if(l.v == mx) cnt += l.cnt;
        if(r.v == mx) cnt += r.cnt;
        cnt %= MOD;

        return {mx, cnt};
    }

    T query(ll st, ll en) { return query(st, en, 0, n); }
    node query(ll st, ll en, ll l, ll r, ll node = 1) {
        if (en < l || st > r) return _seg::node();
        if (st <= l && en >= r) return seg[node];
        ll mid = (l + r) >> 1;
        return merge(query(st, en, l, mid, node * 2), query(st, en, mid + 1, r, node * 2 + 1));
    }

    node update(ll idx, node val) { return update(idx, val, 0, n); }
    node update(ll idx, node val, ll l, ll r, ll node = 1) {
        if (idx < l || idx > r) return seg[node];
        if (l == r) {
            seg[node] = val;
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

    void clear(){ seg.clear(); seg.assign(4 * n + 1, node()); }
};

class wq{
public:
    ll u2, d2; pll v;
    bool operator > (const wq& ot) const{
        return u2 > ot.u2;
    }
};

priority_queue <wq, vector<wq>, greater<wq>> pq;
vector <ll> num;
map <ll, ll> org;
ll cnt;

void run(){
    cin >> n; _seg <pll> seg(4 * n + 1);
    for(int i = 1;i <= n;i++) {
        cin >> a[i].u1 >> a[i].u2 >> a[i].d1 >> a[i].d2;
        num.push_back(a[i].u1);
        num.push_back(a[i].u2);
        num.push_back(a[i].d1);
        num.push_back(a[i].d2);
    }

    sort(all(num));
    for(auto& i : num){
        if(!org.count(i)) cnt++;
        org[i] = cnt;
    }

    for(int i = 1;i <= n;i++){
        a[i].u1 = org[a[i].u1];
        a[i].u2 = org[a[i].u2];
        a[i].d1 = org[a[i].d1];
        a[i].d2 = org[a[i].d2];
    }
    sort(a + 1, a + n + 1);

    for(int i = 1;i <= n;i++){
        while(!pq.empty()){
            auto [nu, nd, nv] = pq.top();
            if(nu >= a[i].u1) break;
            seg.update(nd, {nv.x, nv.y});
            pq.pop();
        }

        pll q = seg.query(1, a[i].d1);
        ll mx = q.x + 1, cnt = max(q.y, 1ll);

        pq.push({a[i].u2, a[i].d2, {mx, cnt}});
    }

    while(!pq.empty()){
        auto [nu, nd, nv] = pq.top();
        seg.update(nd, {nv.x, nv.y});
        pq.pop();
    }
    
    pll q = seg.query(1, 4 * n + 1);
    cout << q.x << " " << q.y << "\n";
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

