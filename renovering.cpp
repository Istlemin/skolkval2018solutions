/*
Vi vill para ihop maximalt antal spikar som vi redan har med spikar som vi behöver,
på ett sådant sätt så att i varje par är spiken vi behöver kortare eller lika lång som den vi redan har.
Säg att den längsta spiken som vi redan har har längd L.
Den vill vi para ihop med den längsta spiken som vi redan har, som uppfyller att dess längd <= L,
eftersom ju längre spik desto större krav ställer spiken på vilka den kan paras ihop med.
När vi parat ihop den längsta spiken vi redan har med den längsta vi behöver som den kan paras ihop med så tar vi bort dessa två och upprepar.
När den längsta spiken vi har inte längre kan paras ihop med någon, eller när alla våra spikar är ihopparade, är vi färdiga

*/

#include<bits/stdc++.h>

using namespace std;

#define rep(i,a,b) for(int i = a; i<int(b);++i)
#define all(v) v.begin(),v.end()
#define sz(v) v.size()
#define trav(a,c) for(auto a: c)

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pii;

int main(){
	cin.sync_with_stdio(false);
    ll n,m;
    cin>>n>>m;
    vi x(n);
    vi y(m);
    rep(i,0,n) cin>>x[i];
    rep(i,0,m) cin>>y[i];

    //Sortera så att de längsta spikarna hamnar sist
    sort(all(x)); 
    sort(all(y));

    vi toBuy;

    while(x.size()){
		if(y.size()&&x[x.size()-1]<=y[y.size()-1]){ //Ifall den längsta spiken vi behöver är kortare än den längsta vi har
			 //Då tar vi bort båda
			x.pop_back();
			y.pop_back();
		} else {
			//Annars kan den längsta vi behöver omöjligt paras ihop med någon, så vi säger att vi måste köpa den och tar sedan bort den.
			toBuy.push_back(x[x.size()-1]);
            x.pop_back();
		}
    }

    sort(all(toBuy));

	cout<<toBuy.size()<<endl;
	rep(i,0,toBuy.size()){
		cout<<toBuy[i]<<" ";
	}
	cout<<endl;
}
