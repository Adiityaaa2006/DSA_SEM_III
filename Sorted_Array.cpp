// Problem Statement :
/* For a given number of integers, select a data structure to rearrange it such that every second element becomes 
greater than its left and right elements. Assume no duplicate elements are present in the list of integers  */

#include <bits/stdc++.h> 
using namespace std; 
 
int main() 
{ 
    int x; 
    cout << "Enter Number of elements to be stored in array :"; 
    cin >> x; 
    int n[10]; 
 
    cout << "Enter the elements of the array :" << endl; 
    for (int i = 0; i < x; i++) 
    { 
        cin >> n[i]; 
    } 
 
    cout << "Array = ["; 
    for (int i = 0; i < x; i++) 
    { 
        cout << n[i] << " "; 
    } 
    cout << "]" << endl; 
 
    for (int i = 1; i < x; i+=2) 
    { 
        if (i+1<x && n[i] < n[i + 1]) 
        { 
            int temp = n[i]; 
            n[i] = n[i + 1]; 
            n[i + 1] = temp; 
        } 
        if(n[i]<n[i-1]) 
        { 
            int temp = n[i]; 
            n[i] = n[i - 1]; 
            n[i - 1] = temp; 
        } 
    } 
 
    cout << "Array = ["; 
    for (int i = 0; i < x; i++) 
    { 
        cout << n[i] << " "; 
    } 
    cout << "]" << endl; 
    return 0; 
}