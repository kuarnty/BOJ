#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

#define endl			'\n'

#ifndef INT_MAX
#define INT_MAX			2147483647
#define INT_MIN			-2147483648
#define LONG_LONG_MAX	9223372036854775807
#define LONG_LONG_MIN	-9223372036854775808
#endif

#define ABS(A)			(((A) > 0) ? (A) : (-A))
#define MAX(A,B)		(((A) > (B)) ? (A) : (B))
#define MIN(A,B)		(((A) < (B)) ? (A) : (B))

using namespace std;

bool check[2001] = { false, };

struct Node
{
	bool complete = false; // true, if a word is completed here
	map<char, Node*> next;
};

void pushToTrie(Node* n, const string s)
{
	for (int i = 0; i < s.length(); i++)
	{
		char letter = s[i];

		if (n->next.find(letter) != n->next.end())
			n = n->next[letter]; // if letter exists, go to the next node
		else
		{
			n->next.insert({ letter, new Node{ false, {} } }); // if letter doesn't exist, create a new node with the letter and an empty map
			n = n->next[letter]; // and go to the (new) next node
		}
	}

	n->complete = true; // mark that a word is completed here
}

//int searchColor(Node* n, const string s, const int minLength)
//{
//	int i = 0;
//
//	// skip the first minLength letters
//	// except for the first time (when minLength = 1)
//	for (; i < minLength - 1; i++)
//		n = n->next[s[i]];
//
//	for (; i < s.length(); i++)
//	{
//		char letter = s[i];
//		if (n->next.find(letter) != n->next.end()) // if letter exists, check if the word is completed here, and longer than minLength
//			if (n->next[letter]->complete/* && i + 1 >= minLength*/) // if completed (and long enough -> unnecessary check by skipping)
//				return i + 1;
//			else // not completed or shorter than minLength -> go to the next node
//				n = n->next[letter];
//		else // if long enough word doesn't exist, return -1
//			return -1;
//	}
//	// searched until end of the team name, but 
//	// 1. not completed at the end of team name
//	// 2. completed, but too long (no letter for name)
//	return -1;
//}

//int searchName(Node* n, const string namePart)
//{
//	int i = 0;
//	for (; i < namePart.length(); i++)
//	{
//		char letter = s[i];
//		if (n->next.find(letter) != n->next.end()) // if letter exists, check if the word is completed here, and longer than minLength
//			if (n->next[letter]->complete && i + 1 == namePart.length()) // if completed, and has same length of rest of the team name
//				return i + 1;
//			else // not completed or not of the length -> go to the next node
//				n = n->next[letter];
//		else // if fitting word doesn't exist, return -1
//			return -1;
//	}
//	// searched until end of the team name, but 
//	// 1. not completed at the end of team name
//	// 2. completed, but no name with length same for the nameLength
//	return -1;
//}

bool checkWord(Node* n, const string s)
{
	for (int i = 0; i < s.length(); i++)
	{
		char letter = s[i];
		if (n->next.find(letter) != n->next.end())
		{
			if (n->next[letter]->complete) // found a word
			{
				if (check[i + 1]) // just next letter is checked (while checking color) <=> the after part is one of color
					return true;
				else
					check[i] = true;
			}
			n = n->next[letter];
		}
		else // different letter found -> quit
			return false;
	}
	// checked until the end
	return false;
}

//bool checkWinnable(const string team, Node* colors, Node* names)
//{
//	int minColorLength = 1;
//	while (minColorLength < team.length())
//	{
//		int colorLen = searchColor(colors, team, minColorLength);
//		if (colorLen == -1) // no enough long color exist
//			return false;
//		else // found a color with enough length
//		{
//			// Now, need to find name, fit to the rest of the team name
//			const string restNamePart = team.substr(colorLen);
//			if (searchName(names, restNamePart) != -1) // if a name with length of exactly the length of left namePart -> Yes!
//				return true;
//			else // no fitting length of name found -> search for longer color
//			{
//				if (minColorLength >= team.length())
//					return false;
//				else
//					minColorLength = colorLen + 1;
//			}
//		}
//	}
//	// no color of enough length found
//	return false;
//}

bool checkWinnable(string team, Node* colors, Node* names)
{
	// check for color prefixes
	checkWord(colors, team);
	// reverse the check array
	reverse(check, check + team.length());
	reverse(team.begin(), team.end());
	return checkWord(names, team);
}

int main()
{
	ios::sync_with_stdio(0);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	Node* colors = new Node{ false, {} };
	Node* reverseNames = new Node{ false, {} };

	int C, N, Q;

	cin >> C >> N;
	while (C--)
	{
		string c;
		cin >> c;
		pushToTrie(colors, c);
	}
	while (N--)
	{
		string n;
		cin >> n;
		reverse(n.begin(), n.end()); // reverse names for easier search of suffixes
		pushToTrie(reverseNames, n);
	}

	cin >> Q;
	while (Q--)
	{
		fill(check, check + 2001, false);
		string team;
		cin >> team;
		cout << (checkWinnable(team, colors, reverseNames) ? "Yes" : "No") << endl;
	}

	return 0;
}