#include <bits/stdc++.h>
#include <ext/rope>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; using ll = long long;
using ld = long double; using pld = pair<ld, ld>;
using i128 = __int128_t; using f128 = __float128; 
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t = 1; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MINF = 0xc0c0c0c0c0c0c0c0;
constexpr ll MAX = 251010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], org[MAX], dep[MAX], result = 1;
pll sz[MAX];
bool l[MAX], r[MAX];
set <ll> num;


void run(){
    cin >> n; num.insert(MINF); num.insert(INF);
    for(int i = 1;i <= n;i++) cin >> a[i], org[a[i]] = i;

    num.insert(a[1]); dep[1] = 1;
    sz[1] = {MINF + 1, INF - 1};

    for(int i = 2;i <= n;i++){
        ll mn = *--num.lower_bound(a[i]);
        ll mx = *num.upper_bound(a[i]);
        num.insert(a[i]);

        if(mn != INF && mn != MINF){
            ll idx = org[mn];
            if(sz[idx].x <= mn && sz[idx].y >= mn && !r[idx]){
                dep[i] = dep[idx] + 1;
                sz[i] = {a[idx] + 1, sz[idx].y};
                r[idx] = 1; result += dep[i]; continue;
            }
        }

        if(mx != INF && mx != MINF){
            ll idx = org[mx];
            if(sz[idx].x <= mx && sz[idx].y >= mx && !l[idx]){
                dep[i] = dep[idx] + 1;
                sz[i] = {sz[idx].x, a[idx] - 1};
                l[idx] = 1; result += dep[i];
            }
        }
    }

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

