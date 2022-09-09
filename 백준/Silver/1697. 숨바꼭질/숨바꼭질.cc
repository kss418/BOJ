#include <bits/stdc++.h>
using namespace std;


int main() {
    int n, m,tmp;
    cin >> n >> m;
    int arr[100002];
    fill(arr,arr+100001,-1);
    arr[n] = 0;
    deque <int> q;
    q.push_back(n);
    while (arr[m] == -1) {
        tmp = q.front();
        q.pop_front();
        for(int cur : {tmp-1,tmp+1,2*tmp}){
            if (cur < 0 || cur > 100000){
                continue;
            }
            if (arr[cur] != -1){
                continue;
            }
            arr[cur] = arr[tmp] + 1;
            q.push_back(cur);
        }
        
    }

    cout << arr[m] << endl;
    
    return 0;
}