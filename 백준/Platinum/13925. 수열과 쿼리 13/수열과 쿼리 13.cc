#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 101010;
constexpr ll MOD = 1e9 + 7;

class _prop {
public:
    vector<ll> seg, arr; ll n;
    vector<pll> lazy;

    _prop(ll n) {
        this->n = n; arr.resize(n + 1);
        seg.resize(4 * n + 1); lazy.resize(4 * n + 1, { 1,0 });
    }

    void con(ll idx, ll val) {  arr[idx] = val; }

    void init() { init(1, n); }
    ll init(ll l, ll r, ll node = 1) {
        if (l == r) return seg[node] = arr[l];
        ll mid = (l + r) >> 1;
        seg[node] = init(l, mid, node * 2) + init(mid + 1, r, node * 2 + 1);
        seg[node] %= MOD;
        return seg[node];
    }

    void propagate(ll l, ll r, ll node) {
        if (lazy[node] == pll(1,0)) return;
        if (l != r) {
            lazy[node * 2].first *= lazy[node].first;
            lazy[node * 2].second *= lazy[node].first;
            lazy[node * 2].second += lazy[node].second;
            lazy[node * 2].first %= MOD;
            lazy[node * 2].second %= MOD;
            lazy[node * 2 + 1].first *= lazy[node].first;
            lazy[node * 2 + 1].second *= lazy[node].first;
            lazy[node * 2 + 1].second += lazy[node].second;
            lazy[node * 2 + 1].first %= MOD;
            lazy[node * 2 + 1].second %= MOD;
        }
        seg[node] *= lazy[node].first;
        seg[node] %= MOD;
        seg[node] += lazy[node].second * (r - l + 1);
        seg[node] %= MOD;
        lazy[node] = { 1,0 };
    }

    void set(ll st, ll en, ll val) { set(st, en, val, 1, n); }
    void set(ll st, ll en, ll val, ll l, ll r, ll node = 1) {
        propagate(l, r, node);

        if (st > r || en < l) return;
        if (l >= st && r <= en) {
            lazy[node].first = 0;
            lazy[node].second = val;
            propagate(l, r, node);
            return;
        }

        ll mid = (l + r) >> 1;
        set(st, en, val, l, mid, node * 2);
        set(st, en, val, mid + 1, r, node * 2 + 1);

        seg[node] = seg[node * 2] + seg[node * 2 + 1];
        seg[node] %= MOD;
    }

    void mul(ll st, ll en, ll val) { mul(st, en, val, 1, n); }
    void mul(ll st, ll en, ll val, ll l, ll r, ll node = 1) {
        propagate(l, r, node);

        if (st > r || en < l) return;
        if (l >= st && r <= en) {
            lazy[node].first *= val;
            lazy[node].first %= MOD;
            lazy[node].second *= val;
            lazy[node].second %= MOD;
            propagate(l, r, node);
            return;
        }

        ll mid = (l + r) >> 1;
        mul(st, en, val, l, mid, node * 2);
        mul(st, en, val, mid + 1, r, node * 2 + 1);

        seg[node] = seg[node * 2] + seg[node * 2 + 1];
        seg[node] %= MOD;
    }

    void add(ll st, ll en, ll val) { add(st, en, val, 1, n); }
    void add(ll st, ll en, ll val, ll l, ll r, ll node = 1) {
        propagate(l, r, node);

        if (st > r || en < l) return;
        if (l >= st && r <= en) {
            lazy[node].second += val;
            lazy[node].second %= MOD;
            propagate(l, r, node);
            return;
        }

        ll mid = (l + r) >> 1;
        add(st, en, val, l, mid, node * 2);
        add(st, en, val, mid + 1, r, node * 2 + 1);

        seg[node] = seg[node * 2] + seg[node * 2 + 1];
        seg[node] %= MOD;
    }

    ll query(ll st, ll en) { return query(st, en, 1, n); }
    ll query(ll st, ll en, ll l, ll r, ll node = 1) {
        propagate(l, r, node);

        if (st > r || en < l) return 0;
        if (l >= st && r <= en) return seg[node] % MOD;

        ll mid = (l + r) >> 1;
        ll ret = query(st, en, l, mid, node * 2) % MOD;
        ret += query(st, en, mid + 1, r, node * 2 + 1) % MOD;

        return ret;
    }
};

int main() {
    fastio;
    cin >> n;
    _prop seg(n);

    for (int i = 1; i <= n; i++) { cin >> t; seg.con(i, t); }
    seg.init(); cin >> m;

    for (int i = 1; i <= m; i++) {
        ll num, s, e, v;
        cin >> num >> s >> e;
        if (num == 1) {
            cin >> v;
            seg.add(s, e, v, 1, n);
        }
        else if (num == 2) {
            cin >> v;
            seg.mul(s, e, v, 1, n);
        }
        else if (num == 3) {
            cin >> v;
            seg.set(s, e, v, 1, n);
        }
        else cout << seg.query(s, e) % MOD << "\n";
    }
    

    return 0;
}