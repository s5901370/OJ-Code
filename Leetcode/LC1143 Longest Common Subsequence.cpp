class Solution {
public:
    int max(int a,int b,int c){
        int ans = a;
        if(ans<b)ans = b;
        if(ans<c)ans = c;
        return ans;
    }
    int max(int a,int b){
        int ans = a;
        if(ans<b)ans = b;
        return ans;
    }
    int longestCommonSubsequence(string text1, string text2) {
        int score[text1.length()+1][text2.length()+1];
        memset(score,0,sizeof(score));
        for(int i=1;i<=text1.length();++i){
            for(int j=1;j<=text2.length();++j){
                if(text1[i-1] == text2[j-1])
                    score[i][j] = score[i-1][j-1]+1;
                else
                    score[i][j] = max(score[i-1][j],score[i][j-1]);
            }
        }
        return score[text1.length()][text2.length()];
    }
};