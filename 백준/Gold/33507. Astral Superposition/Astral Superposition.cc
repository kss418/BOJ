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
constexpr ll MAX = 1010; // SET MAX SIZE
constexpr ll MOD = 998244353;
string st[MAX];
ll cnt[MAX][MAX];

void run(){
    cin >> n >> m >> k;
    for(int i = 0;i < n;i++) {
        cin >> st[i];
        for(int j = 0;j < n;j++){
            if(st[i][j] == 'W') cnt[i][j] = 0;
            else if(st[i][j] == 'G') cnt[i][j] = 1;
            else cnt[i][j] = 2;
        }
    }

    ll result = 0, flag = 1;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            if(cnt[i][j] != 2) continue;
            if(i - k < 0 || j - m < 0) { flag = 0; continue; }
            if(!cnt[i - k][j - m]) { flag = 0; continue; }
            cnt[i - k][j - m]--; cnt[i][j]--; result++;
        }
    }

    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            if(!cnt[i][j]) continue;
            result++; cnt[i][j]--;
            if(i + k >= n || j + m >= n) continue;
            if(cnt[i + k][j + m]) cnt[i + k][j + m]--;
        }
    }

    cout << (flag ? result : -1) << "\n";
}

int main() {
    fastio; cin >> t;
    while(t--) run(); 

    return 0;
}

