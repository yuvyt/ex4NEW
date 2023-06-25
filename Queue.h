//
// Created by lanat on 05/06/2023.
//

#ifndef MTMCHKIN_QUEUE_H
#define MTMCHKIN_QUEUE_H

#include <iostream>
#include <exception>


template<typename T>
class Queue {

private:
    struct Node {
        T data;
        Node *next;

        /*c'tor for the struct Node.
        *@param: value: the data for the node
        *
        */
        explicit Node(const T &value) : data(value), next(nullptr) {}

        /*
        *overloading operator= with a Node object,
        * so it will be another pointer to the other Node
        *
        * @param: otherNode: node to be
        */
        Node &operator=(const Node &otherNode) {
            if (this != &otherNode) {
                this->data = otherNode.data;
                this->next = otherNode.next;
            }
            return *this;
        }

        bool operator==(const Node &otherNode) {
            return (this->data == otherNode.data);
        }

    };

    int m_size;
    Node *m_first;
    Node *m_rear;

public:

    /*c'tor for the class queue.
    *initilaizing the fields to their default values
    *
    */
    Queue() : m_size(0) {
        this->m_first = nullptr;
        this->m_rear = nullptr;
    }

    /*c'tor for the class queue.
    *@param: m_first: size for ne
    *
    */
    // Queue(Node *m_first = nullptr, Node *m_rear = nullptr) { //int m_size = 0,
    //     this->m_first = m_first;
    //     this->m_size = 0;
    //     Node count = m_first;
    //     while (count != nullptr)
    //     {
    //         m_size++;
    //         count=count->next;
    //     }
    //     this->m_rear = m_rear;
    // }

    /*copy c'tor for the class queue.
    *initilaizing the fields to a copy of the values that were in the wanted queue
    *
    * @param: otherQueue: queue to copy
    */
    Queue(const Queue<T> &otherQueue);

    /*class EmptyQueue to throw when encoutring an empty queue is a problem
    */
    class EmptyQueue {
    };

    /*front returns the value of the first element in the queue
    */
    T &front() const;

    /*pushBack adds another element to the end of the queue
    * param: object: a T object to add
    */
    void pushBack(const T &object);

    /*removes the first object of the queue
    */
    void popFront();

    /*returns size of the queue
    */
    int size() const;

    /*d'tor for the queue
    */
    ~Queue();

    /*
    * overloading operator= with a Queue object,
    * makes the current queue identical in content to the recived queue
    *
    * @param: otherQueue: queue to imitate
    */
    Queue<T> &operator=(const Queue<T> &otherQueue);

    /*class InvalidOperation to throw when operating incurrectly on a nullptr
    */
    class InvalidOperation {
    };

    class Iterator;

    /*returns the first node of a queue as an Iterator objects
    */
    Iterator begin() {
        return Iterator(this, m_first);
    }

    /*returns the after the last node of a queue as an Iterator objects
    */
    Iterator end() {
        return Iterator(this, nullptr);
        // return Iterator(this,m_rear->next);

    }

    class ConstIterator;

    /*returns the first node of a const queue as an Iterator objects
    */
    ConstIterator begin() const {
        return ConstIterator(this, m_first);
    }

    /*returns the after the last node of a const queue as an Iterator objects
    */
    ConstIterator end() const {
        return ConstIterator(this, m_rear->next);
    }
//    const T& operator->();

};

template<typename T>


void Queue<T>::popFront() {
    if (m_size == 0) {
        throw EmptyQueue();
    }
    Node *temp = m_first;
    m_first = m_first->next;
    delete temp;
    m_size--;
    if (m_size == 0) {
        m_rear = nullptr;
    }
}

template<typename T>
void Queue<T>::pushBack(const T &object) {
    T toAdd = object;
    Node *newNode = new Node(toAdd);
    if (m_size == 0) {
        m_first = newNode;
        m_rear = newNode;
    } else {
        m_rear->next = newNode;
        if (m_size == 1) {
            m_first->next = newNode;
        }
        m_rear = newNode;
    }
    m_size++;
}

template<typename T>
T &Queue<T>::front() const {
    if (m_size <= 0) {
        throw EmptyQueue();
    }
    return m_first->data;
}



template<typename T>
Queue<T>::~Queue() {
    while (m_size) {
        popFront();
    }

}


template<typename T>
Queue<T>::Queue(const Queue<T> &otherQueue) {

    m_size = 0;
    m_first = nullptr;
    m_rear = nullptr;
    Node *currNode = otherQueue.m_first;
    T toAdd;
    while (currNode != nullptr) {
        try {
            toAdd = currNode->data;
            pushBack(toAdd);

        } catch (std::bad_alloc &e) {
            while (m_size) {
                popFront();
            }
//            delete this;
            throw e;
        }
        currNode = currNode->next;
    }

}

template<typename T>
Queue<T> &Queue<T>::operator=(const Queue<T> &otherQueue) {

    if (this == &otherQueue) {
        return *this;
    }

    Queue<T> newQueue(*this);//copy the current queue so if something went wrong in the assigment i return it as it was
    while (m_size) {//delete the curr nodes of the this queue
        popFront();
    }

    for (Queue<T>::ConstIterator it = otherQueue.begin(); it != otherQueue.end(); ++it) {
        ////use iterators in order to go over the nodes of otherquue
        try {

            pushBack(*it);//try to push the nodes into this queue

        } catch (std::bad_alloc &e) {
            //if pushback threw a badalloc i catch
            while (m_size) {//delte the curr nodes of the this queue
                popFront();
            }
            this->m_size = newQueue.m_size;//return all the members as it was
            this->m_first = newQueue.m_first;
            this->m_rear = newQueue.m_rear;
            throw e;

        }
    }
    return *this;
}


template<typename T>
int Queue<T>::size() const {
    return m_size;
}


template<typename T>
class Queue<T>::Iterator {

public:
    /*overload operator* for class iterator
    */
    T &operator*();

    /*overload operator++ for class iterator
    */
    Iterator &operator++();

    /*overload operator++ (int) for the postfixx for class iterator
    */
    const Iterator operator++(int);

    /*overload operator== for class iterator
    * compares the places in the queue
    * param: it: placment to compare with
    */
    bool operator==(const Iterator &it) const;

    /*overload operator!= for class iterator
    * compares the places in the queue
    * param: it: placment to compare with
    */
    bool operator!=(const Iterator &other) const;

    Iterator(const Iterator &) = default;

    Iterator &operator=(const Iterator &) = default;

    class InvalidOperation {
    };

private:

    Queue<T> *queue;
    Node *current;

    /*c'tor for Iterator
    * param: queue: queue to iterate on
    * param: current: current node on queue
    */
    Iterator(Queue<T> *queue, Node *current) : queue(queue), current(current) {}

    Iterator();//not sure if i should add this
    friend class Queue<T>;

};

template<typename T>
Queue<T>::Iterator::Iterator() : queue(nullptr) {}

template<typename T>
T &Queue<T>::Iterator::operator*() {
    if (current == nullptr) {
        throw InvalidOperation();
    }
    return this->current->data;
}

template<typename T>
typename Queue<T>::Iterator &Queue<T>::Iterator::operator++() {//ahould we add invalidoperation to other
    if (current == nullptr) {
        throw InvalidOperation();
    }
    current = current->next;
    return *this;
}

template<typename T>
const typename Queue<T>::Iterator Queue<T>::Iterator::operator++(int) {//ahould we add invalidoperation to other
    Iterator result = *this;
    ++*this;
    return result;
}

template<typename T>
bool Queue<T>::Iterator::operator==(const Iterator &it) const {
    if (this->queue == it.queue) {
        return current == it.current;
    }
    return false;
}

template<typename T>
bool Queue<T>::Iterator::operator!=(const Iterator &other) const {
    return !(*this == other);
}


template<typename T>
class Queue<T>::ConstIterator {

public:
    /*overload operator* for class ConstIterator
    */
    const T &operator*() const;

    /*overload operator++ for class ConstIterator
    */
    ConstIterator &operator++();

    /*overload operator++ (int) for the postfixx for class ConstIterator
    */
    const ConstIterator operator++(int);

    /*overload operator== for class ConstIterator
    * compares the places in the queue
    * param: it: placment to compare with
    */
    bool operator==(const ConstIterator &it) const;

    const T *operator->() const;

    /*overload operator!= for class ConstIterator
    * compares the places in the queue
    * param: it: placment to compare with
    */
    bool operator!=(const ConstIterator &it) const;

    ConstIterator(const ConstIterator &) = default;

    ConstIterator &operator=(const ConstIterator &) = default;

    class InvalidOperation {
    };

private:

    const Queue<T> *queue;
    const Node *current;

    /*c'tor for ConstIterator
    * param: queue: queue to iterate on
    * param: current: current node on queue
    */
    ConstIterator(const Queue<T> *queue, const Node *current) : queue(queue), current(current) {};

    ConstIterator() = default;//not sure if i should add this
    friend class Queue<T>;

};

template<typename T>
const T &Queue<T>::ConstIterator::operator*() const {
    if (current == nullptr) {
        throw InvalidOperation();
    }
    return this->current->data;
}

template<typename T>
typename Queue<T>::ConstIterator &Queue<T>::ConstIterator::operator++() {//ahould we add invalidoperation to other
    if (current == nullptr) {
        throw InvalidOperation();
    }
    current = current->next;
    return *this;
}

template<typename T>
const typename Queue<T>::ConstIterator
Queue<T>::ConstIterator::operator++(int) {//ahould we add invalidoperation to other
    Iterator result = *this;
    ++*this;
    return result;
}

template<typename T>
bool Queue<T>::ConstIterator::operator==(const ConstIterator &it) const {
    if (this->queue == it.queue) {
        return current == it.current;
    }
    return false;
}

template<typename T>
bool Queue<T>::ConstIterator::operator!=(const ConstIterator &it) const {
    return !(*this == it);
}

template<typename T>
const T *Queue<T>::ConstIterator::operator->() const {
    if (current == nullptr) {
        throw InvalidOperation();
    }
    return &(*this);
}

/*filter  function for queue
* filtering the content of the queue according to a certine function
* param: queue: queue to filter
* param: functionPtr: function to filter by
*/
template<typename T, typename Function>
Queue<T> filter(const Queue<T> &queue, Function functionPtr) {
    Queue<T> resultQueue;
    for (typename Queue<T>::ConstIterator it = queue.begin(); it != queue.end(); ++it) {
        T value = *it;
        if (functionPtr(value)) {
            try {
                resultQueue.pushBack(value);
            } catch (std::bad_alloc &e) {
                throw std::bad_alloc();
            }
        }
    }
    return resultQueue;
}


/*transform function for queue
* changes the content of the queue according to a certine function
* param: queue: queue to filter
* param: functionPtr: function to filter by
*/
template<typename T, typename Function>
void transform(Queue<T> &queue, Function functionPtr) {
    for (typename Queue<T>::Iterator it = queue.begin(); it != queue.end(); ++it) {
        functionPtr(*it);
    }
}

/*overloading << to now print out the front of the queue
* param: os: ostream
* param: queue: queue to print
*/
template<typename T>
std::ostream &operator<<(std::ostream &os, const Queue<T> &queue) {
    os << queue.front();
    return os;
}

#endif //MTMCHKIN_QUEUE_H