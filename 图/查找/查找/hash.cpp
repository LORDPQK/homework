#include"iostream"
#include <iomanip>
using namespace std;
int main()
{
	int hash[10], x, y, i;
	cout << "������10��0-99֮�������" << endl;
	for (i = 1; i <= 10; i++)
	{
		cin >> x;
		if (!(x >= 0 && x <= 99))
		{
			cout << "�������" << endl;
			return 0;
		}
		y = x % 10;
		while (true)
		{
			if (!(hash[y] <= 99 && hash[y] >= 0))
			{
				hash[y] = x;
				break;
			}
			else if (++y == 10)
				y = 0;
		}
	}
	cout << "���ɵĹ�ϣ��Ϊ��" << endl;
	for (i = 0; i < 10; i++)
		cout << setw(4) << i << "|";
	cout << endl << "  _________________________________________________" << endl;
	for (i = 0; i < 10; i++)
		cout << setw(4) << hash[i] << "|";
	return 0;
}