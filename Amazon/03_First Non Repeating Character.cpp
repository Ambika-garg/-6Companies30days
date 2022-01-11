Problem Link: https://practice.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1#
------------------------------------------------------------------------------------------------------------
  
  
  class Solution {
	public:
		int cnt[26]={0};
     string FirstNonRepeating(string s){
         // Code here
         int n=s.length();
         queue<char> q;
         string ans;
         for(int i=0;i<n;++i)
         {
             q.push(s[i]);
             cnt[s[i]-'a']++ ;
             
         while (!q.empty() && cnt[q.front() - 'a'] > 1) {
      q.pop();
        }
        if(q.empty())
        ans+='#';
        else
        ans+=q.front();
         }
         return ans;
     }
		

};
