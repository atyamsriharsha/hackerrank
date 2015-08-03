/* author :: atyam*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
	stack<int> s;
    int v[100005],v1[100005];
	int n,i,top,ans=0,hare,fox=-1;
	cin >> n;
	for(i=1;i<=n;i++)
	 cin>>v[i];
	v1[1]=-1;
	s.push(1);
	for(i=2;i<=n;i++)
	{
		top=s.top();
		if(v[i]>=v[top])
		{
			v1[i]=top;
		}
		else
		{
			while(!s.empty() && v[i]<v[s.top()])
			{
				s.pop();
			}
			if(s.empty())
				v1[i]=-1;
			else
			 v1[i]=s.top();
		}
		s.push(i);
	}
	for(i=1;i<=n;i++)
	{
		if(v1[i]!=-1)
		{
			if(i-v1[i]>ans)
				if(fox==-1)
					ans++;
				else
				 ans+=(i-fox);
			fox=i;
		}
	}
	cout << ans << "\n";
	return 0;
}