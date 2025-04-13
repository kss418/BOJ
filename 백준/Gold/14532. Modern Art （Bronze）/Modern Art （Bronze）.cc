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
constexpr ll MAX = 11; // SET MAX SIZE
constexpr ll MOD = 998244353;
string st[MAX];
ll l[10], r[10], u[10], d[10];

void run(){
    cin >> n;
    for(int i = 0;i < n;i++) cin >> st[i];
    memset(l, 0x3f, sizeof(l));
    memset(d, 0x3f, sizeof(d));

    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            if(st[i][j] == '0') continue;
            l[st[i][j] - '0'] = min<ll>(l[st[i][j] - '0'], j);
            r[st[i][j] - '0'] = max<ll>(r[st[i][j] - '0'], j);
            d[st[i][j] - '0'] = min<ll>(d[st[i][j] - '0'], i);
            u[st[i][j] - '0'] = max<ll>(u[st[i][j] - '0'], i);
        }
    }

    ll result = 0;
    for(int i = 1;i <= 9;i++){
        if(l[i] == INF) continue;
        
        bool now = 1;
        for(int j = 1;j <= 9;j++){
            if(i == j) continue;
            if(l[j] == INF) continue;

            for(int k = d[j];k <= u[j];k++){
                for(int f = l[j];f <= r[j];f++){
                    if(st[k][f] == '0') continue;
                    if(st[k][f] - '0' == i) now = 0;
                }
            }
        }

        result += now;
    }

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

