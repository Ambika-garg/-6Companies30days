Problem Link: https://leetcode.com/problems/ugly-number-ii/
------------------------------------------------------------------

Approach 1: 
class Solution {
public:
  
    int nthUglyNumber(int n) {
        int a=0,b=0,c=0;int m1=2,m2=3,m3=5;
	    vector<long long int> vec(n+1,0);
	    long long int next = 1;
	    vec[0] = 1;
	    for(int i=1;i<=n;i++)
	    {
	        next = min(min(m1,m2), m3);
	        vec[i] = next;
	        if(next==m1)
	        {
	            a++;
	            m1 = 2*vec[a];
	        }
	        if(next==m2)
	        {
	            b++;
	            m2 = 3*vec[b];
	        }
	        if(next==m3)
	        {
	            c++;
	            m3= 5*vec[c];
	        }
	    }
	    return vec[n-1];
    }
};


Approach 2:
class Solution {
public:
  
    int nthUglyNumber(int n) {
        set<long long int> heap;
	    heap.insert(1);
	    n--;
	    while(n--)
	    {
	        long long int s = *heap.begin();
	        heap.erase(s);
	        heap.insert(s*2);
	        heap.insert(s*3);
	        heap.insert(s*5);
	    }
	    return *heap.begin();
    }
};
