class Solution {
public:
    vector<vector<string>> ans;

    void dfs(string word,string beginWord,unordered_map<string, int>& level,vector<string>& path)
    {
        if(word == beginWord)
        {
            vector<string> temp = path;
            reverse(temp.begin(), temp.end());
            ans.push_back(temp);
            return;
        }

        int currLevel = level[word];

        for(int i = 0; i < word.size(); i++)
        {
            char original = word[i];

            for(char ch = 'a'; ch <= 'z'; ch++)
            {
                word[i] = ch;

                if(level.find(word) != level.end() &&
                   level[word] == currLevel - 1)
                {
                    path.push_back(word);

                    dfs(word,
                        beginWord,
                        level,
                        path);

                    path.pop_back();
                }
            }

            word[i] = original;
        }
    }

    
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {

        unordered_set<string> st(wordList.begin(),wordList.end());

        if(st.find(endWord) == st.end())
            return {};

        queue<string> q;
        unordered_map<string, int> level;

        q.push(beginWord);
        level[beginWord] = 0;

        st.erase(beginWord);

        while(!q.empty())
        {
            string word = q.front();
            q.pop();

            int steps = level[word];

            if(word == endWord)
                break;
            for(int i = 0; i < word.size(); i++)
            {
                char original = word[i];

                for(char ch = 'a'; ch <= 'z'; ch++)
                {
                    word[i] = ch;

                    if(st.find(word) != st.end())
                    {
                        q.push(word);

                        level[word] = steps + 1;

                        st.erase(word);
                    }
                }

                word[i] = original;
            }
        }

        if(level.find(endWord) == level.end())
            return {};
        vector<string> path;
        path.push_back(endWord);
        dfs(endWord,beginWord,level,path);
        return ans;
    }
};