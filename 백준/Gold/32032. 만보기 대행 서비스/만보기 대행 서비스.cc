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
constexpr ll MAX = 1010101; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], result = INF;

void mn(ll v){
    result = min(result, v);
}

void run(){
    cin >> n >> m;
    for(int i = 1;i <= n;i++) cin >> a[i];
    sort(a + 1, a + n + 1);

    if(a[1] >= 0) mn(2 * a[n] + m);
    else if(a[n] <= 0) mn(-2 * a[1] + m);
    else{
        mn(2 * a[n] - 2 * a[1] + 2 * m);
        mn(4 * a[n] - 2 * a[1] + m);
        mn(2 * a[n] - 4 * a[1] + m);

        if(a[n] - a[1] >= (m + 1) / 2) mn(4 * (a[n] - a[1]));
        else mn(4 * (a[n] - a[1]) + m - 2 * (a[n] - a[1]));
    }

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

