#include <iostream>
#include <cmath>
using namespace std;

const int N = 100000;
const int M = 50000;

int main()
{
	const int numOfThreads = 4;
	int arr[N];
	int arr2[M];
	double partSum;
	double sum = 0;

	for (int i = 0; i < N; i++) {
		arr[i] = i;
	}

	int numbOfThreadElement = ceil(N * 1.0 / numOfThreads);

	for (int i = 0; i < numOfThreads; i++) {
		partSum = 0;
		for (int j = i * numbOfThreadElement; j < (i + 1) * numbOfThreadElement; j++) {
			partSum += arr[j];
		}
		sum += partSum;
	}
	cout << "First sum is >> " << sum << endl;

	int activeSize = M;
	int lastSize = M;

	for (int i = 0; i < M; i++) {
		arr2[i] = i;
	}

	do {
		if (activeSize % 2 == 0) {
			activeSize /= 2;
		}
		else {
			activeSize = activeSize / 2 + 1;
		}

		for (int i = 0; i < activeSize; i++) {
			if (i != lastSize - i - 1) {
				arr2[i] += arr2[lastSize - i - 1];
				arr2[lastSize - i - 1] = 0;
			}
		}
		lastSize = activeSize;
	} while (activeSize > 1);
	cout << "Second sum is >> " << arr2[0] << endl;
}