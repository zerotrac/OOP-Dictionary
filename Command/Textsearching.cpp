#include "Textsearching.h"

Textsearching::Textsearching()
{

}

Textsearching::~Textsearching()
{

}

Wordlist *Textsearching::search(std::string st, Wordlist *wordlist)
{
    Trie *trie = new Trie();
    trie->addWord(wordlist);

	st = st + ".";
	for (size_t i = 0; i < st.size(); i++)
	{
		st[i] = tolower(st[i]);
	}

    Wordlist *ret_wordlist = new Wordlist();
	std::string single = "";
	for (size_t i = 0; i < st.size(); i++)
	{
		if (st[i] < 'a' || st[i] > 'z')
		{
			Word *word = trie->findPreciseWord(single);
            if (word != nullptr)
            {
                bool flag = true;
                for (int j = 0; j < ret_wordlist->size(); j++)
                {
                    Word *word0 = ret_wordlist->getWord(j);
                    if (word == word0)
                    {
                        flag = false;
                        break;
                    }
                }
                if (flag)
                {
                    ret_wordlist->addWord(word);
                }
            }
			single = "";
		}
		else
		{
			single = single + st[i];
		}
	}
	
    delete trie;
    return ret_wordlist;
}
