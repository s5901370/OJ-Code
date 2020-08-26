class Solution {
public:
    bool isHappy(int n) {//check is 1 true, 2 if false
        bool ANS;
        set<int> ifin;
        while(n != 0){
            ifin.insert(n);
            vector<int> arr;
            while(n/10 != 0){
                arr.push_back(n%10);
                n/=10;
            }
            arr.push_back(n);
            int ans = 0;
            for(int i=0;i<arr.size();++i){
                ans += arr.at(i)*arr.at(i);
            }
            if(ans == 1){
                ANS = true;
                break;
            }
            else{
                if( ifin.find(ans) == ifin.end()){
                    n = ans;
                    continue;
                    
                }
                else{
                    ANS = false;
                    break;
                    
                }    
            }
        }
        return ANS;
    }
};