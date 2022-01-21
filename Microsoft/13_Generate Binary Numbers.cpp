Problem Link:https://practice.geeksforgeeks.org/problems/generate-binary-numbers-1587115620/1/
-------------------------------------------------------------------------------------------------



vector<string> generate(int N)
{
	vector<string> res;
	
	queue<string> q;
	q.push("1");
	for(int i=0;i<N;i++)
	{
	    string str =  q.front();
	    res.push_back(str);
	    q.pop();
	    q.push(str+'0');
	    q.push(str+'1');
	}
	return res;
}


