
#define CATCH_CONFIG_MAIN
#include "catch.h"
#include "SSLL.h"
#include <string>

using namespace cop3530;

static SSLL<int> StaticList;


TEST_CASE( "Testing the default constructor, is_empty (SSLL)", "[SSLL(), is_empty()]" ) {

    SSLL<char> List2;
        REQUIRE(List2.size() == 0);
        REQUIRE(List2.is_empty() == true);
}


TEST_CASE( "Testing the push_back function and verifying with item_at function (SSLL)", "[push_back, item_at]" ) {

    SSLL<int> List;
	
    List.push_back(5);
    List.push_back(3);
    List.push_back(1);
    List.push_back(11);
    List.push_back(15);
    
        REQUIRE( List.item_at(1) == 3 );
        REQUIRE( List.item_at(3) == 11 );
        REQUIRE( List.item_at(0) == 5 );
        REQUIRE( List.item_at(2) == 1 );
        REQUIRE( List.item_at(4) == 15 );
}


TEST_CASE( "Testing copy constructor, item_at() (SSLL)", "[SSLL(SSLL), item_at(n)]" ) {

    SSLL<int> List1;
    
    List1.push_back(7);
    List1.push_back(9);
    List1.push_back(11);
    List1.push_back(13);
    List1.push_back(15);
    List1.push_back(17);
    List1.push_back(19);
  

        REQUIRE(List1.item_at(1)==9);

    SSLL<int> List2(List1);
    int n=List1.size();

        REQUIRE(List2.size()==n);

        for(int i=0; i<n; i++) {
            REQUIRE(List1.item_at(i)==List2.item_at(i));
        }

}

TEST_CASE( "Testing the operator=() and item_at() (SSLL)", "[operator=(), item_at()]" ) {

    SSLL<int> List1;
    
    for(int i=0; i<151; i++) {
        List1.push_back(i);
    }
   
    REQUIRE(List1.item_at(3)==3);
    REQUIRE(List1.item_at(31)==31);
    REQUIRE(List1.item_at(111)==111);
    
    StaticList = List1;
    
    REQUIRE(StaticList.item_at(3)==3);
    REQUIRE(StaticList.item_at(31)==31);
    REQUIRE(StaticList.item_at(111)==111);
    
    StaticList.clear();

}

TEST_CASE("Testing the replace() function", "[replace(), size(), clear()]") {
    
    for(int i=0; i<231; i++) {
        StaticList.push_back(i+1);
    }
    
        REQUIRE(StaticList.item_at(200) == 201);
        REQUIRE(StaticList.size() == 231);
    
    int retval = StaticList.replace(45, 200);
    
        REQUIRE(retval == 201);
        REQUIRE(StaticList.item_at(200) == 45);
    
    StaticList.clear();
    
        REQUIRE(StaticList.size() == 0);
    
}

TEST_CASE("Testing the insert function by inserting 1 at index 200", "[insert()]") {
    
    for(int i=0; i<12; i++) {
        StaticList.push_back(i+1);
    }
    
    StaticList.insert(1, 8);
    
    REQUIRE(StaticList.item_at(0) == 1);
    REQUIRE(StaticList.item_at(8) == 1);
    REQUIRE(StaticList.item_at(9) == 9);
    
    StaticList.clear();
    
}

TEST_CASE("Testing the push_front function, item_at(0) should == 12", "[push_front()]") {
    
     for(int i=0; i<12; i++) {
        StaticList.push_front(i+1);
    }
     
     for(int i=0; i<12; i++) {
         REQUIRE(StaticList.item_at(i) == (12-i));
     }
     
     StaticList.clear();
    
}

TEST_CASE("Testing remove", "[remove()]") {
    
    for(int i=0; i<160; i++) {
        StaticList.push_back(i);
    }
    
    int retval = StaticList.remove(13);
    
    for(int i=0; i<13; i++) {
        REQUIRE(StaticList.item_at(i) == i);
    }
    
    for(int i=13; i<159; i++) {
        REQUIRE(StaticList.item_at(i) == (i+1));
    }
    
    REQUIRE(retval == 13);
    REQUIRE(StaticList.item_at(13) == 14);
    
     StaticList.clear();
}

TEST_CASE("Testing pop_back() and pop_front()", "[pop_back, pop_front]") {
    
    for(int i=0; i<160; i++) {
        StaticList.push_back(i);
    }
    
    int retval_back1 = StaticList.pop_back();
    int retval_front1 = StaticList.pop_front();
    int retval_back2 = StaticList.pop_back();
    int retval_front2 = StaticList.pop_front();
    
    REQUIRE(retval_back1 == 159);
    REQUIRE(retval_back2 == 158);
    
    REQUIRE(retval_front1 == 0);
    REQUIRE(retval_front2 == 1);
    
    for(int i=0; i<155; i++) {
        REQUIRE(StaticList.item_at(i) == (i+2));
    }
    
    StaticList.clear();
    
}

TEST_CASE("Testing the assignment operator", "[operator=]") {
    
    for(int i=0; i<161; i++) {
        StaticList.push_back(i);
    }
    
    SSLL<int> List2=StaticList;
    
    REQUIRE(List2.item_at(100)==100);
    REQUIRE(List2.item_at(77)==77);
    
    StaticList.clear();
    
}

/*bool equals(int a, int b) {
        if(a==b) {
            return true;
        }
        else {
            return false;
        }
    }*/

bool ints_equal( const int& a, const int& b) { //argument for contains()
        return (a == b);
}
 
bool in_list( SSLL<int>& list, int c ) {
  return list.contains( c, ints_equal );
}

TEST_CASE("Testing the contains method", "[contains]") {
    
    for(int i=0; i<16; i++) {
        StaticList.push_back(i);
    }
    
    bool retval1=in_list(StaticList, 14);
    bool retval2=in_list(StaticList, 8000);
    
    REQUIRE( retval1 == true);
    REQUIRE( retval2 == false);
    
    
    StaticList.clear();
}

TEST_CASE("Testing the print() function", "[print()]") {
    
    for(int i=0; i< 161; i++) {
        StaticList.push_back(i);
    }
    
    std::ostream& o = std::cout;
    
    o << "{";
        for(int i=0; i<161; i++) {
            o << StaticList.item_at(i) << ", ";
        } 
    o << "}";
    
    std::ostream& retval = StaticList.print(std::cout);
    
    /*std::string str1 = o.str();
    std::string str2 = retval.str();
    */
    
    REQUIRE(o == retval);
    
    //StaticList.print(std::cout) << std::endl;
    
}



        //==============================================================
        //ITERATOR TESTING      ITERATOR TESTING        ITERATOR TESTING
        //==============================================================


TEST_CASE("Constructs an SSLL list, destructs it, checks the size and head/tail before and after", "[]") {
    
    SSLL<int>* test = new SSLL<int>;
    
   for(int i=0; i<231; i++) {
        test->push_back(i+1);
    }
   
   REQUIRE(test->size() == 231);
   delete test;
    
}

TEST_CASE("Constructs a SSLL list, Creates iterators using begin()", "[SSLL::SSLL(),  SSLL::SSLL_Iter::SSLL_Iter(), SSLL::begin(), SSLL::SSLL_Iter::operator++() ]") {
    SSLL<int>* testList = new SSLL<int>();
    
    for(int i=0; i<211; i++) {
        testList->push_back(i);
    }
    
    SSLL<int>::iterator iter = testList->begin();
    
    REQUIRE(*iter == 0);
    for(int i=0; i<57; i++) {
        iter++;
    }
    REQUIRE(*iter == 57);
    
    delete testList;
}

TEST_CASE("Constructs a list, gets an iterator by begin(), increments one, gets another at different indices, then test the == and != operators on them", "[SSLL::SSLL(),  SSLL::SSLL_Iter::SSLL_Iter(), SSLL::begin(), SSLL::SSLL_Iter::operator++(), SSLL::SSLL_Iter::operator==(), SSLL::SSLL_Iter::operator!=()]") {
    /*test the rest of the operators, etc in here
     */
    SSLL<int> testList;
    
    for(int i=0; i<211; i++) {
        testList.push_back(i);
    }
    
    SSLL<int>::iterator iter = testList.begin();
    
    for(int i=0; i<111; i++) {
        ++iter;
    }
    
    REQUIRE(*iter == 111);
    SSLL<int>::iterator iter2 = testList.begin();
    REQUIRE((iter == iter2) == false);
    REQUIRE((iter != iter2) == true);
    
    
}


TEST_CASE("Constructs a CONST SSLL list, Creates const iterators using begin()", "[SSLL::SSLL(),  SSLL::SSLL_Const_Iter::SSLL_Const_Iter(), SSLL::begin(), SSLL::SSLL_Const_Iter::operator++() ]") {
    SSLL<int> testList;
    
    for(int i=0; i<211; i++) {
        testList.push_back(i);
    }
    
    const SSLL<int> constTestList(testList);
    
    SSLL<int>::const_iterator iter = constTestList.begin();
    
    REQUIRE(*iter == 0);
    for(int i=0; i<57; i++) {
        iter++;
    }
    REQUIRE(*iter == 57);
    
}


TEST_CASE("Constructs a CONST list, gets a const iterator by begin(), increments one, gets another at different indices, then test the == and != operators on them", "[SSLL::SSLL(),  SSLL::SSLL_Iter::SSLL_Iter(), SSLL::begin(), SSLL::SSLL_Iter::operator++(), SSLL::SSLL_Iter::operator==(), SSLL::SSLL_Iter::operator!=()]") {
    /*test the rest of the operators, etc in here
     */
    SSLL<int> testList;
    
    for(int i=0; i<211; i++) {
        testList.push_back(i);
    }
    
    const SSLL<int> constTestList(testList);
    
    SSLL<int>::const_iterator iter = constTestList.begin();
    
    for(int i=0; i<111; i++) {
        ++iter;
    }
    
    REQUIRE(*iter == 111);
    SSLL<int>::const_iterator iter2 = constTestList.begin();
    REQUIRE((iter == iter2) == false);
    REQUIRE((iter != iter2) == true);
    
}