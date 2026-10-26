//i am going to use radix sort because it sort the tracking numbers in 
//ascending order in (O(dn)), where (d <= 9) so the number of digits is bounded by 9 which 
//is linear time so it can use counting sort for each digit, this satisfy the 1st constraints

//for 2nd constraints we need O(log n) space complexity so we need to use in-place algoritm, merge and
//quick sort need O(n) auxiliary memory

#include <iostream>
#include <string>
using namespace std;

class Parcel{
	public:
		int trackingNumber;
	    string sender;
	    string destination;
	    int regionCode;
	    
	    Parcel(){
	    	trackingNumber = 0;
		    sender = " ";
		    destination = " ";
		    regionCode = 0000;
		}
		
		Parcel(int t, string s, string d, int r){
	    	trackingNumber = t;
		    sender = s;
		    destination =  d ;
		    regionCode = r;
		}
};

void countingSort(Parcel arr[], int n, int exp) {
    Parcel output[n];
    int count[10] = {0};

    for (int i = 0; i < n; i++) {
        int digit = (arr[i].trackingNumber / exp) % 10;
        count[digit]++;
    }

    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        int digit = (arr[i].trackingNumber / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

void radixSort(Parcel arr[], int n) {
    int maxNumber = arr[0].trackingNumber;

    for (int i = 1; i < n; i++) {
        if (arr[i].trackingNumber > maxNumber) {
            maxNumber = arr[i].trackingNumber;
        }
    }

    for (int exp = 1; maxNumber / exp > 0; exp *= 10) {
        countingSort(arr, n, exp);
    }
}

int main() {
    int n;

    cout << "Enter number of parcels: ";
    cin >> n;
    Parcel arr[n];

    for (int i = 0; i < n; i++) {
        cout << "Enter tracking number, sender, destination, region code: ";
        cin >> arr[i].trackingNumber >> arr[i].sender >> arr[i].destination >> arr[i].regionCode;
    }
    
    cout << "\nParcels by tracking number:\n";
    
    for (int i = 0; i < n; i++) {
        cout << arr[i].trackingNumber << " " << arr[i].sender << " " << arr[i].destination << " " << arr[i].regionCode << endl;
    }
    
    radixSort(arr, n);

    cout << "\nParcels sorted by tracking number:\n";

    for (int i = 0; i < n; i++) {
        cout << arr[i].trackingNumber << " " << arr[i].sender << " " << arr[i].destination << " " << arr[i].regionCode << endl;
    }

    return 0;
}

//Part 2: 
// quick sort worse case Time Complexity is O(n^2)
//the above algortim full fills these properties:
// worst-case time = O(n log n)
// auxiliray space = O(log n)
//stability = parcels with equal region codes retain their original relative order

