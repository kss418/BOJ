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
constexpr ll MAX = 501010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll sum[MAX][2], cnt[MAX][2], result;

void run(){
    cin >> n >> s;
    for(int i = 1;i <= n;i++){
        sum[i][0] = sum[i - 1][0] + (s[i - 1] == 'G');
        sum[i][1] = sum[i - 1][1] + (s[i - 1] == 'H');
    }

    cnt[0][0] = cnt[0][1] = 1;
    for(int i = 3;i <= n;i++){
        result += cnt[sum[i][0] - 1][0];
        result += cnt[sum[i][1] - 1][1];
        cnt[sum[i - 2][0]][0]++;
        cnt[sum[i - 2][1]][1]++;
    }

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}