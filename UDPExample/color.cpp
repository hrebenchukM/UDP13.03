//#include <iostream>
//#include<Windows.h>
//using namespace std;
//
//int main()
//{
//
//	//COORD point{ 0,0 };// Координата точки
//	//HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE); // получаем адрес собственного окна
//
//	//for (int i = 0; i < 10; i++)
//	//{
//	//	SetConsoleCursorPosition(h, point); // установка курсора в указанную позицию!
//	//    SetConsoleTextAttribute(h, 1); // изменение цвета шрифта
//	//	for (int j = 0; j < 30; j++)
//	//	{
//	//		if (i < 5)
//	//		{
//	//			SetConsoleTextAttribute(h, 1); // изменение цвета шрифта
//	//		}
//	//		else
//	//		{
//	//			SetConsoleTextAttribute(h, 6); // изменение цвета шрифта
//	//		}
//	//		cout << "#";
//	//	}
//	//	point.Y += 1;
//	//}
// //   // Возвращение стандартного цвета
//	//SetConsoleTextAttribute(h, 7); // стандартный цвет
//
//
//	COORD point{ 0,0 };// Координата точки
//	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE); // получаем адрес собственного окна
//
//
//	SetConsoleCursorPosition(h, point); // установка курсора в указанную позицию!
//	SetConsoleTextAttribute(h, 12); // изменение цвета шрифта
//	cout << "Hello world";    //вывод текста в указанной позиции
//
//	// замена координат точки
//	//point.Y += 1; // строки
//	point.X += 12;  // столбцы! 
//	SetConsoleCursorPosition(h, point); /// установка курсора в указанную позицию!
//	SetConsoleTextAttribute(h, 14);  // изменение цвета шрифта
//	cout << "Hello world";    //вывод текста в указанной позиции
//
//	point.Y += 1;  // переход на новую строку!
//	point.X = 0; // начало строки
//	SetConsoleCursorPosition(h, point);
//	SetConsoleTextAttribute(h, 11);
//	cout << "Hello world\n";
//
//	SetConsoleTextAttribute(h, 7); // стандарный цвет!
//
//}