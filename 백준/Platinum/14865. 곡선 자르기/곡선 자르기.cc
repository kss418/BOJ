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
pll a[MAX]; ll la, r1, r2, mx = MINF;
vector <pll> arr;
map <ll, ll> mp;

void run(){
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i].x >> a[i].y;
    rotate(a + 1, min_element(a + 1, a + n + 1), a + n + 1);
    a[0] = a[n]; la = a[0].x;

    for(int i = 1;i <= n;i++){
        if(a[i - 1].y < 0 && a[i].y > 0) la = a[i].x;
        else if(a[i - 1].y > 0 && a[i].y < 0){
            ll mn = min(la, a[i].x), mx = max(la, a[i].x);
            arr.push_back({mn, mx}); mp.insert({mn, mx});
        }
    }
    sort(all(arr));
    mp.insert({MINF, MINF});
    mp.insert({INF, INF});

    for(auto&i : arr){
        auto[l, r] = i;
        auto nxt = mp.upper_bound(l)->y;
        if(nxt > r) r2++;
        if(r >= mx) r1++;
        mx = max(mx, r); 
    }

    cout << r1 << " " << r2;
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

