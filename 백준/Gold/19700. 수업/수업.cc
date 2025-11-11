#include <bits/stdc++.h>
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
constexpr ll MAX = 501010; // SET MAX SIZE
constexpr ll MOD = 998244353;
pll a[MAX];
multiset <ll> ms;

void run(){
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i].x >> a[i].y;
    sort(a + 1, a + n + 1, greater<pll>());

    ms.insert(1);
    for(int i = 2;i <= n;i++){
        auto lb = ms.lower_bound(a[i].y);
        if(lb == ms.begin()) ms.insert(1);
        else{
            ll tmp = *--lb;
            ms.erase(lb);
            ms.insert(tmp + 1);
        }
    }

    cout << ms.size();
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}