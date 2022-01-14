Problem Link: https://practice.geeksforgeeks.org/problems/phone-directory4628/1/#
-------------------------------------------------------------------------------------------
  
  
  
  class Solution{
public:
    vector<string> SearchContacts(string str, string contact[],int n)
    {
        set<string> ans;
        for(int i=0;i<n;i++)
        {
            
            if(str == contact[i].substr(0, str.length()))
            {
                ans.insert(contact[i]);
            }
        }
        if(ans.empty())
        {
            ans.insert("0");
        }
        vector<string> v;
        for(auto i: ans)
        {
            v.push_back(i);
        }
        return v;
    }
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        vector<vector<string>> ans;
        int i=1;
        while(i<=s.length())
        {
            string str = s.substr(0,i);
            vector<string> vec = SearchContacts(str,contact,n);
            ans.push_back(vec);
            i++;
        }
        return ans;
    }
};
