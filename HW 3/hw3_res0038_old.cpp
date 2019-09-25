//Evan Sheehan
//res0038
//hw3_res0038.cpp
//Compile with G++

#include <iostream>
using namespace std;

const double AARON_ACC = 1.0/3;
const double bobAcc = 0.5;
const double charlieAcc = 1.0;
bool aaronAlive = true;
bool bobAlive = true;
bool charlieAlive = true;

int numAlive();
void aaronShoot();
void bobShoot();
void charlieShoot();

int main() {

    srand(time(0));
    int random = rand() % 100;
    cout << random;



    //Strategy 1
    //Go in order of worst to best shooter. Shoot the best shooter still alive.

    /*
     * Aaron goes first, tries to shoot the best man alive
     * Bob goes seconds, tries to shoot best
     * Charlie goes third, tries to shoot best
     *
     */

    while (numAlive() > 1) {
        aaronShoot();
        bobShoot();
        charlieShoot();

        //Aaron shoots charlie if he's alive, otherwise shoot bob
        //Bob shoots charlie if he's alive, otherwise shoot aaron
        //Charlie shoots bob if he's alive, otherwise shoot aaron
    }

    //Strategy 2

    return 0;
}

void aaronShoot() {

    if (aaronAlive) {
        int random = rand() % 100;
        if (charlieAlive) {
            if (random >= AARON_ACC * 100) {
                cout << "Aaron attempts to shoot Charlie and succeeds!\n";
                charlieAlive = false;
            }
            else {
                cout << "Aaron attempts to shoot Charlie and fails!\n";
            }
        } else if (bobAlive) {
            if (random >= AARON_ACC * 100) {
                cout << "Aaron attempts to shoot Bob and succeeds!\n";
                bobAlive = false;
            } else {
                cout << "Aaron attempts to shoot Bob and fails!\n";
            }
        }
    }

    else {
        cout << "Aaron's dead! He can't shoot!\n";
    }
}

void bobShoot() {

    if (bobAlive) {
        int random = rand() % 100;
        if (charlieAlive) {
            if (random >= bobAcc * 100) {
                cout << "Bob attempts to shoot Charlie and succeeds!\n";
                charlieAlive = false;
            }
            else {
                cout << "Bob attempts to shoot Charlie and fails!\n";
            }
        } else if (aaronAlive) {
            if (random >= bobAcc * 100) {
                cout << "Bob attempts to shoot Aaron and succeeds!\n";
                aaronAlive = false;
            } else {
                cout << "Bob attempts to shoot Aaron and fails!\n";
            }
        }
    }

    else {
        cout << "Bob's dead! He can't shoot!\n";
    }

}

void charlieShoot() {

    if (charlieAlive) {
        int random = rand() % 100;
        if (bobAlive) {
            if (random >= charlieAcc * 100) {
                cout << "Charlie attempts to shoot Bob and succeeds!\n";
                bobAlive = false;
            }
            else {
                cout << "Charlie attempts to shoot Bob and fails!\n";
            }
        } else if (aaronAlive) {
            if (random >= charlieAcc * 100) {
                cout << "Charlie attempts to shoot Aaron and succeeds!\n";
                aaronAlive = false;
            } else {
                cout << "Charlie attempts to shoot Aaron and fails!\n";
            }
        }
    }

    else {
        cout << "Charlie's dead! He can't shoot!\n";
    }

}

void revive() {
    aaronAlive = true;
    bobAlive = true;
    charlieAlive = true;
}

int numAlive() {
    int count = 0;
    if (aaronAlive)
        count++;
    if (bobAlive)
        count++;
    if (charlieAlive)
        count++;
    return count;
}


