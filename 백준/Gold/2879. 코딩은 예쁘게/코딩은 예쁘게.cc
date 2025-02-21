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
constexpr ll MAX = 1010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], b[MAX], num[MAX], result;

bool chk(){
    for(int i = 1;i <= n;i++){
        if(num[i]) return 0;
    }
    return 1;
}

void run(){
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 1;i <= n;i++) cin >> b[i], num[i] = a[i] - b[i];
    num[0] = num[1];

    while(!chk()){
        ll now = INF, la = 1;
        for(int i = 1;i <= n;i++){
            if(num[i] > 0 && num[i - 1] > 0) now = min(now, abs(num[i]));
            else if(num[i] < 0 && num[i - 1] < 0) now = min(now, abs(num[i]));
            else{
                if(now != INF){
                    for(int j = la;j < i;j++) num[j] += (num[j] > 0 ? -now : now);
                    result += now;
                }
                now = (num[i] ? abs(num[i]) : INF); la = i;
            }
        }
       
        if(now == INF) continue;
        for(int j = la;j <= n;j++) num[j] += (num[j] > 0 ? -now : now);
        result += now;
    }

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

