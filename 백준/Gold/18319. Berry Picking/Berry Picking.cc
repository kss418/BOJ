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
constexpr ll MAX = 1010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], cnt[MAX], result;

void run(){
    cin >> n >> m;
    for(int i = 1;i <= n;i++) cin >> a[i];
   
    for(int i = 1;i <= 1000;i++){
        memset(cnt, 0, sizeof(cnt));
        for(int j = 1;j <= n;j++){
            cnt[i] += a[j] / i;
            cnt[a[j] % i]++;
        }

        ll er = m / 2;
        for(int j = i;j >= 1;j--){
            ll mn = min(cnt[j], er);
            cnt[j] -= mn; er -= mn;
            if(!er) break;
        }

        ll use = m / 2, now = 0;
        for(int j = i;j >= 1;j--){
            ll mn = min(cnt[j], use);
            cnt[j] -= mn; use -= mn;
            now += mn * j;
            if(!use) break;
        }
        
        result = max(result, now);
    }

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

