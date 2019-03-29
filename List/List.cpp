//
// Created by Jakub Kordel on 29.03.19.
//

/*#include "List.h"

template < class Type>
List<Type>::List(){
    head = nullptr;
    numEl = 0;
}

template <class Type>
List<Type>::List( const List<Type> & list ){
    head = nullptr;
    numEl = 0;
    *this = list;
}

template <class Type>
List<Type>::~List(){
    clearList();
}

template <class Type>
void List<Type>::addElement( const Type & obj ){
    Element * newEl = new Element;
    newEl ->object = obj;
    newEl ->next = head;
    head = newEl;
    ++numEl;
}

template <class Type>
void List<Type>::deleteElement( std::size_t index ){
    if ( index > 0 && index < numEl ) {
        Element * buf = getElement(index + 1);
        delete getElement(index);
        --numEl;
        getElement(index - 1)->next = buf;
    }
    else if ( index == 0 ){
        Element * buf = getElement(1);
        delete getElement(0);
        head = buf;
        --numEl;
    }
}

template <class Type>
List<Type> List<Type>::operator+(const List<Type> & list ) const {
    List<Type> newList( *this );
    return newList += list;
}

template <class Type>
List<Type> & List<Type>::operator+=( const List<Type> & list ){
    Element * temp = list.head;
    while ( temp ){
        addElement( temp ->object );
        temp = temp ->next;
    }
    return *this;
}
*/
/*template <class Type>
std::ostream & operator<<( std::ostream & os, const List<Type> & list ){
    typename List<Type>::Element * temp = list.head;
    while ( temp ){
        os << temp ->object << std::endl;
        temp = temp ->next;
    }
    return os;
}*/
/*

template <class Type>
Type & List<Type>::operator[]( std::size_t index ) const {
    return getElement( index ) ->num;
}

template <class Type>
typename List<Type>::Element * List<Type>::getElement( std::size_t index ) const {
    if ( index >= numEl || index < 0 )
        return nullptr;
    Element * temp = head;
    while( index-- ){
        temp = temp ->next;
    }
    return temp;
}

template <class Type>
size_t List<Type>::numberOfElements() const {
    return numEl;
}

template <class Type>
void List<Type>::clearList(){
    while ( numEl ){
        deleteElement(0);
    }
}

template <class Type>
List<Type> & List<Type>::operator=( const List<Type> & list ) {
    clearList();
    Element * temp = list.head;
    while ( temp ){
        addElement( temp ->object );
        temp = temp ->next;
    }
    return *this;
}
*/