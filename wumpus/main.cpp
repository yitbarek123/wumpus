#include <iostream>
#include "wumpus.h"

using namespace std;

int main() {
    wumpus obj;
    obj.build_env();
    obj.build_ui();
    obj.play();
    return 0;
}
