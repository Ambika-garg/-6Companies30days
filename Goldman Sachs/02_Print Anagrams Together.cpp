Problem Link: https://practice.geeksforgeeks.org/problems/print-anagrams-together/1/#
------------------------------------------------------------------------------------
  
  class Solution{
  public:
    vector<vector<string> > Anagrams(vector<string>& string_list) {
        unordered_map<string, vector<string>> mp;
        for(auto i: string_list)
        {
            string s = i;
            sort(s.begin(), s.end());
            mp[s].push_back(i);
            // cout<<s<<" ";
        }
        
        vector<vector<string>> vec;
        for(auto i:mp)
        {
            // cout<<i.first;
            vec.push_back(i.second);
        }
        return vec;
    }
};
