#include <iostream>
using namespace std;

void displayCode(int code[], int N) {
    for (int i = 0; i < N; i++) {
        cout << code[i] << " ";
    }
    cout << endl;
}

void generateAccessCodes(int allowedDigits[], int numAllowed, int N, int S, int startIndex, 
							int currentLength, int currentSum, int currentCode[], int& count) {
	
    if (currentLength == N) { //base case: current = arr size
        if (currentSum == S) {
            count++;
            displayCode(currentCode, N);
        }
        return;
    }

    for (int i = startIndex; i < numAllowed; i++) {
        if (currentSum + allowedDigits[i] > S) {
            break;
        }
        
        currentCode[currentLength] = allowedDigits[i];
        
        generateAccessCodes(allowedDigits, numAllowed, N, S, i + 1, currentLength + 1, currentSum + allowedDigits[i],currentCode, count);
        currentCode[currentLength] = 0; //back trackign logic
    }
}

int main() {
    int numAllowed;
    cout << "Enter the number of allowed digits: ";
    cin >> numAllowed;
    int* allowedDigits = new int[numAllowed];
    
    cout << "Enter the allowed digits:" << endl;
    for (int i = 0; i < numAllowed; i++) {
        cin >> allowedDigits[i];
    }

    int N, S;
    cout << "Enter code length: ";
    cin >> N;
    cout << "Enter target sum: ";
    cin >> S;

    int* currentCode = new int[N];
    int count = 0;

    cout << "Valid Access Codes:" << endl;
    generateAccessCodes(allowedDigits, numAllowed, N, S, 0, 0, 0, currentCode, count);

    if (count == 0) {
        cout << "No valid access code exists." << endl;
    } else {
        cout << "\nTotal valid access codes: " << count << endl;
    }

    delete[] allowedDigits;
    delete[] currentCode;

    return 0;
}
