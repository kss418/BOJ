#include <bits/stdc++.h>
#include "bogoSort.h"
using namespace std;
using ll = long long;

void sort_array(int n){
    vector <int> v = copy_array();
    while(1){
        ll s = -1, e = -1;
        for(int i = 0;i < n;i++){
            if(v[i] == i) continue;
            s = i; break;
        }

        if(s == -1) break;
        while(v[s] != s){
            for(int i = 0;i < n;i++){
                if(v[i] != s) continue;
                e = i; break;
            }

            shuffle_array(s, e);
            v = copy_array();
        }
    }
}