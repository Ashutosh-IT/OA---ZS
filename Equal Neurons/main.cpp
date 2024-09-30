long solve(vector<int> &layer, int n, long target){
    long count1 = 0;
    long count2 = 0;
    
    for(int i=0; i<n; i++){
        long diff = target-layer[i];
        count1 += (diff%2);
        count2 += (diff/2);
    }
    
    // now i have value of count1 and count2
    long l1 = 2*count1 - 1;
    long l2 = 2*count2;
    
    long ans = max(l1,l2);
    while(count2 > count1){
        count2 -= 1;
        count1 += 2;
        long newAns = max(2*count1 - 1, 2*count2);
        if(newAns > ans) break;
        else ans = newAns;
    }
    
    return ans;
}

long findMinGeneration(vector<int> layer){
    int n = layer.size();
    if(n==1) return 0;
    
    int maxi = layer[0];
    for(int i=1; i<n; i++)
    maxi = max(layer[i],maxi);
    
    long opt1 = solve(layer,n,maxi);
    long opt2 = solve(layer,n,maxi+1);
    long opt3 = solve(layer,n,maxi+2);
    
    return min(opt1,min(opt2,opt3));
}
