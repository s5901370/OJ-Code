class Solution {
public:
    int l=0;
int star=0;
bool pop(vector<char> &arr){
    if(arr.size() == 0)
        return false;
    vector<char>::iterator it = arr.end(),s;
    --it;
    bool flag = false;
    while(it != arr.begin()){

        if(*it == '('){
            arr.erase(it);
            --l;
            return true;
        }
        else if(*it == '*' && !flag){
            flag = true;
            s = it;
        }
        else;
        --it;
    }
    if(*it == '('){
        arr.erase(it);
        --l;
        return true;
    }
    else{
        if(flag){
            arr.erase(s);
        }
        else{

            arr.erase(it);
        }
        --star;

        return true;
    }
        
    
}
bool find(vector<char> &arr){
    for(int i=0;i<arr.size();++i){
        printf("%c ",arr[i]);
        if(arr[i] == '('){
            bool flag = false;
            for(int j=i;j<arr.size();++j){
                if(arr[j] == '*'){
                    arr.erase(arr.begin()+j); 
                    flag =  true;
                    break;
                }
            }
            if(flag);
            else
                return false;
                
        }
    }
    return true;
}
bool checkValidString(string s) {
    l = 0;
    star = 0;
    vector<char> arr;
    cout<<s.length()<<endl;
    for(int i=0;i<s.length();++i){

        if(s[i] == '(' ){
            ++l;
            arr.push_back(s[i]);
        }
        else if(s[i] == '*'){
            ++star;
            arr.push_back(s[i]);
        }
        else{
            if(pop(arr)){
                continue;
            }
            else{
                return false;
            }
        }
    }
    if(l == 0 ){
        return true;
    }
    else if(l >0 && l <= star){
        return find(arr);
    }
    else
        return false;
}
};