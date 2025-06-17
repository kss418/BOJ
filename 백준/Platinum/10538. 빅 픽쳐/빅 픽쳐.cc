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
constexpr ll MAX = 2010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a, b, ret, now, result;
constexpr ll mul = 11;
string st1[MAX], st2[MAX];
ll pre[MAX][MAX];

class _pow {
public:
    _pow() {}

    ll ret(ll a, ll b){
        ll ret = 1;
        while(b){
            if(b & 1) ret *= a;
            a *= a; b >>= 1;
        }      
        return ret;
    }

    ll ret(ll a, ll b, ll p){
        ll ret = 1;
        while(b){
            if(b & 1) ret *= a % p, ret %= p;
            a *= a; a %= p; b >>= 1;
        }      
        return ret;
    }
};

void run(){
    cin >> n >> m >> a >> b; _pow pow;
    for(int i = 0;i < n;i++) cin >> st1[i];
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            ret = ret * mul + (st1[i][j] == 'o' ? 1 : 0);
            ret %= MOD;
        }
    }

    for(int i = 0;i < a;i++) cin >> st2[i];
    for(int i = 0;i < a;i++){
        for(int j = 0;j < b;j++){
            if(i) pre[i][j] = pow.ret(mul, m, MOD) * pre[i - 1][j] % MOD;
            pre[i][j] += (st2[i][j] == 'o' ? 1 : 0);

            if(i >= n){
                pre[i][j] -= pow.ret(mul, n * m, MOD) * (st2[i - n][j] == 'o' ? 1 : 0);
            }
            pre[i][j] = (pre[i][j] + MOD) % MOD;
        }
    }

    for(int i = n - 1;i < a;i++){
        now = 0;
        for(int j = 0;j < b;j++){
            bool flag = 1;
            now *= mul; now %= MOD;
            now += pre[i][j]; now %= MOD;
            if(j >= m) now -= (pre[i][j - m] * pow.ret(mul, m, MOD)) % MOD;
            now = (now + MOD) % MOD;

            if(j >= m - 1 && now != ret) flag = 0; 

            if(flag && j >= m - 1) result++;
        }
    }

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

