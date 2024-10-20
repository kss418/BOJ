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
constexpr ll MAX = 201010;
constexpr ll MOD = 998244353;
ll a[MAX];

class _bs { // 0-based index
public:
    ll l, r;
    _bs(ll l, ll r) {
        this->l = l; this->r = r;
    }

    ll f(ll cur) {
        ll two = 0, five = 0;
        for(int i = 2;i <= cur;i *= 2){
            two += cur / i;
        }  

        for(int i = 5;i <= cur;i *= 5){
            five += cur / i;
        }     

        return min(two, five) < n;
    }

    ll ret() {
        ll lo = l, hi = r, mid = -1;
        while (hi > lo) {
            mid = (hi + lo + 1) >> 1ll;
            if (f(mid)) lo = mid;
            else hi = mid - 1;
        }

        return lo;
    }
};

int main() {
    fastio;

    cin >> n;
    _bs bs(1, 1e9);
    ll ret = bs.ret() + 1;
    
    ll two = 0, five = 0;
    for(int i = 2;i <= ret;i *= 2){
        two += ret / i;
    }  

    for(int i = 5;i <= ret;i *= 5){
        five += ret / i;
    }     

    if(ret == 1e9 || min(two, five) != n) cout << -1;
    else cout << ret;
    

    return 0;
}