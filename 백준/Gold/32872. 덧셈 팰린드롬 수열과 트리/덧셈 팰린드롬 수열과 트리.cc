#include <bits/stdc++.h>
#include <ext/rope>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
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
ll a[MAX], sum[MAX], result;
vector <ll> arr;

bool chk(){
    sum[0] = arr[0]; ll sz = arr.size();
    for(int i = 1;i < sz;i++) sum[i] = sum[i - 1] + arr[i];
    for(int i = 0;i < sz;i++){
        for(int j = i + 1;j < sz;j++){
            if(sum[i] == sum[sz - 1] - sum[j - 1]) return 1;
        }
    }
    return 0;
}

void dfs(ll cur, ll dir, ll st, ll pre = -1){
    arr.push_back(a[cur]);
    if(dir == 1 && cur >= (1ll << (n - 1))){
        if(st <= cur) result += chk();
        arr.pop_back(); return;
    }

    if(cur < (1ll << (n - 1))) {
        if(2 * cur != pre) dfs(2 * cur, 1, st, cur);
        if(2 * cur + 1 != pre) dfs(2 * cur + 1, 1, st, cur);
    }
    if(cur != 1 && !dir && cur / 2 != pre) dfs(cur / 2, 0, st, cur);

    arr.pop_back();
}

void run(){
    cin >> n;
    for(int i = 1;i < (1ll << n);i++) cin >> a[i];
    for(int i = 1ll << (n - 1);i < (1ll << n);i++) dfs(i, 0, i);
    
    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

