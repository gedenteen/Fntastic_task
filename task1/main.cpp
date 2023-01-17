#include <iostream>
#include <string>
#include <map>

int main()
{
    std::string s;
    std::cout << "Input string:\n";
    std::getline(std::cin, s); /* get string with spaces */
    
    std::map<char, int> freq; /* hash table for counting how many times different characters occur */
    int s_len = s.length();

    for (int i = 0; i < s_len; i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            /* convert upper case character to lower case */
            s[i] = s[i] - ('A' - 'a');
        }
        freq[s[i]]++; /* increase the counter of character s[i] */
    }

    /* convert string */
    for (int i = 0; i < s_len; i++) {
        if (freq[s[i]] == 1) {
            s[i] = '(';
        }
        else if (freq[s[i]] > 1) {
            s[i] = ')';
        }
        else {
            std::cout << "error occuruied: freq[s[" << i << "]] = " << freq[s[i]] << "\n";
            return 1;
        }
    }

    std::cout << "Converted string:\n" << s;

    return 0;
}