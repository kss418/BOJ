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
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], result[MAX], cnt, idx;

void run(){
    cin >> n;
    for(int i = 0;i < n;i++) cin >> a[i];

    cout << n << "\n"; 
    while(cnt < n){
        while(result[idx]) idx = (idx + 1) % n;
        result[idx] = a[cnt];
        idx = (idx + a[cnt]) % n;
        a[cnt] = 0; cnt++;
    }

    for(int i = 0;i < n;i++) cout << result[i] << " ";
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

