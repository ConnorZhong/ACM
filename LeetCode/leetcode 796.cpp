class Solution {
public:
	bool rotateString(string A, string B)
	{
		int p = 120;
		while(p--)
		{
			A = A.substr(1) + A[0];
			if (A == B) return true;
		}	
		return false;
	}	

}