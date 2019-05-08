//
// Created by Jakub Kordel on 29.03.19.
//

#ifndef SAPER_LIST_H
#define SAPER_LIST_H

#include <iostream>

template <class Type>
class List {
private:
    struct Element {
        Type object;
        Element *next;
    };

    struct GroupRep {
        Element *head;
        size_t numEl;
        int count;
        GroupRep(const Element *h) {
            count = 1;
            numEl = 0;
            head = nullptr;
            const Element *temp = h;
            while (temp) {
                addElement(temp->object);
                temp = temp->next;
            }
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

        Element *getElement(std::size_t index) const {
            if (index >= numEl || index < 0)
                return nullptr;
            Element *temp = head;
            while (index--) {
                temp = temp->next;
            }
            return temp;
        }

        void clear() {
            while (numEl) {
                deleteElement(0);
            }
        }
        ~GroupRep() {
            clear();
        }
    };

    GroupRep * rep;

    void newRep(){
        if ( rep ->count > 1) {
            --rep ->count;
            rep = new GroupRep(rep ->head);
        } 
    }

public:

    List() {
        rep = new GroupRep(nullptr);
    }

    List(const List &list) {
        rep = list.rep;
        ++rep->count;
    }

    ~List() {
        if ( rep ->count < 2)
            delete rep;
        else
            --rep ->count;
    }

    void addElement(const Type &obj) {
        newRep();
        rep ->addElement( obj );
    }

    void deleteElement(std::size_t index) {
        newRep();
        rep ->deleteElement( index );
    }

    List operator+(const List &list) const {
        List<Type> newList(*this);
        return newList += list;
    }

    List & operator+=(const List &list) {
        Element *temp = list.rep ->head;
        while (temp) {
            addElement(temp->object);
            temp = temp->next;
        }
        return *this;
    }

    friend std::ostream & operator<<( std::ostream & os, const List & list ){
        Element * temp = list.rep ->head;
        while ( temp ){
            os << temp ->object << std::endl;
            temp = temp ->next;
        }
        return os;
    }

    Type & operator[](std::size_t index) {
        newRep();
        return  rep ->getElement(index)->object;
    }

    Type onlyRead( std::size_t index ){
        return  rep ->getElement(index)->object;
    }

    size_t numberOfElements() const {
        return rep ->numEl;
    }

    List & operator=(const List &list) {
	if ( rep ->count < 2 ){
           delete rep;
        }
        else {
           --rep ->count;
        }
        rep = list.rep;
        ++rep ->count;
        return *this;
    }

    void clearList(){
        newRep();
        rep ->clear();
    }
};

#endif //SAPER_LIST_H
