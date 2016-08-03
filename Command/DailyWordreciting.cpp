#include "DailyWordreciting.h"

DailyWordreciting::DailyWordreciting()
{
	clear();
}

DailyWordreciting::~DailyWordreciting()
{

}

void DailyWordreciting::push(Word *word, int x)
{
	size[x]++;
	words[x].push(word);
}

void DailyWordreciting::pop(int x)
{
	size[x]--;
	words[x].pop();
}

void DailyWordreciting::clear()
{
	for (int i = 0; i < 3; i++)
	{
		while (!words[i].empty()) pop(i);
	}
    for (int i = 0; i < 3; i++)
    {
        size[i] = 0;
    }
}

bool DailyWordreciting::isCompleted() const
{
	bool b = true;
	for (int i = 0; i < 2; i++)
	{
		if (!words[i].empty())
		{
			b = false;
			break;
		}
	}
	return b;
}
