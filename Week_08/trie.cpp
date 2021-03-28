class TrieNode
{
private:
	vector<TrieNode*> links;
	bool isEnd;

public:
	TrieNode():isEnd(false), links(26, nullptr)
	{
	}

	bool Contains(char c)
	{
		return links[c - 'a'] != nullptr;
	}

	TrieNode* get(char c)
	{
		return links[c - 'a'];
	}

	void put(char c, TrieNode* node)
	{
		links[c - 'a'] = node;
	}

	void setEnd()
	{
		isEnd = true;
	}

	bool getIsEnd()
	{
		return isEnd;
	}
};

class Trie
{
private:
	TrieNode* root;
public:
	Trie()
	{
		root = new TrieNode();
	}

	void insert(const std::string& word)
	{
		TrieNode* node = root;
		int wordSize = word.size();
		for (int i = 0; i < wordSize; i++)
		{
			char c = word.at(i);
			if (node->Contains(c) == false)
			{
				node->put(c, new TrieNode());
			}
			node = node->get(c);
		}
		node->setEnd();
	}

	bool search(const std::string& word)
	{
		TrieNode* node = searchPrefix(word);
		return node != nullptr && node->getIsEnd();
	}

	bool startsWith(const std::string& word)
	{
		TrieNode* node = searchPrefix(word);
		return node != nullptr;
	}
private:
	TrieNode* searchPrefix(const std::string& word)
	{
		TrieNode* node = root;
		int wordSize = word.size();
		for (int i = 0; i < wordSize; i++)
		{
			char c = word.at(i);
			if (node->Contains(c) == true)
			{
				node = node->get(c);
			}
			else
			{
				return nullptr;
			}
		}
		return node;
	}
};
