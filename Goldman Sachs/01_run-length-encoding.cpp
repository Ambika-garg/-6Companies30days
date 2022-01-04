Problem Link : https://practice.geeksforgeeks.org/problems/run-length-encoding/1/#
----------------------------------------------------------------------------------------
  
 string encode(string src)
{     
  //Your code here 
  int count = 0;
  string ans = "";
  char s = src[0];
  for(int i=0;i<=src.length();i++)
  {
      if(s == src[i])
      {
          count++;
      }
      else
      {
          ans = ans+s;
          ans = ans + to_string(count);
          count = 1;
          s = src[i];
      }
  }
  return ans;
}     
 
