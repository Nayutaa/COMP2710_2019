# include <iostream>
# include <stdlib.h>
# include <assert.h>
# include<ctime>

//This is a program about calculate duel Probability
//I leaned some C++ grammar from CSDN.net and C++ Primer Plus

using namespace std;

const double percentageAWin = 33;
const double percentageBWin = 50;
const double percentageCWin = 100;

bool at_least_two_alive(bool A_alive, bool B_alive, bool C_alive);
/* Input: A_alive indicates whether Aaron is alive */
/* B_alive indicates whether Bob is alive */
/* C_alive indicates whether Charlie is alive */
/* Return: true if at least two are alive */
/* otherwise return false */

void Aaron_shoots1(bool& B_alive, bool& C_alive);
/* Strategy 1: Use call by reference
 * Input: B_alive indicates whether Bob alive or dead
 * C_alive indicates whether Charlie is alive or dead
 * Return: Change B_alive into false if Bob is killed.
 * Change C_alive into false if Charlie is killed.
 */

void Bob_shoots(bool& A_alive, bool& C_alive);
/* Call by reference
 * Input: A_alive indicates if Aaron is alive or dead
 * C_alive indicates whether Charlie is alive or dead
 * Return: Change A_alive into false if Aaron is killed.
 * Change C_alive into false if Charlie is killed.
 */

void Charlie_shoots(bool& A_alive, bool& B_alive);
/* Call by reference
 * Input: A_alive indicates if Aaron is alive or dead
 * B_alive indicates whether Bob is alive or dead
 * Return: Change A_alive into false if Aaron is killed.
 * Change B_alive into false if Bob is killed.
 */

void Aaron_shoots2(bool& B_alive, bool& C_alive);
/* Strategy 2: Use call by reference
 * Input: B_alive indicates whether Bob alive or dead
 * C_alive indicates whether Charlie is alive or dead
 * Return: Change B_alive into false if Bob is killed.
 * Change C_alive into false if Charlie is killed.
 */

bool at_least_two_alive(bool A_alive, bool B_alive, bool C_alive) {
	int n = 0;
	if (A_alive)
		n++;
	if (B_alive) 
		n++;
	if (C_alive)
		n++;

	if (n < 2)
		return false;
	else
		return true;
}

void test_at_least_two_alive(void) {
    cout << "Unit Testing 1: Function - at_least_two_alive()\n";
    
    cout << "    Case 1: Aaron alive, Bob alive, Charlie alive\n";
    assert(true == at_least_two_alive(true, true, true));
    cout << "    Case passed ...\n";
    
    cout << "    Case 2: Aaron dead, Bob alive, Charlie alive\n";
    assert(true == at_least_two_alive(false, true, true));
    cout << "    Case passed ...\n";
    
    cout << "    Case 3: Aaron alive, Bob dead, Charlie alive\n";
    assert(true == at_least_two_alive(true, false, true));
    cout << "    Case passed ...\n";
    
    cout << "    Case 4: Aaron alive, Bob alive, Charlie dead\n";
    assert(true == at_least_two_alive(true, true, false));
    cout << "    Case passed ...\n";
    
    cout << "    Case 5: Aaron dead, Bob dead, Charlie alive\n";
    assert(false == at_least_two_alive(false, false, true));
    cout << "    Case passed ...\n";
    
    cout << "    Case 6: Aaron dead, Bob alive, Charlie dead\n";
    assert(false == at_least_two_alive(false, true, false));
    cout << "    Case passed ...\n";
    
    cout << "    Case 7: Aaron alive, Bob dead, Charlie dead\n";
    assert(false == at_least_two_alive(true, false, false));
    cout << "    Case passed ...\n";
    
    cout << "    Case 8: Aaron dead, Bob dead, Charlie dead\n";
    assert(false == at_least_two_alive(false, false, false));
    cout << "    Case passed ...\n";
}

void Aaron_shoots1(bool& B_alive, bool& C_alive) {
    int shoot_target_result = rand() % 100;
    if (shoot_target_result <= percentageAWin) {
        if (C_alive)
            C_alive = false;
        else 
            B_alive = false;
    }
}

void Bob_shoots(bool& A_alive, bool& C_alive) {
    int shoot_target_result = rand() % 100;
    if (shoot_target_result <= percentageBWin) {
        if (C_alive)
            C_alive = false;
        else
            A_alive = false;
    }
}

void Charlie_shoots(bool& A_alive, bool& B_alive) {
    int shoot_target_result = rand() % 100;
    if (shoot_target_result <= percentageCWin) {
        if (B_alive)
            B_alive = false;
        else
            A_alive = false;
    }
}

void Aaron_shoots2(bool& B_alive, bool& C_alive) {
	if (B_alive == true && C_alive == true) {
		return;
	}
    else {
        int shoot_target_result = rand() % 100;
        if (shoot_target_result <= percentageAWin) {
            if (C_alive) {
                C_alive = false;
            }
            else {
                B_alive = false;
            }
        }
    }
}

void prter() {
	cout << "Press Enter to continue...";
	cin.get();
}

void printPrib(int timesAWin, int timesBWin, int timesCWin, double probA, double probB, double probC) {
	cout << "Aaron won " << timesAWin << "/10000 duels or " << probA << "%" << endl;
	cout << "Bob won " << timesBWin << "/10000 duels or " << probB << "%" << endl;
	cout << "Charlie won " << timesCWin << "/10000 duels or " << probC << "%\n" << endl;
}

int main () {
    srand(time_t(0));
    int timesAWin = 0, timesBWin = 0, timesCWin = 0;
    const int maxNum = 10000;
    double probA, probB, probC;
    bool aAlive, bAlive, cAlive;
    
    cout << "*** Welcome to the Duel Simulator ***" << endl;
    
    test_at_least_two_alive();
    
	prter();
    cout << "Ready to test strategy 1 (run 10000 times):"<<endl;
	prter();
    
    for(int i = 0; i < maxNum; i++) {
        aAlive = true;
        bAlive = true;
        cAlive = true;
        
        while (at_least_two_alive(aAlive, bAlive, cAlive)) {
            if (aAlive == true) {
                Aaron_shoots1(bAlive, cAlive);
            }
            if (bAlive == true) {
                Bob_shoots(aAlive, cAlive);
            }
            if (cAlive == true) {
                Charlie_shoots(aAlive, bAlive);
            }
        }
        if (aAlive==true) {
            timesAWin++;
        }
        else if (bAlive==true) {
            timesBWin++;
        }
        else {
            timesCWin++;
        }
    }
    //Aaron win probability
    probA = ((double)(timesAWin) / maxNum) * 100;
    //Bob win probability
    probB = ((double)(timesBWin) / maxNum) * 100;
    //Charlie win probability
    probC = ((double)(timesCWin) / maxNum) * 100;
    
    int stra1A = timesAWin;
    
	//print the data
	printPrib(timesAWin, timesBWin, timesCWin, probA, probB, probC);
    
    cout << "Ready to test strategy 2 (run 10000 times):"<<endl;
	//let user check
	prter();
    
    timesAWin = 0;
    timesBWin = 0;
    timesCWin = 0;
    
    for (int i = 0; i < maxNum; i++) {
        aAlive = true;
        bAlive = true;
        cAlive = true;
        while (at_least_two_alive(aAlive, bAlive, cAlive)) {
            if (aAlive == true) {
                Aaron_shoots2(bAlive, cAlive);
            }
            if (bAlive == true) {
                Bob_shoots(aAlive, cAlive);
            }
            if (cAlive == true) {
                Charlie_shoots(aAlive, bAlive);
            }
        }
        if (aAlive == true) {
            timesAWin++;
        }
        else if (bAlive == true) {
            timesBWin++;
        }
        else {
            timesCWin++;
        }
    }
	//Aaron win probability
    probA = ((double)(timesAWin) / maxNum) * 100;
	//Bob win probability
    probB = ((double)(timesBWin) / maxNum) * 100;
	//Charlie win probability
    probC = ((double)(timesCWin) / maxNum) * 100;

	//print the data
	printPrib(timesAWin, timesBWin, timesCWin, probA, probB, probC);
    
    if (stra1A > timesAWin)
        cout << "Strategy 1 is better than strategy 2."<<endl;
    else
        cout << "Strategy 2 is better than strategy 1."<<endl;
    
    return 0;
}
