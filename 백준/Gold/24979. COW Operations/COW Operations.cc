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
ll a[MAX], sum[MAX][3], cnt[3];

void run(){
    cin >> s >> m; n = s.size();
    for(int i = 1;i <= n;i++) {
        for(int j = 0;j < 3;j++) sum[i][j] = sum[i - 1][j];
        sum[i][0] += (s[i - 1] == 'C');
        sum[i][1] += (s[i - 1] == 'O');
        sum[i][2] += (s[i - 1] == 'W');
    }

    while(m--){
        ll l, r; cin >> l >> r;
        for(int i = 0;i < 3;i++) cnt[i] = sum[r][i] - sum[l - 1][i];
        bool now = cnt[0] & 1;


        if((cnt[1] & 1) && (cnt[2] & 1)) now ^= 1;
        if((cnt[1] + cnt[2]) & 1) now = 0;
        cout << (now ? "Y" : "N");
    }
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}