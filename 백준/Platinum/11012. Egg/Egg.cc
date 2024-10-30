#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
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
constexpr ll MAX = 10101;
constexpr ll MOD = 998244353;
pll a[MAX];

class node{
public:
    ll x, y, num;
    bool operator <(node& ot){
        return x < ot.x;
    }
};
vector <node> query;

class _sseg {
public:
    ll n; vector <ll> arr, seg;
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

int main() {
    fastio;

    cin >> t;
    while(t--){
        cin >> n >> m; ll result = 0;
        _sseg seg(101010); query.clear();
        for(int i = 1;i <= n;i++) cin >> a[i].x >> a[i].y;
        sort(a + 1, a + n + 1);

        while(m--){
            ll l, r, lo, hi; cin >> l >> r >> lo >> hi;
            query.push_back({r, hi, 1});
            query.push_back({l - 1, lo - 1, 1});
            query.push_back({l - 1, hi, -1});
            query.push_back({r, lo - 1, -1});
        }
        sort(all(query)); ll idx = 1;

        for(auto& i : query){
            auto [cx, cy, num] = i;
            while(a[idx].x <= cx && idx <= n){
                seg.add(a[idx].y, 1); idx++;
            }

            result += seg.query(0, cy) * num;
        }

        cout << result << "\n";
    }

    return 0;
}

