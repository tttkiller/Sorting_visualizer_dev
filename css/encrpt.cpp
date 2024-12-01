#include <iostream>
#include <string>
#include <stack>
#include <bits/stdc++.h>
using namespace std;
string lexicographicallySmallestEncrypted(const string& original) {
    stack<char> temp;
    string encrypted;
    int n = original.size();
    int i = 0;

    while (i < n || !temp.empty()) {
        // Move as many characters as possible from Temp to Encrypted
        while (!temp.empty() && (i == n || temp.top() <= *std::min_element(original.begin() + i, original.end()))) {
            encrypted += temp.top();
            temp.pop();
        }

        // If there are still characters in Original, move the first to Temp
        if (i < n) {
            temp.push(original[i]);
            i++;
        }
    }

    return encrypted;
}

int main() {
    string original;
    cin>>original;
    std::string result = lexicographicallySmallestEncrypted(original);
    std::cout<< result << std::endl;
    return 0;
}
