class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = -1,sell = -1;
        int i = 0, j = 0;//count
        int ans = 0;
        int size = prices.size();
        while(j < size){
            while(i < size){
                if(buy == -1 && sell == -1){
                    buy = prices.at(i);
                    ++j;
                    if(j < size){
                        sell = prices.at(j);
                    }
                    else{
                        break;
                    }
                    while(j < size){
                        if(sell > buy){//make profit
                            if(j+1 < size){
                                if(prices.at(j+1) >= sell){
                                    ++j;
                                    sell = prices.at(j);
                                }
                                else{//sell it
                                    ans += sell - buy;
                                    ++j;
                                    i = j;
                                    buy = -1;
                                    sell = -1;
                                    break;
                                }
                            }
                            else{//sell it
                                ans += sell - buy;
                                ++j;
                                i = j;
                                buy = -1;
                                sell = -1;
                                break;
                            }
                        }
                        else{//restart again
                            i = j;
                            buy = -1;
                            sell = -1;
                            break;
                        }
                    }
                }
                else{
                    printf("you should not be here");
                }
            }//i<size
        }//j<size
        return ans;
    }
};