int fun(int K, int T)// ���� K ���������� T �Σ����Ը��Ƕ��ٸ�����
{
	//if (T == 1) return 2;
	//if (K == 1) return T + 1;
	if (T == 1 || K == 1) return T + 1;	// ����������Ժϲ�����һ��

	return fun(K - 1, T - 1) + fun(K, T - 1);
}

int superEggDrop(int K, int N)
{
	int T = 1;// ���Ի���
	while (fun(K, T) < N + 1) T++;
	return T;
}
