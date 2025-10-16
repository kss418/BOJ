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
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll st, l, r, sum[3], result[3];
ll num[3][3] = {
    {1, 3, 2}, {2, 1, 1}, {2, 3, 2}
};

ll dnc(ll n, ll sz){
    if(!sz) { sum[st - 1]++; return st; }
    ll pre = dnc(n / 3, sz - 1);

    ll tmp[3] = {0, 0, 0};
    tmp[0] = sum[0] + 2 * sum[1];
    tmp[1] = sum[0] + sum[1] + 2 * sum[2];
    tmp[2] = sum[0] + sum[2];
    for(int i = 0;i < 3;i++) sum[i] = tmp[i];
    
    if(n % 3 == 0){
        if(pre == 1 || pre == 3) sum[1]--, sum[2]--;
        else sum[0] -= 2;
    }
    else if(n % 3 == 1){
        if(pre == 1 || pre == 3) sum[1]--;
        else sum[0]--;
    }

    return num[pre - 1][n % 3];
}

void cal(ll idx, ll mul){
    if(idx < 0) return;
    memset(sum, 0, sizeof(sum));
    dnc(idx, n);
    for(int i = 0;i < 3;i++) result[i] += mul * sum[i];
}

void run(){
    cin >> st >> l >> r >> n;
    cal(l - 1, -1); cal(r, 1);
    for(int i = 0;i < 3;i++) cout << result[i] << " ";
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}