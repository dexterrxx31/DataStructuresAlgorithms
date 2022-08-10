int coinChange(vector<int>& coins, int amount) 
{
        vector<int> t(amount + 1 , 0 ) ;
        for(int i = 1 ; i <= amount ; i++)
        {
            t[i] = INT_MAX ;
            for(int x : coins) if(i - x >= 0 and t[i-x] != INT_MAX) t[i] = min(t[i] , t[i-x] + 1);
        }
        return t[amount]==INT_MAX?-1:t[amount] ;
}
