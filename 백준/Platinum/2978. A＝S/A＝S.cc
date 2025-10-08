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
ll sum, dp[MAX][5010], st[MAX];
pll pre[MAX][5010];
vector <ll> tr;

ll solve(ll cur, ll sum){
    if(cur < 0 || sum < 0) return INF;
    ll& ret = dp[cur][sum];
    if(ret != -1) return ret; ret = INF;
    if(!cur) return ret = (sum ? INF : 0);

    ll mul = 1, num = 0;
    for(int i = 0;i <= 3;i++){
        if(cur - i - 1 < 0) break;
        num += mul * (s[cur - i - 1] - '0');
        ll now = solve(cur - i - 1, sum - num) + 1;
        if(ret > now){ 
            ret = now; 
            pre[cur][sum] = {sum - num, i + 1}; 
        }

        if(st[cur - i] != -1){
            for(int j = 0;j <= 3;j++){
                if(st[cur - i] + j >= cur - i) break;
                if(s[st[cur - i] + j] != '0') break;
                ll now = solve(st[cur - i] + j, sum - num) + 1;
                if(ret > now){ 
                    ret = now; 
                    pre[cur][sum] = {sum - num, cur - st[cur - i] - j}; 
                }
            }   
        }

        mul *= 10;
    }

    return ret;
}

void run(){
    cin >> s; ll mul = 1; 
    while(s.back() != '='){
        sum += mul * (s.back() - '0');
        mul *= 10;
        s.pop_back();
    }

    s.pop_back(); memset(dp, -1, sizeof(dp));
    memset(st, -1, sizeof(st));
    ll mn = -1;
    for(int i = 0;i < s.size();i++){
        st[i + 1] = mn;
        if(s[i] == '0') mn = min<ll>(mn, i);
        else mn = i + 1;
    }
    solve(s.size(), sum);

    ll cur = s.size(), now = sum;
    while(cur){
        pll p = pre[cur][now];
        tr.push_back(p.y);
        cur -= p.y; now = p.x;
    }

    reverse(all(tr));
    ll idx = 0; tr.pop_back();

    for(auto& i : tr){
        for(int j = idx;j < idx + i;j++) cout << s[j];
        cout << "+";
        idx += i;
    }

    for(int i = idx;i < s.size();i++) cout << s[i];
    cout << "=" << sum;
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}