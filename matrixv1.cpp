#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
using namespace std;

int main()
{
	srand(time(0));
	int a, b, c, d, k,l;
	cout << "stroki";
	cin >> a;
	cout << "stolbiki";
	cin >> b;
	cout << "strokiv2";
	cin >> c;
	cout << "stolbikiv2";
	cin >> d;
	cout << "kol-vo probelov";
	cin >> k;
	cout << "kol-vo probelov final";
	cin >> l;
	int** M1 = new int* [a];
	for (int i = 0; i < a; i++)
	{
		M1[i] = new int[b];
	}
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < b; j++)
		{
			M1[i][j] = rand() % 100 + 1;
		}
	}
	int** M2 = new int* [c];
	for (int i = 0; i < c; i++)
	{
		M2[i] = new int[d];
		for (int j = 0; j < d; j++)
		{
			M2[i][j] = rand() % 100 + 1;
		}
	}
	if (b != c)
	{
		cout << "nea" << endl;
		return 69;
	}
	int** M3 = new int* [a];
	for (int i = 0; i < a; i++)
	{
		M3[i] = new int[d];
		for (int j = 0; j < d; j++)
		{
			M3[i][j] = 0;
		}
	}
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < d; j++)
		{
			for (int z = 0; z < b; z++)
			{
				M3[i][j] += M1[i][z] * M2[z][j];
			}
		}
	}
	cout << "M1\n";
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < b; j++)
		{
			cout << setw(k) << M1[i][j];
		}
		cout << endl;
	}
	cout << "M2\n";
	for (int i = 0; i < c; i++) {
		for (int j = 0; j < d; j++) {
			cout << setw(k) << M2[i][j];
		}
		cout << endl;
	}
	cout << "M3\n";
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < b; j++)
		{
			cout << setw(l) << M3[i][j];
		}
		cout << endl;
	}
	return 0;
}
