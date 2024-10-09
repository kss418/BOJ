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
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 301010;
constexpr ll MOD = 998244353;
ll arr[MAX];

class _ts { // 0-based index
public:
    ll l, r;
    _ts(ll l, ll r) {
        this->l = l; this->r = r;
    }

    ll f(ll cur) {
        ll ret = 0;
        for (int i = 1; i <= n; i++) ret = max(ret, abs(cur - i) * arr[i]);

        return ret;
    }

    pll ret() {
        while (r - l > 3) {
            ll st = (2 * l + r) / 3, en = (l + 2 * r) / 3;
            if(f(st) > f(en)) l = st;
            else r = en;
        }

        return {l, r};
    }
};

int main() {
    fastio;

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    
    _ts ts(1, n);
    ts.ret();

    ll result = INF;
    for (int i = ts.l; i <= ts.r; i++) result = min(result, ts.f(i));

    cout << result;


    return 0;
}