// Time Complexity: O(n*l*26), n = size of wordlist, l = length of words
// space complexity : O(n)

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> s(wordList.begin(), wordList.end());
        
        // if destination is not present in the set means it is not in the wordlist so we cannot reach it 
        if(s.find(endWord) == s.end()){
            return 0;
        }
        
        int count = 0;
        queue<string>q;
        q.push(beginWord);
        
        while(!q.empty()){
            auto size = q.size();
            count++;
            
            while(size--){
                auto curr = q.front();
                q.pop();
                
                for(int i = 0; i < curr.size(); i++){
                    string temp = curr;
                    
                    for(char ch = 'a'; ch <= 'z'; ch++){
                        temp[i] = ch;
                        
                        if(temp.compare(curr) == 0){
                            continue;
                        }
                        
                        if(temp.compare(endWord) == 0){
                            return count + 1;
                        }
                        
                        if(s.find(temp) != s.end()){
                            q.push(temp);
                            s.erase(temp);
                        }
                    }
                }
            }
        }
        return 0;
    }
};