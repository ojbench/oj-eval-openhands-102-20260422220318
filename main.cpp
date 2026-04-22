#include <bits/stdc++.h>
using namespace std;

static inline int val(char c){
    if(c>='0'&&c<='9') return c-'0';
    if(c>='A'&&c<='Z') return c-'A'+10;
    if(c>='a'&&c<='z') return c-'a'+10;
    return 0;
}
static inline char dig(int v){
    if(v<10) return char('0'+v);
    return char('A'+(v-10));
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m,n,B;
    if(!(cin>>m>>n>>B)) return 0;
    string s1,s2;
    if(!(cin>>s1)) return 0;
    if(!(cin>>s2)) return 0;

    int len1 = (int)s1.size();
    int len2 = (int)s2.size();
    int L = max(len1, len2);

    // compute sum with fixed width L, uppercase output
    string res(L, '0');
    int carry = 0;
    for(int i=0;i<L;i++){
        int d1 = 0, d2 = 0;
        int idx1 = len1-1 - i;
        int idx2 = len2-1 - i;
        if(idx1>=0) d1 = val(s1[idx1]);
        if(idx2>=0) d2 = val(s2[idx2]);
        int sum = d1 + d2 + carry;
        int out = sum % B;
        carry = sum / B;
        res[L-1-i] = dig(out);
    }
    // if carry remains, we truncate (mod within width), so ignore

    // ensure uppercase
    for(char &c: res){
        if(c>='a'&&c<='z') c = char(c - 'a' + 'A');
    }

    cout<<res;
    return 0;
}
