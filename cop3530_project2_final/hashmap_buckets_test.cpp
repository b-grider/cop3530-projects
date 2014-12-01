
//#define CATCH_CONFIG_MAIN
#include "catch.h"
#include "hashmap_buckets.h"
#include<string>
#include<sstream>

using namespace cop3530;

static hashmap_buckets map1;

TEST_CASE( "Testing the hashmap_buckets::insert() function and verifying with the bool results and size function", "[insert(), size()]" ) {

    bool ins1 = map1.insert(3,'c');
    bool ins2 = map1.insert(4,'a');
    bool ins3 = map1.insert(5,'b');
    bool ins4 = map1.insert(6,'d');
    
    
    SECTION("verify inserts (buckets map)") {
        REQUIRE( ins1 );
        REQUIRE( ins2 );
        REQUIRE( ins3 );
        REQUIRE( ins4 );
    }
    
    
    SECTION("Check size, clear, then verify load ==0 and is_empty == true (buckets map)") {
        REQUIRE( map1.size() == 4); 
        
        map1.clear();
        
        REQUIRE(map1.load() == 0);
        REQUIRE(map1.is_empty() == true);
    }
}

/*TEST_CASE("doing a test print, clearing, testing size, then printing again", "[clear(), print(), size(), ]") {
   
    
    std::ostream &o = std::cout;
    
        for(int i=0; i<50; i++) {
            o << "-, ";
        }
    
    std::ostream &retval = map1.print(std::cout);
    
    std::ostringstream res(std::ostringstream::ate);
    std::ostringstream control(std::ostringstream::ate);
    retval << res;
    o << control;
    std::string left = res.str();
    std::string right = control.str();
    
    char * Lcstr = new char [left.length()+1];
    std::strcpy (Lcstr, left.c_str());
    char * Rcstr = new char [right.length()+1];
    std::strcpy (Rcstr, right.c_str());
    
    bool test = (strcmp(Lcstr, Rcstr) == 0);
    
    //REQUIRE(left.length() == 150);        TODO
    //REQUIRE(right.length() == 150);
    REQUIRE(test);
   
    map1.clear();
    REQUIRE(map1.size() == 0);
}*/

TEST_CASE("Testing insert to maximum capacity for (buckets map)", "[insert(), load(), ]") {
    bool ins1 = map1.insert(3,'a');
    bool ins2 = map1.insert(4,'b');
    bool ins3 = map1.insert(5,'c');
    bool ins4 = map1.insert(6,'d');
    bool ins5 = map1.insert(7,'e');
    bool ins6 = map1.insert(8,'f');
    bool ins7 = map1.insert(9,'g');
    bool ins8 = map1.insert(10,'h');
    bool ins9 = map1.insert(11,'i');
    bool ins10 = map1.insert(12,'j');
    bool ins11 = map1.insert(13,'k');
    bool ins12 = map1.insert(14,'l');
    bool ins13 = map1.insert(15,'m');
    bool ins14 = map1.insert(16,'n');
    bool ins15 = map1.insert(17,'o');
    bool ins16 = map1.insert(18,'p');
    bool ins17 = map1.insert(19,'q');
    bool ins18 = map1.insert(20,'r');
    bool ins19 = map1.insert(21,'s');
    bool ins20 = map1.insert(22,'t');
    bool ins21 = map1.insert(23,'u');
    bool ins22 = map1.insert(24,'v');
    bool ins23 = map1.insert(25,'w');
    bool ins24 = map1.insert(26,'x');
    bool ins25 = map1.insert(27,'y');
    bool ins26 = map1.insert(28,'z');
    bool ins27 = map1.insert(29,'b');
    bool ins28 = map1.insert(30,'d');
    bool ins29 = map1.insert(31,'c');
    bool ins30 = map1.insert(32,'a');
    bool ins31 = map1.insert(33,'b');
    bool ins32 = map1.insert(34,'d');
    bool ins33 = map1.insert(35,'c');
    bool ins34 = map1.insert(36,'a');
    bool ins35 = map1.insert(37,'b');
    bool ins36 = map1.insert(38,'d');
    bool ins37 = map1.insert(39,'c');
    bool ins38 = map1.insert(40,'a');
    bool ins39 = map1.insert(41,'b');
    bool ins40 = map1.insert(42,'d');
    bool ins41 = map1.insert(43,'c');
    bool ins42 = map1.insert(44,'a');
    bool ins43 = map1.insert(45,'b');
    bool ins44 = map1.insert(46,'d');
    bool ins45 = map1.insert(47,'c');
    
        SECTION("Search() - verify that value gets replaced (buckets map) on successful search.") {
            //bool ins45 = map1.insert(47,'c');
            char val = 'd';
            REQUIRE(map1.search(47, val));
            REQUIRE(val == 'c');
        }
    bool insSame_Key = map1.insert(47,'e');       //TODO
    
        SECTION("Verify same key insert (buckets map) is functional and search replaces value") {
            char val = 'x';
            REQUIRE(map1.search(47, val));
            REQUIRE(val == 'e');
        }
    
    bool ins46 = map1.insert(48,'a');
    bool ins47 = map1.insert(49,'b');
    bool ins48 = map1.insert(50,'d');
    bool ins49 = map1.insert(51,'c');
    bool ins50 = map1.insert(52,'a');
 //   bool insToo_Large = map1.insert(56,'c');
    
    REQUIRE(ins1 == true);
    REQUIRE(ins2 == true);
    REQUIRE(ins3 == true);
    REQUIRE(ins4 == true);
    REQUIRE(ins5 == true);
    REQUIRE(ins6 == true);
    REQUIRE(ins7 == true);
    REQUIRE(ins8 == true);
    REQUIRE(ins9 == true);
    REQUIRE(ins10 == true);
    REQUIRE(ins11 == true);
    REQUIRE(ins12 == true);
    REQUIRE(ins13 == true);
    REQUIRE(ins14 == true);
    REQUIRE(ins15 == true);
    REQUIRE(ins16 == true);
    REQUIRE(ins17 == true);
    REQUIRE(ins18 == true);
    REQUIRE(ins19 == true);
    REQUIRE(ins20 == true);
    REQUIRE(ins21 == true);
    REQUIRE(ins22 == true);
    REQUIRE(ins23 == true);
    REQUIRE(ins24 == true);
    REQUIRE(ins25 == true);
    REQUIRE(ins26 == true);
    REQUIRE(ins27 == true);
    REQUIRE(ins28 == true);
    REQUIRE(ins29 == true);
    REQUIRE(ins30 == true);
    REQUIRE(ins31 == true);
    REQUIRE(ins32 == true);
    REQUIRE(ins33 == true);
    REQUIRE(ins34 == true);
    REQUIRE(ins35 == true);
    REQUIRE(ins36 == true);
    REQUIRE(ins37 == true);
    REQUIRE(ins38 == true);
    REQUIRE(ins39 == true);
    REQUIRE(ins40 == true);
    REQUIRE(ins41 == true);
    REQUIRE(ins42 == true);
    REQUIRE(ins43 == true);
    REQUIRE(ins44 == true);
    REQUIRE(ins45 == true);
    REQUIRE(ins46 == true);
    REQUIRE(ins47 == true);
    REQUIRE(ins48 == true);
    REQUIRE(ins49 == true);
    REQUIRE(ins50 == true);
    REQUIRE(insSame_Key == true);
   // REQUIRE(insToo_Large == false);
    
    REQUIRE(map1.load() == 1);
    REQUIRE(map1.is_empty() == false);
    
    std::ostream &o = map1.print(std::cout);
    o << std::endl;
    o.flush();
    std::cout << std::endl;
    std::cout << std::endl;
    //map1.clear();
    
}

TEST_CASE("Test remove, check to see if value reference is changed (buckets map)", "[hashmap_oa::remove()]") {
    char v = 'q';
//    map1.remove(12, v);
    //REQUIRE(v == 'j');
}