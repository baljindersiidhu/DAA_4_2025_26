class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi=*max_element(piles.begin(),piles.end());
        int mini=*min_element(piles.begin(),piles.end());
        int left=1;
        int ans=0;
        int right=maxi;
        while(left<=right){
           int mid = left + (right - left) / 2;

           long long cnt=0;
            int value;
            for(int i=0;i<piles.size();i++){
             cnt += (1LL*piles[i] + mid - 1) / mid;  
                    
            }
            if(cnt<=h){
                ans= mid;
                 right=mid-1;
            }
            else{
               
                left=mid+1;
            }
        }
        return ans;
    }
};