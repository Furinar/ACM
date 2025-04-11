#include <bits/stdc++.h>
using namespace std;

const int N = 100010;

int son[N][26], cnt[N], index;

void insert(char str[])
{
    int p = 0;
    for (int i = 0; str[i]; i++)
    {
        int u = str[i] - 'a';
        if (!son[p][u])
            son[p][u] = ++index;
        p = son[p][u];
    }

    cnt[p]++;
}

int query(char str[])
{
    int p = 0;
    for (int i = 0; str[i];i++){
        int u = str[i] - 'a';
        if(!son[p][u])
            return 0;
        p = son[p][u];
    }
    return cnt[p];
}