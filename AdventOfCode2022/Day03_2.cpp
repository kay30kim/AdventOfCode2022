#ifndef __ADVENTOF_CODE_2022__
#define __ADVENTOF_CODE_2022__
#endif

#include "Advent.h"

using namespace std;

namespace Advent
{
	void solution03_2()
	{
		string contents = Advent::input("input03.txt");

		localHashClear();
		int num = 0;
		int ans = 0;

		for (register int i = 0; i < contents.size(); )
		{
			register int j = i, k;
			while (contents[j] && contents[j++] != '\n');
			for (k = i; k <j ; k++)
			{
				local_hash[contents[k] - 'A'] = 10;
			}
			i = k;
			while (contents[j] && contents[j++] != '\n');
			for (k = i; k < j; k++)
			{
				if (local_hash[contents[k] - 'A'] == 10) local_hash[contents[k] - 'A'] = 5;
			}
			i = k;
			while (contents[j] && contents[j++] != '\n');
			for (k = i; k < j; k++)
			{
				if (local_hash[contents[k] - 'A'] == 5) local_hash[contents[k] - 'A'] = 7;
			}
			for (k = 0; k < 100; k++)
			{
				if (local_hash[k] == 7)	num = k;
				local_hash[k] = 0;
			}
			if (num > 26) num -= 31;
			else num += 27;
			ans += num;
			i = j;
		}
		printf("Day 03 answer : %d\n", ans);
	}
}

