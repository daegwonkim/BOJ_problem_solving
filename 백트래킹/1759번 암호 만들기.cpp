/*
* 1. 아이디어
* - 백트래킹을 수행하며 결과값을 배열에 저장한 뒤 출력
* - 결과값을 출력하는 조건은 L개의 알파벳으로 구성되어야 하며, 최소 한 개의 모음과 최소 두 개의 자음으로 구성
* 
* 2. 시간 복잡도
* - 중복 불가능이므로 N!
* 
* 3. 사용 변수
* - int : 구성되는 알파벳의 개수, 사용한 알파벳의 개수
* - char[] : 조교들이 사용했을 법한 알파벳을 저장하기 위한 1차원 배열, 결과값을 저장하기 위한 1차원 배열
*/

#include <iostream>
#include <algorithm>

using namespace std;

#define endl '\n'
#define MAX 15

int l, c;
char alp[MAX];
char result[MAX];

void input()
{
	cin >> l >> c;
	for (int i = 0; i < c; ++i)
		cin >> alp[i];

	sort(alp, alp + c);
}

void BT(int start, int cnt, int vow, int con)
{
	if (cnt == l && vow >= 1 && con >= 2)
	{
		for (int i = 0; i < l; ++i)
			cout << result[i];
		cout << endl;

		return;
	}

	for (int i = start; i < c; ++i)
	{
		result[cnt] = alp[i];

		if (alp[i] == 'a' || alp[i] == 'e' || alp[i] == 'i' || alp[i] == 'o' || alp[i] == 'u')
			BT(i + 1, cnt + 1, vow + 1, con);
		else
			BT(i + 1, cnt + 1, vow, con + 1);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	input();
	BT(0, 0, 0, 0);

	return 0;
}