#include <iostream>
#include <vector>
using namespace std;

#define d 256 // Number of characters in the input alphabet

vector<int> search(string text, string pattern) {
    vector<int> indices;
    int n = text.length();
    int m = pattern.length();
    const int q = 101; // A prime number
    
    int i, j;
    int p = 0; // hash value for pattern
    int t = 0; // hash value for text
    int h = 1;

    // The value of h would be "pow(d, m-1)%q"
    for (i = 0; i < m - 1; i++)
        h = (h * d) % q;

    // Calculate the hash value of pattern and first window of text
    for (i = 0; i < m; i++) {
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }

    // Slide the pattern over text one by one
    for (i = 0; i <= n - m; i++) {
        // Check the hash values of current window of text and pattern.
        // If the hash values match, then only check for characters one by one
        if (p == t) {
            // Check for characters one by one
            for (j = 0; j < m; j++) {
                if (text[i + j] != pattern[j])
                    break;
            }
            if (j == m) // if p == t and pattern[0...m-1] = text[i, i+1, ...i+m-1]
                indices.push_back(i + 1); // 1-based index
        }

        // Calculate hash value for next window of text: Remove leading digit,
        // add trailing digit
        if (i < n - m) {
            t = (d * (t - text[i] * h) + text[i + m]) % q;

            // We might get negative value of t, converting it to positive
            if (t < 0)
                t = (t + q);
        }
    }
    return indices;
}

int main() {
    string text = "birthdayboy";
    string pattern = "birth";
    vector<int> indices = search(text, pattern);
    for (int i = 0; i < indices.size(); i++) {
        cout << indices[i] << " ";
    }
    return 0;
}

