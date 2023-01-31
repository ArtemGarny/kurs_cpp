#include <iostream>
#include <windows.h>
#include <cstring>
#include <fstream>
#include <cctype>

using namespace std;

//непосредственно структура    
struct znak
{
public:
	string name;
	string surname;
	string znakz;
	int birthday;
	int birthmonth;
	int birthyear;
	string pol;


	//функция для ввода нового человека в массив структур	
	void input()
	{

		cout << "Введите имя: ";
		cin >> name;
		cout << "Введите фамилию: ";
		cin >> surname;
		cout << "Введите знак зодиака: ";
		cin >> znakz;
		cout << "Введите дату рождения(через пробел: 1 1 1995): ";
		cin >> birthday >> birthmonth >> birthyear;
		cout << "Введите пол : ";
		cin >> pol;
	}

	//функция для вывода данных структуры на экран	
	void print()
	{
		cout << "Имя: " << name << endl;
		cout << "Фамилия: " << surname << endl;
		cout << "Знак зодиака: " << znakz << endl;
		cout << "Дата рождения:" << birthday << "." << birthmonth << "." << birthyear << endl;
		cout << "Пол: " << pol << endl << endl << endl;
	}

};

static string Lower(string str)
{
	
	
	for (int i=0;i<str.size();i++)
	{
		str[i] = tolower(str[i]);
	}

	return str;
};


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);


	setlocale(LC_ALL, "russian");

	
	znak people[100];

	int i = 0, counter, choice = 0;
	string sur,zodiak,month;
	
	//считывание структур из файла
	ifstream file ;
	file.open("database.txt");
	
	while (!file.eof())
	{
		file >> people[i].name;
		file >> people[i].surname;
		file >> people[i].znakz;
		file >> people[i].birthday;
		file >> people[i].birthmonth;
		file >> people[i].birthyear;
		file >> people[i].pol;

		i++;
	}

	file.close();
	i--;
	

	
	while (true)
	{
		cout << "Что хотите сделать?" << endl;
		cout << "1.Вывести информацию о человеке по фамилии." << endl;
		cout << "2.Вывод людей по знаку зодиака." << endl;
		cout << "3.Вывод людей по введённому месяцу." << endl;
		cout << "4.Записать нового человека." << endl;
		cout << "5.Вывести все структуры на экран." << endl;
		cout << "6.Удалить человека по фамилии." << endl;
		cout << "7.Редактировать данные о человеке по фамилии." << endl;
		cout << "Для выхода нажмите 0." << endl;

		//сортировка
		if (choice == 4 || choice == 0)
		{
			for (int k = 0; k < i; k++)
				for (int l = 0; l < i; l++)
					if (people[k].surname < people[l].surname)
					{
						swap(people[k], people[l]);
					}
		}

		cin >> choice;

		//вывод всего массива структур на экран с помощью метода print
		if (choice == 5)
		{
			system("cls");
			cout << "Вывод всех структур на экран." << endl << endl;
			for (int c = 0; c < i; c++)
			{
				cout << c + 1 << ".";
				people[c].print();
			}
			system("pause");
			system("cls");
		}

		//ввод новой структуры в массив структур с помощью метода input
		else if (choice == 4)
		{
			system("cls");
			cout << "Ввод нового человека." << endl << endl;
			cout << "Введите данные нового человека: " << endl << endl;
			people[i].input();

			system("pause");
			system("cls");

			i++;
		}

		//запись всех структур в файл и завершение работы
		else if (choice == 0)
		{
			system("cls");
			cout << "Производится запись структур в файл и завершеение работы приложения." << endl << endl;
			ofstream file;
			file.open("database.txt");
			for (int c = 0; c < i; c++)
			{
				file << people[c].name << endl;
				file << people[c].surname << endl;
				file << people[c].znakz << endl;
				file << people[c].birthday << " " << people[c].birthmonth << " " << people[c].birthyear << endl;
				file << people[c].pol << endl;
				file << endl;
			}
			file.close();
			cout << "Данные успешно сохранены. До новых встреч.";
			break;
		}

		//поиск структур по фамилии
		else if (choice == 1)
		{
			system("cls");
			cout << "Поиск людей по фамилии." << endl << endl;
			cout << "Введите фамилию, по которой хотите выполнить поиск: ";
			cin >> sur;
			
			cout << endl;
			counter = 0;
			for (int c = 0; c < 100; c++)
			{
				if (Lower(sur) == Lower(people[c].surname))
				{
					people[c].print();
				}
				else
				{
					counter++;
				}
			}
			if (counter == 100)
			{
				cout << "В структуре нет человека с такой фамилией." << endl << endl;
			}
			system("pause");
			system("cls");
		}

		//поиск структур по знаку зодиака
		else if (choice == 2)
		{
			system("cls");
			cout << "Поиск людей по знаку зодиака." << endl << endl;
			
			cout << "Введите знак зодиака, по которому хотите выполнить поиск: ";
			cin >> zodiak;
			cout << endl;
			counter = 0;
			for (int c = 0; c < 100; c++)
			{
				if (Lower(zodiak) == Lower(people[c].znakz))
				{
					people[c].print();
				}
				else
				{
					counter++;
				}
			}
			if (counter == 100)
			{
				cout << "В структуре нет человека с таким знаком зодиака." << endl << endl;
			}
			system("pause");
			system("cls");
		}

		//поиск структур по месяцу рождения
		else if (choice == 3)
		{
			system("cls");
			cout << "Поиск людей по месяцу рождения." << endl << endl;
			
			cout << "Введите месяц, по которому хотите выполнить поиск: ";
			cin >> month;
			month = Lower(month);
			cout << endl;
			counter = 0;
			for (int c = 0; c < 100; c++)
			{
				if (Lower(month)=="январь" && people[c].birthmonth == 1)
				{
					people[c].print();
				}
				else if (Lower(month) == "февраль" && people[c].birthmonth == 2)
				{
					people[c].print();
				}
				else if (Lower(month) == "март" && people[c].birthmonth == 3)
				{
					people[c].print();
				}
				else if (Lower(month) == "апрель" && people[c].birthmonth == 4)
				{
					people[c].print();
				}
				else if (Lower(month) == "май" && people[c].birthmonth == 5)
				{
					people[c].print();
				}
				else if (Lower(month) == "июнь" && people[c].birthmonth == 6)
				{
					people[c].print();
				}
				else if (Lower(month) == "июль" && people[c].birthmonth == 7)
				{
					people[c].print();
				}
				else if (Lower(month) == "август" && people[c].birthmonth == 8)
				{
					people[c].print();
				}
				else if (Lower(month) == "сентябрь" && people[c].birthmonth == 9)
				{
					people[c].print();
				}
				else if (Lower(month) == "октябрь" && people[c].birthmonth == 10)
				{
					people[c].print();
				}
				else if (Lower(month) == "ноябрь" && people[c].birthmonth == 11)
				{
					people[c].print();
				}
				else if (Lower(month) == "декабрь" && people[c].birthmonth == 12)
				{
					people[c].print();
				}
				else { counter++; }

			}
			if (counter == 100)
			{
				cout << "В структуре нет человека родившегося в этот месяц." << endl << endl;
			}
			system("pause");
			system("cls");
		}

		else if (choice == 6)
		{
			counter = 0;
			system("cls");
			cout << "Удаление человека по фамилии." << endl << endl;
			cout << "Введите фамилию человека, которого хотите удалить: ";
			cin >> sur;
			
			for (int c = 0; c < 100; c++)
			{
				if (Lower(sur) == Lower(people[c].surname))
				{
					people[c].print();
					for (int k = c; k < i; k++)
					{
						people[k] = people[k + 1];
					}
				}
				else { counter++; }
			}
			if (counter == 100)
			{
				cout << endl << "В структуре нет такого человека." << endl << endl;
			}
			else
			{
				cout << endl << "Удаление прошло успешно." << endl << endl;
				i--;
			}
			system("pause");
			system("cls");
		}

		else if (choice == 7)
		{
			counter = 0;
			system("cls");
			cout << "Редактирование данных по фамилии." << endl << endl;
			cout << "Введите фамилию человека, которого хотите редактировать: ";
			cin >> sur;
			
			cout << endl;
			for (int c = 0; c < 100; c++)
			{
				if ( Lower(sur) == Lower(people[c].surname) )
				{
					cout << "Найдено совпадение. Начинайте редактирование" << endl;
					people[c].print();
					people[c].input();
				}
				else { counter++; }
			}
			if (counter == 100)
			{
				cout << endl << "В структуре нет такого человека." << endl << endl;
			}
			else
			{
				cout << endl << "Редактирование прошло успешно." << endl << endl;
			}
			system("pause");
			system("cls");
		}
	}

	return 0;
}

