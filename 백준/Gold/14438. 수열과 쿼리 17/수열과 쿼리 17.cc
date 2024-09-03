#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 1010101;
constexpr ll MOD = 1e9 + 7;

class _mnseg {
public:
    ll n; vector <ll> arr, seg;
    _mnseg(ll n) {
        this->n = n;
        arr.resize(n + 1); seg.resize(4 * n + 1);
    }

    void con(ll idx, ll val) { arr[idx] = val; }

    void init() { init(1, n); }
    ll init(ll l, ll r, ll node = 1) {
        if (l == r) return seg[node] = arr[l];
        ll mid = (l + r) >> 1;
        seg[node] = min(init(l, mid, node * 2), init(mid + 1, r, node * 2 + 1)); 
        return seg[node];
    }

    ll query(ll st, ll en) { return query(st, en, 1, n); }
    ll query(ll st, ll en, ll l, ll r, ll node = 1) {
        if (en < l || st > r) return INF;
        if (st <= l && en >= r) return seg[node];
        ll mid = (l + r) >> 1;
        return min(query(st, en, l, mid, node * 2), query(st, en, mid + 1, r, node * 2 + 1));
    }

    ll update(ll idx, ll val) { return update(idx, val, 1, n); }
    ll update(ll idx, ll val, ll l, ll r, ll node = 1) {
        if (idx < l || idx > r) return seg[node];
        if (l == r) return seg[node] = val;
        ll mid = (l + r) >> 1;

        seg[node] = min(update(idx, val, l, mid, node * 2), update(idx, val, mid + 1, r, node * 2 + 1));
        return seg[node];
    }
};
ll arr[MAX];

int main() {
    fastio;

    cin >> n;
    _mnseg seg(n);

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        seg.con(i, arr[i]);
    }
    seg.init();

    cin >> m;
    while (m--) {
        ll num; cin >> num;
        if (num == 1) {
            ll idx, v;
            cin >> idx >> v;
            seg.update(idx, v);
        }
        else {
            ll st, en;
            cin >> st >> en;
            cout << seg.query(st, en) << "\n";
        }
    }



    return 0;
}