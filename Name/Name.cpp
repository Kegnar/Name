//Написать класс Name с полями класса имя и фамилия(динамические).
//Прописать приватный метод очистки имени и фамилии.Добавить перегрузку оператора присваивания.
//конструкторы и деструкторы на свое усмотрение(но они должны быть)
//https://github.com/Kebbot/BW425-OOP - пробный код есть в репозитории

#include <Windows.h>
#include <iostream>

using namespace std;

class Name
{
	char* name;
	char* surname;
	void clearName() const
	{
		for (int i = 0; i < strlen(name + 1); i++)
		{
			name[i] = NULL;
		}
		for (int i = 0; i < strlen(surname + 1); i++)
		{
			surname[i] = NULL;
		}
	}
public:
	Name(const char* name_p, const char* surname_p)
	{
		if (name_p)
		{
			name = new char[strlen(name_p) + 1] {};
			strcpy_s(name, strlen(name_p) + 1, name_p);
		}
		if (surname_p)
		{
			surname = new char[strlen(surname_p) + 1] {};
			strcpy_s(surname, strlen(surname_p) + 1, surname_p);
		}
	}
	Name() :Name(nullptr, nullptr) {}
	Name& operator=(const Name& name_p)
	{
		if (&name_p != this)
		{
			if (name_p.name)
			{
				this->name = new char[strlen(name_p.name) + 1] {};
				strcpy_s(this->name, strlen(name_p.name) + 1, name_p.name);
			}
			if (name_p.surname)
			{
				this->surname = new char[strlen(name_p.surname) + 1] {};
				strcpy_s(this->surname, strlen(name_p.surname) + 1, name_p.surname);
			}
		}
		return *this;
	}
	Name(const Name& name_p)
	{
		if (&name_p != this)
		{
			if (name_p.name)
			{
				this->name = new char[strlen(name_p.name) + 1] {};
				strcpy_s(this->name, strlen(name_p.name) + 1, name_p.name);
			}
			if (name_p.surname)
			{
				this->surname = new char[strlen(name_p.surname) + 1] {};
				strcpy_s(this->surname, strlen(name_p.surname) + 1, name_p.surname);
			}
		}
	}
	~Name()
	{
		delete[]surname;
		delete[]name;
	}
	char* getName()const
	{
		return name;
	}
	char* getSurname()const
	{
		return surname;
	}
	Name& setName(char* name_p)
	{
		this->name = name_p;
		return *this;
	}
	Name& setSurname(char* surname_p)
	{
		this->surname = surname_p;
		return *this;
	}
	void clear()
	{
		clearName();
		cout << "Данные очищены";
	}
};
ostream& operator <<(ostream& os, const Name& name_p)
{
	os << name_p.getName() << ' ' << name_p.getSurname();
	return os;
}


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Name name1{ "Петя","Иванов" };
	cout << "Имя: " << name1 << '\n';
	Name name2;
	name2 = name1;
	cout << "Работает очистка имени\n";
	name1.clear();
	cout << "\nПовторный вывод\n";
	cout << name1 << '\n';
	cout << "Работа оператора копирования: " << name2 << '\n';
}
