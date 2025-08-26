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
constexpr ll MAX = 501010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], b[MAX], num[MAX];
vector <ll> arr, vec[2 * MAX];
constexpr ll MID = 500500;

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
            return *this;
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
    cin >> n >> m; arr.clear(); _seg seg(n + 3);
    for(int i = -n;i <= n;i++) vec[i + MID].clear();

    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 1;i <= n;i++) cin >> b[i];

    arr.push_back(INF); arr.push_back(MINF);
    arr.push_back(0); num[0] = 0;
    ll now = 0, cnt = 0;
    for(int i = 1;i <= n;i++){
        now += b[i] * (a[i] == 1 ? 1 : -1);
        num[i] = now; arr.push_back(now);
        cnt += (a[i] == 1 ? 1 : -1);
        vec[cnt + MID].push_back(i);
    }

    sort(all(arr));
    arr.erase(unique(all(arr)), arr.end());
    vec[MID].push_back(0);

    ll result = 0; 
    for(int i = -n;i <= n;i++){
        for(auto& j : vec[i + MID]){
            ll now = num[j];
            ll ub = upper_bound(all(arr), now + m) - arr.begin() - 1;
            ll lb = lower_bound(all(arr), now - m) - arr.begin();

            result += seg.query(lb, ub);
            ll idx = lower_bound(all(arr), now) - arr.begin();
            seg.add(idx, 1);
        }

        for(auto& j : vec[i + MID]){
            ll idx = lower_bound(all(arr), num[j]) - arr.begin(); 
            seg.update(idx, 0);
        }
    }
    
    cout << result << "\n";
}

int main() {
    fastio; cin >> t;
    while(t--) run(); 

    return 0;
}