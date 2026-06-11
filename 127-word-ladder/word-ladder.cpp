class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if(wordSet.find(endWord) == wordSet.end()) return 0;

        queue<pair<string,int>> q;
        q.push({beginWord,1});

        while(!q.empty()){
            string word = q.front().first;
            int steps = q.front().second; 
            q.pop(); 
            if(word == endWord) return steps;

            for(int i = 0; i <= word.length(); i++){
                char og = word[i];
                for(int j = 'a'; j<= 'z'; j++){
                    if(j == og) continue;
                    word[i] = j;
                    if (wordSet.find(word) != wordSet.end()) {
                        q.push({word, steps + 1});
                        wordSet.erase(word); 
                    }
                }
                word[i] = og;
            }
        
        }
        return 0;
    }
};