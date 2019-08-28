#include <cmath>
#include <iostream>
//Boyang yu
//bzy0015
//hw2_bzy0015.cpp
//This is a program about calculate loans
//I leaned some C++ grammar from CSDN.net and C++ Primer Plus

using namespace std;


int main() {
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

	double loanAmount, interRateY, interRateM, monthlyPaments, inter = 0, principal = 0,
		displayRate, totalInter = 0, lastMonthPament;
	int month = 0;

	cout << "Loan Amount: ";
	cin >> loanAmount;
	cout << "Interest Rate (% per year): ";
	cin >> interRateY;
	cout << "Monthly Payments: ";
	cin >> monthlyPaments;

	interRateM = interRateY / 12;
	displayRate = interRateM;
	interRateM *= 0.01;

	//If can not pay off
	if (interRateM * loanAmount > monthlyPaments) {
		cout << "You need to increase your monthly payment to pay off the loan.";
	}
	//Can pay the loan normally
	else {
		cout << "******************************************************" << endl
			<< "	 Amortization Table " << endl << "******************************************************" << endl
			<< "Month	Balance	Payment Rate	Interest Principal" << endl << month << "	$" << loanAmount
			<< " N/A	" << "N/A\tN/A\tN/A" << endl;
		do {
			//Deal with last pament
			if (loanAmount <= monthlyPaments) {
				month++;
				inter = interRateM * loanAmount;
				lastMonthPament = loanAmount + inter;
				loanAmount -= monthlyPaments;
				monthlyPaments = loanAmount + monthlyPaments;
				cout << month << "      $" << "0.00" << " $" << lastMonthPament << " " << displayRate
					<< "	$" << inter << " $" << monthlyPaments << endl;
				totalInter = inter + totalInter;
				break;
			}
			else {
				//Calulat the loan
				month++;

				inter = interRateM * loanAmount;
				principal = monthlyPaments - inter;
				loanAmount -= principal;
				cout << month << "      $" << loanAmount << " $" << monthlyPaments << " " << displayRate
					<< "	$" << inter << " $" << principal << endl;

				totalInter = inter + totalInter;
			}

		} while (loanAmount >= 0);

		cout << "******************************************************" << endl << endl << "It takes "
			<< month << " months to pay off the loan."
			<< endl << "Total interest paid is : $" << totalInter;
	}


	return 0;
}