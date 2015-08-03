/************************************************************
   Author : atyam
************************************************************/

#include <bits/stdc++.h>
using namespace std ;


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
#define rep(i,a,b) for(i=a;i<=b;i++)
#define repi(i,a,b) for(i=a;i>=b;i--)
#define repdf(i,a,b,d) for(i=a;i<=b;i+=d)
#define repdb(i,a,b,d) for(i=a;i>=b;i-=d)
#define TC() int t;cin>>t;while(t--)

std::vector<long long int> v;
long long int n ;

/*int search(int temp,int high,int low)
{
	int mid = (high+low)/2 ;
    if(high<low)
    	return 0;


	if(temp > v[mid])
		search(temp,high,mid+1)
	else
		search(temp,0,mid) ;
}*/
int main()
{
	long long int temp,j,count1 ;
	cin >>  n;
	for(long long int i=0;i<n;i++)
	{
		cin >> temp ;
		v.PB(temp) ;
	}
	sort(v.begin(),v.end()) ;
	int max1 = v[n-1] ;
	int min1 = v[0] ;
	int q ;
	cin >> q ;
	for(int i=0;i<q;i++)
	{
		count1 = 0 ;
		cin >> temp ;
		if(temp>v[n-1])
		{
			cout << n ;
			//continue ; 
		}
		else if(temp<v[0])
			cout << 0 ;
        else
        {
		  for(j=0;j<n;j++)
		  {
			//cout << "atyam" ;
			if(temp<=v[j])
			{
				break ;
			}
			else if(temp>v[j])
			{
				count1++ ;
			}
		  }
		  cout << count1 << endl;
	    }
	}
  return 0 ;
}

