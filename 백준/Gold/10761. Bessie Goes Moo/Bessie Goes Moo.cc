#include <bits/stdc++.h>
#include <ext/rope>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; using ll = long long;
using ld = long double; using pld = pair<ld, ld>;
using i128 = __int128_t; using f128 = __float128; 
using pll = pair<ll, ll>;
ll n, m, k, t = 1; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MINF = 0xc0c0c0c0c0c0c0c0;
constexpr ll MAX = 5010; // SET MAX SIZE
constexpr ll MOD = 998244353;
vector <ll> num[26];
ll dp[8][7][7][7], result;
vector <char> c = {'B', 'E', 'S', 'I', 'G', 'O', 'M'};
ll di[7] = {-1, -2, -2, -1, 0, 0, 0};
ll dj[7] = {0, -1, -1, 0, -1, -1, 0};
ll dk[7] = {0, 0, 0, 0, 0, -2, -1};

ll mod(ll num){
    return ((num % 7) + 7) % 7;
}

ll solve(ll cur, ll i, ll j, ll k){
    ll& ret = dp[cur][i][j][k];
    if(ret != -1) return ret; ret = 0;
    if(!cur) return ret = (i || j || k) ? 0 : 1;
    
    for(auto& diff : num[c[cur - 1] - 'A']){
        ll ni = i + diff * di[cur - 1];
        ll nj = j + diff * dj[cur - 1];
        ll nk = k + diff * dk[cur - 1];
        ret += solve(cur - 1, mod(ni), mod(nj), mod(nk));
    }

    return ret;
}

void run(){
    cin >> n;
    for(int i = 1;i <= n;i++){
        char c; ll x; cin >> c >> x;
        num[c - 'A'].push_back(x);
    }

    memset(dp, -1, sizeof(dp));
    for(int i = 0;i < 7;i++){
        for(int j = 0;j < 7;j++){
            for(int k = 0;k < 7;k++){
                ll cnt = (i == 0) + (j == 0) + (k == 0);
                if(!cnt) continue;
                result += solve(7, i, j, k);
            }
        }
    }

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}