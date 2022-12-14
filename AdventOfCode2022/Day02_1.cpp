#ifndef _ADVENT_OF_CODE_2022_
#define _ADVENT_OF_CODE_2022_
#endif

#include <stdio.h>
#include <iostream>
#include <unordered_map>
#include <fstream> // ifstream header
#include <sstream> // stringstream header
#include <string> // getline header

#define DEBUG_ASSERT cout << "debug" <<endl
using namespace std;

namespace Advent02
{
	enum class Shape { Rock, Paper, Scissors };
	enum class Result { Loss, Draw, Win };
	int result[3][3] = { {3,0,6}, {6,3,0}, {0,6,3} };
	int result2[3][3] = { {3,4,8}, {1,5,9}, {2,6,7} };

	string input()
	{
		// setbuf(stdout, NULL);
		// freopen("input02_1.txt", "r", stdin);
		ifstream file("input02_1.txt");
		if (file.fail()) {
			DEBUG_ASSERT;
		}
		stringstream buf;
		buf << file.rdbuf();
		string contents = buf.str();
		return contents;
	}

	void Solution()
	{
		string contents = input();
		int score = 0;

		for (register int i = 0; i < contents.size(); i += 4)
		{
			int opponentShape = static_cast<int>(contents[i] - 'A');
			//int playerShape = static_cast<int>(contents[i + 2] - 'X');
			int playerResult = static_cast<int>(contents[i + 2] - 'X');

			// score += playerShape + 1 + result[playerShape][opponentShape];
			score += result2[opponentShape][playerResult];
			printf("%d\n", score);
		}
	}
}
int main()
{
	Advent02::Solution();
	return 0;
}

/*
unorderd_map
- map 보다 더 빠른 탐색 가능한 자료구조
- Pros : Hash Table로 time complexity O(1)
- Cons : key가 유사한 데이터 많으면 충돌로 성능 떨어짐 + memory
*/