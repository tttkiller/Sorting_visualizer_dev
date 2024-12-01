#include<bits/stdc++.h>
using namespace std;
int getMinOperations(int data_count, vector<int>& data) {  
    int left = 0, right = data_count - 1;  
    int operations = 0;  

    while (left < right) {  
        if (data[left] == data[right]) {  
            left++;  
            right--;  
        } else {  
            // We need to perform an operation  
            operations++;  
            
            // Move the pointer that points to the lesser frequency element  
            if (data[left + 1] == data[right]) {  
                // If moving left is beneficial  
                left++;  
            } else if (data[left] == data[right - 1]) {  
                // If moving right is beneficial  
                right--;  
            } else {  
                // If neither inner pair matches, just decide arbitrarily  
                // or we replace either one  
                left++;  
            }  
        }  
    }  

    return operations;  
}  

int main() {  
    int n;  
    cin >> n;  
    vector<int> data(n);    
    for (int i = 0; i < n; i++) {  
        cin >> data[i];  
    }  

    int result = getMinOperations(n, data);  
    cout << result <<endl;  

    return 0;  
}