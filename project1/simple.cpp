#include <iostream>
#include <cmath>
using namespace std;


int main()
{
    int n, factorial =1;
	cout << "Enter the elements: ";
	int factorial = 1;
	cin >> n;
    int arr[10];
    cout << "Please enter "<<n<<" element: ";
	for (int i = 0; i <= n; ++i) {
        cin >> arr[i];
	}

    cout << "\n";
    
    for(int i = 1; i <= n; ++i){
        factorial *= i;
    }
	
    float sum = 0, mean, standardDeviation = 0;

	for (int i = 0; i < n; ++i) {
		sum += arr[i];
	}
    mean = sum/n;
    
	for (int i = 0; i < n; ++i) {
		standardDeviation += pow(data[i] - mean, 2);
	}
    cout << "Standard Deviation = " << sqrt(standardDeviation / n) << endl;
    cout << "Factorial of "<<n<<"="<<Factorial<<endl;
	return 0;
}
