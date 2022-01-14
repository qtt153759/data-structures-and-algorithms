#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    const vector<string> pad = {
        "", "", "abc", "def", "ghi", "jkl",
        "mno", "pqrs", "tuv", "wxyz"};

    vector<string> letterCombinations(string digits)
    {
        if (digits.empty())
            return {};
        vector<string> result;
        result.push_back("");

        for (auto digit : digits)
        {
            vector<string> tmp;
            for (auto candidate : pad[digit - '0'])
            {
                for (auto s : result)
                {
                    tmp.push_back(s + candidate);
                }
            }
            result.swap(tmp);
        }
        return result;
    }
};
int main()
{
    Solution res;
    vector<string> text = res.letterCombinations("23");
    for (int i = 0; i < text.size(); i++)
    {
        cout << text[i] << " ";
    }
}