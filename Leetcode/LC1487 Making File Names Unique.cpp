class Solution {
public:
    unordered_map<string,int> table;
    vector<string> getFolderNames(vector<string>& names) {
        vector<string> ans;
        for(int i=0;i<names.size();++i){
            if(table.count(names[i]) == 0){
                table[names[i]] = 1;
                ans.push_back(names[i]);
            }
            else{
                int k = table[names[i]];
                string temp = names[i]+"("+to_string(k)+")";
                while(table.count(temp) >0){
                    k++;
                    temp = names[i]+"("+to_string(k)+")";
                }
                ans.push_back(temp);
                table[names[i]] = k;
                table[temp] = 1;
            }
            
        }
        return ans;
    }
};