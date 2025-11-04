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
constexpr ll MAX = 101010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], cnt[1010101], d[1010101], mul[1010101];

void run(){
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i], cnt[a[i]]++;

    for(int i = 1;i < 1010101;i++){
        for(int j = i;j < 1010101;j += i){
            if(i != j) cnt[i] += cnt[j];
            d[j]++;
        }
    }

    for(int i = 1;i < 1010101;i++){
        mul[i] = cnt[i] * max(cnt[i] - 1, 0ll) * max(cnt[i] - 2, 0ll) / 6;
    }

    for(int i = 1010100;i >= 2;i--){
        for(int j = 2 * i;j < 1010101;j += i){
            mul[i] -= mul[j]; 
        }
    }

    for(int i = 2;i < 1010101;i++) mul[1] -= mul[i];
    cout << mul[1];
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}
