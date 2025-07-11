class Solution {
public:

// time complexity:- O(m*n) +O(mlogn)
    int approach1(int n, vector<vector<int>>& meetings){
        int m=meetings.size();

        sort(meetings.begin(),meetings.end()); //Sort meeting based on start time.

        // here we have used long long bec. we are adding duration so may be it can 
        // go out of bound.

        vector<long long> lastAvailableAt(n,0); // room willbe available at
        vector<int> roomUsedCount(n,0); // how many times room is used

        for(vector<int> &meet :meetings){
            int start=meet[0];
            int end=meet[1];
            int duration =end-start;
            bool found=false;

            long long earlyEndRoomTime=LLONG_MAX;
            int earlyEndRoom=0;

        // finding the first available room for current meeting
            for(int room=0;room<n;room++){

                if(lastAvailableAt[room]<=start){
                    lastAvailableAt[room]=end; // current meeting will finish at end.
                    roomUsedCount[room]++;
                    found=true;
                    break;
                }

                if(lastAvailableAt[room]<earlyEndRoomTime){
                    earlyEndRoomTime=lastAvailableAt[room];
                    earlyEndRoom=room;
                }
            }

            // if we couldn't find the room
            if(!found){
                // picking the room which will end first.
                lastAvailableAt[earlyEndRoom]+=duration;
                roomUsedCount[earlyEndRoom]++;
            }
        }

        // now finding the max. used room
        int resultRoom=-1; // room no.
        int maxUse=0;

        for(int i=0;i<n;i++){
            if(roomUsedCount[i]>maxUse){
                maxUse=roomUsedCount[i];
                resultRoom=i;
            }
        }

        return resultRoom;
    }

 // APPROACH 2:- TC:- O(mlogn) , SC:- O(n)
    typedef pair<long long,int> P;
    int approach2(int n, vector<vector<int>>& meetings){

        sort(meetings.begin(),meetings.end());
        vector<int>roomUsedCount(n,0);

        priority_queue<P,vector<P>,greater<P>> usedRooms; // min-heap
        priority_queue<int,vector<int>,greater<int>> availableRooms; 

    // inputting the available rooms
        for(int room=0;room<n;room++){
            availableRooms.push(room);
        }

        for(vector<int> meet :meetings){
            int start=meet[0];
            int end=meet[1];
            int duration =end-start;

            while(!usedRooms.empty() && usedRooms.top().first<=start){
                int room=usedRooms.top().second;
                usedRooms.pop();
                availableRooms.push(room);
            }

            if(!availableRooms.empty()){
                int room=availableRooms.top();
                availableRooms.pop();
                usedRooms.push({end,room});
                roomUsedCount[room]++;
            }

            else{
                P top_element=usedRooms.top();
                usedRooms.pop();
                int room=top_element.second;
                top_element.first+=duration;
                usedRooms.push(top_element);
                roomUsedCount[room]++;
            }
        }

        int resultRoom=-1;
        int maxUse=0;

        for(int i=0;i<n;i++){
            if(roomUsedCount[i]>maxUse){
                maxUse=roomUsedCount[i];
                resultRoom=i;
            }
        }

        return resultRoom;

    }
    int mostBooked(int n, vector<vector<int>>& meetings) {

        // APPROACH 1:- TC:-O(m*n)
        // return approach1(n,meetings);

        // APPROACH 2:- TC:- O(mlogn) , SC:- O(n)

        //  here we are using min_heap.
        // intuition behind this approach is we are traversing the lastAvailable room
        // again and again for finding which is free so we will use minheap for 
        // this which will do work in logn 

         return approach2(n,meetings);


    }
};