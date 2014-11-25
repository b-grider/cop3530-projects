/* 
 * File:   SSLL.h
 * Author: Ben
 *
 * Created on September 21, 2014, 11:23 AM
 */

#ifndef SSLL_H
#define	SSLL_H

// SSLL.H
// 
// Singly-linked list (non-polymorphic)
//
// by Dave Small
// for COP 3530
// 201409.16 - created

#include <iostream>
#include<ostream>
#include<stdexcept>

namespace cop3530 {

  template <typename T>
  class SSLL {
    
    struct node {
        T data;
        node* next;
    }; // end struct Node
    
    
    typedef node* link;
    typedef T value_type;
    node* head;
    node* tail;
    int listSize;
    
    
    link getNodeContaining(int index) {
        link temp = head;
        while(index!=0) {
            temp=temp->next;
            index--;
        }
    }
    
  public:
      
      typedef std::size_t size_t;
      
    //=======================================================
    //NON CONST ITER    NON CONST ITER    NON CONST ITER
    //=======================================================
      
      
      class SSLL_Iter { //: public std::iterator<std::forward_iterator_tag, T>
            
            public:
              // inheriting from std::iterator<std::forward_iterator_tag, T>
              // automagically sets up these typedefs...
              typedef T value_type;
              typedef std::ptrdiff_t difference_type;
              typedef T& reference;
              typedef T* pointer;
              typedef std::forward_iterator_tag iterator_category;

              // but not these typedefs...
              typedef SSLL_Iter self_type;
              typedef SSLL_Iter& self_reference;

            private:
              node* here;

            public:
              explicit SSLL_Iter( node* start) {
                  if(start == nullptr) {
                      throw std::invalid_argument("The node pointer must be a valid argument of the list");
                  }
                  else {
                      here=start;
                  }
              }
              SSLL_Iter( const SSLL_Iter& src ) : here( src.here ) {}
              
              reference operator*() const {
                  return here->data;
              }
              pointer operator->() const {
                  return here->data;                  //TODO
              }

              self_reference operator=( const SSLL_Iter& src ) {
                   here=src.here;
              }

              self_reference operator++() {     //pre-increment
                        // node* temp = here;
                         here=here->next;           //TODO
                         return *this;
              }
              
              self_type operator++(int) {       // post-increment
                         SSLL_Iter * retval = new SSLL_Iter(*this);
                         here=here->next;
                         SSLL_Iter t = *retval;
                         delete retval;
                         return t;
              }

              bool operator==(const SSLL_Iter& rhs) const {
                  
                  return (this->here == rhs.here);
                  
              }
              
              bool operator!=(const SSLL_Iter& rhs) const {
                 
                  return (this->here!=rhs.here);
                  
              }
              
     };
     
     
     //===============================================================
     //    CONST ITER SSL       CONST ITER SSL       CONST ITER SSL
     //===============================================================
     
     
     class SSLL_Const_Iter { //: public std::iterator<std::forward_iterator_tag, T>
            
            public:
              // inheriting from std::iterator<std::forward_iterator_tag, T>
              // automagically sets up these typedefs...
              typedef T value_type;
              typedef std::ptrdiff_t difference_type;
              typedef const T& reference;
              typedef const T* pointer;
              typedef std::forward_iterator_tag iterator_category;

              // but not these typedefs...
              typedef SSLL_Const_Iter self_type;
              typedef SSLL_Const_Iter& self_reference;

            private:
              const node* here;

            public:
              explicit SSLL_Const_Iter( node* start) {
                  if(start == nullptr) {
                      throw std::invalid_argument("The node pointer must be a valid argument of the list");
                  }
                  else {
                      here=start;
                  }
              }
              SSLL_Const_Iter( const SSLL_Const_Iter& src ) : here( src.here ) {}
              
              reference operator*() const {
                  return here->data;
              }
              pointer operator->() const {
                  return here;                  //TODO
              }

              self_reference operator=( const SSLL_Const_Iter& src ) {
                   here=src.here;
              }

              self_reference operator++() {     //pre-increment
                        // node* temp = here;
                         here=here->next;           //TODO
                         return *this;
              }
              
              self_reference operator++(int) {       // post-increment
                         SSLL_Const_Iter * retval = new SSLL_Const_Iter(*this);
                         here=here->next;
                         SSLL_Const_Iter t = *retval;
                         delete retval;
                         return t;
              }

              bool operator==(const SSLL_Const_Iter& rhs) const {
                  
                  return (this->here == rhs.here);
                  
              }
              
              bool operator!=(const SSLL_Const_Iter& rhs) const {
                 
                  return (this->here!=rhs.here);
                  
              }
     };
     
     typedef SSLL_Iter iterator;
     typedef SSLL_Const_Iter const_iterator;
  
    //==============================================================
    //          Constructors/destructor/assignment operator
    //==============================================================
     
     

    SSLL() : head(nullptr), tail(nullptr), listSize(0) {}
    
    //--------------------------------------------------
    SSLL( const SSLL& src ) {
        listSize=0;
        int sz=src.size();
        for(int i=0; i<sz; i++) {
            this->push_back(src.item_at(i));
        }
    }                                        //is this a copy constructor? called like [SSLL example = new SSLL(baseSSLL);]?
    
    //--------------------------------------------------
    ~SSLL() {
       /* node* temp=head;
        while(head!=nullptr) {
            head=head->next;
            delete temp;
        }*/
      }
    // safely dispose of this SSLL's contents

    
    //--------------------------------------------------
    SSLL& operator=( const SSLL& src ) {
      if ( &src == this ) // check for self-assignment
	return *this;     // do nothing
      
      else {
          //dispose of contents
          this->clear();
          
          //populate this SSLL
          int thisSize = 0;
          int srcSize=src.size();
          while(thisSize<srcSize) {
              this->push_back(src.item_at(thisSize));
              thisSize++;
          }
      }
      
      // safely dispose of this SSLL's contents
      // populate this SSLL with copies of the other SSLL's contents
    }
    
    //--------------------------------------------------
    // member functions
    //--------------------------------------------------
    
    
    SSLL_Iter begin() {
        return SSLL_Iter(head);
    }
    
    SSLL_Iter end() {
        return SSLL_Iter(tail->next);
    }
    
    SSLL_Const_Iter begin() const {
        return SSLL_Const_Iter(head);
    }
    
    SSLL_Const_Iter end() const {
        return SSLL_Const_Iter(tail->next);
    }
    
    T& operator[](int i) { 
        if(this->is_empty()) {
            throw std::out_of_range("This is an empty SSLL");
        }
        else if(i < 0) {
            throw std::invalid_argument("Valid arguments must be in the range [0,list size-1]");
        }
        else if(i >= listSize) {
            throw std::out_of_range("A valid index must be < list size");
        }
        else {
            link temp = this->getNodeContaining(i);
            return &(temp->data);
        }
    }
    
    T const& operator[](int i) const { 
        if(this->is_empty()) {
            throw std::out_of_range("This is an empty SSLL");
        }
        else if(i < 0) {
            throw std::invalid_argument("Valid arguments must be in the range [0,list size-1]");
        }
        else if(i >= listSize) {
            throw std::out_of_range("A valid index must be < list size");
        }
        else {
            link temp = this->getNodeContaining(i);
            T const& retval = &(temp->data);
            return retval;
        }
    }

    T replace( const T& element, int position ) {
        if(this->is_empty()) {
            throw std::out_of_range("This is an empty SSLL");
        }
        else if(position < 0) {
            throw std::invalid_argument("Valid arguments must be in the range [0,list size-1]");
        }
        else if(position >= listSize) {
            throw std::out_of_range("A valid index must be < list size");
        }
        else {
            link x = head;
            while(position!=0) {
                x=x->next;
                position--;
            }
            T retval=x->data;
            x->data=element;
            return retval;
        }
    }

    //replaces the existing element at the specified position with the specified element and returns the original element.
    
    void insert( const T& element, int position ) {
        if(position < 0) {
            throw std::invalid_argument("Valid arguments must be in the range [0,list size-1]");
        }
        else if(position > listSize) {
            throw std::out_of_range("A valid index must be < list size");
        }
        if((position==0) && (listSize==0)) {
            head=new node();
            head->data=element;
            tail=head;
            listSize++;
           // return;
        }
        else if(position==listSize) {
            tail->next=new node();
            tail=tail->next;
            tail->data=element;
            listSize++;
            //return;
        }
        else {
            link x=head;
            while(position!=1) {                //one element before the [position] index number;
                x=x->next;
                position--;
            }
            link y=new node();
            y->data=element; 
            y->next=x->next;
            x->next=y; y=nullptr; 
            listSize++;
            return;
        }
    }
    
    //adds the specified element to the list at the specified position, shifting the element originally at that and those in subsequent positions one position to the ”right.“
    
    void push_front( const T& element ) {
        if(listSize==0) {
            link x = new node();
            x->data=element; x->next=nullptr;
            head=x; tail=head; listSize++;
        }
        else {
            link x = new node();
            x->data=element;
            x->next=head; head=x;
            listSize++;
        }
    }
    
    //prepends the specified element to the list.
    
    void push_back( const T& element ) {
        if(listSize==0) {
            link x = new node();
            x->data=element; x->next=nullptr;
            head=x; tail=head; listSize++;
        }
        else {
            link x = new node();
            x->data=element;
            tail->next=x; tail=tail->next;
            tail->next=nullptr; listSize++;
        }
       // this->insert(element, listSize);
    }
    
    //appends the specified element to the list.
    
    T pop_front() {
        if(this->is_empty()) {                           //TODO exceptions
                throw std::length_error("This is already an empty list");
            }
        else {
             T retval;
            link x = head;
            head=head->next;
            retval = x->data;
            delete x; listSize--;
            return retval;
        }
    }

    //removes and returns the element at the list's head.
    
    T pop_back() {
       // try {
            if(this->is_empty()) {                           //TODO exceptions
                throw std::length_error("This is already an empty list");
            }
            else {
            link x=head;
            while(x->next!=tail) {
                x=x->next;
            }
             T retval=x->next->data;                   //x is now the element before the tail element. EXCEPTION
             x->next=nullptr;
             delete tail;
             tail=x; listSize--;
             return retval;
            }
       /* }*/ /*catch(...) {
            
        }*/
    }

    //removes and returns the element at the list's tail.
    
    T remove( int position ) {
        if(this->is_empty()) {
            throw std::out_of_range("This is an empty SSLL");
        }
        else if(position < 0) {
            throw std::invalid_argument("Valid arguments must be in the range [0,list size-1]");
        }
        else if(position >= listSize) {
            throw std::out_of_range("A valid index must be < list size");
        }
        else if(position==0) {
           return this->pop_front();
        }
        else if(position==(listSize-1)) {
            return this->pop_back();
        }
        else {
           link x=head;
           
                while(position!=1) {
                    x=x->next; position--;
                }
           
           link y=x->next;                //now x is at the node before the designated node
           x->next=x->next->next;
           T retval=y->data;
                /*head=x;*/ listSize--;
           delete y; x=nullptr;
           return retval;
          } 
    }

    //removes and returns the the element at the specified position, shifting the subsequent elements one position to the ”left.“
    
    T item_at( int position ) const {
        if(this->is_empty()) {
            throw std::out_of_range("This is an empty SSLL");
        }
        else if(position < 0) {
            throw std::invalid_argument("Valid arguments must be in the range [0,list size-1]");
        }
        else if(position >= listSize) {
            throw std::out_of_range("A valid index must be < list size");
        }
        else {
            link x=head;
            int count=0;
            while(count!=position) {
                x=x->next;
                count++;
            }
            T retval = x->data;
            return retval;
        }
        
    }

    //returns (without removing from the list) the element at the specified position.
    
    bool is_empty() const {
        if(listSize==0) return true;
        else return false;
    }

    //returns true IFF the list contains no elements.
    
    size_t size() const {return listSize;}

    //returns the number of elements in the list.
    
    void clear() {
        link x = head;
        while (head!=nullptr) {
            head = head->next;
            delete x;
            x=head;
        }
        listSize=0;
        tail=nullptr;
    }     

    //removes all elements from the list.
    
    bool contains( const T& element, bool equals( const T& a, const T& b  ) ) const {
        
        for(int i=0; i<listSize; i++) {
            if(equals(this->item_at(i), element)) {
                return true;
            }
        }
        return false;
    }

    //returns true IFF one of the elements of the list matches the specified element.
    
    std::ostream& print( std::ostream& out ) const {
        if(this->is_empty()) {
            out << "<empty list>";
            return out;
        }
        else {
            link x = head;
            out << "{";
            while(x!=nullptr) {
                 out << x->data << "," << " ";              //TODO override << operator for T?
                 x=x->next;
            } out << "}";
       // out << "asldcbasdkj";
        
        return out;
        }
    }
    
    //If the list is empty, inserts "<empty list>" into the ostream; otherwise, inserts, enclosed in square brackets, the list's elements, separated by commas, in sequential order.

  }; //end class SSLL
} // end namespace cop3530

#endif	/* SSLL_H */

