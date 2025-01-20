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
constexpr ll MAX = 1010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], cnt[3], num[MAX];

class _prop { 
public:
    vector<ll> seg, lazy; ll n;

    _prop(ll n) {
        this->n = n; 
        seg.resize(4 * n + 1); lazy.resize(4 * n + 1);
    }

    void propagate(ll l, ll r, ll node) {
        if (!lazy[node]) return;
        if (l != r) {
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }
        seg[node] += lazy[node] * (r - l + 1);
        lazy[node] = 0;
    }

    void add(ll st, ll en, ll val) { add(st, en, val, 0, n); }
    void add(ll st, ll en, ll val, ll l, ll r, ll node = 1) {
        propagate(l, r, node);

        if (st > r || en < l) return;
        if (l >= st && r <= en) {
            lazy[node] += val; propagate(l, r, node);
            return;
        }

        ll mid = (l + r) >> 1;
        add(st, en, val, l, mid, node * 2);
        add(st, en, val, mid + 1, r, node * 2 + 1);

        seg[node] = seg[node * 2] + seg[node * 2 + 1];
    }

    ll query(ll st, ll en) { return query(st, en, 0, n); }
    ll query(ll st, ll en, ll l, ll r, ll node = 1) {
        propagate(l, r, node);

        if (st > r || en < l) return 0;
        if (l >= st && r <= en) return seg[node];

        ll mid = (l + r) >> 1;
        ll ret = query(st, en, l, mid, node * 2);
        ret += query(st, en, mid + 1, r, node * 2 + 1);

        return ret;
    }
};

void run(){
    cin >> n >> m; _prop seg(n), one(n); 
    seg.add(1, n, 1); one.add(1, n, 1);
    while(m--){
        for(int i = 0;i < 3;i++) cin >> cnt[i];
        seg.add(max(n - cnt[2] + 1, 0ll), n, 2);
        seg.add(max(n - cnt[2] - cnt[1] + 1, 0ll), max(n - cnt[2], 0ll), 1);
        one.add(min(cnt[0] + 1, n), min(cnt[0] + cnt[1], n), 1);
        one.add(min(cnt[0] + cnt[1] + 1, n), min(cnt[0] + cnt[1] + cnt[2], n), 2);
    }

    for(int i = 1;i <= n;i++) {
        num[i] = seg.query(i, i);
        a[n - i + 1] = one.query(i, i);
    }
    
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            cout << (j == 1 && i != 1 ? a[i] : num[j]) << " ";
        }
        cout << "\n";
    }
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

