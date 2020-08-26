class Solution {
public:
    bool detectCapitalUse(string word) {
        bool ans = true;
        if(toupper(word[0]) == word[0]){
            
                if(toupper(word[1]) == word[1]){
                    for(int i=1;i<word.length();++i){
                        if(tolower(word[i]) == word[i]){
                            ans = false;
                            break;
                        }
                    }
                }
                else{
                    for(int i=1;i<word.length();++i){
                        if(toupper(word[i]) == word[i]){
                            ans = false;
                            break;
                        }
                    }
                }
            
        }
        else{
            for(int i=1;i<word.length();++i){
                if(toupper(word[i]) == word[i]){
                    ans = false;
                    break;
                }
            }
        }
        return ans;
    }
};