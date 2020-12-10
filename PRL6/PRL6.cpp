#include <iostream>
#include <cmath>
using namespace std;

const int N = 100000;
const int M = 50000;
const int numOfThreads = 4;

void initArray(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		arr[i] = i;
	}
}

double findFirstSum(int arr[]) {
	double partSum;
	double sum = 0;

	int numbOfThreadElement = ceil(N * 1.0 / numOfThreads);

	for (int i = 0; i < numOfThreads; i++) {
		partSum = 0;
		for (int j = i * numbOfThreadElement; j < (i + 1) * numbOfThreadElement; j++) {
			partSum += arr[j];
		}
		sum += partSum;
	}
	return sum;
}

int findSecondSum(int arr[]) {
	int activeSize = M;
	int lastSize = M;

	do {
		if (activeSize % 2 == 0) {
			activeSize /= 2;
		}
		else {
			activeSize = activeSize / 2 + 1;
		}

		for (int i = 0; i < activeSize; i++) {
			if (i != lastSize - i - 1) {
				arr[i] += arr[lastSize - i - 1];
				arr[lastSize - i - 1] = 0;
			}
		}
		lastSize = activeSize;
	} while (activeSize > 1);
	return arr[0];
}

int main()
{
	int arr[N];
	int arr2[M];
	
	initArray(arr, N);
	cout << "First sum is >> " << findFirstSum(arr) << endl;

	initArray(arr2, M);
	cout << "Second sum is >> " << findSecondSum(arr2) << endl;
}