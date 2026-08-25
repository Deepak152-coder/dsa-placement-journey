#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    bool isVowel(char ch)
    {

        bool ans = ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' ||
                   ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' ||
                   ch == 'O' || ch == 'U';

        return ans;
    }

    string reverseVowels(string s)
    {

        int i = 0;
        int j = s.size() - 1;

        while (i <= j)
        {

            if (!isVowel(s[i]))
            {
                i++;
            }

            if (!isVowel(s[j]))
            {
                j--;
            }
            else if (isVowel(s[i]) && isVowel(s[j]))
            {
                swap(s[i], s[j]);

                i++;
                j--;
            }
        }

        return s;
    }
};

int main()
{

    Solution obj;

    string s = "hello";

    string ans = obj.reverseVowels(s);

    cout << "Original: " << s << endl;
    cout << "Result: " << ans << endl;

    return 0;
}