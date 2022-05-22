#include <Windows.h> 
#include <iostream> 
#include <time.h> 
using namespace std;


void outputMatrix(int** matrix, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}
void iterationTransope(int** matrix, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = i; j < size; j++) {

			swap(matrix[i][j], matrix[j][i]);
		}
	}

}


void iterationTranspose(int** matrix, int size, int i = 0, int j = 0) {
	if (j == size) {
		i++;
		j = i;
	}
	if (i == size) {
		cout << endl;
		return;
	}

	swap(matrix[i][j], matrix[j][i]);
	j++;
	iterationTranspose(matrix, size, i, j);
}


int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));
	int** matrix;
	int size;
	cout << "Введіть розмір квадратної матриці: "; cin >> size;
	matrix = new int* [size];
	for (int i = 0; i < size; i++) {
		matrix[i] = new int[size];
		for (int j = 0; j < size; j++) {
			matrix[i][j] = rand() % 11;
		}
	}
	outputMatrix(matrix, size);
	iterationTranspose(matrix, size);
	outputMatrix(matrix, size);

	for (int i = 0; i < size; i++)
		delete[] matrix[i];
	delete[] matrix;
	return 0;

}