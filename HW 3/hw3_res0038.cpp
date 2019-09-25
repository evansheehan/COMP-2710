//Evan Sheehan
//res0038
//hw3_res0038.cpp
//Compile with G++

#include <iostream>
#include <stdlib.h>
#include <assert.h>
#include <ctime>
using namespace std;

const int NUM_DUELS = 10000;
const double AARON_ACC = 1.0/3;
const double BOB_ACC = 0.5;
const double CHARLIE_ACC = 1.0;
bool A_alive = true;
bool B_alive = true;
bool C_alive = true;

bool at_least_two_alive(bool A_alive, bool B_alive, bool C_alive);
void Aaron_shoots1(bool& B_alive, bool& C_alive);
void Bob_shoots(bool& A_alive, bool& C_alive);
void Charlie_shoots(bool& A_alive, bool& B_alive);
void Aaron_shoots2(bool& B_alive, bool& C_alive);
void test_at_least_two_alive();
void enter_prompt();

int main() {

    srand(time(0));

    cout << "***Welcome to the Duel Simulator***" << endl;
    test_at_least_two_alive();
    enter_prompt();

    //Start of Strategy 1
    cout << "Ready to test strategy 1 (run " << NUM_DUELS << " times):" << endl;
    enter_prompt();

    int aaronWins = 0;
    int bobWins = 0;
    int charlieWins = 0;
    int duelCount = 1;

    while (duelCount < NUM_DUELS) {
        while (at_least_two_alive(A_alive, B_alive, C_alive)) {
            if (A_alive) {
                Aaron_shoots1(B_alive, C_alive);
            }
            if (B_alive) {
                Bob_shoots(A_alive, C_alive);
            }
            if (C_alive) {
                Charlie_shoots(A_alive, B_alive);
            }
        }
        if (A_alive) {
            aaronWins++;
        } else if (B_alive) {
            bobWins++;
        } else {
            charlieWins++;
        }
        A_alive = true;
        B_alive = true;
        C_alive = true;
        duelCount++;
    }
    cout << "Aaron won " << aaronWins << "/" << NUM_DUELS << " duels or " << (double)aaronWins/NUM_DUELS * 100<< "%" << endl;
    cout << "Bob won " << bobWins << "/" << NUM_DUELS << " duels or " << (double)bobWins/NUM_DUELS * 100 << "%" << endl;
    cout << "Charlie won " << charlieWins << "/" << NUM_DUELS << " duels or " << (double)charlieWins/NUM_DUELS * 100 << "%" << endl;

    //Start of Strategy 2
    cout << "\nReady to test strategy 2 (run " << NUM_DUELS << " times):" << endl;
    enter_prompt();

    int aaronStrat1Wins = aaronWins;
    aaronWins = 0;
    bobWins = 0;
    charlieWins = 0;
    duelCount = 1;

    while (duelCount < NUM_DUELS) {
        while (at_least_two_alive(A_alive, B_alive, C_alive)) {
            if (A_alive) {
                Aaron_shoots2(B_alive, C_alive);
            }
            if (B_alive) {
                Bob_shoots(A_alive, C_alive);
            }
            if (C_alive) {
                Charlie_shoots(A_alive, B_alive);
            }
        }
        if (A_alive) {
            aaronWins++;
        } else if (B_alive) {
            bobWins++;
        } else {
            charlieWins++;
        }
        A_alive = true;
        B_alive = true;
        C_alive = true;
        duelCount++;
    }
    cout << "Aaron won " << aaronWins << "/" << NUM_DUELS << " duels or " << (double)aaronWins/NUM_DUELS * 100<< "%" << endl;
    cout << "Bob won " << bobWins << "/" << NUM_DUELS << " duels or " << (double)bobWins/NUM_DUELS * 100 << "%" << endl;
    cout << "Charlie won " << charlieWins << "/" << NUM_DUELS << " duels or " << (double)charlieWins/NUM_DUELS * 100 << "%" << endl;

    if (aaronWins > aaronStrat1Wins) {
        cout << "\n Strategy 2 is better than strategy 1." << endl;
    }
    else {
        cout << "\n Strategy 1 is better than strategy 2." << endl;
    }

    return 0;
}








bool at_least_two_alive(bool A_alive, bool B_alive, bool C_alive) {
    int numAlive = 0;
    if (A_alive) {numAlive++;}
    if (B_alive) {numAlive++;}
    if (C_alive) {numAlive++;}
    if (numAlive >= 2) {return true;}
    else {return false;}
}

void Aaron_shoots1(bool& B_alive, bool& C_alive) {
    int shoot_result = rand() % 100;
    if (C_alive) {
        if (shoot_result <= AARON_ACC * 100) {
            C_alive = false;
        }
        else {

        }
    }
    else if (B_alive) {
        if (shoot_result <= AARON_ACC * 100) {
            B_alive = false;
        }
        else {

        }
    }
}

void Bob_shoots(bool& A_alive, bool& C_alive) {
    int shoot_result = rand() % 100;
    if (C_alive) {
        if (shoot_result <= BOB_ACC * 100) {
            C_alive = false;
        }
        else {

        }
    }
    else if (A_alive) {
        if (shoot_result <= BOB_ACC * 100) {
            A_alive = false;
        }
        else {

        }
    }
}

void Charlie_shoots(bool& A_alive, bool& B_alive) {
    int shoot_result = rand() % 100;
    if (B_alive) {
        if (shoot_result <= CHARLIE_ACC * 100) {
            B_alive = false;
        }
        else {

        }
    }
    else if (A_alive) {
        if (shoot_result <= CHARLIE_ACC * 100) {
            A_alive = false;
        }
        else {

        }
    }
}

void Aaron_shoots2(bool& B_alive, bool& C_alive) {
    int shoot_result = rand() % 100;
    if (!B_alive) {
        if (shoot_result <= AARON_ACC * 100) {
            C_alive = false;
        }
    }
    else if (!C_alive) {
        if (shoot_result <= AARON_ACC * 100) {
            B_alive = false;
        }
    }
}

void test_at_least_two_alive() {
    cout << "Unit Testing 1: Function - at_least_two_alive()" << endl;
    cout << "\tCase 1: Aaron alive, Bob alive, Charlie alive" << endl;
    assert(true == at_least_two_alive(true, true, true));
    cout << "\tCase passed ..." << endl;

    cout << "\tCase 2: Aaron dead, Bob alive, Charlie alive" << endl;
    assert(true == at_least_two_alive(false, true, true));
    cout << "\tCase passed ..." << endl;

    cout << "\tCase 3: Aaron alive, Bob dead, Charlie alive" << endl;
    assert(true == at_least_two_alive(true, false, true));
    cout << "\tCase passed ..." << endl;

    cout << "\tCase 4: Aaron alive, Bob alive, Charlie dead" << endl;
    assert(true == at_least_two_alive(true, true, false));
    cout << "\tCase passed ..." << endl;

    cout << "\tCase 5: Aaron dead, Bob dead, Charlie alive" << endl;
    assert(false == at_least_two_alive(false, false, true));
    cout << "\tCase passed ..." << endl;

    cout << "\tCase 6: Aaron dead, Bob alive, Charlie dead" << endl;
    assert(false == at_least_two_alive(false, true, false));
    cout << "\tCase passed ..." << endl;

    cout << "\tCase 7: Aaron alive, Bob dead, Charlie dead" << endl;
    assert(false == at_least_two_alive(true, false, false));
    cout << "\tCase passed ..." << endl;

    cout << "\tCase 8: Aaron dead, Bob dead, Charlie dead" << endl;
    assert(false == at_least_two_alive(false, false, false));
    cout << "\tCase passed ..." << endl;
}

void enter_prompt() {
    cout << "Press Enter to continue..." << endl;
    cin.get();
}

