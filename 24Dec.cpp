Wine Buying and Selling - :Given an array, Arr[] of size N represents N house built along a straight line with equal distance between adjacent houses. Each house has a certain number of wine and they want to buy/sell those wines to other houses. Transporting one bottle of wine from one house to an adjacent house results in one unit of work. The task is to find the minimum number of work is required to fulfill all the demands of those N houses.

if arr[i] < 0, then ith house wants to sell arr[i] number of a wine bottle to other houses.
if arr[i] > 0, then ith house wants to buy arr[i] number of a wine bottle from other houses.
Note: One have to print the minimum number such that, all the house can buy/sell wine to each other.
It is guaranteed that sum of all the elements of the array will be 0.




Solution - : 
class Solution{
  public:
  long long int wineSelling(vector<int>& Arr, int N){
      
        vector<pair<int,int> > buy;
        vector<pair<int,int> > sell;
        for(int i=0;i<N;i++){
            if(Arr[i]>0) buy.push_back({Arr[i],i});
            else sell.push_back({Arr[i],i});
        }
        long long int ans = 0;
        int i=0,j=0;
        while(i<buy.size() and j<sell.size()){
            long long int x = min(buy[i].first,-sell[j].first);
            buy[i].first -= x;
            sell[j].first += x;
            long long int diff = abs(buy[i].second - sell[j].second);
            ans += (x * diff);
            if(buy[i].first == 0) i++;
            if(sell[j].first == 0) j++;
        }
        return ans;
  }
};
