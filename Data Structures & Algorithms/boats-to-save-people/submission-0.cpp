class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());

        int j = people.size()-1;
        int i =0;
        int cnt = 0;
        while(i<j){
            if(people[j]+people[i]<=limit){
               j--;
               i++; 
               cnt++;
            }else{
                j--;
                cnt++;
            }
        }

        if(i==j) cnt++;
        return cnt;

        
    }
};

// 1, 3, 2, 3, 2 l =3

// 1, 2, 2, 3,3 


// 1,2,4,5