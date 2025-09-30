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
constexpr ll MAX = 251010; // SET MAX SIZE
constexpr ll MOD = 998244353;
constexpr ll MID = 125010;
ll a[MAX], suf[MAX][5], cnt[5], pre;
bool use[MAX];

void st(ll idx, ll num){
    idx += MID;
    if(!a[idx]) return;
    if(!suf[idx][num]) cnt[num]++;
    suf[idx][num]++;
}

void er(ll idx, ll num){
    idx += MID;
    if(!a[idx]) return;
    if(suf[idx][num] && num == 2 && !use[idx]){
        pre++, use[idx] = 1;
        for(int i = 0;i < 5;i++){
            if(suf[idx][i]) cnt[i]--;
            suf[idx][i] = 0;
        }
    }

    if(suf[idx][num] > 0){
        if(suf[idx][num] == 1) cnt[num]--;
        suf[idx][num]--;
    }
}

void run(){
    cin >> n >> m;
    for(int i = 1;i <= n;i++) cin >> k, a[k + MID] = 1;
    cin >> s;

    ll x = 0;
    for(auto& i : s){
        if(i == 'L') x--;
        else if(i == 'R') x++;
        else for(int i = 0;i < 5;i++) st(x - 2 + i, i);
    }
    
    ll result = 0; x = 0;
    for(auto& i : s){
        if(i == 'L'){
            ll now = cnt[4];
            result = max(result, now + pre);

            now = cnt[2];
            result = max(result, now + pre);

            now = cnt[3] + (a[x + MID] && !suf[x + MID][3] && !use[x + MID]);
            result = max(result, now + pre);

            x--;
        }
        else if(i == 'R'){
            ll now = cnt[0];
            result = max(result, now + pre);

            now = cnt[2];
            result = max(result, now + pre);

            now = cnt[1] + (a[x + MID] && !suf[x + MID][1] && !use[x + MID]);
            result = max(result, now + pre);

            x++;
        }
        else{
            ll now = cnt[3] - (suf[x + MID + 1][3] == 1);
            result = max(result, now + pre);

            now = cnt[1] - (suf[x + MID - 1][1] == 1);
            result = max(result, now + pre);

            now = cnt[2];
            result = max(result, now + pre);
            for(int i = 0;i < 5;i++) er(x - 2 + i, i);
        }
    }

    result = max(result, pre);
    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}