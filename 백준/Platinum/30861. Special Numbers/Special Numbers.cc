#include <bits/stdc++.h>
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
constexpr ll MAX = 22; // SET MAX SIZE
constexpr ll MOD = 1e9 + 7;
string a, b;
unordered_map <ll, ll> dp[MAX][2];
ll pre, nxt;

class _gcd {
public:
    _gcd() {}

    tll init(ll a, ll b) {
        if (!b) return { a, 1, 0 };
        auto [g, x, y] = init(b, a % b);
        return { g, y, x - a / b * y };
    }

    ll ret(ll a, ll b) {
        return get<0>(init(a, b));
    }

    ll inv(ll a, ll mod) {
        auto [g, x, y] = init(a, mod);
        if (!a || g != 1) return -1;
        return (x < 0 ? x + mod : x);
    }
}; _gcd g;

ll solve(ll cur, ll cnt, ll div, string& s){
    if(dp[cur][cnt].count(div)) return dp[cur][cnt][div];
    ll& ret = dp[cur][cnt][div];
    if(cur == s.size() - 1){
        return ret = (div == 1 ? 1 : 0);
    }

    if(!cnt){
        for(int i = 0;i <= s[cur + 1] - '0';i++){
            ll num = g.ret(div, i);
            ret += solve(cur + 1, i != s[cur + 1] - '0', div / num, s);
            ret %= MOD;
        }
    }
    else{
        for(int i = 0;i <= 9;i++){
            ll num = g.ret(div, i);
            ret += solve(cur + 1, 1, div / num, s);
            ret %= MOD;
        }
    }

    return ret %= MOD;
}

void sub(){
    string st; a[a.size() - 1]--;
    for(int i = a.size() - 1;i >= 0;i--){
        if(a[i] >= '0') break;
        a[i] = '9'; a[i - 1]--;
    }

    bool flag = 1;
    for(auto& i : a){
        if(i == '0' && flag) continue;
        flag = 0; st.push_back(i);
    }

    if(st.empty()) st.push_back('0');
    a = st;
}

void init(){
    for(int i = 0;i < MAX;i++){
        for(int j = 0;j < 2;j++) dp[i][j].clear();
    }
}

void run(){
    cin >> n >> a >> b; sub();
    for(int i = 1;i <= b[0] - '0';i++){
        ll now = g.ret(n, i);
        nxt += solve(0, i != b[0] - '0', n / now, b);
        nxt %= MOD;
    }

    for(int i = 1;i < b.size();i++){
        for(int j = 1;j <= 9;j++){
            ll now = g.ret(n, j);
            nxt += solve(i, 1, n / now, b);
            nxt %= MOD;
        }
    }
    
    init();
    for(int i = 1;i <= a[0] - '0';i++){
        ll now = g.ret(n, i);
        pre += solve(0, i != a[0] - '0', n / now, a);
        pre %= MOD;
    }

    for(int i = 1;i < a.size();i++){
        for(int j = 1;j <= 9;j++){
            ll now = g.ret(n, j);
            pre += solve(i, 1, n / now, a);
            pre %= MOD;
        }
    }

    cout << (nxt - pre + MOD) % MOD;
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}