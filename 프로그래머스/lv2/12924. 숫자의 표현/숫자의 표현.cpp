int solution(int n)
{
	// 자기 자신의 숫자는 1을 더해놓고 시작.
	int answer = 1;
	int cnt = 1;
	int cou;
	int add = 0;

	// while문 2개 돌림
	//

	while (true)
	{
		// cou는 cnt부터 시작.
		if (cnt >= ((n / 2) + 1))
			break;
		cou = cnt;
		while (true)
		{
			add += cou;

			// add 값이 n과 같다면 answer에 1을 더함.
			if (add == n) {
				answer++;
				break;
			}
			// add값이 n보다 크다면 while문 탈출.
			else if (add > n) break;
			cou++;
		}

		cnt++;
		add = 0;
	}

	return answer;
}
