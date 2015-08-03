/************************************************************
   Author : atyam
************************************************************/

#include <bits/stdc++.h>
using namespace std ;

typedef long long ll ;
typedef pair<int,int> pii ;
typedef vector<pii> vii ;

int a[9][9],row1[2],sum,k,col[2],flag1,flag2 ;

class result1
{
public:
   int x1,y1,x2,y2 ;
};

int comp(result1 a,result1 b)
{
    if(a.x1<b.x1)
    {
      return 1 ;
    }
    if(a.x1==b.x1)
    {
      return a.y1<b.y1 ;
    }
}

int solve()
{
  
}

int main()
{
	int test,ans,sum1,sum2 ;
	cin >> test ;
  int cases = 1 ;
	while(test--)
	{
    int p = 0 ;
    std::vector<result1> result;
    flag1 = 0 ;
    flag2 = 0 ;
	  k = 0; 
       for(int i = 0; i < 9; ++i)
       {
       	  sum = 0 ;
       	   for(int j = 0; j < 9; ++j)
       	   {
       		  cin >> a[i][j] ;
       		  sum+=a[i][j] ; 
       	   }
       	    if(sum!=45)
       	    {
       		  row1[k] = i ;
       		  k++ ;
            flag1 = 1 ;
       	   }
       }
       if(flag1==0)
       {
        cout << "Serendipity" << endl ;
       }
       else
       {
          int j = 0 ;
          k = 0 ;
         for(int i=0;i<9;i++)
         {
          for(int j=0;j<9;j++)
          {
            sum1= 0 ;
            sum2 = 0 ;
            swap(a[row1[0]][i],a[row1[1]][j]) ;
            for (int k = 0; k <9 ; ++k)
            {
              sum1+=a[row1[0]][k] ;
              sum2+=a[row1[1]][k] ;
            }
            if(sum1==45 && sum2==45)
            {
              ans = solve() ;
             // cout << ans ;
              if(ans==1)
              {
                 result[p].x1 = row1[0] ;
                 result[p].y1 = i ;
                 result[p].x2 = row1[1] ;
                 result[p].y2 = j ;
                 p++ ;
                // result.push_back(pii(row1[1],j)) ;
              }
            }
            swap(a[row1[0]][i],a[row1[1]][j]) ;
          }
         }
          cout << "Case #" << cases <<":" << endl ;
          sort(result.begin(),result.end(),comp) ;
        /*  for(std::vector<result1>::iterator it =result.begin();it!=result.end();it++)
          {
            cout << result[*it].x1 << result[*it].y1 << result[*it].x2 << result[*it].y2  << endl ;
          }*/
          cout << result.size() ; 
       }
           cases++ ;
	}
  return 0 ;
}