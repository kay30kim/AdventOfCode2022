#ifndef __ADVENT_H__
#define __ADVENT_H__
#endif

#include <iostream>
#include <stdio.h>
#include <unordered_map>
#include <string> // getline header
#include <fstream> // ifstream header
#include <sstream> // stringstream header

#define DEBUG_ASSERT cout << "debug" <<endl

using namespace std;

namespace Advent
{
	static string input(string filename)
	{
		// setbuf(stdout, NULL);
		// freopen("input02_1.txt", "r", stdin);
		ifstream file(filename);
		if (file.fail())
		{
			DEBUG_ASSERT;
		}
		stringstream buf;
		buf << file.rdbuf();
		string contents = buf.str();
		return contents;
	}

	static int local_hash[100];

	void localHashClear();
	void solution03();
	void solution03_2();
	// empty;
}