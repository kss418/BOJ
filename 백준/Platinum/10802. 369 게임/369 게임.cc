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
constexpr ll MAX = 101010; // SET MAX SIZE
constexpr ll MOD = 20150523;
ll dp1[MAX][3][2], dp2[MAX][3][2];
ll pre, nxt; string a, b;

void mi(string& s){
    for(int i = s.size() - 1;i >= 0;i--){
        if(s[i] != '0') { s[i]--; break; }
        s[i] = '9';
    }
}

ll solve1(ll cur, ll mod, ll f){
    ll& ret = dp1[cur][mod][f];
    if(ret != -1) return ret; ret = 0;
    if(cur == a.size()) return ret = (mod ? 1 : 0);

    if(f){
        for(int i = 0;i <= a[cur] - '0';i++){
            if(i % 3 == 0 && i) continue;
            ret += solve1(cur + 1, (mod + i) % 3, (i == a[cur] - '0')) % MOD;
            ret %= MOD;
        }
    }
    else{
        for(int i = 0;i <= 9;i++){
            if(i % 3 == 0 && i) continue;
            ret += solve1(cur + 1, (mod + i) % 3, 0) % MOD;
            ret %= MOD;
        }
    }

    return ret %= MOD;
}

ll solve2(ll cur, ll mod, ll f){
    ll& ret = dp2[cur][mod][f];
    if(ret != -1) return ret; ret = 0;
    if(cur == b.size()) return ret = (mod ? 1 : 0);

    if(f){
        for(int i = 0;i <= b[cur] - '0';i++){
            if(i % 3 == 0 && i) continue;
            ret += solve2(cur + 1, (mod + i) % 3, (i == b[cur] - '0')) % MOD;
            ret %= MOD;
        }
    }
    else{
        for(int i = 0;i <= 9;i++){
            if(i % 3 == 0 && i) continue;
            ret += solve2(cur + 1, (mod + i) % 3, 0) % MOD;
            ret %= MOD;
        }
    }

    return ret %= MOD;
}

void run(){
    cin >> a >> b; mi(a);
    reverse(all(a));
    while(a.size() >= 2 && a.back() == '0') a.pop_back();
    reverse(all(a));

    memset(dp1, -1, sizeof(dp1)); memset(dp2, -1, sizeof(dp2));
    for(auto& i : a) pre = (10 * pre + i - '0') % MOD;
    for(auto& i : b) nxt = (10 * nxt + i - '0') % MOD;
    pre = (pre - solve1(0, 0, 1) + MOD) % MOD;
    nxt = (nxt - solve2(0, 0, 1) + MOD) % MOD;

    cout << (nxt - pre + MOD) % MOD;
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

