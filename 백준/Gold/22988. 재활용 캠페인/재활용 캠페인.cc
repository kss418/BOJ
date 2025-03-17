#include <bits/stdc++.h>
#include <ext/rope>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define x first 
#define y second
using namespace std; using ll = long long;
using ld = long double; using pld = pair<ld, ld>;
using i128 = __int128_t; using f128 = __float128; 
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t = 1; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MINF = 0xc0c0c0c0c0c0c0c0;
constexpr ll MAX = 101010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], result;
multiset <ll> num;

void run(){
    cin >> n >> m;
    for(int i = 1;i <= n;i++) {
        cin >> a[i]; a[i] <<= 1ll;
        if(a[i] == (m << 1ll)){ result++; continue; }
        num.insert(a[i]);
    }

    while(num.size() > 1){
        auto now = --num.end();
        auto lb = num.lower_bound(m - *now);
        if(lb == num.end() || lb == now) break;
        result++; num.erase(now);
        num.erase(lb);
    }

    result += num.size() / 3;
    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}