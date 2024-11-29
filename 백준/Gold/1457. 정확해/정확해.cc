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
ll a[MAX];

class _pow {
public:
	_pow() {}

	ll ret(ll a, ll b){
        ll ret = 1;
        while(b){
            if(b & 1) ret *= a;
            a *= a; b >>= 1;
        }      
        return ret;
    }

	ll ret(ll a, ll b, ll p){
        ll ret = 1;
        while(b){
            if(b & 1) ret *= a % p, ret %= p;
            a *= a; a %= p; b >>= 1;
        }      
        return ret;
    }
}; _pow p;

ll div(ll n){
    ll ret = 0;
    for(int i = 1;i <= n;i++) ret += n / i;

    return ret;
}

ll div_sq(ll n, ll m){
    ll ret = 0;
    for(int i = 1;p.ret(i, m) <= n;i++) ret += n / p.ret(i, m);

    return ret;
}

int main() {
    fastio;

    cin >> n >> m >> k; 
    ll a = div(n + m) - div(n - 1) - m - 1;
    ll b = div_sq(n + m, k) - div_sq(n - 1, k);
    if(n == 1) a++;

    cout << a - b;
    
     
    return 0;
}