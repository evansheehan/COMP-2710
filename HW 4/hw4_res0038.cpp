// Evan Sheehan
// res0038
// hw4_res0038.cpp
// Chapter 9 slides & http://www.cplusplus.com/reference/fstream/fstream/


#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

const int MAX_SIZE = 100;

int readFile(int array[], ifstream& inStream);
void printArray(int array[], int arraySize);
void printOutArray(int array[], int arraySize);
int sort (int inputArray1[], int inputArray1_size, int inputArray2[], int inputArray2_size, int outputArray[]);
void writefile(int outputArray[], int outputArray_size);
int main() {

    cout << "*** Welcome to Evan Sheehan's sorting program ***\n";

    string filename;
    ifstream inStream;
    ofstream outStream;

    int iArray1[MAX_SIZE];
    int iArray1_size;
    int iArray2[MAX_SIZE];
    int iArray2_size;
    int oArray[MAX_SIZE];
    int oArray_size;

    //Prompt user for first filename
    cout << "Enter the first input file name: ";
    cin >> filename;
    filename = (char*)filename.c_str();
    inStream.open(filename);

    if (inStream.fail()) {
        cout << "Input file opening failed." << endl;
        exit(1);
    }

    iArray1_size = readFile(iArray1, inStream);

    inStream.close();
 
    cout << "The list of " << iArray1_size << " numbers in file " << filename << " is:\n";
    printArray(iArray1, iArray1_size);

    //Prompt the user for second filename
    cout << "\nEnter the second input file name: ";
    cin >> filename;
    filename = (char*)filename.c_str();
    inStream.open(filename);

    if (inStream.fail()) {
        cout << "Input file opening failed." << endl;
        exit(1);
    }

    iArray2_size = readFile(iArray2, inStream);

    inStream.close();
 
    cout << "The list of " << iArray2_size << " numbers in file " << filename << " is:\n";
    printArray(iArray2, iArray2_size);

    oArray_size = sort(iArray1, iArray1_size, iArray2, iArray2_size, oArray);
    writefile(oArray, oArray_size);

    cout << "\nThe sorted list of " << oArray_size << " integers is: ";
    printOutArray(oArray, oArray_size);

    return 0;
}

void printArray (int array[], int arraySize) {
    int index = 0;

    while (index < arraySize) {
    cout << array[index] << "\n";
    index++;
    }
}

void printOutArray (int array[], int arraySize) {
    int index = 0;

    while (index < arraySize) {
    cout << array[index] << " ";
    index++;
    }
    cout << "\n";
}

int readFile(int array[], ifstream& inStream) {
    int index = 0;

    inStream >> array[index];

    while (!inStream.eof()) {
        index++;
        inStream >> array[index];
    }
    index++;

    return index;
}

int sort (int inputArray1[], int inputArray1_size, int inputArray2[], int inputArray2_size, int outputArray[]) {
    int index1 = 0;
    int index2 = 0;
    int index3 = 0;

    while (inputArray1_size > index1 && inputArray2_size > index2) {
        if (inputArray1[index1] < inputArray2[index2]) {outputArray[index3] = inputArray1[index1]; index1++;}
        else {outputArray[index3] = inputArray2[index2]; index2++;} 
        index3++;
    }
    if (inputArray1_size > index1) {
        while (inputArray1_size > index1) {
            outputArray[index3] = inputArray1[index1];
            index1++;
            index3++;
        }
    }
    else if (inputArray2_size > index2) {
        while (inputArray2_size > index2) {
            outputArray[index3] = inputArray2[index2];
            index2++;
            index3++;
        }
    }
    return index3;
}

void writefile(int outputArray[], int outputArray_size) {
    ofstream outStream("outFile.txt");

    if (!outStream) {
        cout << "Cannot open file.\n";
    }

    for (int i = 0; i < outputArray_size; i++) {
        outStream << outputArray[i] << "\n";
    }
    outStream.close();
}
