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

int main()
{
	long long int n,k,count1=0,temp ;
	cin >> n >> k ;
	std::vector<long long int> boys;
	std::vector<long long int> girls;
	for(int i = 0; i < n; ++i)
	{
		cin >> temp ;
		boys.PB(temp) ;
	}
	for(int i = 0; i < n; ++i)
	{
		cin >> temp ;
		girls.PB(temp) ;
	}
    sort(all(boys)) ;
    sort(all(girls)) ;
    /*for(int i = 0; i < n; ++i)
	{
		cout << boys[i] << " ";
	}
	for(int i = 0; i < n; ++i)
	{
		cout << girls[i] << " ";
	}*/
    for(int i = 0,j=0; i < n && j<n;)
    {
    	//cout << i << endl ;
    	if(abs(boys[i]-girls[j])<=k)
    	{
    		count1++ ;
    		//cout << count1 << endl ;;
    		i++ ;
    		j++ ;
    	}
    	else
    	{
    		if(boys[i]>girls[j])
    			j++ ;
    		else
    			i++ ;
    	}
    }
    cout << count1 << endl ;
  return 0 ;
}