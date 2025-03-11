#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <vector>
#include <thread>
#include <atomic>
using namespace std;
atomic<int> finalsum = 0;

void Mnogoparametrov(int** M1, int** M2, int** M3, int start, int end, int b, int d)
{
	for (int i = start; i < end; i++)
	{
		for (int j = 0; j < d; j++)
		{
			M3[i][j] = 0;
			for (int z = 0; z < b; z++)
			{
				M3[i][j] += M1[i][z] * M2[z][j];
			}
			finalsum += M3[i][j];
		}
	}
}
int main()
{
	srand(time(0));
	int a, b, c, d, k, l;
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
			finalsum += M3[i][j];
		}
	}
	const int kolvoporokov = thread::hardware_concurrency();
	vector<thread> potok;
	int zatrats = a / kolvoporokov;

	for (int t = 0; t < kolvoporokov; t++)
	{
		int start = t * zatrats;
		int end = (t == kolvoporokov - 1) ? a : start + zatrats;
		potok.emplace_back(Mnogoparametrov, M1, M2, M3, start, end, b, d);
	}
	for (auto& th : potok)
	{
		th.join();
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
	for (int i = 0; i < c; i++)
	{
		for (int j = 0; j < d; j++)
		{
			cout << setw(k) << M2[i][j];
		}
		cout << endl;
	}
	cout << "M3\n";
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < d; j++)
		{
			cout << setw(l) << M3[i][j];
		}
		cout << endl;
	}
	cout << "tyt po idee gg" << finalsum << endl;

	return 0;
}
