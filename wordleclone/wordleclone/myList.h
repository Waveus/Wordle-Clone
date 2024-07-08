#pragma once
#include <iterator>
#include <memory>
#include <initializer_list>
#include <iostream>

namespace lN
{
	template <typename D>
	struct listNode
	{
	public:

	std::shared_ptr<listNode<D>> nextListElement;
	std::shared_ptr<listNode<D>> previousListElement;
	D value;
	};
}

template<typename T>
class myList
{
private:
	std::shared_ptr<lN::listNode<T>> HEAD;
	std::shared_ptr<lN::listNode<T>> TAIL;
	size_t sizeValue;
public:

	myList() : HEAD(nullptr), TAIL(nullptr), sizeValue(0) {}; //default
	
	myList(myList& other) : HEAD(nullptr), TAIL(nullptr), sizeValue(0) {
		std::shared_ptr<lN::listNode<T>> BUF;

		BUF = other.HEAD;

		while (BUF != other.TAIL)
		{
			push_back(BUF->value);
			BUF = BUF->nextListElement;
		}
		if (BUF != nullptr)
		{
			push_back(BUF->value);
		}

	};

	myList(myList&& other) : HEAD(std::move(other.HEAD)), TAIL(std::move(other.TAIL)), sizeValue(std::move(other.sizeValue)) {

		other.HEAD = nullptr;
		other.TAIL = nullptr;
		other.sizeValue = 0;
	};

	myList(std::initializer_list<T> objectsToLoadToList) : HEAD(nullptr), TAIL(nullptr), sizeValue(0)
	{
		HEAD = nullptr;
		TAIL = nullptr;

		for (const T& oneObjectToLoad : objectsToLoadToList)
		{
			push_back(oneObjectToLoad);
		}
	};

	~myList()
	{
		if (sizeValue != 0)
		{
			while (HEAD != TAIL)
			{
				std::shared_ptr<lN::listNode<T>> BUF = HEAD->nextListElement;
				HEAD->nextListElement = nullptr;
				HEAD = BUF;
				HEAD->previousListElement = nullptr;
				sizeValue--;
			}
			sizeValue--;
			HEAD = nullptr;
			TAIL = nullptr;
		}
		else
		{

		}
	}

	T& operator[] (size_t index)
	{
		if (index < 0 || index >= sizeValue)
		{
			throw std::out_of_range("Index out of range");
		}
		std::shared_ptr<lN::listNode<T>> BUF = HEAD;

		for (size_t i = 0; i < index; i++)
		{
			BUF = BUF->nextListElement;
		}

		return BUF->value;
	}

	myList& operator=(myList& other)
	{
		if (this != &other)
		{
		
			clear();
			std::shared_ptr<lN::listNode<T>> BUF;
			BUF = other.HEAD;

			while (BUF != other.TAIL)
			{
				push_back(BUF->value);
				BUF = BUF->nextListElement;
			}
			if (BUF != nullptr)
			{
				push_back(BUF->value);
			}
		}
		return *this;
	};

	myList& operator=(myList&& other)
	{
		if (this != &other)
		{

			clear();
			std::shared_ptr<lN::listNode<T>> BUF;
	
			HEAD = other.HEAD;
			TAIL = other.TAIL;

			other.HEAD = nullptr;
			other.TAIL = nullptr;
			other.sizeValue = 0;

		}
		return *this;
	};

	struct Iterator
	{
		using iterator_category = std::forward_iterator_tag;
		using difference_type = std::ptrdiff_t;
		using value_type = T;
		using pointer = std::shared_ptr<lN::listNode<T>>;
		using reference = T&;

		Iterator(std::shared_ptr<lN::listNode<T>> ptr) : m_ptr(ptr) {}

		reference operator*() const { return m_ptr->value; }
		pointer operator->() { return &m_ptr->value; }

		Iterator& operator++() { m_ptr = m_ptr->nextListElement; return *this; }

		Iterator operator++(int) { Iterator tmp = *this; ++(*this); return tmp; }

		friend bool operator== (const Iterator& a, const Iterator& b) { return a.m_ptr == b.m_ptr; };
		friend bool operator!= (const Iterator& a, const Iterator& b) { return a.m_ptr != b.m_ptr; };

	private:
		pointer m_ptr;
	};

	Iterator begin() { return Iterator(HEAD); }
	Iterator end() {
		if (TAIL != nullptr) { return Iterator(TAIL->nextListElement); }
		else
		{
			return Iterator(nullptr);;
		}
	}

	void push_front(const T& objectToPushFront)
	{

		if (TAIL == nullptr)
		{
			HEAD = std::make_shared<lN::listNode<T>>();
			HEAD->value = objectToPushFront;
			TAIL = HEAD;
		}
		else if (TAIL == HEAD && TAIL != nullptr)
		{
			std::shared_ptr<lN::listNode<T>> BUF = std::make_shared<lN::listNode<T>>();
			BUF->value = objectToPushFront;
			BUF->nextListElement = HEAD;
			HEAD->previousListElement = BUF;
			HEAD = BUF;
			TAIL->previousListElement = HEAD;
		}
		else
		{
			std::shared_ptr<lN::listNode<T>> BUF = std::make_shared<lN::listNode<T>>();
			BUF->value = objectToPushFront;
			BUF->nextListElement = HEAD;
			HEAD->previousListElement = BUF;
			HEAD = BUF;
		}
		sizeValue++;
	}
	
	void push_back(const T& objectToPushBack)
	{

		if (TAIL == nullptr)
		{
			HEAD = std::make_shared<lN::listNode<T>>();
			HEAD->value = objectToPushBack;
			TAIL = HEAD;
		}
		else if (TAIL == HEAD && TAIL != nullptr)
		{
			std::shared_ptr<lN::listNode<T>> BUF = std::make_shared<lN::listNode<T>>();
			BUF->value = objectToPushBack;
			BUF->previousListElement = TAIL;
			TAIL->nextListElement = BUF;
			TAIL = BUF;
			HEAD->previousListElement = TAIL;
		}
		else
		{
			std::shared_ptr<lN::listNode<T>> BUF = std::make_shared<lN::listNode<T>>();
			BUF->value = objectToPushBack;
			BUF->previousListElement = TAIL;
			TAIL->nextListElement = BUF;
			TAIL = BUF;
		}
		sizeValue++;
	}
	
	void push_back(T& objectToPushBack)
	{

		if (TAIL == nullptr)
		{
			HEAD = std::make_shared<lN::listNode<T>>();
			HEAD->value = objectToPushBack;
			TAIL = HEAD;
		}
		else if (TAIL == HEAD && TAIL != nullptr)
		{
			std::shared_ptr<lN::listNode<T>> BUF = std::make_shared<lN::listNode<T>>();
			BUF->value = objectToPushBack;
			BUF->previousListElement = TAIL;
			TAIL->nextListElement = BUF;
			TAIL = BUF;
			HEAD->previousListElement = TAIL;
		}
		else
		{
			std::shared_ptr<lN::listNode<T>> BUF = std::make_shared<lN::listNode<T>>();
			BUF->value = objectToPushBack;
			BUF->previousListElement = TAIL;
			TAIL->nextListElement = BUF;
			TAIL = BUF;
		}
		sizeValue++;
	}


	void show()
	{
		std::shared_ptr<lN::listNode<T>> BUF = HEAD;
		while (BUF != nullptr)
		{
			BUF = BUF->nextListElement;
		}
	}

	void pop_back()
	{
		if (sizeValue != 1)
		{
			sizeValue--;
			std::shared_ptr<lN::listNode<T>> BUF = TAIL->previousListElement;
			TAIL->previousListElement = nullptr;
			TAIL = BUF;
			TAIL->nextListElement = nullptr;
			
		}
		else 
		{
		sizeValue--;
		HEAD = nullptr;
		TAIL = nullptr;
		}
	}

	void pop_front()
	{
		if (sizeValue != 1)
		{
			sizeValue--;
			std::shared_ptr<lN::listNode<T>> BUF = HEAD->nextListElement;
			HEAD->nextListElement = nullptr;
			HEAD = BUF;
			HEAD->previousListElement = nullptr;

		}
		else
		{
			sizeValue--;
			HEAD = nullptr;
			TAIL = nullptr;
		}
	}

	void clear()
	{
		while (HEAD != TAIL)
		{
			std::shared_ptr<lN::listNode<T>> BUF = HEAD->nextListElement;
			HEAD->nextListElement = nullptr;
			HEAD = BUF;
			HEAD->previousListElement = nullptr;
			sizeValue--;
		}

		if (sizeValue == 1)
		{
			sizeValue--;
			HEAD = nullptr;
			TAIL = nullptr;
		}

	}

	size_t size()
	{
		return sizeValue;
	}

};
;
