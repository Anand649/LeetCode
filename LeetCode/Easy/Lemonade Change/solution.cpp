class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        if(bills[0]!=5) return false;
        int fives=0,tens=0;
        for(int i=0;i<bills.size();i++)
        {
            if(bills[i]==5){
                fives++;
                continue;
            }
            else if(bills[i]==10){
                if(fives>0) {
                    fives--;   
                }
                else return false; 
                tens++;
            }
            else
            {
                if(fives>0 && tens>0)
                {
                    tens--; fives--;
                } 
                else if(fives>2)
                {
                    fives-=3;
                }
                else return false;
            }
        }
        return true;
    }
};