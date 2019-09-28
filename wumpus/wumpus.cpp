//
// Created by yitbarek on 9/14/19.
//
#include <chrono>
#include <thread>
#include <iostream>
#include "wumpus.h"

static int game[4][4];

void wumpus::build_env() {

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            game[i][j] = 0;
        }
    }
    game[0][3] = -1;
    game[3][1] = -1;
    game[3][0] = -1;
    game[2][2] = -2;
    game[3][3] = 100;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (game[i][j] == -2) {
                if ((i + 1 < 4) && (game[i + 1][j] != -1)) {
                    game[i + 1][j] += 5;
                }
                if ((j + 1 < 4) && (game[i][j + 1] != -1)) {
                    game[i][j + 1] += 5;
                }
                if ((i - 1 > 0) && (game[i - 1][j] != -1)) {
                    game[i - 1][j] += 5;
                }
                if ((j - 1 > 0) && (game[i][j - 1] != -1)) {
                    game[i][j - 1] += 5;
                }
            }
            if (game[i][j] == -1) {
                if ((i + 1 < 4) && (game[i + 1][j] != -2) && (game[i + 1][j] != -1)) {
                    game[i + 1][j] += 6;
                }
                if ((j + 1 < 4) && (game[i][j + 1] != -2) && (game[i][j + 1] != -1)) {
                    game[i][j + 1] += 6;
                }
                if ((i - 1 > 0) && (game[i - 1][j] != -2) && (game[i - 1][j] != -1)) {
                    game[i - 1][j] += 6;
                }
                if ((j - 1 > 0) && (game[i][j - 1] != -2) && (game[i][j - 1] != -1)) {
                    game[i][j - 1] += 6;
                }
            }
        }
    }
}

void wumpus::build_ui(){
cout << "********************************" << endl << "|";
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (i == 0 && j == 0) {
                cout << "Agent" << i << j << " " << "| ";
            }
            if (game[i][j] == 0 && (i + j > 0)) {
                cout << "free" << i << j << " " << " | ";
            }
            if (game[i][j] == -1) {
                cout << "pit" << i << j << " " << "  | ";
            }
            if (game[i][j] == -2) {
                cout << "wumpus" << i << j << " " << "| ";
            }
            if (game[i][j] == 5) {
                cout << "free" << i << j << " " << " | ";
            }
            if (game[i][j] == 6) {
                cout << "free" << i << j << " " << " | ";
            }
            if (game[i][j] == 12) {
                cout << "free" << i << j << " " << " | ";
            }
            if (game[i][j] == 11) {
                cout << "free" << i << j << " " << " | ";
            }
            if (game[i][j] > 50) {
                cout << "gold" << i << j << " " << " | ";
            }
        }
        cout << endl;
        cout << "********************************" << endl;
        if (i < 3) {
            cout << "|";
        }
    }
}

bool wumpus::check_pit(int i, int j) {
    if (i > 0 && j > 0) {
        if (((game[i - 1][j] == 6 || game[i-1][j]==11||game[i-1][j]==12)&& (game[i][j-1] == 6 || game[i][j-1]==11||game[i][j-1]==12))==false) {
            return false;
        }
    }
    return true;
}
bool wumpus::check_pit_lower(int i, int j) {
    if (i > 0 && j < 3) {
        if (((game[i - 1][j] == 6 || game[i-1][j]==11||game[i-1][j]==12)&& (game[i][j+1] == 6 || game[i][j+1]==11||game[i][j+1]==12))==false) {
            return false;
        }
    }
    return true;
}
bool wumpus::check_pit_upper(int i, int j) {
    if (i > 0 && j > 0) {
        if (((game[i][j-1] == 6 || game[i][j-1]==11||game[i][j-1]==12)&& (game[i+1][j] == 6 || game[i+1][j]==11||game[i+1][j]==12))==false) {
            return false;
        }
    }
    return true;
}

bool wumpus::check_wumpus(int i, int j) {
    if (i > 0 && j > 0) {
        if ((game[i - 1][j] == 5 || game[i - 1][j] == 11) && (game[i][j - 1] == 5 || game[i][j - 1] == 11)) {
            return true;
        }
    }
    return false;
}

bool wumpus::check_wumpus_upper(int i, int j) {
    if (i > 0 && j > 0) {
        if ((game[i][j-1] == 5 || game[i][j-1] == 11) && (game[i][j +1] == 5 || game[i][j +1] == 11)) {
            return true;
        }
    }
    return false;
}

bool wumpus::check_gold(int i, int j) {
    if (game[i][j] > 50) {
        cout << "the gold is at" << i << j;
        return true;
    }
    return false;
}

bool wumpus::check_failed(int i, int j) {
    if ((game[i][j] == -1) || (game[i][j] == -2)|| (game[i][j] == -6)) {
        cout << "failed at" << i << j;
        return true;
    }
    return false;
}

void wumpus::wumpus_exist(int m, int n){
    if (wumpus::check_wumpus(m + 1, n + 1) == true && (m + 1 < 4 && n + 1 < 4)) {
        cout << "wumpus is at" << m + 1 << n + 1 << endl;
        game[m + 1][n + 1] = 0;
        game[m][n + 1] -= 5;
        game[m + 1][n] -= 5;
        game[m + 2][n + 1] -= 5;
        game[m + 1][n + 2] -= 5;
        cout << "wumpus is killed" << endl;
    }
}

bool wumpus::play() {
    int m = 0;
    int n = 0;
    int temp1 = 0;
    int temp2 = 0;
    bool game_over = false;
    bool gold = false;
    bool diagonal_checked = false;

    cout << "I am at position" << m << n << endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    while (true) {
        if (m < 3 && n < 3) {
            if (check_pit(m + 1, n + 1) == false && (m < 4 && n < 4) ) {
                cout << "no pit at" << m + 1 << n + 1 << endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(1000));
                wumpus_exist(m,n);

                //if (check_pit(m, n + 1) == false) {
                cout << "I am at" << m << n + 1 << endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(1000));
                if (check_gold(m, n + 1) == true || check_failed(m, n + 1) == true) {
                        return false;
                    }
                    cout << "I am at" << m + 1 << n + 1 << endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(1000));

                if (check_gold(m + 1, n + 1) == true || check_failed(m + 1, n + 1) == true) {
                        return false;
                    }
                    n = n + 1;
                    m = m + 1;
                diagonal_checked = true;
            }
            if (diagonal_checked == true && (m < 4 && n < 4)) {
                temp1 = m;
                temp2 = n;
                //upper diagonal
                if (check_pit_upper(m - 1, n + 1) == false) {
                    cout << "no pit at" << m - 1 << n + 1 << endl;
                    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
                    if (check_pit(m - 1, n) == false && (m < 4 && n < 4)) {
                        cout << "I am at" << m - 1 << n << endl;
                        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
                        if (check_gold(m - 1, n) == true || check_failed(m - 1, n) == true && (m < 4 && n < 4)) {
                            return false;
                        }
                        cout << "I am at" << m - 1 << n + 1 << endl;
                        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
                        if (check_gold(m - 1, n + 1) == true ||
                            check_failed(m - 1, n + 1) == true && (m < 4 && n < 4)) {
                            return false;
                        }
                        n = n + 1;
                        m = m - 1;
                    }
                }
                m = temp1;
                n = temp2;
                //lower diagonal
                if (check_pit_lower(m + 1, n - 1) == false && (m < 4 && n < 4)) {
                    if(m+1<4 && n-1 >0) {
                        cout << "no pit at" << m + 1 << n - 1 << endl;
                        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
                    }
                    if (check_pit(m, n - 1) == false) {
                        cout << "I am at" << m << n - 1 << endl;
                        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
                        if (check_gold(m, n - 1) == true || check_failed(m, n - 1) == true && (m < 4 && n < 4)) {
                            return false;
                        }
                        if(m+1<4 && n-1 >0) {
                            cout << "I am at" << m + 1 << n - 1 << endl;
                            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
                        }
                        if (check_gold(m + 1, n - 1) == true || check_failed(m + 1, n - 1) == true && (m < 4 && n < 4)) {
                            return false;
                        }
                        n = n - 1;
                        m = m + 1;
                    }
                    if (check_pit(m + 1, n) == false && (m < 4 && n < 4)) {
                        cout << "I am at" << m << n + 1 <<endl;
                        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
                        if (check_gold(m, n + 1) == true || check_failed(m, n + 1) == true && (m < 4 && n < 4)) {
                            return false;
                        }
                        if(m+1<4 && n-1 >0) {
                            cout << "I am at" << m + 1 << n - 1 << endl;
                            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
                        }
                        if (check_gold(m + 1, n - 1) == true || check_failed(m + 1, n - 1) == true && (m < 4 && n < 4)) {
                            return false;
                        }
                        m = m + 1;
                        n = n - 1;
                    }
                }
                m = temp1;
                n = temp2;
                diagonal_checked = false;
            }
        }
        if (game[m][n] == -1 || game[m][n] == -2) {
            cout << "I have failled at" << m << n;
            return false;
        }

    }
}