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
constexpr ll MAX = 101010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX];

class _prop { 
public:
    vector<ll> seg, lazy; ll n;

    _prop() {}
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
        seg[node] += lazy[node];
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

        seg[node] = min(seg[node * 2], seg[node * 2 + 1]);
    }

    ll query(ll st, ll en) { return query(st, en, 0, n); }
    ll query(ll st, ll en, ll l, ll r, ll node = 1) {
        propagate(l, r, node);

        if (st > r || en < l) return INF;
        if (l >= st && r <= en) return seg[node];

        ll mid = (l + r) >> 1;
        ll ret = query(st, en, l, mid, node * 2);
        ret = min(ret, query(st, en, mid + 1, r, node * 2 + 1));

        return ret;
    }
} seg;

bool chk(){
    if(seg.query(s.size(), s.size())) return 0;
    return seg.query(1, s.size()) >= 0;
}

void run(){
    cin >> s; seg = {s.size()};
    for(int i = 1;i <= s.size();i++){
        a[i] = a[i - 1] + (s[i - 1] == '(' ? 1 : -1);
        seg.add(i, i, a[i]);
    }

    ll result = 0;
    for(int i = 1;i <= s.size();i++){
        seg.add(i, s.size(), (s[i - 1] == '(' ? -2 : 2));
        result += chk();
        seg.add(i, s.size(), (s[i - 1] == '(' ? 2 : -2));
    }

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}