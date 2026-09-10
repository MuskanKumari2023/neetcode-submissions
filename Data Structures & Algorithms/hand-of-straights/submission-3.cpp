class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
       int freq[1002]={0};
       int n=hand.size();
       if(n%groupSize!=0)return false;
       for(int i=0;i<n;i++)freq[hand[i]]++;
       for(int card=0;card<=1000;card++){
        while(freq[card]>0){
            for(int j=0;j<groupSize;j++){
                int cur_card=card+j;
                if(freq[cur_card]==0)return false;
                freq[cur_card]--;
            }
        }
       }
       return true;
    }
};
