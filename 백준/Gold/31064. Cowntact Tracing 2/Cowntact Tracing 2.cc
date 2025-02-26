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
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;
vector <ll> num;
ll mn = INF, result;

void run(){
    cin >> n >> s; ll cnt = 0;
    for(int i = 0;i < n;i++){
        if(s[i] == '0'){
            if(!cnt) continue;
            num.push_back(cnt); cnt = 0;
        }
        else cnt++;
    }
    if(cnt) num.push_back(cnt);

    
    for(int i = 0;i < num.size();i++) {
        if(s[0] == '1' && !i) mn = min(mn, num[i] - 1);
        else if (s.back() == '1' && i == num.size() - 1){
            mn = min(mn, num[i] - 1);
        }
        else mn = min(mn, (num[i] - 1) / 2);
    }
    
    for(int i = 0;i < num.size();i++) {
        ll now = 0;
        now = num[i] / (2 * mn + 1) + (num[i] % (2 * mn + 1) ? 1 : 0);
        result += now;
    }

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}