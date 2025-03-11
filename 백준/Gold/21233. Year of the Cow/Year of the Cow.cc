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
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX];
vector <ll> arr;

void run(){
    cin >> n >> m; m--; ll result = 0;
    for(int i = 1;i <= n;i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    result = a[n] - (a[n] % 12) + 12;
    if(a[n] % 12 == 0) result -= 12;

    for(int i = 1;i <= n;i++){
        ll now = a[i] - (a[i] % 12) - (a[i - 1] - (a[i - 1] % 12) + 12);
        if(a[i - 1] % 12 == 0) now += 12;
        arr.push_back(max(now, 0ll));
    }
    sort(all(arr));

    while(m--) result -= arr.back(), arr.pop_back();
    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
    }