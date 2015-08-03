#include <bits/stdc++.h>
using namespace std ;

// A utility function to get the middle index from corner indexes.
long long int getMid(long long int s, long long int e) {  return s + (e -s)/2;  }
 
/*  A recursive function to get the sum of values in given range of the array.
    The following are parameters for this function.
 
    st    --> Polong long inter to segment tree
    index --> Index of current node in the segment tree. Initially 0 is
             passed as root is always at index 0
    ss & se  --> Starting and ending indexes of the segment represented by
                 current node, i.e., st[index]
    qs & qe  --> Starting and ending indexes of query range */
long long int getSumUtil(long long int *st, long long int ss, long long int se, long long int qs, long long int qe, long long int index)
{
    // If segment of this node is a part of given range, then return the 
    // sum of the segment
    if (qs <= ss && qe >= se)
        return st[index]%1000000007;
 
    // If segment of this node is outside the given range
    if (se < qs || ss > qe)
        return 0;
 
    // If a part of this segment overlaps with the given range
    long long int mid = getMid(ss, se);
    return getSumUtil(st, ss, mid, qs, qe, 2*index+1)%1000000007 +
           getSumUtil(st, mid+1, se, qs, qe, 2*index+2)%1000000007;
}

void update_tree(long long int arr[],long long int *st,long long int node,long long int a,long long int b,long long int i,long long int j,long long int value) 
{
    
    if(a > b || a > j || b < i) // Current segment is not within range [i, j]
        return;
    
    if(a == b) 
    { 
            arr[node] += (value*(value+1));
            value+=1 ;
            return;
    }
 
    update_tree(arr,st,node*2, a, (a+b)/2, i, j, value); // Updating left child
    update_tree(arr,st,1+node*2, 1+(a+b)/2, b, i, j, value); // Updating right child
 
    arr[node] = arr[node*2] +arr[node*2+1]; // Updating root with max value
}

 
// Return sum of elements in range from index qs (quey start) to
// qe (query end).  It mainly uses getSumUtil()
long long int getSum(long long int *st, long long int n, long long int qs, long long int qe)
{
    // Check for erroneous input values
    if(qs < 0 || qe > n-1 || qs > qe)
    {
        printf("Invalid Input");
        return -1;
    }
 
    return getSumUtil(st, 0, n-1, qs, qe, 0);
}
 
// A recursive function that constructs Segment Tree for array[ss..se].
// si is index of current node in segment tree st
long long int constructSTUtil(long long int arr[], long long int ss, long long int se, long long int *st, long long int si)
{
    // If there is one element in array, store it in current node of
    // segment tree and return
    if (ss == se)
    {
        st[si] = arr[ss];
        return arr[ss];
    }
 
    // If there are more than one elements, then recur for left and
    // right subtrees and store the sum of values in this node
    long long int mid = getMid(ss, se);
    st[si] =  constructSTUtil(arr, ss, mid, st, si*2+1) +
              constructSTUtil(arr, mid+1, se, st, si*2+2);
    return st[si];
}
 
/* Function to construct segment tree from given array. This function
   allocates memory for segment tree and calls constructSTUtil() to
   fill the allocated memory */
long long int *constructST(long long int arr[], long long int n)
{
    // Allocate memory for segment tree
    long long int x = (long long int)(ceil(log2(n))); //Height of segment tree
    long long int max_size = 2*(long long int)pow(2, x) - 1; //Maximum size of segment tree
    long long int *st = new long long int[max_size];
 
    // Fill the allocated memory st
    constructSTUtil(arr, 0, n-1, st, 0);
 
    // Return the constructed segment tree
    return st;
}
 
// Driver program to test above functions
int main()
{
    long long int arr[200001] ;
    long long int n,q,a,x,y ;
    cin >> n >> q ;
    memset(arr,0,n) ;
 
    // Build segment tree from given array
    long long int *st = constructST(arr, n);
    for (long long int i = 0; i < q; ++i)
    {
        cin >> a >> x >> y ;
        if(a==1)
        {
            long long int ref1 = 1 ;
         //   for (long long int j = x-1; j <y ; ++j)
           // {
                 update_tree(arr,st,1,0,n-1,x-1,y-1,1) ;
             //   ref1+=1 ;
            //}
        }
        else
        {
            cout << getSum(st, n,x-1,y-1)%1000000007 << endl;
        }
    }
    return 0;
}
