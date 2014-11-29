
//#define CATCH_CONFIG_MAIN
#include "catch.h"
#include "hashmap_buckets.h"


static hashmap_buckets map1;

TEST_CASE( "Testing the insert function and verifying with size function (hashmap_buckets)", "[insert(), size()]" ) {

    bool ins1 = map1.insert(3,'c');
    bool ins2 = map1.insert(4,'a');
    bool ins3 = map1.insert(5,'b');
    bool ins4 = map1.insert(6,'d');
    
        REQUIRE( ins1 );
        REQUIRE( ins2 );
        REQUIRE( ins3 );
        REQUIRE( ins4 );
        
        REQUIRE( map1.size() == 4); 
}
/*
TEST_CASE("doing a test print, clearing, testing size, then printing again (hashmap_buckets)", "[clear(), print(), size(), ]") {
   
    
    map1.print(std::cout);
    map1.clear();
    
    REQUIRE(map1.size() == 0);
}

TEST_CASE("", "[]") {
    
}*/
