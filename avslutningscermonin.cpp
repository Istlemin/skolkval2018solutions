/*
Vi definerar en funktion f(last,index) som löser uppgiften från index och frammåt. f svarar alltså på frågan:

Vilket är det största antalet intillsittande par vi kan uppnå bland platserna
index-1, index, index+1, ... , str.size()-1 (platserna är 0-indexerade),
givet att personen på position index-1 är från sällskap "last"?

Det fiffiga med att definera en sådan funktion är att vi kan räkna ut värdet på den rekursivt
genom att testa alla olika möjligheter för hur personen på position index kan byta sin plats,
räkna hur många nya intillsittande par det gav upphov till, och sedan rekursera.

a[i] beskriver vilket sällskap som urspungligen satt på position i.

Fall 1: Personen på plats index sitter kvar.
        Vi räknar antal par bland index-1 och index och rekurserar från f(a[index],index+1)

Fall 2: Personen på plats index byter ett steg till höger.
        Vi utför bytet, räknar antal par bland index-1, index, index+1 och rekurserar från f(a[index],index+2)

Fall 3: Personen på plats index byter två steg till höger (ifall man får byta två steg), och personen på index+1 sitter kvar.
        Vi utför bytet, räknar antal par bland index-1, index, index+1, index+2 och rekurserar från f(a[index],index+3)

Fall 3: Personen på plats index byter två steg till höger, och personen på index+1 byter också plats två steg till höger.
        Vi utför de två bytena, räknar antal par bland index-1, index, index+1, index+2, index+3 och rekurserar från f(a[index+1],index+4)


Värdet av f beror endast av parametrarna last och index. Därför kan vi "memoize:a",
det vill säga vi kommer ihåg svaret för ett givet par av parametrar, så behöver vi inte räkna ut det igen.
Det gör att rekursionsträdet, som annars skulle växt exponetiellt, begränsas till att antalet noder blir maximalt antalet sätt att välja parametrarna 
*/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i < int(b); ++i)
#define trav(a, v) for(auto& a : v)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define D(x) cerr << #x << " = " << x << endl

typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

ll n,m,k;
vi a;

vector<vi> mem;

ll numPairs(vi v){
	ll ans = 0;
	rep(i,0,v.size()-1) ans += (v[i]==v[i+1]);

	return ans;
}

ll f(ll index, ll last){
	if(index==n) return 0;
	//cout<<index<<" "<<last<<endl;
	if(mem[index][last]!=-1) return mem[index][last];

	ll best = f(index+1, a[index]) + numPairs(vi({last,a[index]})); //Fall 1

	if(index<n-1)
		best = max(best, f(index+2,a[index]) + numPairs(vi({last,a[index+1],a[index]})));//Fall 2

	if(k==2){
		if(index<n-2)
			best = max(best, f(index+3,a[index]) + numPairs(vi({last,a[index+2],a[index+1],a[index]})));//Fall 3

		if(index<n-3)
			best = max(best, f(index+4,a[index+1]) + numPairs(vi({last,a[index+2],a[index+3],a[index],a[index+1]})));//Fall 4
	}


	return mem[index][last] = best;
}

int main(){
	cin.sync_with_stdio(false); cin.tie(0);

	string str; cin>>str;
	n = str.size();
	a.resize(n);
	rep(i,0,n) {
		a[i] = str[i]-'A';
	}
	cin>>k;

	mem.resize(n,vi(5,-1));

	cout<<f(0,4)<<endl;
}
