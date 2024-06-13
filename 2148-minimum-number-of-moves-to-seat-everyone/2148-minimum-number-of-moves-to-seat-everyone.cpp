class Solution {
public:
    int a1(vector<int>& seats, vector<int>& students){

        int n=seats.size();
        sort(seats.begin(),seats.end());
        sort(students.begin(),students.end());
        
        int cnt=0;
        
        for(int i=0;i<n;i++){
            cnt+=abs(seats[i]-students[i]);
        }
        
        return cnt;
    }

    int a2(vector<int>& seats, vector<int>& students){

        int n=seats.size();

        vector<int> position_seats(101,0);
        vector<int> position_stud(101,0);

        for(auto &x : seats) position_seats[x]++;
        for(auto &x : students) position_stud[x]++;

        int i=0,j=0;
        int moves=0;

        // here instead of going till 100 we can find max number of seats 
        // and students first then go till that max value.
        
        while(i<=100 && j<=100){

            if(position_seats[i]==0) i++;
            if(position_stud[j]==0) j++;

            if(i<=100 && j<=100 && position_seats[i]!=0 && position_stud[j]!=0){

                moves+=abs(i-j);
                position_seats[i]--;
                position_stud[j]--;
                
            }
        }

        return moves;

    }
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
    
    // APPROACH 1:- USING SORTING 
    // T.C:- O(nlogn) , S.C :- O(1)
        return a1(seats,students);

    // APPROACH 2:- USING COUNT SORT
    // T.C :- O(N) , S.C :- O(N)
        return a2(seats,students);

    }
};
