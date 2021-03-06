// Генератор метатегов.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <conio.h>
#include <excpt.h>
#include <Windows.h>
#include <cstdlib>

using namespace std;

int main(int argc, char* argv[])
{
	system("color F");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);	
	ofstream fout("Генератор.txt"); // создаём объект класса ofstream для записи и связываем его с файлом Генератор.txt
	string title = "<title>";
	string descriptionBegin = "<meta name=\"description\" content=\"";
	string end = "\"/>";
	string keywords = "<meta name=\"keywords\" content=\"";
	string viewport = "<meta name=\"viewport\" content=\"width = device - width, initial - scale = 1\" />";
	string encoding = "<meta charset=\"";	
	string cssLink = "<link rel=\"stylesheet\" type=\"text / css\" href=\"";
	string linkJQ = "<script src = \"https://code.jquery.com/jquery-3.3.1.js\" integrity = \"sha256-2Kok7MbOyxpgUVvAk/HJ2jigOSYS2auK4Pfzbm7uH60=\" crossorigin = \"anonymous\">< / script>";
	string linkJs = "<script src=\"";
	string robot = "<meta name=\"robots\" content=\"";
	string buffer;
	char action;

	fout << viewport << endl;
	do{
		system("color F");
	cout << "\nВыберите действие: ";
	cin >> action;
		switch (action) {
		case '1':
			system("color F");
			cout << "\nВведите заголовок страницы: ";
			cin.ignore();
			getline(cin, buffer);
			fout << title << buffer << title << endl; //Записываем полученное значение в текстовый файл
			break;
		case '2':
			system("color F");
			cout << "\nСоставьте описание страницы: ";
			cin.ignore();
			getline(cin, buffer);
			fout << descriptionBegin << buffer << end << endl;
			break;
		case '3':	
			system("color F");
			cout << "\nВведите ключевые слова (не более 4-5, неповторяющихся слов): ";
			cin.ignore();
			getline(cin, buffer);
			fout << keywords << buffer << end << endl;
			break;
		case '4':
			system("color F");
			cout << "\nВведите кодировку (для коррекстного отбражения кириллицы рекомендуется использовать utf-8): ";
			cin.ignore();
			getline(cin, buffer);
			fout << encoding << buffer << end << endl;
			break;
		case '5':
			system("color F");
			cout << "\nВведите расположение файла css: ";
			cin.ignore();
			getline(cin, buffer);
			fout << cssLink << buffer << "\">" << endl;
			break;
		case '6':
			system("color F");
			cout << "\nJQuery успешно подключен" << endl;
				fout << linkJQ << endl;
				break;
		case '7': 
			cout << "\nВведите расположение файла js: ";
				cin.ignore();
			getline(cin, buffer);
			fout << cssLink << buffer << "\">< / script>" << endl;
			break;
		case '8':
			cout << "Индексация страницы: "<< endl<< "—index (или noindex) — разрешена (запрещена) индексация страницы;"<<endl<<
				"—follow(или nofollow) — разрешена(запрещена) индексация ссылок;"<<endl<<
				 "—all — аналог одновременного использования index и follow;" << endl <<
			"—none — аналог одновременного использования noindex и nofollow;" << endl <<
			"—noarchive — в результатах поиска не будет выводиться ссылка на сохраненную в кэше копию."<<endl;
			cin.ignore();
			getline(cin, buffer);
			fout << robot << buffer << end << endl;
			break;
		case '0':
			return 0;
			break;
		default: 
			system("cls");
			system("color c");
			cout << "\n Неизвестная команда";
		}
	} while (action != 'exit');
	fout.close(); // закрываем файл
	_getch();
	return 0;
}
