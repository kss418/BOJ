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
constexpr ll MAX = 301010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], l[MAX], r[MAX], sl[MAX], sr[MAX];
bool tl[MAX], tr[MAX];


void run(){
    cin >> n >> m;
    for(int i = 1;i <= n;i++) cin >> a[i];
    cin >> s; a[0] = a[n + 1] = INF;

    for(int i = 1;i <= n;i++){
        if(s[i - 1] == 'T') tl[i] = 1;
        if(a[i] >= a[i - 1]) tl[i] |= tl[i - 1];
    }

    for(int i = n;i >= 1;i--){
        if(s[i - 1] == 'T') tr[i] = 1;
        if(a[i] >= a[i + 1]) tr[i] |= tr[i + 1];
    }

    for(int i = 1;i <= n;i++){
        l[i] = sl[i] = 1;
        if(a[i] >= a[i - 1]) l[i] = l[i - 1] + 1;
        if(a[i] == a[i - 1]) sl[i] = sl[i - 1] + 1;
    }

    for(int i = n;i >= 1;i--){
        r[i] = sr[i] = 1;
        if(a[i] >= a[i + 1]) r[i] = r[i + 1] + 1;
        if(a[i] == a[i + 1]) sr[i] = sr[i + 1] + 1;
    }

    if(tl[m] || tr[m]){
        ll now = 0, mx = 0;
        for(int i = 1;i <= n;i++){
            if(tl[i] || tr[i]) now++;
            else mx = max({mx, sl[i] + sr[i] - 1 + max(l[i] - sl[i], r[i] - sr[i])});
        }

        cout << now + mx;
    }
    else{
        cout << sl[m] + sr[m] - 1 + max(l[m] - sl[m], r[m] - sr[m]);
    }
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}