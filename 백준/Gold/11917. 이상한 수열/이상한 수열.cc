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
constexpr ll MAX = 50101; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], cnt, mn = INF;
map <ll, bool> mp;

void run(){
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        if(!mp.count(a[i])) cnt++;
        mp[a[i]] = 1;
    }
    
    for(int i = 1;i <= n;i++){
        if(a[i] < cnt) continue;
        mn = min(mn, a[i]);
    }
    cin >> m;

    if(m <= n) cout << a[m];
    else cout << min(mn, m - n + cnt - 1);
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

