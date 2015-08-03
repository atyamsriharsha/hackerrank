/************************************************************
   Author : atyam
************************************************************/

#include <bits/stdc++.h>
using namespace std ;
#define ll long long

/*debugging*/

#define out1(x)cout<<#x<<" is "<<x<<endl
#define out2(x,y)cout<<#x<<" is "<<x<<" "<<#y <<" is "<<y<<endl
#define out3(x,y,z)cout<<#x<<" is "<<x<<" "<<#y<<" is "<<y<<" "<<#z<<" is "<<z<<endl;
#define out4(a,b,c,d)cout<<#a<<" is "<<a<<" "<<#b<<"  is "<<b<<" "<<#c<<" is "<<c<<" "<<#d<<" is "<<d<<endl;
#define show(i,a,n) for(i=0;i<n;i++)cout<<a[i]<<" ";cout<<endl;
#define sz(a) cout<<"size of "<<#a<<" is "<<a.size()
#define exectime() cout<<"execution time "<<(double)(clock() - tStart)/CLOCKS_PER_SEC<<endl;

/*standard values*/

#define INF 1e18
#define PI 3.14159265359
#define MAX 1000006


/*Frequent functions*/
#define all(v) v.begin(),v.end()
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define si(n) scanf("%d",&n)
#define sl(n) scanf("%lld",&n)
#define pu putchar
#define gu getchar
#define FastIn std::ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

/*loops and initialisation*/

#define init(a,b) memset(a,b,sizeof(a))
#define rep(i,a,b) for(int i=a;i<b;i++)
#define repi(i,a,b) for(i=a;i>=b;i--)
#define repdf(i,a,b,d) for(i=a;i<=b;i+=d)
#define repdb(i,a,b,d) for(i=a;i>=b;i-=d)
#define TC() int t;cin>>t;while(t--)
#define vi vector<int> v
#define vc vector<char> v 

bool cmp(pair<long long,long long>p1,pair<long long,long long>p2)
{
	if(p1.second==p2.second)
	{
		return p1.first>=p2.first ;
	}
	return p1.second<=p2.second ;
}

int main()
{
	long long n,count1,max1=-1,ref1,ref2,indx1,indx2 ;
	pair<long long,long long>res[100001] ;
	cin >> n ;
	for(long long i = 1; i <= n; i++)
	{
		cin >> res[i].first ;
		//indx1 = res[i].first ;
		cin >> res[i].second ;
		//indx2 = res[i].second ;
	}
	sort(res+1,res+n+1,cmp) ;
/*	for(long long i = 1; i <= n; i++)
	{
		cout << res[i].first << " ";
		cout << res[i].second << endl;
	}
*/
	for(long long i = 1; i <=n; i++)
	{
		count1  = n-i+1 ;
		ref1 = res[i].first ;
		cout << res[i].first << " " << res[i].second << endl ;
		for(int j = i+1; j <=n ; j++)
		{
		       cout << res[j].first << " " << res[j].second << endl ;
	           if(ref1>=res[j].first  && res[i].second <= res[j].second)
	           {
	    	     count1-- ;
	    	    // ref1 = res[j].first ;
	    	   }
	    	   else
	    	   {
	    	   	ref1 = res[j].first ;
	    	   }
	    }
	//   cout << count1 << " " ;
	   max1 = max(max1,count1) ;
	//   cout << "this is max1" << " "<< max1 << endl ;
	}
	cout << max1 << endl ;
  return 0 ;
}