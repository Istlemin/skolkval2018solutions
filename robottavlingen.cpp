/*
Att hitta maximala antalet är enkelt, det är bara att för varje ruta i rutnätet ta minimumvärdet av kolumnvärdet och radvärdet.

Att hitta minimala antalet är svårare. Vi börjar med att betrakta hur många 5or som behöver sätta ut, om vi vill har så få som möjligt.
Vi måste såklart minst lägga en 5a i varje kolumn som har värdet 5 (hur skulle kolumnen fått värdet 5 om den inte innehåller en 5a?),
och vi måste på samma sätt även lägga en 5a i varje rad.
Om fr5 är antalet rader med värdet 5 och fc5 antalet kolumner med värdet 5 behöver vi då minst max(fr5,fc5) stycken 5or.
Så länge det finns både någon 5-kolumn utan 5a i sig och en 5-rad som inte innehåller en femma så kan vi placera en 5a i den rutan som 
kolumnen och raden delar. Ifall vi bara har en 5-rad så kan vi placera ut en 5a i den raden i någon kolumn som redan har en 5a i sig,
och på samma sätt kan vi göra om vi bara har en 5-kolumn. Alltså går max(fr5,fc5) antal 5or att uppnå.

Samma argument kan vi använda för 4,3 och 2 får att bevisa att minsta antal 4or, 3or och 2or är max(fr4,fc4), max(fr3,fc3) och max(fr2,fc2) respektive.
Skillnaden är att man måste notera att när man inte tex har en 4-rad som man måste placera en fyra i, men inga 4-kolumner,
så kan vi placera 4an i någon av 5-kolumnerna istället. Det kommer alltid antingen finnas en 4a-kolumn eller 5-kolumn att placera i,
eftersom det det måste enligt raden vi jobbar med finnas en 4a någonstans, så någon kolumns maxvärde är minst 4.

Alla rutor som vi inte redan placerat något i placerar vi 1or i.

Notera att i lösningen placerar vi aldrig faktiskt ut något, utan bara räknar direkt ut vad summan blir om vi hade placerat ut det.
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

int main(){
	cin.sync_with_stdio(false); cin.tie(0);

	ll n;
	cin>>n;
	vi r(n);
	vi c(n);
	rep(i,0,n) cin>>r[i];
	rep(i,0,n) cin>>c[i];

	ll mx = 0;
	rep(i,0,n)
		rep(j,0,n){
			mx += min(r[i],c[j]);
		}
	map<ll,ll> fr;
	map<ll,ll> fc;

	rep(i,0,n){
		fr[r[i]]++;
		fc[c[i]]++;
	}

	ll mn = 0;
	ll numPlaced = 0;

	rep(i,1,6){
		mn += max(fc[i],fr[i])*i; //Placera ut max(fc[i],fr[i]) stycken av siffran "i"
		numPlaced += max(fc[i],fr[i]);
	}

	mn += n*n - numPlaced; //Lägg till alla ettor


	cout<<mn<<" "<<mx<<endl;

}
