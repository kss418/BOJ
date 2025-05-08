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
constexpr ll MAX = 101010; // SET MAX SIZE
constexpr ll MOD = 998244353;
constexpr ll MID = 101010;
class node{
public:
    ll x;
    char c = 'A';

    bool operator < (const node& ot) const{
        return x < ot.x;
    }
};
node a[MAX];
ll result, sum[2 * MAX];
map <ll, ll> idx;

void run(){
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i].x >> a[i].c;
    sort(a + 1, a + n + 1);
    for(int i = 1;i <= n;i++) idx[a[i].x] = i;
    
    ll now = 0; result = 0;
    for(int i = 1;i <= n;i++){
        if(a[i - 1].c != a[i].c) now = 0;
        else now += a[i].x - a[i - 1].x;
        result = max(result, now);
    }

    now = MID; memset(sum, 0x3f, sizeof(sum));
    sum[MID] = 0;
    for(int i = 1;i <= n;i++){
        now += (a[i].c == 'G' ? 1 : -1);
        if(sum[now] != INF) result = max(result, a[i].x - a[idx[sum[now]] + 1].x);
        sum[now] = min(sum[now], a[i].x);
    }

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}