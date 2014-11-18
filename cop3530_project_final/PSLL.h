/* 
 * File:   PSLL.h
 * Author: Ben
 *
 * Created on September 19, 2014, 7:59 PM
 */


#ifndef PSLL_H
#define	PSLL_H

#include<iostream>
#include<stdexcept>
//#include"listIndexException.h"


namespace cop3530 {

template<typename T>
class PSLL {
    
    struct node {
        T data;
        node* next;
    };
    
    typedef node* link;
    
    node* listHead;
    node* listTail;         //List members
    int listSize;
    
    link x;                 //global link for conducting list operations. This will be for strictly utility purposes.
    
    node* freeHead;
  //  node* freeTail;         //Free list members
    int freeSize;
    
    void freeNodes(int begin, int end) {                                                            //frees all nodes on [begin,end] interval, inclusive
        if((begin < 0) || (begin >= listSize) || (end < 0) || (end >= listSize)) {
            std::cout << "index out of bounds, try with new valid inputs." << std::endl;
        }
        else {
           link temp;                                    //start with x getting the head node.
            int deleteList = (end-begin+1);
            x=getNodeptr(begin-2);                        //x now has the node previous to begin
            while(deleteList!=0) {
                temp=x->next;
                x->next=x->next->next;                  //removing the node from the sequence of links
                appendFree(temp);                       //add temp node to free List
                x=x->next; listSize++; deleteList--;
            }
        }
     }
    
    void appendFree(link a) {
        if(freeSize==0) {
            freeHead=a; freeSize++;
        }
        else {
            a->next=freeHead;
            freeHead=a; freeSize++;
        }
        
    }
    
    link getNodeptr(int index) {
        link n=nullptr;
        x=listHead;
        for(int i=0;i!=index;i++) {
            x=x->next;
        }
        n=x;
    }
    
    
    public:
        
        //=======================================================================
        //          CONSTRUCTORS         CONSTRUCTORS        CONSTRUCTORS
        //======================================================================
        
        PSLL() {
    
            listHead=nullptr;
            listTail=nullptr;
            listSize=0;

            x=nullptr;

            freeHead=nullptr;
            freeSize=0;
     
        }

        ~PSLL() {
            while(listHead!=nullptr) {
                x=listHead;
                listHead=listHead->next;
                delete x;
            }
            
             while(freeHead!=nullptr) {
                x=freeHead;
                freeHead=freeHead->next;
                delete x;
            }
        }

        PSLL(const PSLL &obj) {
            
            listHead=nullptr;
            listTail=nullptr;
            listSize=0;

            x=nullptr;

            freeHead=nullptr;
            freeSize=0;
            
            int sz=obj.size();
            for(int i=0; i<sz; i++) {
                this->push_back(obj.item_at(i));
            }
        }
        
        
        //======================================================================
        //      ITERATORS        ITERATORS           ITERATORS
        //======================================================================
        
        
       class PSLL_Iter { //: public std::iterator<std::forward_iterator_tag, T>
            
            public:
              // inheriting from std::iterator<std::forward_iterator_tag, T>
              // automagically sets up these typedefs...
              typedef T value_type;
              typedef std::ptrdiff_t difference_type;
              typedef T& reference;
              typedef T* pointer;
              typedef std::forward_iterator_tag iterator_category;

              // but not these typedefs...
              typedef PSLL_Iter self_type;
              typedef PSLL_Iter& self_reference;

            private:
              node* here;

            public:
              explicit PSLL_Iter( node* start) : here( start ) {}
              PSLL_Iter( const PSLL_Iter& src ) : here( src.here ) {}
              
              reference operator*() const {
                  return here->data;
              }
              pointer operator->() const {
                  return here;
              }

              self_reference operator=( const PSLL_Iter& src ) {
                   here=src;
              }

              self_reference operator++() {     //pre-increment
            
                      if(here->next == nullptr) {
                          throw std::out_of_range("You're already at the end of the list.");
                      }
                      else {
                         node* temp = here;
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

              bool operator==(const PSLL_Iter& rhs) const {
                  
                  return (this->here == rhs.here);
                  
              }
              
              bool operator!=(const PSLL_Iter& rhs) const {
                 
                  return (here!=rhs.here);
                  
              }
     };
     
     
     
     
     class PSLL_Const_Iter { //: public std::iterator<std::forward_iterator_tag, T>
            
            public:
              // inheriting from std::iterator<std::forward_iterator_tag, T>
              // automagically sets up these typedefs...
              typedef T value_type;
              typedef std::ptrdiff_t difference_type;
              typedef T& reference;
              typedef T* pointer;
              typedef std::forward_iterator_tag iterator_category;

              // but not these typedefs...
              typedef PSLL_Const_Iter self_type;
              typedef PSLL_Const_Iter& self_reference;

            private:
              node* here;

            public:
              explicit PSLL_Const_Iter( node* start) : here( start ) {}
              PSLL_Const_Iter( const PSLL_Const_Iter& src ) : here( src.here ) {}
              
              reference operator*() const {
                  return here->data;
              }
              pointer operator->() const {
                  return here;
              }

              self_reference operator=( const PSLL_Const_Iter& src ) {
                   here=src;
              }

              self_reference operator++() {     //pre-increment
            
                      if(here->next == nullptr) {
                          throw std::out_of_range("You're already at the end of the list.");
                      }
                      else {
                         PSLL_Const_Iter* temp = new PSLL_Const_Iter(*this);
                         here=here->next;           //TODO
                         return *this;
                      }
              }
              
              self_type operator++(int) {       // post-increment
                  
                      if(here->next == nullptr) {
                          throw std::out_of_range("You're already at the end of the list.");
                      }
                      else {
                         PSLL_Const_Iter* temp = new PSLL_Const_Iter(*this);
                         here=here->next;           //TODO
                         return *temp;
                      }
              }

              bool operator==(const PSLL_Const_Iter& rhs) const {
                  
                  return (this->here == rhs.here);
                  
              }
              
              bool operator!=(const PSLL_Const_Iter& rhs) const {
                 
                  return (here!=rhs.here);
                  
              }
     };
        
        
     //=========================================================================
     //     PUBLIC MEMBER FUNCTIONS     PUBLIC MEMBER FUNCTIONS
     //=========================================================================
     
        
        void testFreeNodes(int a, int b) {
            freeNodes(a,b);
        }
        
        void append(T item) {
            if (listHead==nullptr) {
                if(freeHead==nullptr) {                 //if free list is also empty
                    x = new node;                       //allocate space for a new node
                    listHead=x; listHead->data=item;
                    listTail=listHead;    listSize++;              //head and tail get the new node
                }
                else {
                    x = freeHead; x->data = item;                          //use x to get pointer to next available free node; initialize new nodes fields.
                    freeHead = freeHead->next; freeSize--;              //remove node from free list
                    listHead->next = x; listTail=listHead; listTail->next=nullptr; listSize++;      //connect node to data storing list
                }
            }
            else {
                if(freeHead==nullptr) {                                          //if data list isn't empty but free is..
                    x = new node;                                                //allocate space for a new node
                    listTail->next=x; listTail=listTail->next;                   //tail gets the new node
                    listTail->data=item;   listSize++;
                }
                else {
                    x = freeHead; x->data = item;                          //neither data list nor free list are empty..
                    freeHead = freeHead->next; freeSize--;              
                    listTail->next = x; listTail=listTail->next; listSize++; 
                }
            }
        }
        
        int getFreeSize() {
            return freeSize;
        }
        
        void printList() {
            x=listHead;
            while(x!=nullptr) {
                std::cout << x->data << std::endl;
                x=x->next;
            }
        }

        T popBack() {

            T retval = listTail->data;
            
            x=listTail;
            listHead=listHead->next; 
            x->next=freeHead;
            freeHead=x;
            
            return retval;

        }

        T popFront() {
            T retval=listHead->data;
            
            x=listHead;
            listHead=listHead->next; 
            x->next=freeHead;
            freeHead=x;
            
            return retval;
        }
        
        
        
        
    T replace( const T& element, int position ) {
        if(position < 0 || position >= listSize) {
            std::cout << "enter valid position" << std::endl;
        }
        else if(this->is_empty()) {
            std::cout << "No item to replace" << std::endl;
            this->push_front(element);
        }
        else {
            
            link x = listHead;
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
        else if(position==listSize) {
            if(listSize==0) {
                listHead=new node();
                listHead->data=element;
                listTail=listHead;
                listSize++;
                return;
            }
            else {
                listTail->next=new node();
                listTail=listTail->next;
                listTail->data=element;
                listSize++;
                return;
            }
        }
        else {
            link x=listHead;
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
        if (listHead==nullptr) {
                if(freeHead==nullptr) {                 //if free list is also empty
                    x = new node;                       //allocate space for a new node
                    listHead=x; listHead->data=element;
                    listTail=listHead;    listSize++;              //head and tail get the new node
                }
                else {
                    x = freeHead; x->data = element;                          //use x to get pointer to next available free node; initialize new nodes fields.
                    freeHead = freeHead->next; freeSize--;              //remove node from free list
                    x->next=listHead; listHead=x; listTail=listHead; listTail->next=nullptr; listSize++;      //connect node to data storing list
                }
            }
            else {
                if(freeHead==nullptr) {                                          //if data list isn't empty but free is..
                    x = new node;                                                //allocate space for a new node
                    x->data=element; x->next=listHead;                   //tail gets the new node
                    listHead=x;   listSize++;
                }
                else {
                    x = freeHead; x->data = element;                          //neither data list nor free list are empty..
                    freeHead = freeHead->next; freeSize--;              
                    x->next=listHead;                   //tail gets the new node
                    listHead=x;   listSize++;
                }
            }
    }
    
    //prepends the specified element to the list.
    
    void push_back( const T& element ) {
      /*  if (listHead==nullptr) {
                if(freeHead==nullptr) {                 //if free list is also empty
                    x = new node;                       //allocate space for a new node
                    listHead=x; listHead->data=element;
                    listTail=listHead;    listSize++;              //head and tail get the new node
                }
                else {
                    x = freeHead; x->data = element;                          //use x to get pointer to next available free node; initialize new nodes fields.
                    freeHead = freeHead->next; freeSize--;              //remove node from free list
                    listHead->next = x; listTail=listHead; listTail->next=nullptr; listSize++;      //connect node to data storing list
                }
            }
            else {
                if(freeHead==nullptr) {                                          //if data list isn't empty but free is..
                    x = new node;                                                //allocate space for a new node
                    listTail->next=x; listTail=listTail->next;                   //tail gets the new node
                    listTail->data=element;   listSize++;
                }
                else {
                    x = freeHead; x->data = element;                          //neither data list nor free list are empty..
                    freeHead = freeHead->next; freeSize--;              
                    listTail->next = x; listTail=listTail->next; listSize++; 
                }
            }*/
        
        this->insert(element, listSize);
        
    }
    
    //appends the specified element to the list.
    
    T pop_front() {
        T retval;
        x = listHead;
        listHead=listHead->next;
        retval = x->data;
        x->next=freeHead; freeHead=x; listSize--; freeSize++;
        return retval;
    }

    //removes and returns the element at the list's head.
    
    T pop_back() {
        // try {
            if(listHead == nullptr) {
                std::cout << "Empty list!" << std::endl;
            }
            else {
            x=listHead;
            while(x->next!=listTail) {
                x=x->next;
            }
             T retval=x->next->data;                   //x is now the element before the tail element. EXCEPTION
             x->next=nullptr; listSize--;
             listTail->next=freeHead; freeHead=listTail;    //appending node being popped to free list. It is now freeHead.
             listTail=x; freeSize++;
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
                link x=listHead;
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
                return listHead->data;
            }
            else {
                std::cout << "Cannot be done, list is empty or position < 0" << std::endl;
            }
        }
        else if(position >= listSize) {
            std::cout << "position too large, not going to work." << std::endl;     //index out of bounds exception
            return 0;
        }
        else {
            link y=listHead;
            int count=0;
            while((count)!=position) {
                y=y->next;
                count++;
            }
            T retval = y->data;
            return retval;
        }
    }

    //returns (without removing from the list) the element at the specified position.
    
    bool is_empty() const {
        if (listSize==0) {
            return true;
        }
        else {
            return false;
        }
    }

    //returns true IFF the list contains no elements.
    
    int size() const {
        return listSize;
    }

    //returns the number of elements in the list.
    
    void clear() {
        if(this->is_empty()) {
            return;
        }
        else {
            link x = listHead;      //Grab head of list
            link y = listTail;      //Grab tail

            y->next = freeHead;     //append entire former list to free list, use existing links
            freeHead=x;             //freeHead is now former listHead

            freeSize+=listSize;     //free list increases by listSize
            listSize=0;
            listHead=nullptr;
            listTail=nullptr;       //list is now empty, nodes are stored for later use in free list
        }
    }

    //removes all elements from the list.
    
    PSLL& operator=( const PSLL& src ) {
        if ( &src == this ) // check for self-assignment
	return *this;     // do nothing
      
      else {
          //dispose of contents
            if(!this->is_empty()) {
                 this->clear();
            }
         // this->clear();
          
          //populate this SSLL
          int thisSize = 0;
          int srcSize=src.size();
          while(thisSize<srcSize) {
              this->push_back(src.item_at(thisSize));
              thisSize++;
          }
    }
 }
    
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
        link x = listHead;
        while(x!=nullptr) {
            out << x->data << " ";              //TODO override << operator for T?
            x=x->next;
    }
        return out;
    }
    
    //If the list is empty, inserts "<empty list>" into the ostream; otherwise, inserts, enclosed in square brackets, the list's elements, separated by commas, in sequential order.
        
        
};
}

#endif	/* PSLL_H */
