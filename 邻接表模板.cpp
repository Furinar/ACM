#include <bits/stdc++.h>
using namespace std;

const int N= 100010;
int head, e[N], en[N], index;

void init(){
    head = -1;
    index = 0;
}

void add_to_head(int x){
    e[index] = x;
    ne[index] = head;
    head = index;
    index++;
}

void add(int k,int x){
    e[index] = x;
    ne[index] = ne[k];
    ne[k] = index;
    index++;
}

void del(int k){
    swap(e[k], e[en[k]]);
    en[k] = en[en[k]];
}