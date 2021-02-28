class Solution {
public:
    bool isChangable(const string& left, const string& right)
    {
        int count = 0;
        int size = (int)left.size();
        for (int i = 0; i < size; i++)
        {
            if (left[i] == right[i])
            {
                count += 1;
            }
        }
        return count >= (size - 1);
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList)
    {
        if (find(wordList.begin(), wordList.end(), endWord) == wordList.end())
        {
            return 0;
        }

        deque<string> que;
        que.push_back(beginWord);
        int step = 0;
        while (que.empty() == false)
        {
            int size = que.size();
            for (int i = 0; i < size; i++)
            {
                string current = que.front();
                que.pop_front();
                if (current == endWord)
                {
                    return step + 1;
                }
                //将下层字符串入队
                for(auto itor = wordList.begin(); itor != wordList.end();)
                {
                    if(isChangable(current, *itor) == true)
                    {
                        que.push_back(*itor);
                        itor = wordList.erase(itor);
                    }
                    else
                    {
                        ++itor;
                    }
                }
            }
            step += 1;
        }
        return 0;
    }
};
