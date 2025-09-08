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
constexpr ll MAX = 15; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], result;
bool v[MAX];
ll sum[4][2];
vector <ll> vec;

void bt(){
    if(vec.size() == 16){
        result++;
        return;
    }

    ll sz = vec.size(), y = vec.size() / 4, x = vec.size() % 4;
    if(sz == 7 || sz == 2 || sz == 3){
        if(x == 3 && a[y + 5] != sum[y][0]) return;
        vec.push_back(0);
        bt();
        vec.pop_back();
        return;
    }

    if(x == 3){
        ll la = a[y + 5] - sum[y][0];
        if(la >= 14 || la <= 0 || v[la]) return; 
        if(sum[x][1] + la > a[x + 1]) return;
        v[la] = 1; sum[y][0] += la; sum[x][1] += la;
        vec.push_back(la);
        bt();
        vec.pop_back();
        v[la] = 0; sum[y][0] -= la; sum[x][1] -= la;
        return;
    }

    for(int i = 1;i <= 13;i++){
        if(v[i]) continue;
        if(sum[y][0] + i > a[y + 5]) break;
        if(sum[x][1] + i > a[x + 1]) break;
        v[i] = 1; vec.push_back(i);
        sum[y][0] += i; sum[x][1] += i;
        bt();
        sum[y][0] -= i; sum[x][1] -= i;
        v[i] = 0; vec.pop_back();
    }
}

void run(){
    for(int i = 1;i <= 8;i++) cin >> a[i];
    reverse(a + 5, a + 9); bt();

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}