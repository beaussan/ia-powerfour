//
// Created by nicbe on 19/12/2017.
//

// #define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file


#include "../PowerFour.h"
#include "../libs/catch.hpp"



TEST_CASE("Power four validation is correct", "[PowerFour]") {
    PowerFour* pf = new PowerFour();
    SECTION("Line validation") {
        SECTION( "should output the correct value" ) {
            REQUIRE( pf->checkIfWin() == NONE );
            pf->play(RED, 0);
            REQUIRE( pf->checkIfWin() == NONE );
            pf->play(RED, 1);
            REQUIRE( pf->checkIfWin() == NONE );
            pf->play(RED, 2);
            REQUIRE( pf->checkIfWin() == NONE );
            pf->play(RED, 3);
            REQUIRE( pf->checkIfWin() == RED );
        }
        SECTION( "should output the correct value" ) {
            REQUIRE( pf->checkIfWin() == NONE );
            pf->play(BLUE, 0);
            REQUIRE( pf->checkIfWin() == NONE );
            pf->play(BLUE, 1);
            REQUIRE( pf->checkIfWin() == NONE );
            pf->play(BLUE, 2);
            REQUIRE( pf->checkIfWin() == NONE );
            pf->play(BLUE, 3);
            REQUIRE( pf->checkIfWin() == BLUE );
        }


        SECTION("should work on line starts") {
            REQUIRE( pf->checkIfWin() == NONE );
            pf->play(BLUE, 1);
            REQUIRE( pf->checkIfWin() == NONE );
            pf->play(BLUE, 2);
            REQUIRE( pf->checkIfWin() == NONE );
            pf->play(BLUE, 3);
            REQUIRE( pf->checkIfWin() == NONE );
            pf->play(BLUE, 4);
            REQUIRE( pf->checkIfWin() == BLUE );
        }
        SECTION("should work on line middle") {
            REQUIRE( pf->checkIfWin() == NONE );
            pf->play(BLUE, 2);
            REQUIRE( pf->checkIfWin() == NONE );
            pf->play(BLUE, 3);
            REQUIRE( pf->checkIfWin() == NONE );
            pf->play(BLUE, 4);
            REQUIRE( pf->checkIfWin() == NONE );
            pf->play(BLUE, 5);
            REQUIRE( pf->checkIfWin() == BLUE );
        }
        SECTION("should work on line ends") {
            REQUIRE( pf->checkIfWin() == NONE );
            pf->play(BLUE, 3);
            REQUIRE( pf->checkIfWin() == NONE );
            pf->play(BLUE, 4);
            REQUIRE( pf->checkIfWin() == NONE );
            pf->play(BLUE, 5);
            REQUIRE( pf->checkIfWin() == NONE );
            pf->play(BLUE, 6);
            REQUIRE( pf->checkIfWin() == BLUE );
        }
 /*
    | | | |X|X|X|X|
    | | | |X|O|X|O|
    | | | |O|X|O|X|
    | | | |O|X|O|X|
    | | | |X|O|X|O|
    | | | |X|O|X|O|
    +-+-+-+-+-+-+-+*/


        SECTION("should work on last line ends") {
            pf->play(BLUE, 3);
            pf->play(BLUE, 3);
            pf->play(RED, 3);
            pf->play(RED, 3);
            pf->play(BLUE, 3);

            pf->play(RED, 4);
            pf->play(RED, 4);
            pf->play(BLUE, 4);
            pf->play(BLUE, 4);
            pf->play(RED, 4);

            pf->play(BLUE, 5);
            pf->play(BLUE, 5);
            pf->play(RED, 5);
            pf->play(RED, 5);
            pf->play(BLUE, 5);



            pf->play(RED, 6);
            pf->play(RED, 6);
            pf->play(BLUE, 6);
            pf->play(BLUE, 6);
            pf->play(RED, 6);

            REQUIRE( pf->checkIfWin() == NONE );
            pf->play(RED, 3);
            pf->play(RED, 4);
            pf->play(RED, 5);
            pf->play(RED, 6);

            REQUIRE( pf->checkIfWin() == RED );
        }
    }

    SECTION("Column validation") {
        SECTION("should work on column starts") {
            REQUIRE( pf->checkIfWin() == NONE );
            pf->play(RED, 0);
            REQUIRE( pf->checkIfWin() == NONE );
            pf->play(RED, 0);
            REQUIRE( pf->checkIfWin() == NONE );
            pf->play(RED, 0);
            REQUIRE( pf->checkIfWin() == NONE );
            pf->play(RED, 0);
            REQUIRE( pf->checkIfWin() == RED );
        }
        SECTION("should work on column middle") {
            pf->play(BLUE, 0);
            REQUIRE( pf->checkIfWin() == NONE );
            pf->play(RED, 0);
            REQUIRE( pf->checkIfWin() == NONE );
            pf->play(RED, 0);
            REQUIRE( pf->checkIfWin() == NONE );
            pf->play(RED, 0);
            REQUIRE( pf->checkIfWin() == NONE );
            pf->play(RED, 0);
            REQUIRE( pf->checkIfWin() == RED );
        }
        SECTION("should work on column ends") {
            pf->play(BLUE, 0);
            pf->play(BLUE, 0);
            REQUIRE( pf->checkIfWin() == NONE );
            pf->play(RED, 0);
            REQUIRE( pf->checkIfWin() == NONE );
            pf->play(RED, 0);
            REQUIRE( pf->checkIfWin() == NONE );
            pf->play(RED, 0);
            REQUIRE( pf->checkIfWin() == NONE );
            pf->play(RED, 0);
            REQUIRE( pf->checkIfWin() == RED );
        }
        SECTION("should work on last column ends") {
            pf->play(BLUE, 6);
            pf->play(BLUE, 6);
            REQUIRE( pf->checkIfWin() == NONE );
            pf->play(RED, 6);
            REQUIRE( pf->checkIfWin() == NONE );
            pf->play(RED, 6);
            REQUIRE( pf->checkIfWin() == NONE );
            pf->play(RED, 6);
            REQUIRE( pf->checkIfWin() == NONE );
            pf->play(RED, 6);
            REQUIRE( pf->checkIfWin() == RED );
        }
    }

    SECTION("Diagonal right validation") {
        SECTION("should work on column starts") {
            pf->play(BLUE, 1);
            pf->play(BLUE, 2);
            pf->play(BLUE, 2);
            pf->play(BLUE, 3);
            pf->play(BLUE, 3);
            pf->play(BLUE, 3);
            REQUIRE( pf->checkIfWin() == NONE );
            pf->play(RED, 0);
            REQUIRE( pf->checkIfWin() == NONE );
            pf->play(RED, 1);
            REQUIRE( pf->checkIfWin() == NONE );
            pf->play(RED, 2);
            REQUIRE( pf->checkIfWin() == NONE );
            pf->play(RED, 3);
            REQUIRE( pf->checkIfWin() == RED );
        }
        SECTION("should work on column middle") {
            pf->play(BLUE, 2);
            pf->play(BLUE, 3);
            pf->play(BLUE, 3);
            pf->play(BLUE, 4);
            pf->play(BLUE, 4);
            pf->play(BLUE, 4);
            REQUIRE( pf->checkIfWin() == NONE );
            pf->play(RED, 1);
            REQUIRE( pf->checkIfWin() == NONE );
            pf->play(RED, 2);
            REQUIRE( pf->checkIfWin() == NONE );
            pf->play(RED, 3);
            REQUIRE( pf->checkIfWin() == NONE );
            pf->play(RED, 4);
            REQUIRE( pf->checkIfWin() == RED );
        }
        SECTION("should work on column middle") {
            pf->play(BLUE, 3);
            pf->play(BLUE, 4);
            pf->play(BLUE, 4);
            pf->play(BLUE, 5);
            pf->play(BLUE, 5);
            pf->play(BLUE, 5);
            REQUIRE( pf->checkIfWin() == NONE );
            pf->play(RED, 2);
            REQUIRE( pf->checkIfWin() == NONE );
            pf->play(RED, 3);
            REQUIRE( pf->checkIfWin() == NONE );
            pf->play(RED, 4);
            REQUIRE( pf->checkIfWin() == NONE );
            pf->play(RED, 5);
            REQUIRE( pf->checkIfWin() == RED );
        }
        SECTION("should work on column end") {
            pf->play(BLUE, 4);
            pf->play(BLUE, 5);
            pf->play(BLUE, 5);
            pf->play(BLUE, 6);
            pf->play(BLUE, 6);
            pf->play(BLUE, 6);
            REQUIRE( pf->checkIfWin() == NONE );
            pf->play(RED, 3);
            REQUIRE( pf->checkIfWin() == NONE );
            pf->play(RED, 4);
            REQUIRE( pf->checkIfWin() == NONE );
            pf->play(RED, 5);
            REQUIRE( pf->checkIfWin() == NONE );
            pf->play(RED, 6);
            REQUIRE( pf->checkIfWin() == RED );
        }


        SECTION("should work on column top end") {
            pf->play(BLUE, 3);
            pf->play(BLUE, 3);

            pf->play(BLUE, 4);
            pf->play(RED , 4);
            pf->play(RED , 4);

            pf->play(RED , 5);
            pf->play(BLUE, 5);
            pf->play(RED , 5);
            pf->play(BLUE, 5);

            pf->play(BLUE, 6);
            pf->play(RED , 6);
            pf->play(BLUE, 6);
            pf->play(BLUE, 6);
            pf->play(BLUE, 6);

            pf->print();

            REQUIRE( pf->checkIfWin() == NONE );
            pf->play(RED, 3);
            REQUIRE( pf->checkIfWin() == NONE );
            pf->play(RED, 4);
            REQUIRE( pf->checkIfWin() == NONE );
            pf->play(RED, 5);
            REQUIRE( pf->checkIfWin() == NONE );
            pf->play(RED, 6);
            REQUIRE( pf->checkIfWin() == RED );

            pf->print();
        }
    }


    SECTION("Diagonal left validation") {
        SECTION("should work on column starts") {
            pf->play(BLUE, 0);
            pf->play(BLUE, 0);
            pf->play(BLUE, 0);
            pf->play(BLUE, 1);
            pf->play(BLUE, 1);
            pf->play(BLUE, 2);
            REQUIRE( pf->checkIfWin() == NONE );
            pf->play(RED, 0);
            REQUIRE( pf->checkIfWin() == NONE );
            pf->play(RED, 1);
            REQUIRE( pf->checkIfWin() == NONE );
            pf->play(RED, 2);
            REQUIRE( pf->checkIfWin() == NONE );
            pf->play(RED, 3);
            REQUIRE( pf->checkIfWin() == RED );
        }
        SECTION("should work on column middle") {
            pf->play(BLUE, 1);
            pf->play(BLUE, 1);
            pf->play(BLUE, 1);
            pf->play(BLUE, 2);
            pf->play(BLUE, 2);
            pf->play(BLUE, 3);
            REQUIRE( pf->checkIfWin() == NONE );
            pf->play(RED, 1);
            REQUIRE( pf->checkIfWin() == NONE );
            pf->play(RED, 2);
            REQUIRE( pf->checkIfWin() == NONE );
            pf->play(RED, 3);
            REQUIRE( pf->checkIfWin() == NONE );
            pf->play(RED, 4);
            REQUIRE( pf->checkIfWin() == RED );
        }
        SECTION("should work on column middle") {
            pf->play(BLUE, 2);
            pf->play(BLUE, 2);
            pf->play(BLUE, 2);
            pf->play(BLUE, 3);
            pf->play(BLUE, 3);
            pf->play(BLUE, 4);
            REQUIRE( pf->checkIfWin() == NONE );
            pf->play(RED, 2);
            REQUIRE( pf->checkIfWin() == NONE );
            pf->play(RED, 3);
            REQUIRE( pf->checkIfWin() == NONE );
            pf->play(RED, 4);
            REQUIRE( pf->checkIfWin() == NONE );
            pf->play(RED, 5);
            REQUIRE( pf->checkIfWin() == RED );
        }
        SECTION("should work on column end") {
            pf->play(BLUE, 3);
            pf->play(BLUE, 3);
            pf->play(BLUE, 3);
            pf->play(BLUE, 4);
            pf->play(BLUE, 4);
            pf->play(BLUE, 5);
            REQUIRE( pf->checkIfWin() == NONE );
            pf->play(RED, 3);
            REQUIRE( pf->checkIfWin() == NONE );
            pf->play(RED, 4);
            REQUIRE( pf->checkIfWin() == NONE );
            pf->play(RED, 5);
            REQUIRE( pf->checkIfWin() == NONE );
            pf->play(RED, 6);
            REQUIRE( pf->checkIfWin() == RED );
        }
        SECTION("should work on column top end") {
            pf->play(BLUE, 3);
            pf->play(RED , 3);
            pf->play(BLUE, 3);
            pf->play(BLUE, 3);
            pf->play(BLUE, 3);

            pf->play(BLUE, 4);
            pf->play(BLUE, 4);
            pf->play(RED , 4);
            pf->play(RED , 4);

            pf->play(BLUE, 5);
            pf->play(RED , 5);
            pf->play(BLUE, 5);


            pf->play(RED , 6);
            pf->play(BLUE, 6);

            REQUIRE( pf->checkIfWin() == NONE );
            pf->play(RED, 3);
            REQUIRE( pf->checkIfWin() == NONE );
            pf->play(RED, 4);
            REQUIRE( pf->checkIfWin() == NONE );
            pf->play(RED, 5);
            REQUIRE( pf->checkIfWin() == NONE );
            pf->play(RED, 6);
            REQUIRE( pf->checkIfWin() == RED );
        }


    }

}
