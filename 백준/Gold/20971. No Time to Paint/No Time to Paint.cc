#include <bits/stdc++.h>
#include <ext/rope>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
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
vector <ll> arr[26];
set <pll> num;
set <ll> ban;
priority_queue <ll> pq;

class node{
public:
    ll s, e, idx;
    bool operator < (const node& ot) const{
        if(s == ot.s) return e < ot.e;
        return s < ot.s;
    }
};
vector <node> query;

template <typename T = ll> // query type
class _seg { // 구간 예외 처리하기
public:
    ll n;
    class node{
    public:
        ll v;
        node() : node(0){}
        node(ll v) : v(v) {}
        
        node operator += (node ot){ // add
            v += ot.v;
            return v;
        }

        operator T(){ // update -> query
            return v;
        }
    };
    vector <node> seg;

    _seg(){}
    _seg(ll n) { this->n = n; seg.resize(4 * n + 1, node()); }

    node merge(node l, node r){
        return{
            l.v + r.v
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

void run(){
    cin >> n >> m >> s; ban.insert(INF); _seg seg(n), cnt(n);
    for(int i = 0;i < n;i++) arr[s[i] - 'A'].push_back(i);
    for(int i = 0;i < 26;i++){
        if(arr[i].empty()) continue;
        ll la = arr[i][0];

        for(int j = 1;j < arr[i].size();j++){
            ll now = arr[i][j];
            ll pre = arr[i][j - 1];
            if(*ban.upper_bound(la) >= now) continue;
            num.insert({la, pre}); la = now;
            seg.add(pre, 1);
        }
        num.insert({la, arr[i].back()});
        seg.add(arr[i].back(), 1);
        for(auto& i : arr[i]) ban.insert(i);
    }   

    ll now = num.size();
    for(int i = 1;i <= m;i++){
        ll s, e; cin >> s >> e; s--; e--;
        query.push_back({s, e, i});
    }
    sort(all(query));

    pq.push(MINF);
    for(auto&[l, r, i] : query){
        while(!num.empty() && num.begin()->x < l){
            seg.add(num.begin()->y, -1);
            cnt.add(num.begin()->y, 1);
            num.erase(num.begin());
        }
        result[i] = now - seg.query(l, r) + cnt.query(r + 1, n - 1);
    }

    for(int i = 1;i <= m;i++) cout << result[i] << "\n";
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}