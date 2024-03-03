class Solution{
public:
	// The main function that returns the arrangement with the largest value as
	// string.
	// The function accepts a vector of strings
	
	    
	    // Custom comparator function to compare two strings
    static bool compareStrings(string a, string b) {
        string ab = a + b;
        string ba = b + a;
        return ab > ba; // Return true if concatenating a + b gives a larger number
    }

    // The main function that returns the arrangement with the largest value as
    // string.
    // The function accepts a vector of strings
    string printLargest(int n, vector<string> &arr) {
        // Sort the array of strings using the custom comparison function
        sort(arr.begin(), arr.end(), compareStrings);

        // Concatenate the sorted strings to form the largest number
        string result = "";
        for (const string& s : arr) {
            result += s;
        }

        return result;
    }
	
};
