/* 
 * File:   CDAL.h
 * Author: Ben
 *
 * Created on September 26, 2014, 11:58 PM
 */

#ifndef CDAL_H
#define	CDAL_H

#include<iostream>
#include<stdexcept>

namespace cop3530 {
 
template<typename T>
class CDAL {
    
    
    //===========================================================
    // DEFINE SMART NODE   DEFINE SMART NODE   DEFINE SMART NODE
    //===========================================================
    
        struct node {
                    
                    T* data;
                    int nodeListSize;
                    node* next;

                    node() : data(new T[50]), nodeListSize(0), next(nullptr) {}
                  /*  ~node() {
                        delete [] data;
                    }*/

                    bool is_empty() {
                        if (nodeListSize==0) {
                            return true;
                        }
                        else {
                            return false;
                        }
                    }

                    void shiftRight(int index) {            //dumb right shift. Will overwrite values and lose final value if you're not careful.

                        T temp1, temp2;
                        temp2=0;
                        temp1=data[index];
                        int i=index;
                         while(i<(nodeListSize+1)) {
                             data[i]=temp2;
                             temp2=temp1;
                             temp1=data[i+1]; i++;
                         }

                    }

                    void shiftLeft(int index) {
                        int i=index;
                         while(i<(nodeListSize+1)) {
                             data[i]=data[i+1];
                             i++;
                         }
                    }

                    void insert(T item, int position) {
                        if(nodeListSize==50) {                                       //inserting on full list
                            if(next==nullptr) {                             //if there's no next node..
                                node* temp=new node();        
                                this->next=temp;                            //make a new one and call insert on it with the last element
                                T pushOver = data[49];
                           //Remember, position MUST be <=4 because of selective insertion in list method.
                                next->insert(pushOver, 0);
                                this->shiftRight(position);         
                                data[position]=item;                       //shift all elements to make room for the inserted element.
                            }
                            else {
                                T pushOver = data[49];
                                next->insert(pushOver, 0);
                                this->shiftRight(position);
                                data[position]=item;
                            }
                        }
                        else if(position == nodeListSize) {
                            data[position]=item; nodeListSize++;
                        }
                        else {
                            //next->insert(data[49], 0);
                            this->shiftRight(position);
                            data[position]=item; nodeListSize++;
                        }
                    }

                    T replace(const T& element, int position) {
                        T retval;
                        
                        retval = data[position];
                        data[position]=element;
                        
                        return retval;
                    }
                    
                    T remove(int index) {
                        T retval;
                            if(nodeListSize==50) {
                                if(next==nullptr) {
                                    retval = data[index];
                                    this->shiftLeft(index);
                                    nodeListSize--;
                                }
                                else {
                                    retval = data[index];
                                    int temp = next->remove(0);
                                    this->shiftLeft(index);
                                    this->data[49]=temp;
                                }
                            }
                            else {
                                retval = data[index];
                                this->shiftLeft(index);
                                nodeListSize--;
                            }
                        return retval;
                    }

                    void printFields() {
                        std::cout << *data << std::endl;
                        std::cout << nodeListSize << std::endl;
                        std::cout << *next << std::endl;
                    }

                    std::ostream& print( std::ostream& out ) const {
                        for(int i=0; i<nodeListSize; i++) {
                            out << data[i] << " ";
                        }
                    }
                    
                   void printlist() {
                        for(int i=0; i<nodeListSize; i++) {
                            std::cout << data[i] << " ";
                        }
                    }
                   
                   T item_at(int i) {
                       return data[i];
                   }
                   
             };
             
             
    node* head;
    node* tail;
    int totalSize;
    int numberOfNodes;
    
    
  void appendNode() {
        
       if(this->is_empty()) {
            head = new node();
            tail=head;
            numberOfNodes++;
        }
       else {
             tail->next=new node();
             tail=tail->next;
             numberOfNodes++;
         }
         
    }
    
    node* getNodeContaining(int index) {                //returns a node pointer to the node containing the index
        
        node* temp=head;
        int nodeToInsertOn = index/50;
        int counter=0;
        
            while(counter!=nodeToInsertOn) {
                temp=temp->next;
                counter++;
            }
        
        return temp;
    }
    
    node* getNodeContainingConstVersion(int index) const {                //returns a node pointer to the node containing the index
        
        node* temp=head;
        int nodeToInsertOn = index/50;
        int counter=0;
        
            while(counter!=nodeToInsertOn) {
                temp=temp->next;
                counter++;
            }
        
        return temp;
    }
    
    bool shouldAddToNodeCount() {
        if (totalSize%50==1) {
            return true;
        }
        else {
            return false;
        }
    }
             
    
                            //============================================================
        public:             // BEGINNING OF PUBLIC MEMBERS    BEGINNING OF PUBLIC MEMBERS
                            //============================================================
            
            
            
            //====================================================
            //   CONSTRUCTORS    CONSTRUCTORS     CONSTRUCTORS
            //====================================================
            
            
      CDAL() : head(nullptr), tail(nullptr), numberOfNodes(0), totalSize(0) {}
        
      ~CDAL() {
          
         /* node* temp=head;
          
          while(temp!=nullptr) {
              head=temp->next;
              delete [] temp;
              temp=head;
          }*/
      }
        
      CDAL(const CDAL& src) {
          head = nullptr;
          tail=nullptr;
          numberOfNodes=0;
          totalSize=0;
          int sz = src.size();
          for(int i=0; i<sz; i++) {
              this->push_back(src.item_at(i));
          }
      }
      
      
      //=========================================================================
      // NON CONST ITERATOR       NON CONST ITERATOR         NON CONST ITERATOR
      //=========================================================================
      
       class CDAL_Iter { //: public std::iterator<std::forward_iterator_tag, T>
            
            public:
              // inheriting from std::iterator<std::forward_iterator_tag, T>
              // automagically sets up these typedefs...
              typedef T value_type;
              typedef std::ptrdiff_t difference_type;
              typedef T& reference;
              typedef T* pointer;
              typedef std::forward_iterator_tag iterator_category;

              // but not these typedefs...
              typedef CDAL_Iter self_type;
              typedef CDAL_Iter& self_reference;

            private:
              node* here;
              int index;

            public:
              explicit CDAL_Iter( node* start) : here( start ), index(0) {}
              CDAL_Iter( const CDAL_Iter& src ) : here( src.here ), index(src.index) {}
              explicit CDAL_Iter( node* start, int ind) : here( start ), index(ind) {}
              
              reference operator*() const {
                  if(index>(here->nodeListSize+1)) {
                      throw std::out_of_range("The requested index does not exist in the list.");
                  }
                  else {
                      return here->data[index];
                  }
              }
              
              pointer operator->() const {
                  return here;
              }

              self_reference operator=( const CDAL_Iter& src ) {
                   here=src.here;
                   index=src.index;
              }

              self_reference operator++() {     //pre-increment
                    
                      if((here->next == nullptr) && (index == (here->nodeListSize-1))) {
                          throw std::out_of_range("You're already at the end of the list.");
                      }
                      else {
                          if(index==49) {
                              index=0;
                              here=here->next;
                              return *this;
                          }
                          else {
                              index++;
                              return *this;
                          }
                      }
              }
              
              self_type operator++(int) {       // post-increment
                  
                      if((here->next == nullptr) && (index == (here->nodeListSize-1))) {
                          throw std::out_of_range("You're already at the end of the list.");
                      }
                      else {
                         node* temp = here;
                         here=here->next;           //TODO
                         return *temp;
                      }
              }

              bool operator==(const CDAL_Iter& rhs) const {
                  
                  return ((this->here == rhs.here) && (index == rhs.index));
                  
              }
              
              bool operator!=(const CDAL_Iter& rhs) const {
                 
                  return ((this->here!=rhs.here) && (this->index != rhs.index));
                  
              }
     };
      
     
     
     //=========================================================================
     //  CONST ITERATOR        CONST ITERATOR          CONST ITERATOR
     //=========================================================================
      
       class CDAL_Const_Iter { //: public std::iterator<std::forward_iterator_tag, T>
            
            public:
              // inheriting from std::iterator<std::forward_iterator_tag, T>
              // automagically sets up these typedefs...
              typedef T value_type;
              typedef std::ptrdiff_t difference_type;
              typedef T& reference;
              typedef T* pointer;
              typedef std::forward_iterator_tag iterator_category;

              // but not these typedefs...
              typedef CDAL_Const_Iter self_type;
              typedef CDAL_Const_Iter& self_reference;

            private:
              node* here;
              int index;

            public:
              explicit CDAL_Const_Iter( node* start) : here( start ), index(0) {}
              explicit CDAL_Const_Iter( node* start, int ind) : here( start ), index(ind) {}
              CDAL_Const_Iter( const CDAL_Const_Iter& src ) : here( src.here ) {}
              
              reference operator*() const {
                  return here->data;
              }
              pointer operator->() const {
                  return here;
              }

              self_reference operator=( const CDAL_Const_Iter& src ) {
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

              bool operator==(const CDAL_Const_Iter& rhs) const {
                  
                  return (this->here == rhs.here);
                  
              }
              
              bool operator!=(const CDAL_Const_Iter& rhs) const {
                 
                  return (here!=rhs.here);
                  
              }
     };
     
     
     
        
     
     CDAL_Iter begin() {
         return CDAL_Iter(head, 0);
     }
       
     CDAL_Const_Iter begin() const {
         return CDAL_Const_Iter(head, 0);
     }
     
     CDAL_Iter end() {
         return CDAL_Iter(tail, (tail->nodeListSize-1));
     }
       
     CDAL_Const_Iter end() const {
         return CDAL_Const_Iter(tail, (tail->nodeListSize-1));
     }
        
    T replace( const T& element, int position ) {
    
        node* nodeToInsert = this->getNodeContaining(position);
        T retval = nodeToInsert->replace(element, position%50);
        
        return retval;
    }

    //replaces the existing element at the specified position with the specified element and returns the original element.
        
        
    void insert( const T& element, int position ) {
        try {
            if ((position>totalSize) || (position<0)) {
                throw std::invalid_argument("Position to insert on must be >=0 and < list size.");
            }
            if(this->is_empty()) {
                this->appendNode();
                head->insert(element, 0);
                totalSize++;
            }
            else if((position==totalSize) && ((position%50)==0)) {
                this->appendNode();
                node* insertOn=this->getNodeContaining(position);
                insertOn->insert(element, position%50);
                totalSize++;
            }
            else {
                node* insertOn=this->getNodeContaining(position);
                insertOn->insert(element, position%50);
                totalSize++;
                if(this->shouldAddToNodeCount()) {
                    numberOfNodes++;
                }
            }
        
        } catch(std::invalid_argument a) {
            std::cout << a.what() << std::endl;
        }
        
    }
    
    //adds the specified element to the list at the specified position, shifting the element originally at that and those in subsequent positions one position to the ”right.“
    
    void push_front( const T& element ) {
            this->insert(element, 0);
    }
    
    //prepends the specified element to the list.
    
    void push_back( const T& element ) {
        this->insert(element, totalSize);
    }
    
    //appends the specified element to the list.
    
   T pop_front() {
       T retval=this->item_at(0);
       this->remove(0);
       return retval;
    }

    //removes and returns the element at the list's head.
    
   T pop_back() {
      // T retval=this->item_at(totalSize);
       T retval=this->remove(totalSize-1);
       return retval;
    }

    //removes and returns the element at the list's tail.
    
   T remove( int position ) {
       T retval;
            if(position < 0) {
                  throw std::invalid_argument("A valid item_at(index) index is between 0 and list size, inclusive.");
              }
              else if(position >= totalSize) {
                  throw std::out_of_range("Element index must be in [0,listSize] range, inclusive.");
              }
              else {
                node* nodeToRemoveFrom=this->getNodeContaining(position);
                retval = nodeToRemoveFrom->remove(position%50);
                totalSize--;
              }
       return retval;
    }

    //removes and returns the the element at the specified position, shifting the subsequent elements one position to the ”left.“
    
 T item_at( int position ) const {
       
     try {
         if(position < 0) {
             throw std::invalid_argument("A valid item_at(index) index is between 0 and list size, inclusive.");
         }
         else if(position >= totalSize) {
             throw std::out_of_range("Element index must be in [0,listSize] range, inclusive.");
         }
         else {  
              int index=position%50;
              node* theNode = this->getNodeContainingConstVersion(position);
              T retval=theNode->item_at(index);
              return retval;
            }
        } catch(std::invalid_argument a) {
            std::cerr << "invalid argument error: " << a.what() << std::endl;
        } catch(std::out_of_range o) {
            std::cerr << "Out of range error: " << o.what() << std::endl;
        }
       
    }

    //returns (without removing from the list) the element at the specified position.
    
    bool is_empty() const {
        if(head == nullptr) {
            return true;
        }
        else {
            return false;
        }
    }

    //returns true IFF the list contains no elements.
    
    int size() const {return totalSize;}

    //returns the number of elements in the list.
    
   void clear() {
       
       node* temp=head;
          
          while(temp!=nullptr) {
              head=temp->next;
              delete [] temp;
              temp=head;
          }
       head=nullptr; tail=nullptr;
       totalSize=0; numberOfNodes=0;
    }    

    //removes all elements from the list.
    
   bool contains( const T& element, bool equals( const T& a, const T& b  ) ) const {
       bool retval=false;
       for(int i=0; i<totalSize; i++) {
           if(equals(this->item_at(i), element)) {
               retval=true;
           }
       }
       return retval;
    }

    //returns true IFF one of the elements of the list matches the specified element.
    
    std::ostream& print( std::ostream& out ) const {
        node* temp=head;
        
        for(int i=0; i<(numberOfNodes-1); i++) {
            for(int j=0; j<50;j++) {
                out << temp->item_at(j) << " ";
            }
            temp=temp->next;
        }
        
        int finalSize=temp->nodeListSize;
        
        for(int k=0; k<finalSize; k++) {
            out << temp->item_at(k) << " ";
        }
            
        return out;
    }
    
    //If the list is empty, inserts "<empty list>" into the ostream; otherwise, inserts, enclosed in square brackets, the list's elements, separated by commas, in sequential order.
        
        
};
}


#endif	/* CDAL_H */

