#include <iostream>
#include "LinkedList.hpp";

template<class T>
LinkedList<T>::Node::Node(const T& data, typename Node* next) : data(data), next(next){}

template<class T>
void LinkedList<T>::copy(const LinkedList& other) {
	Node* iter = other.start;
	while (iter)
	{
		push_back(iter->data);
		iter = iter->next;
	}
}

template<class T>
void LinkedList<T>::free(Node* node) {
	if (!node) return;
	free(node->next);
	delete node;
	node = nullptr;
}

template<class T>
void LinkedList<T>::free() {
	free(start);
}

template<class T>
void LinkedList<T>::reverse(Node* node) {
	if (!node || !node->next)
	{
		return;
	}
	reverse(node->next);
	node->next->next = node;
}

template<class T>
const typename LinkedList<T>::Node* LinkedList<T>::find(size_t ind) const {
	if (ind > m_size || ind < 0)
	{
		throw std::out_of_range("Index is out of range.");
	}
	Node* iter = start;
	size_t i = 0;
	while (iter && i < ind)
	{
		iter = iter->next;
		i++;
	}
	return iter;
}

template<class T>
typename LinkedList<T>::Node* LinkedList<T>::find(size_t ind) {
	Node* iter = start;
	size_t i = 0;
	while (iter && i < ind)
	{
		iter = iter->next;
		i++;
	}
	return iter;
}

template<class T>
LinkedList<T>::LinkedList() : start(nullptr), end(nullptr), m_size(0){}

template<class T>
LinkedList<T>::LinkedList(const LinkedList& other) { copy(other); }

template<class T>
LinkedList<T>::LinkedList(const T* arr, size_t size){
	for (size_t i = 0; i < size; i++)
	{
		push_back(arr[i]);
	}
}

template<class T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList& other) {
	if (this==&other)
	{
		return *this;
	}
	free();
	copy(other);
	return *this;
}

template<class T>
LinkedList<T>::~LinkedList() {
	free();
}

template<class T>
bool LinkedList<T>::empty() {
	return !start;
}

template<class T>
size_t LinkedList<T>::size() const {
	return m_size;
}

template<class T>
void LinkedList<T>::push_front(const T& data) {
	if (empty())
	{
		start = new Node(data);
		end = start;
		m_size++;
		return; 
	}
	Node* node = new Node(data, start);
	start = node;
	m_size++;
}

