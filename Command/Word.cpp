#include "Word.h"

bool operator < (const p_IS &x, const p_IS &y)
{
	return x.first < y.first || (x.first == y.first && x.second.size() < y.second.size());
}

int Word::minLevel = -1;
int Word::maxLevel = 6;
int Word::defaultLevel = 2;
int Word::maxSentenceSize = 2;

void Word::clear()
{
	name = "";
	clearMeaning();
	clearSentence();
	level = defaultLevel;
};

void Word::updateName(std::string newName)
{
	name = newName;
}

void Word::updateMeaning(std::string newMeaning)
{
	curMeaningSize++;
	meaning.push_back(newMeaning);
}

void Word::clearMeaning()
{
	curMeaningSize = 0;
	meaning.clear();
}

void Word::updateSentence(std::string newSentence)
{
	if (curSentenceSize == maxSentenceSize) return;
	if (newSentence.size() == 0) return;

	curSentenceSize++;
	sentence.insert(std::make_pair(curSentenceSize - 1, newSentence));
}

void Word::deleteSentence(int label)
{
	if (label < 0 || label >= curSentenceSize) return;

	curSentenceSize--;
	std::string ept = "";
	auto iter = sentence.lower_bound(std::make_pair(label, ept));
	sentence.erase(iter);

	std::set <p_IS> replace;
	int relab = 0;
	for (auto iter = sentence.begin(); iter != sentence.end(); iter++, relab++)
	{
		replace.insert(std::make_pair(relab, iter->second));
	}
	sentence = replace;
	replace.clear();
}

void Word::clearSentence()
{
	curSentenceSize = 0;
	sentence.clear();
}

void Word::setParameter(bool recite)
{
	int delta = (recite == true ? 1 : -1);
	setLevel(delta);
}

void Word::setLevel(int delta)
{
	if (delta >= minLevel && delta <= maxLevel)
	{
		level = delta;
	}
}

void Word::incLevel(int delta)
{
	level += delta;
	if (level > maxLevel) level = maxLevel;
}

void Word::decLevel(int delta)
{
	level -= delta;
	if (level < minLevel) level = minLevel;
}

void Word::setComplete()
{
	setLevel(-1);
}

std::string Word::getName() const
{
	return name;
}

int Word::getMeaningSize() const
{
	return curMeaningSize;
}

std::string Word::getMeaning(int label) const
{
	return meaning[label];
}

int Word::getSentenceSize() const
{
	return curSentenceSize;
}

std::string Word::getSentence(int label) const
{
	std::string ept = "";
	auto iter = sentence.lower_bound(std::make_pair(label, ept));
	return iter->second;
}

int Word::getLevel() const
{
	return level;
}

std::ostream &operator << (std::ostream &out, const Word &word)
{
	out << word.name << std::endl << std::endl;
	out << "Meaning:" << std::endl;
	for (size_t i = 0; i < word.meaning.size(); i++)
	{
		out << i << ". " << word.meaning[i] << std::endl;
	}
	out << "Sentence:" << std::endl;
	for (auto i = word.sentence.begin(); i != word.sentence.end(); i++)
	{
		out << i->first << ". " << i->second << std::endl;
	}
	return out;
}

void Word::output() const
{
	std::cout << this;
}

int Word::getMinLevel()
{
	return minLevel;
}

int Word::getMaxLevel()
{
	return maxLevel;
}

int Word::getDefaultLevel()
{
	return defaultLevel;
}
