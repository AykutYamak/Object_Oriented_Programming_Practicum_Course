#pragma once
#include <iostream>

template<typename T>
class LinkedList {
private:
	struct Node {
		T data;
		Node* next;

		Node(const T& data, Node* next = nullptr);
	};

	Node* start;
	Node* end;
	size_t m_size;
	
	void copy(const LinkedList& other);
	void free();
	void free(Node* node);
	void reverse(Node* node);
	const Node* find(size_t ind) const;
	Node* find(size_t ind);
public:
	LinkedList();
	LinkedList(const LinkedList& other);
	LinkedList(const T* arr, size_t size);
	LinkedList& operator=(const LinkedList& other);
	~LinkedList();
	bool empty();
	size_t size() const;
	void push_front(const T& data);
	void pop_front();
	void push_back(const T& data);
	void insertAt(size_t ind, const T& data);
	void insertAfter(size_t ind,const T& data);
	void removeAt(size_t int);
	void removeElement(const std::function<bool(const T&)>& f);
	T& get(size_t ind);
	const T& get(size_t ind) const;
	LinkedList& concat(const LinkedList& other);
	LinkedList& concat(LinkedList&& other);
	template<class R>
	LinkedList<R> map(const std::function<R(const T&)>& f) const;
	const LinkedList& foreach(const std::function<void(const T&)>& f) const;
	LinkedList& foreach(const std::function<void(T&)>& f);
	LinkedList filter(const std::function<bool(const T&)>& f) const;
	T& find(const std::function<bool(const T&)>& f);
	const T& find(const std::function<bool(const T&)>& f) const;
	LinkedList sortBy(const std::function<bool(const T&, const T&)>& lessThan) const;
	LinkedList& reverse();
	void print() const;
};