#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; using ll = long long; using pll = pair<ll, ll>; 
constexpr ll INF = 0x3f3f3f3f3f3f3f3f;

ll findMinClicks(int m, int k, vector<pair<int,int>> a){
    vector <vector <ll>> arr(m);
    vector <ll> vx;
    unordered_map <ll, ll> mp; ll now = 0, c = 0;
    for(auto& [y, x] : a) arr[y].push_back(x);

    mp[k - 1] = 0;
    for(int i = 0;i < m;i++){
        if(arr[i].empty()) continue;
        ll sz = arr[i].size();
        for(int j = 0;j < sz;j++) arr[i].push_back(arr[i][j] + k);
        sort(all(arr[i]));

        now += arr[i][0];
        mp[arr[i][0]] += 2; mp[0]--;
        vx.push_back(arr[i][0]);
        vx.push_back(0);

        for(int j = 1;j < arr[i].size();j++){
            ll diff = arr[i][j] - arr[i][j - 1];
            mp[arr[i][j]] += 2;
            vx.push_back(arr[i][j]);
            if(diff % 2){
                mp[arr[i][j - 1] + diff / 2]--;
                mp[arr[i][j - 1] + (diff / 2) + 1]--;
                vx.push_back(arr[i][j - 1] + (diff / 2));
                vx.push_back(arr[i][j - 1] + (diff / 2) + 1);
            }
            else{
                mp[arr[i][j - 1] + diff / 2] -= 2;
                vx.push_back(arr[i][j - 1] + diff / 2);
            }
        }
    }

    sort(all(vx)); vx.erase(unique(all(vx)), vx.end());

    ll ret = INF;
    for(int i = 0;i < vx.size();i++){
        ll x = vx[i], y = mp[x];
        ret = min(ret, now);
        if(i + 1 == vx.size()) break;

        ll nx = vx[i + 1];
        c += y; now += (nx - x) * c;
    }

    return ret;
}   