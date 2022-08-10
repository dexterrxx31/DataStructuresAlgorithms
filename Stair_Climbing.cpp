 //Top Down Approch
vector<int> t (46 ,-1) ;
class Solution {
public:
    int climbStairs(int n) {
        //Top Down Approch
        if(n<=1) return t[n] = 1 ; 
        if(t[n] != -1)
            return t[n] ;
        else return t[n] = climbStairs(n-1) + climbStairs(n-2);
    }
};

//Bottom up Approch
class Solution {
public:
    int climbStairs(int n) {
        vector<int> t ={1,1} ;
        for(int i = 2 ; i <= n ;i++) t.push_back(t[i-1] +t[i-2]) ;
        return t[n] ;
    }
};
