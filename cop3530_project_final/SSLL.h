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
    
    node* head;
    node* tail;
    int listSize;
    
  public:
      
      
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
              explicit SSLL_Iter( node* start) : here( start ) {}
              SSLL_Iter( const SSLL_Iter& src ) : here( src.here ) {}
              
              reference operator*() const {
                  return here->data;
              }
              pointer operator->() const {
                  return here;                  //TODO
              }

              self_reference operator=( const SSLL_Iter& src ) {
                   here=src.here;
              }

              self_reference operator++() {     //pre-increment
            
                      if(here->next == nullptr) {
                          throw std::out_of_range("You're already at the end of the list.");
                      }
                      else {
                        // node* temp = here;
                         here=here->next;           //TODO
                         return *this;
                      }
              }
              
              self_type operator++(int) {       // post-increment
                  
                      if(here->next == nullptr) {
                          throw std::out_of_range("You're already at the end of the list.");
                      }
                      else {
                         node* temp = here;
                         here=here->next;           //TODO
                         return *temp;
                      }
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
              explicit SSLL_Const_Iter( node* start) : here( start ) {}
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
            
                      if(here->next == nullptr) {
                          throw std::out_of_range("You're already at the end of the list.");
                      }
                      else {
                        // node* temp = here;
                         here=here->next;           //TODO
                         return *this;
                      }
              }
              
              self_reference operator++(int) {       // post-increment
                  
                      if(here->next == nullptr) {
                          throw std::out_of_range("You're already at the end of the list.");
                      }
                      else {
                         SSLL_Const_Iter * temp=new SSLL_Const_Iter(*this);
                         here=here->next;           //TODO
                         return *temp;
                      }
              }

              bool operator==(const SSLL_Const_Iter& rhs) const {
                  
                  return (this->here == rhs.here);
                  
              }
              
              bool operator!=(const SSLL_Const_Iter& rhs) const {
                 
                  return (this->here!=rhs.here);
                  
              }
     };
     
     
  
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
        return SSLL_Iter(tail);
    }
    
    SSLL_Const_Iter begin() const {
        return SSLL_Const_Iter(head);
    }
    
    SSLL_Const_Iter end() const {
        return SSLL_Const_Iter(tail);
    }
    

    T replace( const T& element, int position ) {
        if(position < 0 || position >= listSize) {
            std::cout << "enter valid position" << std::endl;
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
        if((position <0) || (position > listSize)) {
            throw std::out_of_range("The valid indices to insert on are on the interval [0, listSize]");
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
        T retval;
        link x = head;
        head=head->next;
        retval = x->data;
        delete x; listSize--;
        return retval;
    }

    //removes and returns the element at the list's head.
    
    T pop_back() {
       // try {
            if(head == nullptr) {
                std::cout << "Empty list!" << std::endl;
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
        if(position==0) {
            this->pop_front();
        }
        else if(position==(listSize-1)) {
            this->pop_back();
        }
        else if((position>0) && (position<(listSize-1))) {
            if(this->is_empty()) {
                throw std::invalid_argument("This is an empty list silly.");
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
        
    }

    //removes and returns the the element at the specified position, shifting the subsequent elements one position to the ”left.“
    
    T item_at( int position ) const {
        if(position <= 0) {
            if((listSize>=1) && (position==0)) {
                return head->data;
            }
            else {
                if(position < 0) {
                    throw std::invalid_argument("The position must be >=0 to be valid");
                }
                else {
                    throw std::out_of_range("The specified index is out of the range of this list's values");
                }
            }
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
    
    int size() const {return listSize;}

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
        link x = head;
        while(x!=nullptr) {
            out << x->data << " ";              //TODO override << operator for T?
            x=x->next;
        }
       // out << "asldcbasdkj";
        
        return out;
    }
    
    //If the list is empty, inserts "<empty list>" into the ostream; otherwise, inserts, enclosed in square brackets, the list's elements, separated by commas, in sequential order.

  }; //end class SSLL
} // end namespace cop3530

#endif	/* SSLL_H */

