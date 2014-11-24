/* 
 * File:   SDAL.h
 * Author: Ben
 *
 * Created on September 24, 2014, 9:16 AM
 */

#ifndef SDAL_H
#define	SDAL_H

#include<iostream>
#include<ostream>
#include<stdexcept>
#include<iterator>


namespace cop3530 {
    template<typename T>
    class SDAL {

       // typedef int size_t;
        
        double listSize;
        double arraySize;
        T* head;
        T* data;

        void makeBigger(int n) {                             //creates new backing array 1.5 times bigger, copies elements over, deletes old array 
            //int newArraySize = (arraySize*1.5);         //TESTED AND WORKS
            T *newData = new T[n];

            for(int i=0; i<listSize; i++) {
                newData[i]=data[i];
            }

            delete [] data;
            data=newData;
            arraySize=n;
        }

        void makeSmaller(int n) {
           // int newArraySize=(arraySize/2);
            T *newData = new T[n];
            for(int i=0; i<listSize; i++) {
                newData[i]=data[i];
            }
            delete [] data;
            data=newData;
            arraySize=n;
        }

        void shiftRight(int startPosition) {
            T temp1, temp2;
            temp1=data[startPosition];
            
            if(startPosition == (listSize)) {
                listSize++;
                return;
            }

                 for(int i=(startPosition); i<=listSize; ++i) {
                     //temp1 = data[startPosition];
                     temp2=temp1;
                      temp1=data[i];
                      data[i]=temp2;
                 }
            listSize++;
        }

        void shiftLeft(int startPosition) {     
                 for(int i=(startPosition-1); i<listSize; i++) {
                      data[i]=data[i+1];
                 }
            listSize--;
        }

        public:

           //=======================================================================
           //        NON CONST DYNAMIC ARRAY ITER   NON CONST DYNAMIC ARRAY ITER
           //=======================================================================


            class SDAL_Iter { //: public std::iterator<std::forward_iterator_tag, T>

                public:
                  // inheriting from std::iterator<std::forward_iterator_tag, T>
                  // automagically sets up these typedefs...
                  typedef T value_type;
                  typedef std::ptrdiff_t difference_type;
                  typedef T& reference;
                  typedef T* pointer;
                  typedef std::forward_iterator_tag iterator_category;

                  // but not these typedefs...
                  typedef SDAL_Iter self_type;
                  typedef SDAL_Iter& self_reference;

                private:
                  int here;

                public:
                  explicit SDAL_Iter( int start) : here( start ) {}
                  SDAL_Iter( const SDAL_Iter& src ) : here( src.here ) {}

                  reference operator*() const {
                      return data[here];
                  }
                  pointer operator->() const {
                      return here;
                  }

                  self_reference operator=( const SDAL_Iter& src ) {
                       here=src.here;
                  }

                  self_reference operator++() {     //pre-increment
                      if(here == &data[listSize-1]) {
                          throw std::out_of_range("Cannot increment, you are at the end of the dynamic array.");
                      }
                      else {
                        here++;
                        return *this;
                      }
                  }

                  self_reference operator++(int) {       // post-increment
                       if(here == &data[listSize-1]) {
                          throw std::out_of_range("Cannot increment, you are at the end of the dynamic array.");
                      }
                      else {
                          SDAL_Iter* temp = new SDAL_Iter(*this);
                          here++;
                          return *temp;
                      } 
                  }

                  bool operator==(const SDAL_Iter& rhs) const {
                      return (this->here==rhs.here);
                  }

                  bool operator!=(const SDAL_Iter& rhs) const {
                     return (this->here!=rhs.here);
                  }
         };


         //=======================================================================
         //       CONST DYNAMIC ARRAY ITER      CONST DYNAMIC ARRAY ITER
         //=======================================================================



         class SDAL_Const_Iter { //: public std::iterator<std::forward_iterator_tag, T>

                public:
                  // inheriting from std::iterator<std::forward_iterator_tag, T>
                  // automagically sets up these typedefs...
                  typedef T value_type;
                  typedef std::ptrdiff_t difference_type;
                  typedef T& reference;
                  typedef T* pointer;
                  typedef std::forward_iterator_tag iterator_category;

                  // but not these typedefs...
                  typedef SDAL_Const_Iter self_type;
                  typedef SDAL_Const_Iter& self_reference;

                private:
                  const T* here;

                public:
                  explicit SDAL_Const_Iter( T* start) : here( start ) {}
                  SDAL_Const_Iter( const SDAL_Const_Iter& src ) : here( src.here ) {}

                  reference operator*() const {
                      return *here;
                  }
                  pointer operator->() const {
                      return here;
                  }

                  self_reference operator=( const SDAL_Const_Iter& src ) {
                       here=src;
                  }

                  self_reference operator++() {     //pre-increment
                      if(here == &data[listSize-1]) {
                          throw std::out_of_range("Cannot increment, you are at the end of the list.");
                      }
                      here++;
                      return *this;
                  }

                  self_reference operator++(int) {       // post-increment
                      if(here == &data[listSize-1]) {
                          throw std::out_of_range("Cannot increment, you are at the end of the dynamic array.");
                      }
                      else {
                          SDAL_Const_Iter* temp = new SDAL_Const_Iter(*this);
                          here++;
                          return *temp;
                      }
                  }

                  bool operator==(const SDAL_Const_Iter& rhs) const {
                      return (this->here==rhs.here);
                  }

                  bool operator!=(const SDAL_Const_Iter& rhs) const {
                      return (this->here!=rhs.here);
                  }
         };

         
         
            typedef T value_type;
            typedef std::size_t size_t;
            typedef SDAL_Iter iterator;
            typedef SDAL_Const_Iter const_iterator;
            

            SDAL() {
                listSize=0;
                data = new T[50];
                head=&data[0];
                arraySize=50;
            }

            SDAL(int n) {
                listSize=0;
                data = new T[n];
                head=&data[0];
                arraySize=n;
            }

            ~SDAL() {
               // delete [] data;
                head=nullptr;
            }

            SDAL(const SDAL& src) {
                data=new T[src.size()];
                listSize=0; arraySize=src.size();
                for(int i=0; i<src.size(); i++) {
                    data[i]=src.item_at(i);                     //HELP
                }
                listSize=src.size();
            }

            SDAL& operator=(const SDAL& src) {
                if(src.getArraySize()>arraySize) {
                    this->makeBigger(src.getArraySize());
                }
                else if(src.getArraySize()<arraySize) {
                    this->makeSmaller(src.getArraySize());
                }
                for(int i=0; i<src.size(); i++) {
                    data[i]=src.item_at(i);
                    listSize++;
                }
            }

            SDAL_Iter begin() {
                return SDAL_Iter(0);
            }

             SDAL_Iter end() {
                // T* arg = head;
                /* for(int i=0; i<listSize-1;i++) {
                     arg++;
                 }*/
                return SDAL_Iter(this->listSize-1);
            }

             SDAL_Const_Iter begin() const {
                return SDAL_Const_Iter(0);
            }

             SDAL_Const_Iter end() const {
                // T* arg = head;
                /* for(int i=0; i<listSize-1;i++) {
                     arg++;
                 }*/
                return SDAL_Const_Iter(this->listSize-1);
            }

             
            /*T& operator[](int i) { 
            //— returns a reference to the indexed element
            }
    
            T const& operator[](int i) const { 
             //— returns an immutable reference to the indexed element
       
             }*/
             
             
            int getArraySize() const {
                return arraySize;
            }

            void getFields() {
                std::cout << "Head is: " << *head << std::endl;
             //   std::cout << "Tail is: " << *tail << std::endl;
                std::cout << "listSize is: " << listSize << std::endl;
                std::cout << "arraySize is: " << arraySize << std::endl;
            }

            T replace( T item, int position ) {
                
              if(this->is_empty()) {
                    throw std::out_of_range("This is an empty SDAL");
                }
              else if(position < 0) {
                    throw std::invalid_argument("Valid arguments must be in the range [0,list size-1]");
                }
              else if(position >= listSize) {
                    throw std::out_of_range("A valid index must be < list size");
                }
              else {
                T retval = this->item_at(position);
                data[position] = item;
                return retval;
              }
            }                    //just remove then insert, right?

            void insert( T element, int position ) {  
                        if(position < 0) {
                            throw std::invalid_argument("Valid arguments must be in the range [0,list size-1]");
                        }
                        else if(position > listSize) {
                            throw std::out_of_range("A valid index must be < list size");
                        }
                       else if(listSize==arraySize) {                  //check if we need to make bigger.
                           this->makeBigger(arraySize*1.5);
                           this->shiftRight(position);  //shiftRight will increase listSize; don't worry about it
                           data[position]=element;
                       }
                       else {
                           if(listSize==0) {
                               data[0]=element;
                               listSize++;
                           }
                           else {
                               this->shiftRight(position);
                               data[position]=element;
                           }
                    }

            }

            void push_back(T item) {
                this->insert(item, listSize);
            }

           void push_front(T item) {
                this->insert(item, 0);
            }

           T remove(int position) {
               T retval;
                    if(this->is_empty()) {
                        throw std::out_of_range("This is an empty SDAL");
                    }
                    else if(position < 0) {
                        throw std::invalid_argument("Valid arguments must be in the range [0,list size-1]");
                    }
                    else if(position >= listSize) {
                        throw std::out_of_range("A valid index must be < list size");
                    }
                    else {
                        retval=data[position];
                        this->shiftLeft(position+1);
                        if((arraySize >= 100) && (listSize < (arraySize/2))) {
                            this->makeSmaller(arraySize/2);
                        }
                    }
               return retval;
            }

           T pop_back() {
               if(this->is_empty()) {
                    throw std::length_error("This is an empty SDAL");
                }
               return this->remove(listSize-1);
               //listSize--;
           }

           T pop_front() {
               if(this->is_empty()) {
                    throw std::length_error("This is an empty SDAL");
                }
               return this->remove(0);
           }

            T item_at(int position) const {
                if(listSize==0) {
                      throw std::out_of_range("This is an empty SDAL");
                  }
                if(position < 0) {
                      throw std::invalid_argument("Valid arguments must be in the range [0,list size-1]");
                  }
                else if(position >= listSize) {
                      throw std::out_of_range("A valid index must be < list size");
                  }
                else {
                    int tempInt = data[position];
                    return tempInt;
                }
            }

           bool is_empty() {
                bool retval;
                if (listSize==0) {
                    retval=true;
                }
                else{
                    retval=false;
                }
                return retval;
            }

           size_t size() const {
                return (size_t) listSize;
            }
        
           void clear() {
               listSize=0;
               delete [] data;
               data = new T[50];
               arraySize=50;
           }

           bool contains( const T& element, bool equals( const T& a, const T& b  ) ) const {
               bool retval=false;
               for(int i=0;i<listSize;i++) {
                   if(equals(element, data[i])) {
                       retval=true;
                   }
               }
               return retval;
            }

            std::ostream& print(std::ostream& out) {
                if(this->is_empty()) {
                    out << "<empty list>";
                    return out;
                }
                else {
                    int i=0;
                        while(i<listSize) {
                            out << data[i] << " ";
                            i++;
                        }
                return out;
                }
                
            }
    };
}
#endif	/* SDAL_H */

