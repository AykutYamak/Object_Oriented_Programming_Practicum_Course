#include <iostream>

template<class T>
class LinkedList {
    struct Node {
        T value;
        Node* next;

        Node(const T& value, Node* next = nullptr) : value(value), next(next), size(0)
    };
    Node* start;
    Node* end;
    size_t size;
    void copy(const LinkedList& other) {
        Node* iter = other.start;
        while (iter)
        {
            push_front(iter->value);
            iter = iter->next;
        }
    }
    void free() {
        while (start)
        {
            pop_front();
        }
    }
public:

    LinkedList() : start(nullptr), end(nullptr), size(0) {}
    LinkedList(const LinkedList& other){
        copy(other);
    }
    LinkedList& operator=(const LinkedList& other) {
        if (this!=&other)
        {
            free();
            copy(other);
        }
        return *this;
    }
    ~LinkedList() {
        free();
    }
    bool empty() {
        return !start;
    }
    void push_front(const T& element) {
        if (!end)
        {
            start = new Node(element);
            end = start;
            return;
        }
        Node* node = new Node(element, start);
        start = node;
    }
    void insertAfter(size_t ind, const T& element) {
        if (empty())
        {
            push_back(element);
            return;
        }
        size_t i = 0;
        Node* iter = start;
        while (iter && i < ind) {
            iter = iter->next;
            i++;
        }
        Node* newElement = new Node(element,iter->next);
        iter->next = newElement;
    }
   /* void push_back(const T& element){
        if (!start)
        {
            start = new Node<T>(element);
            return;
        }
        Node<T>* iter;
        while (iter && iter->next)
        {
            iter = iter->next;
        }
        iter->next = new Node<T>(element);
    }*/
    void push_back(const T& element) {
        if (!start)
        {
            start = new Node(element);
            end = start;
            return;
        }
        end->next = new Node(element);
        end = end->next;
    }
    void pop_front() {
        Node<T>* toDelete = start;
        start = start->next;// (*start).next
        delete toDelete;
    }
    void concat(const LinkedList& other) {
        if (this != &other)
        {


            Node* iter = other.start;
            while (iter)
            {
                push_back(iter->value);
                iter = iter->next;

            }
            
        }
        else
        {
            LinkedList<T> copyList;
            copyList.copy(copyList);
            return 
        }
        
    }
    void print() {
        Node* iter = start;
        while (iter != nullptr)
        {
            std::cout << iter->value << " ";
            iter = iter->next;
        }
    }
};
int main()
{
    LinkedList<int> list;
    for (size_t i = 0; i < 10; i++)
    {
        list.push_back(i);
    }
    list.insertAfter(2, 10);
    list.print();
}

