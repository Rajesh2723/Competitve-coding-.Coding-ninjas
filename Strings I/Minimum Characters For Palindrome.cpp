/*
Problem statement
Given a string STR of length N. The task is to return the count of minimum characters to be added at front to make the string a palindrome.

For example, for the given string “deed”, the string is already a palindrome, thus, minimum characters needed are 0.

Similarly, for the given string “aabaaca”, the minimum characters needed are 2 i.e. ‘a’ and ‘c’ which makes the string “acaabaaca” palindrome.

Detailed explanation ( Input/output format, Notes, Images )
Constraints :
1 <= T <= 10 
1 <= N <= 10 ^ 5 
STR contains only lowercase English letters.

Time limit: 1 sec
Sample input 1 :
2
abcd
dad 
Sample output 1 :
3
0
Explanation of sample input 1 :
For test case 1 : 
Minimum characters to be added at front to make it a palindrome are 3 i.e. “dcb” which makes the string “dcbabcd”.  

For test case 2 :
The string is already a palindrome, we do not need to add any character.     
Sample input 2 :
2
xxaxxa    
abb
Sample output 2 :
1
2
  */

int minCharsforPalindrome(string str) {
	int i=0;
	int j=str.size()-1;
	int k=j;
	int c=0;
	while(i<=j){
		if(str[i]==str[j]){
			i++;
			j--;
		}else{
			i=0;
			k--;
			j=k;
			c++;
		}
	}
	return c;
	
}
/*
/*
    Time complexity: O(N)
    Space complexity: O(N)
    
    Where N is length of the string.    
*/

#include <vector>

// Function for calculating lps array
vector<int> calculateLPSArray(string str)
{
    int m = str.length();
    vector<int> lps(m);

    int len = 0;

    // As, lps[0] is always 0
    lps[0] = 0;

    // The loop calculates lps[i] for i = 1 to M-1.
    int i = 1;
    while (i < m)
    {
        // We get new prefix and new suffix, so increase length of  current lps by 1 and go to next iteration.
        if (str[i] == str[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            // Don't increment i here
            if (len != 0)
            {
                len = lps[len - 1];
            }
            else
            {
                // There isn't any lps ends with pat[i], so set lps[i] = 0 and go to next iteration.
                lps[i] = 0;
                i++;
            }
        }
    }

    return lps;
}

// Function for reverse a string
string reverse(string s)
{

    int n = s.length();

    for (int i = 0; i < n / 2; i++)
    {
        char temp = s[i];
        s[i] = s[n - i - 1];
        s[n - i - 1] = temp;
    }

    return s;
}

int minCharsforPalindrome(string str)
{
    string revStr = reverse(str);

    // Concatenate string with $ symbol and reverse string.
    string concat = str + "$" + revStr;

    // Get LPS array of this concatenated string
    vector<int> lps = calculateLPSArray(concat);

    return (str.length() - lps[lps.size() - 1]);
}
*/
