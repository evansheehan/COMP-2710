//Evan Sheehan
//res0038
//hw1_res0038.cpp
//This program calculates how much diet coke is fatal.
//Savitch, Walter. (2013). Absolute C++ 5th Ed.

#include <iostream>
using namespace std;

double mouseWeight;
double fatalSweetener;
double friendWeight;
double fatalCoke;
double const SWEETENER_PCT = 0.001;
double CalculateFatalAmt(double mouseWeightIn, double fatalSweetenerIn, double friendWeightIn);

int main() {

    cout << "Please input the weight of the mouse in kg" << endl;
    cin >> mouseWeight;
    cout << "Please input the fatal amount of sweetener for mouse in kg" << endl;
    cin >> fatalSweetener;
    cout << "Please input the weight of your dear friend in kg" << endl;
    cin >> friendWeight;
    fatalCoke = CalculateFatalAmt(mouseWeight, fatalSweetener, friendWeight);
    cout << "The fatal amount of Diet Coke for your friend is: " << fatalCoke << " kg" << endl;


    return 0;
}

double CalculateFatalAmt (double mouseWeightIn, double fatalSweetenerIn, double friendWeightIn) {

    return (fatalSweetenerIn * friendWeightIn)/(mouseWeightIn * SWEETENER_PCT);

}