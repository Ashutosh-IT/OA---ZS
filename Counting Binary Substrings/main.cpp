int counting(string s){
    int n = s.size();
    int ans = 0;
    
    int count1 = 0;
    int count2 = 0;
    
    int i=0;
    while(i<n){
        char num = s[i];
        while(i<n && num == s[i]){
            count2++;
            i++;
        }
        
        ans += min(count1,count2);
        count1 = count2;
        count2 = 0;
    }
    
    return ans;
}
