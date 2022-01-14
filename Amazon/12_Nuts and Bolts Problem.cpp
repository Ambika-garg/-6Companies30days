Problem Link: https://practice.geeksforgeeks.org/problems/nuts-and-bolts-problem0431/1#
-----------------------------------------------------------------------------------------
  
  
  class Solution{
public:	

	void matchPairs(char nuts[], char bolts[], int n) {
	    // code 
	    unordered_map<char, int> dict;
	    vector<char> arr = {'!', '#', '$', '%', '&', '*', '@', '^', '~' };
	    for(int i=0;i<arr.size();i++)
	    {
	        dict[arr[i]] = i+1;
	    }
	    
	    for(int i=0;i<n;i++)
	    {
	        nuts[i] = dict[nuts[i]];
	        bolts[i] = dict[bolts[i]];
	    }
	    
	    sort(nuts, nuts+n);
	    sort(bolts, bolts+n);
	    
	    for(int i=0;i<arr.size();i++)
	    {
	        dict[i+1] = arr[i];
	    }
	    
	    for(int i=0;i<n;i++)
	    {
	        nuts[i] = dict[nuts[i]];
	        bolts[i] = dict[bolts[i]];
	    }
	    return;
	}

};


