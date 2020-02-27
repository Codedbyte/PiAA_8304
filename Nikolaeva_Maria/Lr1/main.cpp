#include <iostream>
#include <Windows.h>

#include "TableTop.h"


bool isOptimalLength(int n);
void optimalSolution(int n);


int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

    std::cout << "������� ����� ������ �������� [2; 40]: ";
    int n = 0; //����� ������� ��������
	std::cin >> n;
	if (std::cin.bad()) {
		std::cout << "\n������ �����";
        exit(1);
	}
	if (n < 2 || n > 40) {
		std::cout << "\n������ �����";
        exit(1);
	}

    if (isOptimalLength(n)) { //���� ����� ���� ����� ����� - �������� ��������������� �������
		optimalSolution(n);
	}
	else { //����� - �������� ����� ���������������� ������� � ������������
		TableTop tableTop(n);
		tableTop.startBacktracking();
	}

	std::cout << std::endl;
	return 0;
}


bool isOptimalLength(int n) {
	if (n % 2 == 0 || n % 3 == 0 || n % 5 == 0) {
		return true;
	}
	return false;
}


void optimalSolution(int n) {
    if (n % 2 == 0) {
        std::cout << "\n����� ���������: 4\n"; //��������� 4 ���������� ��������
		std::cout << "1 1 " << n/2 << std::endl;
		std::cout << 1 + n/2 << " 1 " << n/2 << std::endl;
		std::cout << "1 " << 1 + n/2 << " " << n/2 << std::endl;
		std::cout << 1 + n/2 << " " << 1 + n/2 << " " << n/2 << std::endl;
	}
    else if (n % 3 == 0) {
        std::cout << "\n����� ���������: 6\n" << std::endl; // ��������� ������� �������� 2/3 �� ������� ��������� � 5 ��������� �������� 1/3
		std::cout << "1 1 " << 2 * n / 2 << std::endl;
		std::cout << 1 + 2 * n / 2 << " 1 " << n / 2 << std::endl;
		std::cout << "1 " << 1 + 2 * n / 2 << " " << n / 2 << std::endl;
		std::cout << 1 + 2 * n / 2 << " " << 1 + n / 2 << " " << n / 2 << std::endl;
		std::cout << 1 + n / 2 << " " << 1 + 2 * n / 2 << " " << n / 2 << std::endl;
		std::cout << 1 + 2 * n / 2 << " " << 1 + 2 * n / 2 << " " << n / 2 << std::endl;
	}
    else if (n % 5 == 0) {
        std::cout << "\n����� ���������: 8\n" << std::endl; // ��������� ������� �������� 3/5 �� ������� ���������, 3 �������� 2/5 � 4 �������� 1/5
		std::cout << "1 1 " << 3 * n / 5 << std::endl;
		std::cout << 1 + 3 * n / 5 << " 1 " << 2 * n / 5 << std::endl;
		std::cout << "1 " << 1 + 3 * n / 5 << " " << 2 * n / 5 << std::endl;
		std::cout << 1 + 3 * n / 5 << " " << 1 + 3 * n / 5 << " " << 2 * n / 5 << std::endl;
		std::cout << 1 + 2 * n / 5 << " " << 1 + 3 * n / 5 << " " << n / 5 << std::endl;
		std::cout << 1 + 2 * n / 5 << " " << 1 + 4 * n / 5 << " " << n / 5 << std::endl;
		std::cout << 1 + 3 * n / 5 << " " << 1 + 2 * n / 5 << " " << n / 5 << std::endl;
		std::cout << 1 + 4 * n / 5 << " " << 1 + 2 * n / 5 << " " << n / 5 << std::endl;
	}
}
