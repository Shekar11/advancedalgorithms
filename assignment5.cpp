#include <bits/stdc++.h>
using namespace std;

int lcs(string str1, string str2, int x, int y)
{
	int dp[x + 1][y + 1];

	for (int i = 0; i <= x; i++)
	{
		for (int j = 0; j <= y; j++)
		{
			if (i == 0 || j == 0)
			{
				dp[i][j] = 0;
			}
			else if (str1[i - 1] == str2[j - 1])
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else
			{
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}

	return dp[x][y];
}

int main()
{
	string str1 = "AGGTAB";
	string str2 = "GXTXAYB";
	int x = str1.size();
	int y = str2.size();

	cout << "LCS is " << lcs(str1, str2, x, y);

	return 0;
}
