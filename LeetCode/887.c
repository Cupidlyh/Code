int fun(int K, int T)// 计算 K 个鸡蛋，扔 T 次，可以覆盖多少个区间
{
	//if (T == 1) return 2;
	//if (K == 1) return T + 1;
	if (T == 1 || K == 1) return T + 1;	// 上面两句可以合并成这一句

	return fun(K - 1, T - 1) + fun(K, T - 1);
}

int superEggDrop(int K, int N)
{
	int T = 1;// 测试机会
	while (fun(K, T) < N + 1) T++;
	return T;
}
