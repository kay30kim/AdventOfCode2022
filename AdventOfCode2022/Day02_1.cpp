#ifndef _ADVENT_OF_CODE_2022_
#define _ADVENT_OF_CODE_2022_
#endif

#include "Advent.h"

using namespace std;

namespace Advent
{
	enum class Shape { Rock, Paper, Scissors };
	enum class Result { Loss, Draw, Win };
	int result[3][3] = { {3,0,6}, {6,3,0}, {0,6,3} };
	int result2[3][3] = { {3,4,8}, {1,5,9}, {2,6,7} };

	void Solution()
	{
		string contents = input("input02_1.txt");
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

/*
unorderd_map
- map ���� �� ���� Ž�� ������ �ڷᱸ��
- Pros : Hash Table�� time complexity O(1)
- Cons : key�� ������ ������ ������ �浹�� ���� ������ + memory
*/