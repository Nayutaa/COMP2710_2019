#include <cmath>
#include <iostream>
//Boyang yu
//bzy0015
//hw1_bzy0015.cpp
//This is a program calculates the fatal amonumt of soda
//I leaned some C++ grammar from CSDN.net and C++ Primer Plus

using namespace std;

int main() {
	double humanWeight, mouseWeight, mouseAmount, humanAmount;
	cout << "Please input the weight of the mouse in kg" << endl;
	cin >> mouseWeight;
	cout << "Please input the fatal amount of sweetener for mouse in kg" << endl;
	cin >> mouseAmount;
	cout << "Please input the weight of your dear friend in kg"<< endl;
	cin >> humanWeight;
	humanAmount = (mouseAmount * humanWeight) / (mouseWeight * 0.001);
	cout << "The fatal amount of Coke for your friend is: ";
	cout << humanAmount;
	cout << " kg" << endl;
	return 0;
}  
