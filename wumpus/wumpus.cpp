/**
 * wumpus.cpp ---
 *
 * Author: Hizkias
 *         Yitbarek
 *
 */

/**
* build enviornment including UI and set the
* sensory values.Then implement the algorithm.
*/
#include <chrono>
#include <thread>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include "wumpus.h"

using namespace std;

static int game[4][4];
static bool flag=true;
/**
 * Initalize variables.
 */
void wumpus::build_env() {
    int randomi, randomj;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            game[i][j] = 0;
        }
    }
    //The test is build on the following arrangment
    bool pitsAdded = false;
    bool wumpusAdded = false;
    bool goldAdded = false;

//    game[0][3] = -1;//
//    game[3][1] = -1;// There is pit
//    game[1][3] = 100;//
//    game[2][0] = -2;// There is wumpus
//    game[3][3] = -1;// There is gold

    // adding pits
    while (!pitsAdded){
        cout << "Adding pits " << endl;
        int addedPitsCount = 0;
        int row, col;
        pitRowAndCol:
             row = this->generateRandomNumber(0, 3);
             col = this->generateRandomNumber(0, 3);

       // make sure the upper four cells are free of any danger
       if((row == 0 && col == 0) || (row == 0 && col == 1) || (row == 1 && col == 0) || (row == 1 && col == 1) ){
           goto pitRowAndCol;
       }
       // wait until 3 pits added
       while(addedPitsCount < 3){
           if(game[row][col] == 0){
               game[row][col] = -1;
               addedPitsCount += 1;
           }
           else {
               goto pitRowAndCol;
           }
       }
       pitsAdded = true;
    }


    // adding wumpus
    while (!wumpusAdded){
        cout << "Adding wumpus " << endl;
        int row, col;
        wumpusRowAndCol:
        row = this->generateRandomNumber(0, 3);
        col = this->generateRandomNumber(0, 3);
        // make sure the upper four cells are free of any danger
        if((row == 0 && col == 0) || (row == 0 && col == 1) || (row == 1 && col == 0) || (row == 1 && col == 1) ){
            goto wumpusRowAndCol;
        }
        else{
            if (game[row][col] == 0){
                game[row][col] = -2;
                wumpusAdded = true;
            }
            else {
                goto wumpusRowAndCol;
            }
        }
    }
    // adding gold

    while(!goldAdded){
        cout << "Adding gold" << endl;
        int row, col;
        goldRowAndCol:
            row = this->generateRandomNumber(0, 3);
            col = this->generateRandomNumber(0, 3);
        if(row == 0 && col == 0){
            goto goldRowAndCol;
        }
        else {
            if(game[row][col] == 0){
                game[row][col] = 100;
                goldAdded = true;
            }
            else {
                goto  goldRowAndCol;
            }
        }

    }


/*
    // the first pit

    randomi = random()% 4;
    randomj = random()% 4;
    if (randomi + randomj > 1 && randomi * randomj != 1) {
        game[randomi][randomj] = -1;
    }
    // the second pit
    randomi = random()% 4;
    randomj = random()% 4;
    if (randomi + randomj > 1 && randomi * randomj != 1) {
        game[randomi][randomj] = -1;
    }
    // the third pit
    randomi = random()% 4;
    randomj = random()% 4;
    if (randomi + randomj > 1 && randomi * randomj != 1) {
        game[randomi][randomj] = -1;
    }
    // wumpus
    randomi = random()% 4;
    randomj = random()% 4;
    if (randomi + randomj > 1 && randomi * randomj != 1) {
        game[randomi][randomj] = -2;
    }
    // gold
    randomi = random()% 4;
    randomj = random()% 4;
    if (randomi + randomj > 1 && randomi * randomj != 1) {
        game[randomi][randomj] = 100;
    }
*/

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            // add 5 to all wumpus neighbours
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
            // add 6 to all pit neighbours
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
/**
 * Build UI.
 */
void wumpus::build_ui2(int k, int l){
    cout << "**********************" << endl << "|";
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (i == k && j == l) {
                cout << "  A  ";
            }
            if (game[i][j] == 0  && ((i==k && j==l)==false)) {
                cout << "  0  ";
            }
            if (game[i][j] == -1  && ((i==k && j==l)==false)) {
                cout << "  P  ";
            }
            if (game[i][j] == -2  && ((i==k && j==l)==false)) {
                cout << "  W  ";
            }
            if (game[i][j] == 5  && ((i==k && j==l)==false)) {
                cout << "  F  ";
            }
            if (game[i][j] == 6  && ((i==k && j==l)==false)) {
                cout << "  F  ";
            }
            if (game[i][j] == 12  && ((i==k && j==l)==false)) {
                cout << "  F  ";
            }
            if (game[i][j] == 17  && ((i==k && j==l)==false)) {
                cout << "  F  ";
            }
            if (game[i][j] == 11  && ((i==k && j==l)==false)) {
                cout << "  F  ";
            }
            if (game[i][j] > 50  && ((i==k && j==l)==false)) {
                cout << "  G  ";
            }
        }
        cout << endl;
        cout << "**********************" << endl;
        if (i < 3) {
            cout << "|";
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
            if (game[i][j] == 17) {
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

/**
 * Logs current position.
 * @param i the row of the cell
 * @param j the column of the cell
 */
void wumpus::display(int i,int j){
    cout << "I am at" << i << j << endl;
    build_ui2(i ,j);
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

}

/**
 * Check for existence of pit diagonally.
 * @param i the row of the cell
 * @param j the column of the cell
 * @return true if pit exist, else false
 */
bool wumpus::check_pit(int i, int j) {
    return (game[i - 1][j] == 6 || game[i-1][j]==11||game[i-1][j]==12||game[i-1][j]==17)&& (game[i][j-1] == 6 || game[i][j-1]==11||game[i][j-1]==12||game[i][j-1]==17) && (i > 0 && j > 0);
}

/**
 * Check for existence of pit for lower diagonal.
 * @param i the row of the cell
 * @param j the column of the cell
 * @return true if pit exist, else false
 */
bool wumpus::check_pit_lower(int i, int j) {
    return (game[i - 1][j] == 6 || game[i-1][j]==11||game[i-1][j]==12||game[i-1][j]==17)&& (game[i][j+1] == 6 || game[i][j+1]==11||game[i][j+1]==12||game[i][j+1]==17) && (i > 0 && j < 3);
}

/**
 * Check for existence of pit for upper diagonal.
 * @param i the row of the cell
 * @param j the column of the cell
 * @return true if pit exist, else false
 */
bool wumpus::check_pit_upper(int i, int j) {
    return (game[i][j-1] == 6 || game[i][j-1]==11||game[i][j-1]==12||game[i][j-1]==17)&& (game[i+1][j] == 6 || game[i+1][j]==11||game[i+1][j]==12||game[i+1][j]==17) && (i > -1 && j > -1);
}

/**
 * Check for existence of wumpus for diagonally.
 * @param i the row of the cell
 * @param j the column of the cell
 * @return true if wumpus exist, else false
 */
bool wumpus::check_wumpus(int i, int j) {
    return (game[i - 1][j] == 5 || game[i - 1][j] == 11 || game[i - 1][j] == 17) && (game[i][j - 1] == 5 || game[i][j - 1] == 11|| game[i][j - 1] == 17)&&(i > 0 && j > 0);
}

/**
 * Check for existence of wumpus for upper diagonal.
 * @param i the row of the cell
 * @param j the column of the cell
 * @return true if wumpus exist, else false
 */
bool wumpus::check_wumpus_upper(int i, int j) {
    return (game[i][j-1] == 5 || game[i][j-1] == 11 || game[i][j-1] == 17) && (game[i+1][j] == 5 || game[i+1][j] == 11|| game[i+1][j] == 17) && (i > -1 && j > -1);
}

/**
 * Check for existence of gold on the current cell.
 * @param i the row of the cell
 * @param j the column of the cell
 * @return true if gold exist, else false
 */
bool wumpus::check_gold(int i, int j) {
    if (game[i][j] > 50) {
        cout << "the gold is at" << i << j;
        return true;
    }
    return false;
}

/**
 * Check for game_failed.
 * @param i the row of the cell
 * @param j the column of the cell
 * @return true if pit or wumpus  exist, else false
 */
bool wumpus::check_failed(int i, int j) {
    if ((game[i][j] == -1) || (game[i][j] == -2)|| (game[i][j] == -6)) {
        cout << "failed at" << i << j;
        return true;
    }
    return false;
}

/**
 * Calls check for wumpus function and
 * kills if wumpus is found.
 * @param m the row of the cell
 * @param n the column of the cell
 */
void wumpus::wumpus_exist(int m, int n){
    if (wumpus::check_wumpus(m + 1, n + 1) == true && (m + 1 < 4 && n + 1 < 4)) {
        cout << "wumpus is at" << m + 1 << n + 1 << endl;
        game[m + 1][n + 1] = 0;
        game[m][n + 1] -= 5;
        game[m + 1][n] -= 5;
        game[m + 2][n + 1] -= 5;
        game[m + 1][n + 2] -= 5;
        cout << "wumpus is killed" << endl;
        m=m+1;
        n=n+1;
    }
}

/**
 * traverse the matrix until the
 * game over or the gold is found.
 */
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
            if (m < 4 && n < 4)  {
                //cout << "no pit at" << m + 1 << n + 1 << endl;
                //std::this_thread::sleep_for(std::chrono::milliseconds(1000));
                wumpus_exist(m,n);

                if (check_gold(m, n + 1) == true || check_failed(m, n + 1) == true) {
                        return false;
                    }
                if (check_gold(m+1, n) == true || check_failed(m+1, n) == true) {
                    return false;
                }
                if (check_gold(m + 1, n + 1) == true || check_failed(m + 1, n + 1) == true) {
                        return false;
                    }
                display(m,n+1);
                display(m,n);
                display(m+1,n);
                if (check_pit(m + 1, n+1) == false && (m < 4 && n < 4)) {
                    cout << "no pit at" << m + 1 << n + 1 << endl;
                    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
                    display(m+1,n+1);

                    if (check_gold(m + 1, n + 1) == true || check_failed(m + 1, n + 1) == true) {
                        return false;
                    }
                    n = n + 1;
                    m = m + 1;
                }


                diagonal_checked = true;
            }
            if (diagonal_checked == true && (m < 4 && n < 4)) {
                temp1 = m;
                temp2 = n;
                //upper diagonal

                    //if (check_pit(m - 1, n) == false && (m < 4 && n < 4)) {

                        if (check_gold(m - 1, n) == true || check_failed(m - 1, n) == true && (m < 4 && n < 4)) {
                            return false;
                        }
                        if (check_gold(m, n+1) == true || check_failed(m, n+1) == true && (m < 4 && n < 4)) {
                        return false;
                    }
                        display(m-1,n);
                        display(m,n);
                        display(m,n+1);
                       if (check_pit_upper(m - 1, n+1) == false && (m < 4 && n < 4)) {
                           cout << "no pit at" << m - 1 << n + 1 << endl;
                           std::this_thread::sleep_for(std::chrono::milliseconds(1000));
                           display(m - 1, n + 1);
                           if (check_gold(m-1, n+1) == true || check_failed(m-1, n+1) == true) {
                               return false;
                           }
                           display(m-1,n);
                           display(m,n);

                         //  n = n + 1;
                       //    m = m - 1;
                       }
                       else{
                           display(m,n);
                       }

              //}

             //   display(m,n);
                m = temp1;
                n = temp2;
                //lower diagonal
     //           if (check_pit_lower(m + 1, n - 1) == false && (m < 4 && n < 4)) {
       //             if(m+1<4 && n-1 >0) {

         //           }
                display(m,n-1);

                if (check_gold(m, n - 1) == true || check_failed(m, n - 1) == true && (m < 4 && n < 4)) {
                            return false;
                        }
                display(m,n);
                display(m+1,n);

                        if (check_gold(m+1, n) == true || check_failed(m+1, n) == true && (m < 4 && n < 4)) {
                            return false;
                        }
                        if(m+1<4 && n-1 >0) {
                          //  display(m+1,n-1);
                        }
                if (check_pit_lower(m + 1, n - 1) == false && (m < 4 && n < 4)) {
                    display(m+1,n-1);
                    cout << "no pit at" << m + 1 << n - 1 << endl;
                    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

                }
          //      }


                display(m+1,n);
                display(m,n);
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

int wumpus::generateRandomNumber(int lowerBound, int UpperBound) {
    // Use current time as
    // seed for random generator
    srand(time(0));
    return (rand() %
            (UpperBound - lowerBound + 1)) + lowerBound;
}