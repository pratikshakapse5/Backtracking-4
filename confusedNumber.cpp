//TC: O(n)
//SC: O(1)
//Approach: 2 parts to the quetion : first check if the number is a valid confusing number and second to make sure we check all the numbers in the given range-> for this we can simply use dfs with for loop based recusion. basically just consider all the numbers that involve 0,1,6,9,8 etc. this way we are not going exponentially 5^n rather we simply chck for numbers above and have a base condition that takes care of range n and as well as same number condition.  

class Solution {
public:
unordered_map<int,int> map={{0,0},{1,1},{6,9},{8,8},{9,6}};
int count=0;
    int confusingNumberII(int n) {
        
         dfs(0, n );
         return count;
    }
    void dfs(long  val, long  n){
        //base case:
        if(val>n)
            return;
        if(validConfusingNumber(val))
            count++;
        for(auto [key,value]: map)
        {
            long newnum=val*10+key;
            if(newnum!=val)
                dfs(newnum, n);
           // val/=10;
        }
    }
    bool validConfusingNumber(long  val)
    {
        long  newNum=0, temp=val;
        while(temp)
        {
            long rem=temp%10;
            newNum=newNum*10+map[rem];
            temp/=10;
        }
        return newNum!=val;
    }
};