int solve(vector<int> &arr){
    int n = arr.size();

    int evenSum = 0;
    int oddSum = 0;

    for(int i=0; i<n; i++){
        if(i%2 == 0) evenSum += arr[i];
        else oddSum += arr[i];
    }

    int ans = 0;

    // calculate answer by removing each element one by one
    int prefixOdd = 0;
    int prefixEven = 0;

    for(int i=0; i<n; i++){
        int remOdd, remEven;
        if(i%2 == 0){
            remOdd = oddSum - prefixOdd;
            remEven = evenSum - (prefixEven + arr[i]);
        }
        else{
            remOdd = oddSum - (prefixOdd + arr[i]);
            remEven = evenSum - prefixEven;
        }

        if(prefixEven + remOdd == prefixOdd + remEven){
            ans++;
        }

        if(i%2 == 0) prefixEven += arr[i];
        else prefixOdd += arr[i];
    }

    return ans;
}
