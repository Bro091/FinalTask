#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <fstream>


// ����������� �� ����������, ������ 165 �� ��������
/*++N - ���������� ��� ��������� ����������, � �� ����� ��� N++ ���������� ����� �� ��� ���������, �� ��� ���� ��� ����� ������ ����������
int& postinc(int& var) {
	int tmp = var; // 10
	var = var + 1; // 11
	return tmp;    // 10
}
int& postinc(int& var) {
	var = var + 1; // 11
	return var;    // 11
}*/


//���������� ������� ���������� �������
template <typename T>
void fill_arr(T arr[], const int length, int left, int right) {
	srand(time(NULL));
	for (int i = 0; i < length; i++)
		arr[i] = rand() % (right - left) + left;
}
//����� ������� � �������
template <typename T>
void print_arr(T arr[], const int length) {
	std::cout << '[';
	for (int i = 0; i < length; i++)
		std::cout << arr[i] << ", ";
	std::cout << "\b\b]\n";
}

//����������� ��������� �� ��������� ������
template <typename T> 
void memory_mx(T**& pointer, int rows, int cols) {
	pointer = new T * [rows];
	for (int i = 0; i < rows; i++)
		pointer[i] = new T[cols]{}; // {} - ���������� ������� ������
}

// ������������ �������, ���������� ��� �������� ������������ ������
template <typename T>
void clear_mx(T**& pointer, int rows) {
	for (int i = 0; i < rows; i++)
		delete[] pointer[i];
	delete[] pointer;
	pointer = nullptr;
}

template <typename T>
T* positive(T arr1[], const int length1, T arr2[], const int length2, int& var ) {
	T* tmp = new T[length1 + length2];
	var = 0;
	for (int i = 0; i < length1; i++)
		if (arr1[i] > 0) 
			tmp[var++] = arr1[i];
	for (int i = 0; i < length2; i++)
		if (arr2[i] > 0)
			tmp[var++] = arr2[i];

	T* result = new T[var];
	for (int i = 0; i < var; i++)
		result[i] = tmp[i];

	delete[] tmp;
	return result; 

}

bool number_name(int num, std::string file_path);



int main() {
	setlocale(LC_ALL, "Ru");
	int n, m;


	//������ 1. ��������� ������������ ������
	/*std::cout << "������ 1. \n������� ������ ������� -> ";
	std::cin >> n;
	std::cout << "������� ������ ������� -> ";
	std::cin >> m;
	int** mx = nullptr; // nullptr - ����������� ������� ������

	memory_mx(mx, n, m);

	std::cout << "�������� ������:\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			std::cout << mx[i][j] << '\t';
		std::cout << std::endl;
	}

	clear_mx(mx, n);
	std::cout << '\n';*/


	// ������ 2. ������ ������������� ���������
	/*std::cout << "������ 2. \n������ ������:\n";
	const int size1 = 7, size2 = 6;
	int arr1[size1], arr2[size2];
	fill_arr(arr1, size1, -10, 15);
	fill_arr(arr2, size2, -15, 10);
	print_arr(arr1, size1);
	std::cout << "������ ������:\n";
	print_arr(arr2, size2);

	int size3;
	int* arr3 = positive(arr1, size1, arr2, size2, size3);

	std::cout << "�������� ������:\n";
	print_arr(arr3, size3);

	delete[] arr3;*/

	//������ 3. 
	std::cout << "������ 3.\n������� ���������� ����� -> ";
	std::cin >> n;
	if (number_name(n, "namber.txt"))
		std::cout << "����� �������� � ����\n\n";
	else
		std::cout << "������ ���������� �������.\n\n";
	
	

	return 0;
}

bool number_name(int num, std::string file_path)
{
	if (num < 10 || num > 99)
		return false;
	static const char* tens[]
	{
		 "��������", "��������",
		"�����", "���������", "����������",
		"���������", "�����������", "���������"
	};
	static const char* ones[]
	{
		" "," ����", " ���", " ���",
		" ������", " ����", " �����",
		" ����", " ������", " ������"
	};
	static const char* exceps[]                   // exceps - ����������
	{
		"������",
		"����������",
		"����������",
		"����������",
		"�������������",
		"����������",
		"�����������",
		"����������",
		"������������",
		"������������"
	};
	int num1 = num / 10; // ������ �����
	int num2 = num % 10; // ������ �����


	std::ofstream file; // ����������� �����
	file.open(file_path); //�������� �����
	if (num1 == 1)
	{
		file << exceps[num2] << '\n'; // ������ � ����
		file.close();  //������� �����
		return true;
	}
	file << tens[num1 - 2] << ones[num2]; // �������� 2, ������ ��� �� �� ��������� 0 � ����� ��� �� ������ ������� �������, ��� ��� �� ��������� ��� if (num1 == 1)
	file.close();
	return true;
}