class Solution {
public:
    bool count (vector<int>& tasks, vector<int>& workers, int pills, int strength,int mid){

        int pillsUsed=0;
        multiset<int> st(workers.begin(),workers.begin()+mid);

        for(int i=mid-1;i>=0;i--){
            
            int req=tasks[i];
            auto it=prev(st.end());

            if(*it>=req){
                st.erase(it);
            } else if(pillsUsed>=pills){
                return false;
            } else {

                auto weakestWorkerIt=st.lower_bound(req-strength);

                if(weakestWorkerIt==st.end()) return false;
                st.erase(weakestWorkerIt);
                pillsUsed++;
            }

        }

        return true;
    }
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        
        int m=tasks.size();
        int n=workers.size();

        sort(tasks.begin(),tasks.end());
        sort(workers.begin(),workers.end(),greater<int>());

        int l=0;
        int r=min(m,n);
        int result=0;

        while(l<=r){

            int mid=l+(r-l)/2;

            if(count(tasks,workers,pills,strength,mid)){
                result=mid;
                l=mid+1;
            } else {
                r=mid-1;
            }
        }

        return result;
    }
};