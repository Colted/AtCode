#include<bits/stdc++.h>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i,n) for(int i=0;i<n;i++)
using P=pair<int,int>;
 
int main(void){
int n;
const int MX=1000005;
vector<vector<P>> events(MX);
cin >> n;
rep(ni,n){
    int m;
    cin>>m;
    vector<P> p(m);
    rep(i,m) cin>>p[i].first>>p[i].second;
    int j=0;
 
    rep(i,m) if(p[i]<p[j]) j=i;
    rotate(p.begin(),p.begin()+j,p.end());
    if(p[0].first != p[1].first){
        reverse(p.begin()+1,p.end());
    }
    for(int i=0;i<m;i+=2){
        int x=p[i].first;
        int l=p[i].second,r=p[i+1].second;
        events[x].emplace_back(l,r);
    }
}
int q;
cin >> q;
vector<vector<P>> qs(MX);
rep(i,q){
    int x,y;
    cin >> x >> y;
    qs[x].emplace_back(y,i);
}
vector<int> ans(q);
 
fenwick_tree<int> t(MX);
rep(x,MX){  
    for(auto [l,r] : events[x]){
 
        int w=1;
        if(l > r) swap(l,r), w= -1;
        t.add(l,w);
        t.add(r,-w);
    }
    for(auto [y,qi] : qs[x]){
        ans[qi]=t.sum(0,y+1);
    }
}
 
rep(i,q) cout<<ans[i]<<endl;
}