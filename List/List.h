//
// Created by Jakub Kordel on 29.03.19.
//

#ifndef SAPER_LIST_H
#define SAPER_LIST_H

#include <iostream>

template <class Type>
class List {

    struct Element {
        Type object;
        Element *next;
    };

    Element *head;
    size_t numEl;

    Element *getElement(std::size_t index) const {
        if (index >= numEl || index < 0)
            return nullptr;
        Element *temp = head;
        while (index--) {
            temp = temp->next;
        }
        return temp;
    }

public:
    List() {
        head = nullptr;
        numEl = 0;
    }

    List(const List &list) {
        head = nullptr;
        numEl = 0;
        *this = list;
    }

    ~List() {
        clearList();
    }

    void addElement(const Type &obj) {
        Element *newEl = new Element;
        newEl->object = obj;
        newEl->next = head;
        head = newEl;
        ++numEl;
    }

    void deleteElement(std::size_t index) {
        if (index > 0 && index < numEl) {
            Element *buf = getElement(index + 1);
            delete getElement(index);
            --numEl;
            getElement(index - 1)->next = buf;
        } else if (index == 0) {
            Element *buf = getElement(1);
            delete getElement(0);
            head = buf;
            --numEl;
        }
    }

    List operator+(const List &list) const {
        List<Type> newList(*this);
        return newList += list;
    }

    List & operator+=(const List &list) {
        Element *temp = list.head;
        while (temp) {
            addElement(temp->object);
            temp = temp->next;
        }
        return *this;
    }

    friend std::ostream & operator<<( std::ostream & os, const List & list ){
        Element * temp = list.head;
        while ( temp ){
            os << temp ->object << std::endl;
            temp = temp ->next;
        }
        return os;
    }

    Type & operator[](std::size_t index) const {
        return getElement(index)->object;
    }

    size_t numberOfElements() const {
        return numEl;
    }

    void clearList() {
        while (numEl) {
            deleteElement(0);
        }
    }

    List & operator=(const List &list) {
        clearList();
        Element *temp = list.head;
        while (temp) {
            addElement(temp->object);
            temp = temp->next;
        }
        return *this;
    }
};

#endif //SAPER_LIST_H
