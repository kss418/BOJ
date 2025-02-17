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
constexpr ll MAX = 101010; // SET MAX SIZE
constexpr ll MOD = 998244353;
string st[3], result;
ll cnt[3], use[3];
vector <ll> one, two[3];

void run(){
    for(int i = 0;i < 3;i++) cin >> st[i];
    result.resize(st[0].size());

    for(int i = 0;i < st[0].size();i++){
        if(st[0][i] != st[1][i] && st[1][i] != st[2][i] && st[2][i] != st[0][i]){
            one.push_back(i);
        }
    }

    for(int i = 0;i < st[0].size();i++){
        if(st[0][i] == st[1][i] && st[1][i] == st[2][i]){
            for(int j = 0;j < 3;j++) cnt[j]++;
            result[i] = st[0][i];
        }
        else if(st[0][i] != st[1][i] && st[1][i] != st[2][i] && st[2][i] != st[0][i]) {}
        else{
            if(st[0][i] == st[1][i]){
                cnt[0]++; cnt[1]++;
                result[i] = st[0][i];
                two[2].push_back(i);
            }
            else if(st[0][i] == st[2][i]){
                cnt[0]++; cnt[2]++;
                result[i] = st[0][i];
                two[1].push_back(i);
            }
            else{
                cnt[1]++; cnt[2]++;
                result[i] = st[1][i];
                two[0].push_back(i);
            }
        }
    }

    for(auto& i : one){
        ll mn = cnt[0], idx = 0;
        for(int j = 1;j < 3;j++){
            if(cnt[j] > mn) continue;
            mn = cnt[j]; idx = j;
        }
        cnt[idx]++;
        result[i] = st[idx][i];
    }

    ll mn = cnt[0], idx = 0;
    for(int i = 1;i < 3;i++){
        if(cnt[i] > mn) continue;
        mn = cnt[i]; idx = i;
    }

    while(1){
        bool flag = 0;
        for(int i = 0;i < 3;i++){
            if(idx == i) continue;
            if(cnt[idx] >= cnt[i]) flag = 1;
        }

        if(two[idx].empty() || flag) break;
        for(int i = 0;i < 3;i++){
            cnt[i] += (i == idx ? 1 : -1);
        }
        ll back = two[idx].back(); two[idx].pop_back();
        result[back] = st[idx][back];
    }

    cout << st[0].size() - min({cnt[0], cnt[1], cnt[2]}) << "\n" << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}