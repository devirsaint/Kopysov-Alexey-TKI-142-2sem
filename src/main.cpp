#include "../include/ClassDoublyLinkedList.h"

#include <cstdlib>
#include <exception>
#include <iostream>
#include <string>

using namespace std;

/**
* @brief Считывает число типа int введённое с клавиатуры
* @return Число типа int
*/
int get_number();

/**
* @brief Считывает индекс элемента введённый с клавиатуры
* @return Индекс элемента
*/
size_t get_index();

/**
* @brief Область работы с линейным двусвязным списком
*/
void runDoublyLinkedList();

/**
* @brief Точка входа в программу
* @return 0 если программа выполнена корректно, иначе 1
*/
int main()
{
	system("chcp 65001 > nul");
	system("CLS");

	try
	{
		runDoublyLinkedList();
	}
	catch (const exception& error)
	{
		cerr << "Работа программы остановлена из-за ошибки: " << error.what() << endl;
		return 1;
	}

	return 0;
}

void ERROR(const string text)
{
	cerr << text << endl;
	exit(1);
}

int get_number()
{
	int number = 0;
	cin >> number;

	if (cin.fail())
	{
		ERROR("Ошибка ввода");
	}

	return number;
}

size_t get_index()
{
	int index = 0;
	cin >> index;

	if (cin.fail() || index < 0)
	{
		ERROR("Ошибка ввода индекса");
	}

	return static_cast<size_t>(index);
}

void runDoublyLinkedList()
{
	DoublyLinkedList<int> First;

	cout << "Введите количество элементов в списке: ";
	int count = get_number();

	if (count < 0)
	{
		ERROR("Ошибка ввода количества элементов");
	}

	for (int i = 0; i < count; i++)
	{
		cout << "Введите " << i + 1 << " элемент списка: ";
		First.push_back(get_number());
	}

	system("CLS");

	cout << "Список: " << First.toString() << endl;
	cout << "Размер списка: " << First.printSize() << endl;

	cout << endl << "Введите элемент для поиска: ";
	int searchElement = get_number();
	int searchIndex = First.find(searchElement);

	if (searchIndex == -1)
	{
		cout << "Элемент не найден" << endl;
	}
	else
	{
		cout << "Элемент найден под индексом: " << searchIndex << endl;
	}

	cout << endl << "Введите индекс, куда будет вставлен новый элемент: ";
	size_t insertIndex = get_index();
	cout << "Введите элемент для вставки: ";
	int insertElement = get_number();
	First.insert(insertIndex, insertElement);
	cout << "Список после вставки: " << First.toString() << endl;
	cout << "Размер списка: " << First.printSize() << endl;

	cout << endl << "Введите значение элемента, который нужно изменить: ";
	int oldElement = get_number();
	cout << "Введите новое значение элемента: ";
	int newElement = get_number();

	if (First.modify(oldElement, newElement))
	{
		cout << "Список после модификации: " << First.toString() << endl;
	}
	else
	{
		cout << "Элемент для модификации не найден" << endl;
	}

	cout << endl << "Введите индекс элемента, который нужно удалить: ";
	size_t removeIndex = get_index();
	First.remove(removeIndex);
	cout << "Список после удаления: " << First.toString() << endl;
	cout << "Размер списка: " << First.printSize() << endl;

	cout << endl << "Введите элемент, который будет добавлен оператором <<: ";
	int addedElement = get_number();
	First << addedElement;
	cout << "Список после оператора <<: " << First.toString() << endl;

	if (!First.empty())
	{
		int deletedElement = 0;
		First >> deletedElement;
		cout << "Удалённый оператором >> элемент: " << deletedElement << endl;
		cout << "Список после оператора >>: " << First.toString() << endl;
	}
}
