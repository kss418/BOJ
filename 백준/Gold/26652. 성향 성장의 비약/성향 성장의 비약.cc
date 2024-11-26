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
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], b[MAX], mx[MAX], mn;

ll sum(ll num){
    return num * (num + 1) / 2;
}

bool chk(ll cur){
    ll use = m;
    for(int i = 1;i <= n;i++){
        ll pre = mx[i];
        use -= max(cur - pre, 0ll);
        if(use < 0) break;
    }
    return use >= 0;
}

ll ret(){
    ll l = 0, r = 1e15;
    while(r > l){
        ll mid = (l + r + 1) >> 1;
        if(chk(mid)) l = mid;
        else r = mid - 1;
    }
    return l;
}

template <typename T = ll>
class _bs { // 0-based index
public:
    T l, r, mn, use;
    _bs(T l, T r, T mn, T use) {
        this->l = l; this->r = r;
        this->mn = mn; this->use = use;
    }

    bool f(T cur) {
        ll a = sum(mn - 1), b = sum(cur - 1);
        ll diff = b - a;
        return diff <= use;
    }

    T ret() {
        T lo = l, hi = r, mid = -1;
        while (hi > lo) {
            mid = (hi + lo + 1) / (T)2;
            if (f(mid)) lo = mid;
            else hi = mid - 1;
        }

        return lo;
    }
};

int main() {
    fastio;

    cin >> n >> m;
    for(int i = 1;i <= n;i++) cin >> a[i], mn = max(mn, a[i]);
    for(int i = 1;i <= n;i++) cin >> b[i];
    
    for(int i = 1;i <= n;i++){
        _bs bs(a[i], (ll)3e9, a[i], b[i]);
        mx[i] = bs.ret();
    }
    ll result = ret();

    if(result < mn) cout << -1;
    else cout << result;

     
    return 0;
}