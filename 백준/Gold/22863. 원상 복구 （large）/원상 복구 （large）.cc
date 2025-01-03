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
constexpr ll MAX = 1010101;
constexpr ll MOD = 998244353;
ll a[MAX], inv[MAX], arr[MAX];
ll num[50][MAX];

class _st {
public:
    ll n; 
    _st(ll n, ll m) { //n 개수 m 깊이
        this->n = n;
    }

    void add(ll st, ll en) {
        num[0][st] = en;
    }

    void init() {
        for (int i = 1; i <= log2(m); i++) {
            for (int j = 1; j <= n; j++) num[i][j] = num[i - 1][num[i - 1][j]];
        }
    }

    ll ret(ll n, ll d) { //n 노드 d 깊이
        for (int i = log2(m); i >= 0; i--) {
            if (d & (1ll << i)) n = num[i][n];
        }

        return n;
    }
};

int main() {
    fastio;

    cin >> n >> m; _st st(n, m);
    for(int i = 1;i <= n;i++) cin >> arr[i];
    for(int i = 1;i <= n;i++) cin >> a[i];

    for(int i = 1;i <= n;i++) inv[a[i]] = i;
    for(int i = 1;i <= n;i++) st.add(i, inv[i]);
    st.init();

    for(int i = 1;i <= n;i++) cout << arr[st.ret(i, m)] << " ";
    
    
    return 0;
}