vvi dp (n + 1, vi((1LL << 5), inf));
	dp[0][0] = 0;
	rep(i, 1, n){
		int ma = 0;
		rep(j, 1, 5)
			if(a[i][j] >= val)
				ma |= (1LL << (j - 1));
		dp[i] = dp[i - 1];
		rep(j, 0, (1LL << 5) - 1)
			dp[i][j | ma] = min(dp[i][j | ma], dp[i - 1][j] + 1);
	}
	return (dp[n][(1LL << 5) - 1] <= 3);