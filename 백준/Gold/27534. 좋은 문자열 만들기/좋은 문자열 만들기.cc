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
ll pre[MAX][2], suf[MAX][2];

void run(){
    cin >> n >> s;
    if(n == 3 || n == 1){
        cout << -1 << "\n"; return;
    }
    else if(n == 2){
        if(s == "00" || s == "11") cout << 1 << "\n";
        else cout << 0 << "\n";
        return;
    }

    for(int i = 1;i <= n;i++){
        for(int j = 0;j <= 1;j++){
            pre[i][j] = pre[i - 1][j];
            if(s[i - 1] != j + '0') pre[i][j]++;
        }
    }

    suf[n + 1][0] = suf[n + 1][1] = 0;
    for(int i = n;i >= 1;i--){
        for(int j = 0;j <= 1;j++){
            suf[i][j] = suf[i + 1][j];
            if(s[i - 1] != j + '0') suf[i][j]++;
        }
    }

    ll result = INF;
    for(int i = 1;i < n / 2;i++){
        for(int j = 0;j <= 1;j++){
            ll now = pre[i][j] + suf[n - i + 1][j ^ 1];
            if(s[i] == '0' + j) now++;
            if(s[n - i - 1] == '0' + (j ^ 1)) now++;

            result = min(result, now);
        }
    }

    if(n % 2 == 0){
        ll a = pre[n / 2][0] + suf[n / 2 + 1][1];
        ll b = pre[n / 2][1] + suf[n / 2 + 1][0];
        ll mn = min(a, b); result = min(result, mn);
    }

    cout << result << "\n";
}

int main() {
    fastio; cin >> t;
    while(t--) run(); 

    return 0;
}

