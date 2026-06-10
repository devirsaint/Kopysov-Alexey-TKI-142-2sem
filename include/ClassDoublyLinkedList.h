#pragma once

#include <initializer_list>
#include <list>
#include <sstream>
#include <stdexcept>
#include <string>

using namespace std;

/**
* @brief Класс линейный двусвязный список
*/
template<typename Type>
class DoublyLinkedList
{
private:
	/**
	* @brief Структура узла двусвязного списка
	*/
	struct Node
	{
		/**
		* @param value - значение узла списка
		*/
		Type value;

		/**
		* @param previous - указатель на предыдущий узел списка
		*/
		Node* previous;

		/**
		* @param next - указатель на следующий узел списка
		*/
		Node* next;

		/**
		* @brief Конструктор структуры по-умолчанию
		*/
		Node(void) : value(Type()), previous(nullptr), next(nullptr) {}

		/**
		* @brief Конструктор структуры по заданному значению
		* @param newValue - значение узла списка
		*/
		Node(const Type& newValue) : value(newValue), previous(nullptr), next(nullptr) {}
	};

	/**
	* @param head - указатель на первый узел списка
	*/
	Node* head;

	/**
	* @param tail - указатель на последний узел списка
	*/
	Node* tail;

	/**
	* @param count - размер списка
	*/
	size_t count;

	/**
	* @brief Выводит ошибку и завершает работу метода
	* @param text - текст ошибки
	*/
	void ERROR(const string text) const;

	/**
	* @brief Возвращает узел списка по индексу
	* @param index - индекс узла списка
	* @return Указатель на узел списка
	*/
	Node* getNode(const size_t index) const;

	/**
	* @brief Копирует данные из другого списка
	* @param other - другой список
	*/
	void copyFrom(const DoublyLinkedList& other);

public:
	/**
	* @brief Конструктор класса по-умолчанию, задаёт пустой список
	*/
	DoublyLinkedList(void);

	/**
	* @brief Конструктор класса, задаёт список по списку инициализации
	* @param other - список данных
	*/
	DoublyLinkedList(const initializer_list<Type> other);

	/**
	* @brief Конструктор класса, задаёт список по переданному списку данных
	* @param other - список данных
	*/
	DoublyLinkedList(const list<Type>& other);

	/**
	* @brief Конструктор класса, задаёт список по переданному списку
	* @param other - переданный список
	*/
	DoublyLinkedList(const DoublyLinkedList& other);

	/**
	* @brief Конструктор класса, задаёт список по ссылке на список
	* @param other - ссылка на переданный список
	*/
	DoublyLinkedList(DoublyLinkedList&& other) noexcept;

	/**
	* @brief Добавление элемента в конец списка
	* @param object - объект, добавляемый в список
	*/
	void push_back(const Type& object);

	/**
	* @brief Добавление элемента в начало списка
	* @param object - объект, добавляемый в список
	*/
	void push_front(const Type& object);

	/**
	* @brief Вставка элемента в список по индексу
	* @param index - индекс, куда будет вставлен элемент
	* @param object - объект, добавляемый в список
	*/
	void insert(const size_t index, const Type& object);

	/**
	* @brief Удаление первого элемента списка
	* @return Значение удалённого элемента
	*/
	Type pop_front();

	/**
	* @brief Удаление последнего элемента списка
	* @return Значение удалённого элемента
	*/
	Type pop_back();

	/**
	* @brief Удаление элемента списка по индексу
	* @param index - индекс удаляемого элемента
	*/
	void remove(const size_t index);

	/**
	* @brief Поиск элемента списка по значению
	* @param object - искомый объект
	* @return Индекс элемента или -1, если элемент не найден
	*/
	int find(const Type& object) const;

	/**
	* @brief Проверка наличия элемента в списке
	* @param object - искомый объект
	* @return true или false
	*/
	bool contains(const Type& object) const;

	/**
	* @brief Модификация элемента списка по значению
	* @param oldObject - старое значение элемента
	* @param newObject - новое значение элемента
	* @return true или false
	*/
	bool modify(const Type& oldObject, const Type& newObject);

	/**
	* @brief Проверка списка на пустоту
	* @return true или false
	*/
	bool empty() const;

	/**
	* @brief Очистка списка
	*/
	void clear();

	/**
	* @brief Вывод размера списка
	* @return Число - размер списка
	*/
	size_t printSize() const;

	/**
	* @brief Вывод данных списка
	* @return Указатель на первый узел списка
	*/
	const void* printData() const;

	/**
	* @brief Вывод списка в строку
	* @return Список, сериализованный в строку
	*/
	string toString() const;

	/**
	* @brief Оператор присваивания списка (копирование)
	* @param other - другой список
	* @return Список
	*/
	DoublyLinkedList& operator = (const DoublyLinkedList& other);

	/**
	* @brief Оператор присваивания списка (присваивание)
	* @param other - ссылка на другой список
	* @return Список
	*/
	DoublyLinkedList& operator = (DoublyLinkedList&& other) noexcept;

	/**
	* @brief Оператор сравнения списков
	* @param other - другой список
	* @return true или false
	*/
	bool operator == (const DoublyLinkedList& other) const;

	/**
	* @brief Оператор сравнения списков
	* @param other - другой список
	* @return true или false
	*/
	bool operator != (const DoublyLinkedList& other) const;

	/**
	* @brief Оператор, показывающий n-й элемент списка
	* @param index - индекс элемента, который будет показан
	* @return n-й элемент списка
	*/
	Type& operator [] (const size_t index);

	/**
	* @brief Оператор, показывающий n-й элемент списка
	* @param index - индекс элемента, который будет показан
	* @return n-й элемент списка
	*/
	const Type& operator [] (const size_t index) const;

	/**
	* @brief Оператор добавления элемента в конец списка
	* @param object - объект, добавляемый в список
	* @return Список
	*/
	DoublyLinkedList& operator << (const Type& object);

	/**
	* @brief Оператор удаления элемента из начала списка
	* @param object - объект, в который будет записан удалённый элемент
	* @return Список
	*/
	DoublyLinkedList& operator >> (Type& object);

	/**
	* @brief Деструктор класса по-умолчанию
	*/
	~DoublyLinkedList();
};

template<typename Type>
void DoublyLinkedList<Type>::ERROR(const string text) const
{
	throw runtime_error(text);
}

template<typename Type>
typename DoublyLinkedList<Type>::Node* DoublyLinkedList<Type>::getNode(const size_t index) const
{
	if (index >= count)
	{
		ERROR("Выход за границы списка");
	}

	Node* current = nullptr;

	if (index < count / 2)
	{
		current = head;
		for (size_t i = 0; i < index; i++)
		{
			current = current->next;
		}
	}
	else
	{
		current = tail;
		for (size_t i = count - 1; i > index; i--)
		{
			current = current->previous;
		}
	}

	return current;
}

template<typename Type>
void DoublyLinkedList<Type>::copyFrom(const DoublyLinkedList& other)
{
	Node* current = other.head;
	while (current != nullptr)
	{
		push_back(current->value);
		current = current->next;
	}
}

template<typename Type>
DoublyLinkedList<Type>::DoublyLinkedList(void) : head(nullptr), tail(nullptr), count(0) {}

template<typename Type>
DoublyLinkedList<Type>::DoublyLinkedList(const initializer_list<Type> other) : head(nullptr), tail(nullptr), count(0)
{
	for (const auto& value : other)
	{
		push_back(value);
	}
}

template<typename Type>
DoublyLinkedList<Type>::DoublyLinkedList(const list<Type>& other) : head(nullptr), tail(nullptr), count(0)
{
	for (const auto& value : other)
	{
		push_back(value);
	}
}

template<typename Type>
DoublyLinkedList<Type>::DoublyLinkedList(const DoublyLinkedList& other) : head(nullptr), tail(nullptr), count(0)
{
	copyFrom(other);
}

template<typename Type>
DoublyLinkedList<Type>::DoublyLinkedList(DoublyLinkedList&& other) noexcept : head(other.head), tail(other.tail), count(other.count)
{
	other.head = nullptr;
	other.tail = nullptr;
	other.count = 0;
}

template<typename Type>
void DoublyLinkedList<Type>::push_back(const Type& object)
{
	Node* node = new Node(object);

	if (count == 0)
	{
		head = node;
		tail = node;
	}
	else
	{
		node->previous = tail;
		tail->next = node;
		tail = node;
	}

	count++;
}

template<typename Type>
void DoublyLinkedList<Type>::push_front(const Type& object)
{
	Node* node = new Node(object);

	if (count == 0)
	{
		head = node;
		tail = node;
	}
	else
	{
		node->next = head;
		head->previous = node;
		head = node;
	}

	count++;
}

template<typename Type>
void DoublyLinkedList<Type>::insert(const size_t index, const Type& object)
{
	if (index > count)
	{
		ERROR("Выход за границы списка");
	}

	if (index == 0)
	{
		push_front(object);
		return;
	}

	if (index == count)
	{
		push_back(object);
		return;
	}

	Node* current = getNode(index);
	Node* node = new Node(object);

	node->previous = current->previous;
	node->next = current;
	current->previous->next = node;
	current->previous = node;

	count++;
}

template<typename Type>
Type DoublyLinkedList<Type>::pop_front()
{
	if (count == 0)
	{
		ERROR("Список пуст, удаление не выполнено");
	}

	Node* deleted = head;
	Type value = deleted->value;

	if (count == 1)
	{
		head = nullptr;
		tail = nullptr;
	}
	else
	{
		head = head->next;
		head->previous = nullptr;
	}

	delete deleted;
	count--;

	return value;
}

template<typename Type>
Type DoublyLinkedList<Type>::pop_back()
{
	if (count == 0)
	{
		ERROR("Список пуст, удаление не выполнено");
	}

	Node* deleted = tail;
	Type value = deleted->value;

	if (count == 1)
	{
		head = nullptr;
		tail = nullptr;
	}
	else
	{
		tail = tail->previous;
		tail->next = nullptr;
	}

	delete deleted;
	count--;

	return value;
}

template<typename Type>
void DoublyLinkedList<Type>::remove(const size_t index)
{
	if (index >= count)
	{
		ERROR("Выход за границы списка");
	}

	if (index == 0)
	{
		pop_front();
		return;
	}

	if (index == count - 1)
	{
		pop_back();
		return;
	}

	Node* deleted = getNode(index);

	deleted->previous->next = deleted->next;
	deleted->next->previous = deleted->previous;

	delete deleted;
	count--;
}

template<typename Type>
int DoublyLinkedList<Type>::find(const Type& object) const
{
	Node* current = head;
	int index = 0;

	while (current != nullptr)
	{
		if (current->value == object)
		{
			return index;
		}

		current = current->next;
		index++;
	}

	return -1;
}

template<typename Type>
bool DoublyLinkedList<Type>::contains(const Type& object) const
{
	return find(object) != -1;
}

template<typename Type>
bool DoublyLinkedList<Type>::modify(const Type& oldObject, const Type& newObject)
{
	Node* current = head;

	while (current != nullptr)
	{
		if (current->value == oldObject)
		{
			current->value = newObject;
			return true;
		}

		current = current->next;
	}

	return false;
}

template<typename Type>
bool DoublyLinkedList<Type>::empty() const
{
	return count == 0;
}

template<typename Type>
void DoublyLinkedList<Type>::clear()
{
	while (head != nullptr)
	{
		Node* deleted = head;
		head = head->next;
		delete deleted;
	}

	tail = nullptr;
	count = 0;
}

template<typename Type>
size_t DoublyLinkedList<Type>::printSize() const
{
	return count;
}

template<typename Type>
const void* DoublyLinkedList<Type>::printData() const
{
	return head;
}

template<typename Type>
string DoublyLinkedList<Type>::toString() const
{
	stringstream stream;
	stream << "{";

	Node* current = head;
	while (current != nullptr)
	{
		stream << current->value;

		if (current->next != nullptr)
		{
			stream << ", ";
		}

		current = current->next;
	}

	stream << "}";
	return stream.str();
}

template<typename Type>
DoublyLinkedList<Type>& DoublyLinkedList<Type>::operator = (const DoublyLinkedList& other)
{
	if (this != &other)
	{
		clear();
		copyFrom(other);
	}

	return *this;
}

template<typename Type>
DoublyLinkedList<Type>& DoublyLinkedList<Type>::operator = (DoublyLinkedList&& other) noexcept
{
	if (this != &other)
	{
		clear();

		head = other.head;
		tail = other.tail;
		count = other.count;

		other.head = nullptr;
		other.tail = nullptr;
		other.count = 0;
	}

	return *this;
}

template<typename Type>
bool DoublyLinkedList<Type>::operator == (const DoublyLinkedList& other) const
{
	if (count != other.count)
	{
		return false;
	}

	Node* first = head;
	Node* second = other.head;

	while (first != nullptr)
	{
		if (first->value != second->value)
		{
			return false;
		}

		first = first->next;
		second = second->next;
	}

	return true;
}

template<typename Type>
bool DoublyLinkedList<Type>::operator != (const DoublyLinkedList& other) const
{
	return !(*this == other);
}

template<typename Type>
Type& DoublyLinkedList<Type>::operator [] (const size_t index)
{
	return getNode(index)->value;
}

template<typename Type>
const Type& DoublyLinkedList<Type>::operator [] (const size_t index) const
{
	return getNode(index)->value;
}

template<typename Type>
DoublyLinkedList<Type>& DoublyLinkedList<Type>::operator << (const Type& object)
{
	push_back(object);
	return *this;
}

template<typename Type>
DoublyLinkedList<Type>& DoublyLinkedList<Type>::operator >> (Type& object)
{
	object = pop_front();
	return *this;
}

template<typename Type>
DoublyLinkedList<Type>::~DoublyLinkedList()
{
	clear();
}
