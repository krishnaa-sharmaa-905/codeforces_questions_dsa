#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>

struct Query{
    int l, r, idx;
};

int BLOCK;

// sorting queries
bool cmp(Query a, Query b){

    int blockA = a.l / BLOCK;
    int blockB = b.l / BLOCK;

    if(blockA != blockB)
        return blockA < blockB;

    return a.r < b.r;
}

void solve(){

    int n;
    cin >> n;

    vi a(n);

    for(int i = 0; i < n; i++)
        cin >> a[i];

    int q;
    cin >> q;

    vector<Query> queries(q);

    for(int i = 0; i < q; i++){

        cin >> queries[i].l
            >> queries[i].r;

        queries[i].l--;
        queries[i].r--;

        queries[i].idx = i;
    }

    BLOCK = sqrt(n);

    sort(queries.begin(),
         queries.end(),
         cmp);

    unordered_map<int,int> freq;

    int distinct = 0;

    auto add = [&](int idx){

        freq[a[idx]]++;

        if(freq[a[idx]] == 1)
            distinct++;
    };

    auto remove = [&](int idx){

        freq[a[idx]]--;

        if(freq[a[idx]] == 0)
            distinct--;
    };

    int currL = 0;
    int currR = -1;

    vi ans(q);

    for(auto qu : queries){

        int L = qu.l;
        int R = qu.r;

        // expand right
        while(currR < R){

            currR++;

            add(currR);
        }

        // shrink right
        while(currR > R){

            remove(currR);

            currR--;
        }

        // shrink left
        while(currL < L){

            remove(currL);

            currL++;
        }

        // expand left
        while(currL > L){

            currL--;

            add(currL);
        }

        ans[qu.idx] = distinct;
    }

    for(int x : ans)
        cout << x << endl;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}