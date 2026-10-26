//(1): implementation of the code
#include <iostream>
#include <string>
using namespace std;

class Student{
	public:
		string id;
	    string name;
	    string department;
	    float cgpa;

		Student(){
			id = " ";
			name = " ";
			department = " ";
			cgpa = 0.0;
		}
		Student(string i, string n, string d, float c){
			id = i;
			name = n;
			department = d;
			cgpa = c;
		}
};

void merge(Student arr[], int left, int mid, int right) {

    int n1 = mid - left + 1;
    int n2 = right - mid;

    Student L[n1], R[n2];

    for (int i = 0; i < n1; i++){
        L[i] = arr[left + i];
    }

    for (int j = 0; j < n2; j++){
        R[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {

        if (L[i].cgpa >= R[j].cgpa) {
            arr[k] = L[i];
            i++;
        }

        else {
            arr[k] = R[j];
            j++;
        }

        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(Student arr[], int left, int right) {

    if (left >= right){
        return;
    }

    int mid = left + (right - left) / 2;

    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);

    merge(arr, left, mid, right);
}

void display(Student arr[], int n){
	
    cout << "Final Merit List:" << endl;
    cout << "==============================================================\n";
    cout << "ID\tName\t\tDepartment\tCGPA\tAward\n";
    cout << "===============================================================\n";

    for(int i = 0; i < n; i++){

        string award;

        if(arr[i].cgpa >= 3.80){
            award = "Rector's List";
        }
        else if(arr[i].cgpa >= 3.50){
            award = "Dean's List";
        }
        else{
            award = "No Award";
        }

        cout << arr[i].id << "\t" << arr[i].name << "\t\t" << arr[i].department << "\t\t" << arr[i].cgpa << "\t" << award << endl;
    }
}

int main() {

    int n;
    cout << "Enter the number of students: " << endl;
    cin >> n;


    Student arr[n];

    for(int i = 0; i < n; i++){

        cout << "\nEnter details for student " << i + 1 << endl;

        cout << "Enter student ID: ";
        cin >> arr[i].id;

        cout << "Enter student name: ";
        cin >> arr[i].name;

        cout << "Enter department: ";
        cin >> arr[i].department;

        cout << "Enter CGPA: ";
        cin >> arr[i].cgpa;

        if(arr[i].cgpa < 0 || arr[i].cgpa > 4.0){
            cout << "Enter valid CGPA between 0 and 4.0" << endl;
            return 0;
        }
    }

    cout << "\nOriginal student records:" << endl;
    for(int i = 0; i < n; i++){
        cout << arr[i].id << " " << arr[i].name << " " << arr[i].department << " " << arr[i].cgpa << endl;
    }

    mergeSort(arr, 0, n - 1);

    display(arr, n);

    return 0;
}

//(2): My chosen algorithm is Merge Sort because it works on the principle of
// divide and conquer it divides the array into smaller subarrays, sorts them,
// and merges them in descending order of CGPA when CGPAs are equal, the
// algorithm preserves their original input order, maintaining stability.

