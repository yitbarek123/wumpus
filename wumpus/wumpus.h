//
// Created by yitbarek on 9/20/19.
//

using namespace std;


class wumpus {

public:
    void build_env();
    bool check_pit(int i, int j);
    bool check_wumpus(int i, int j);
    bool check_gold(int i, int j);
    bool check_failed(int i, int j);
    void build_ui();
    bool play();

    void delayPrint(int durationInSeconds);
};