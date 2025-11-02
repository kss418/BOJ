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
constexpr ll MAX = 201; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX][10101], l, dp[MAX][MAX];
ll c[MAX][MAX], mul[MAX][MAX];
unordered_map <ll, ll> num;
vector <pll> arr[MAX];
vector <ll> d;

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

ll solve(ll cur, ll cnt){
    ll& ret = dp[cur][cnt];
    if(ret != -1) return ret; ret = 0;
    if(!cur) return ret = (d[cnt] == 1 ? 1 : 0);


    for(auto& i : d){
        ll now = num[d[cnt] / g.ret(d[cnt], i)];
        ret += c[cur][num[i]] * solve(cur - 1, now);
        ret %= l;
    }
  
    if(cur != 1 && cur != n) for(auto& [x, c] : arr[cur]){
        ll now = num[d[cnt] / g.ret(d[cnt], d[x])];
        ret += c * solve(cur - 1, now);
        ret %= l;
    }
    
    return ret %= l;
}

void run(){
    cin >> n >> m >> k >> l;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++) cin >> a[i][j];
    }

    for(int i = 1;i * i <= k;i++){
        if(k % i) continue;
        d.push_back(i);
        if(k / i != i) d.push_back(k / i);
    }
    
    sort(all(d));
    for(int i = 0;i < d.size();i++) num[d[i]] = i;

    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            ll now = g.ret(a[i][j], k);
            c[i][num[now]]++;
        }
    }

    for(int i = 2;i < n;i++){
        for(int j = 0;j < d.size();j++){
            for(int l = 0;l < d.size();l++){
                if(j == l){
                    ll now = g.ret(d[j] * d[j], k);
                    mul[i][num[now]] += c[i][j] * (c[i][j] - 1);
                }
                else{
                    ll now = g.ret(d[j] * d[l], k);
                    mul[i][num[now]] += c[i][j] * c[i][l];
                }
            }
        }

        for(int j = 0;j < d.size();j++) arr[i].push_back({j, mul[i][j]});
    }

    memset(dp, -1, sizeof(dp));
    cout << solve(n, num[k]);
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}