//Floyd-Warshal algorithm is an all-pairs shortest path algorithm using dynamic programming.
//O(n^3)
void FloydWarshal()
{
	//If graph d is given in matrix form where d[i][i] = 0
	//and rest uninitialized are INT_MAX
	for(ll k = 1; k <= n; k++)
	{
		for(ll i = 1; i <= n; i++)
		{
			for(ll j = 1; j <= n; j++)
				d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
		}
	}
}
	
