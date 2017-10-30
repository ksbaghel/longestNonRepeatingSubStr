// longestNonRepeatingSubStr.cpp : Defines the entry point for the console application.
/*
Given a string,
find the length of the longest substring without repeating characters.

Example:

The longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3.

For "bbbbb" the longest substring is "b", with the length of 1.
*/

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

void print_longestNonRepeatingSubStr(string& s)
{
	int len = s.length();
	int start, end;
	start = end = 0;
	vector<int> hash(256, 0);
	int maxLen = 0;
	int startIdx = -1;

	while (start <= end && end < len)
	{
		hash[s[end]]++;

		while(start <= end && hash[s[end]] > 1)
		{
			//Now start popping out from start
			hash[s[start]]--;
			start++;
		}

		if (end - start + 1 > maxLen)
		{
			maxLen = end - start + 1;
			startIdx = start;
		}
		end++;
	}

	cout << "MaxLen : " << maxLen << "  -> " << s.substr(startIdx, maxLen) << endl;
}


int main()
{
	string s;
	cin >> s;

	print_longestNonRepeatingSubStr(s);

    return 0;
}

