//
// Created by yitbarek on 9/14/19.
//

#include <cxxtest/TestSuite.h>
#include "../src/wumpus.h"

class gametest : public CxxTest::TestSuite {
public:
    void testgamefailled(void) {
        wumpus t;
        int game[4][4];

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                game[i][j] = 0;
            }
        }
        game[2][0] = -2;
        game[0][2] = -1;
        game[3][1] = -1;
        game[3][3] = 100;
        t.build_env();
        TS_ASSERT_EQUALS(t.check_failed(0, 2), true);
    }
};