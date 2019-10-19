/**
 * wumpus.h ---
 *
 * Author: Hezkias
 *         Yitbarek
 *
 */

#ifndef WUMPUS_WUMPUS_H
#define WUMPUS_WUMPUS_H
class wumpus {

public:
    void build_env();
    bool check_pit(int i, int j);
    bool check_pit_upper(int i, int j);
    bool check_wumpus(int i, int j);
    bool check_gold(int i, int j);
    bool check_failed(int i, int j);
    bool check_wumpus_upper(int i, int j);
    bool check_pit_lower(int i, int j);
    void wumpus_exist(int i, int j);
    void build_ui();
    void build_ui2(int k, int l);
    bool play();
    void display(int i,int j);
    bool check_wumpus_lower(int i, int j);
    int generateRandomNumber(int lowerBound, int UpperBound);
    bool diagonal(int i, int j);
    bool upper_diagonal(int i,int j);
    bool lower_diagonal(int i,int j);

};
#endif //WUMPUS_WUMPUS_H
