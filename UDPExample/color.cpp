//#include <iostream>
//#include<Windows.h>
//using namespace std;
//
//int main()
//{
//
//	//COORD point{ 0,0 };// ���������� �����
//	//HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE); // �������� ����� ������������ ����
//
//	//for (int i = 0; i < 10; i++)
//	//{
//	//	SetConsoleCursorPosition(h, point); // ��������� ������� � ��������� �������!
//	//    SetConsoleTextAttribute(h, 1); // ��������� ����� ������
//	//	for (int j = 0; j < 30; j++)
//	//	{
//	//		if (i < 5)
//	//		{
//	//			SetConsoleTextAttribute(h, 1); // ��������� ����� ������
//	//		}
//	//		else
//	//		{
//	//			SetConsoleTextAttribute(h, 6); // ��������� ����� ������
//	//		}
//	//		cout << "#";
//	//	}
//	//	point.Y += 1;
//	//}
// //   // ����������� ������������ �����
//	//SetConsoleTextAttribute(h, 7); // ����������� ����
//
//
//	COORD point{ 0,0 };// ���������� �����
//	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE); // �������� ����� ������������ ����
//
//
//	SetConsoleCursorPosition(h, point); // ��������� ������� � ��������� �������!
//	SetConsoleTextAttribute(h, 12); // ��������� ����� ������
//	cout << "Hello world";    //����� ������ � ��������� �������
//
//	// ������ ��������� �����
//	//point.Y += 1; // ������
//	point.X += 12;  // �������! 
//	SetConsoleCursorPosition(h, point); /// ��������� ������� � ��������� �������!
//	SetConsoleTextAttribute(h, 14);  // ��������� ����� ������
//	cout << "Hello world";    //����� ������ � ��������� �������
//
//	point.Y += 1;  // ������� �� ����� ������!
//	point.X = 0; // ������ ������
//	SetConsoleCursorPosition(h, point);
//	SetConsoleTextAttribute(h, 11);
//	cout << "Hello world\n";
//
//	SetConsoleTextAttribute(h, 7); // ���������� ����!
//
//}