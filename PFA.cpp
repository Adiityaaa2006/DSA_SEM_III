#include <iostream>
#include <cmath>
using namespace std;

typedef struct {
	int coeff;
	int expo;
} poly;

class Polynomial {
public:
	poly e1[10], e2[10], result[20];
	int n1, n2, n3;
	
	void input(poly e[], int& n) {
		cout << "Enter number of terms: ";
		cin >> n;
		
		for (int i = 0; i < n; i++) {
			cout << "Enter coefficient for term " << i + 1 << ": ";
			cin >> e[i].coeff;
			cout << "Enter exponent for term " << i + 1 << ": ";
			cin >> e[i].expo;
		}
	}
	
	void display(poly e[], int n) {
		for (int i = 0; i < n; i++) {
			cout << e[i].coeff << "x^" << e[i].expo;
			if (i != n - 1)
				cout << " + ";
		}
		cout << endl;
	}
	
	void add() {
		int i = 0, j = 0;
		n3 = 0;
		
		while (i < n1 && j < n2) {
			if (e1[i].expo == e2[j].expo) {
				result[n3].coeff = e1[i].coeff + e2[j].coeff;
				result[n3].expo = e1[i].expo;
				i++;
				j++;
				n3++;
			} else if (e1[i].expo > e2[j].expo) {
				result[n3] = e1[i];
				i++;
				n3++;
			} else {
				result[n3] = e2[j];
				j++;
				n3++;
			}
		}
		
		while (i < n1) result[n3++] = e1[i++];
		while (j < n2) result[n3++] = e2[j++];
		cout << "Addition Result: ";
		display(result, n3);
	}
	
	void subtract() {
		int i = 0, j = 0;
		n3 = 0;
		
		while (i < n1 && j < n2) {
			if (e1[i].expo == e2[j].expo) {
				result[n3].coeff = e1[i].coeff - e2[j].coeff;
				result[n3].expo = e1[i].expo;
				i++;
				j++;
				n3++;
			} else if (e1[i].expo > e2[j].expo) {
				result[n3] = e1[i];
				i++;
				n3++;
			} else {
				result[n3] = e2[j];
				result[n3].coeff = -result[n3].coeff;
				j++;
				n3++;
			}
		}
		
		while (i < n1) result[n3++] = e1[i++];
		while (j < n2) {
			result[n3] = e2[j];
			result[n3].coeff = -result[n3].coeff;
			j++;
			n3++;
		}
		cout << "Subtraction Result: ";
		display(result, n3);
	}
	
	void multiply() {
		poly temp[50];
		int n = 0;
		for (int i = 0; i < n1; i++) {
			for (int j = 0; j < n2; j++) {
				temp[n].coeff = e1[i].coeff * e2[j].coeff;
				temp[n].expo = e1[i].expo + e2[j].expo;
				n++;
			}
		}
		
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				if (temp[i].expo == temp[j].expo) {
					temp[i].coeff += temp[j].coeff;
					temp[j].coeff = 0;
				}
			}
		}
		
		n3 = 0;
		for (int i = 0; i < n; i++) {
			if (temp[i].coeff != 0) {
				result[n3++] = temp[i];
			}
		}
		cout << "Multiplication Result: ";
		display(result, n3);
	}
};

int main() {
	Polynomial obj;
	
	cout << "Enter First Polynomial:\n";
	obj.input(obj.e1, obj.n1);
	
	cout << "Enter Second Polynomial:\n";
	obj.input(obj.e2, obj.n2);
	
	cout << "\nFirst Polynomial: ";
	obj.display(obj.e1, obj.n1);
	
	cout << "Second Polynomial: ";
	obj.display(obj.e2, obj.n2);
	obj.add();
	obj.subtract();
	obj.multiply();
	
	return 0;
}
