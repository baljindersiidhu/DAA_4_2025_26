class Solution {
  public:
  
    bool canPaint(vector<int>& arr, int k, long long maxTime){
        long long currSum = 0;
        int painters = 1;
        
        for(int i = 0; i < arr.size(); i++){
            
            if(arr[i] > maxTime) return false;
            
            if(currSum + arr[i] <= maxTime){
                currSum += arr[i];
            }
            else{
                painters++;
                currSum = arr[i];
            }
        }
        
        return painters <= k;
    }
  
    int minTime(vector<int>& arr, int k) {
        
        long long low = *max_element(arr.begin(), arr.end());
        long long high = accumulate(arr.begin(), arr.end(), 0LL);
        long long ans = high;
        
        while(low <= high){
            
            long long mid = low + (high - low) / 2;
            
            if(canPaint(arr, k, mid)){
                ans = mid;          
                high = mid - 1;     // try smaller
            }
            else{
                low = mid + 1;      // need more time
            }
        }
        
        return (int)ans;
    }
};
