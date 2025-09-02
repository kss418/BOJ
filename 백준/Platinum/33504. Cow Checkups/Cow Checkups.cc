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
constexpr ll MAX = 501010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], b[MAX], result;
ll sum[MAX], cnt[MAX];
stack <ll> sm[MAX];

void run(){
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 1;i <= n;i++) cin >> b[i];

    for(int i = 1;i <= n;i++){
        if(a[i] != b[i]) continue;
        ll l = i - 1, r = n - i;
        result += l * (l + 1) / 2;
        result += r * (r + 1) / 2;
        result += min(l, r) + 1;
    }

    for(int j = 1;j <= 2;j++){
        for(int i = n;i >= 1;i--){
            while(!sm[a[i]].empty() && sm[a[i]].top() > i){
                ll t = sm[a[i]].top();
                cnt[a[i]]++;
                sum[a[i]] -= t;
                sm[a[i]].pop();
            }

            if(a[i] == b[i]){
                result += cnt[a[i]] * i + sum[a[i]];
                sm[b[i]].push(n - i + 1); sum[b[i]] += n - i + 1;
            }
            else{
                sm[b[i]].push(n - i + 1); sum[b[i]] += n - i + 1;
                result += cnt[a[i]] * i + sum[a[i]];
            }
        }

        reverse(a + 1, a + n + 1);
        reverse(b + 1, b + n + 1);
        for(int i = 1;i <= n;i++){
            sum[i] = cnt[i] = 0;
            while(!sm[i].empty()) sm[i].pop();
        }
    }

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}