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
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define repi(i,a,b) for(i=a;i>=b;i--)
#define repdf(i,a,b,d) for(i=a;i<=b;i+=d)
#define repdb(i,a,b,d) for(i=a;i>=b;i-=d)
#define TC() int t;cin>>t;while(t--)
#define vi vector<int> v
#define vc vector<char> v 

int main()
{
	long long int n,arr[3001],r2,res2,ans2=-1,n1,n2;
	cin >> n ;
	n1 = n ;
	n2 = n ;
	rep(i,1,n)
		cin >> arr[i];
	long long int temp,max1 =-1,sum1=0;
	//cin >> n ;
	//int v[3001];
	/*for(int i = 1; i <= n; i++)
	{
	   cin >> temp ;
	   v[i] = temp ; 
	}*/
	for(long long int i1=1;i1<=n1;i1++)
	{
	   for(long long int j1=1;j1<=n1;j1++)
	   {
	   	 sum1 = 0 ;
	   	 if(j1%2==1 && i1+j1<=n)
	   	 {
	   	 	if(j1==1)
	   	 	{
	   	 		sum1+=arr[i1]*arr[i1+1] ;
	   	 	}
	   	 	else
	   	 	{
	   	 		long long int middle1 = (i1)+(j1)/2 ;
	   	 		//cout << i << " " << j << endl ;
	   	 		//cout << middle << endl ;
	   	 		long long int p1 = 0 ;
	   	 		for(long long int k1=i1;k1<=middle1;k1++)
	   	 		{
	   	 			sum1+= arr[k1]*arr[i1+j1-p1] ;
	   	 			p1++ ;
	   	 		}
	   	 	}
	   	 	if(sum1>max1)
	   	 		max1 = sum1 ;
	   	 }
	   }
	}
	//cout << max1 << endl ;
	long long int i2=1,j2,k2,l2;
	while(i2<=n2)
	{
		rep(j2,1,500)
		{
            if(n2>500 && j2==3)
                break;
			r2=i2+j2;
			if(r2>n2)
				break;
			res2=0;
			k2=i2;
			while(k2>1)
			{
				if(r2>n2)
					break;
				res2+=arr[k2]*arr[r2];
				if(res2<0)
					res2=0;
				ans2=max(ans2,res2);
				r2++;
				k2--;
			}
		}
		i2++;
	}
	//cout << ans << "\n";
	cout << max(ans2,max1) << endl ;
  return 0 ;
}