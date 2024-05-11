class Solution {
public:
    double a1(vector<int>& quality, vector<int>& wage, int k) {

        int n=quality.size();
        double result=INT_MAX;
        for(int manager=0;manager<n;manager++){
            
           double manager_ratio =(double)wage[manager]/quality[manager];

           vector<double> group;
           for(int worker=0;worker<n;worker++){
                double worker_wage=manager_ratio*quality[worker];
                if(worker_wage>=wage[worker]){
                    group.push_back(worker_wage);
                }
           }
           if(group.size()<k) continue;

           priority_queue<double> pq;

           double sum_wage=0; 
           for(auto &wage: group){
                sum_wage+=wage;
                pq.push(wage);

                if(pq.size()>k){
                    sum_wage-=pq.top();
                    pq.pop();
                }
           }
           result=min(result,sum_wage); 
        }
        return result;

    }

    double a2(vector<int>& quality, vector<int>& wage, int k){
        int n=quality.size();

        double result=INT_MAX;
        vector<pair<double,int>> worker_ratio(n);

        for(int worker=0;worker<n;worker++){
            worker_ratio[worker]=make_pair((double)wage[worker]/quality[worker],quality[worker]);
        }

        sort(worker_ratio.begin(),worker_ratio.end());

        for(int manager=k-1;manager<n;manager++){

            double managerRatio=worker_ratio[manager].first;
            vector<double> group;

            for(int worker=0;worker<=manager;worker++){
                double worker_wage=managerRatio*worker_ratio[worker].second;
                group.push_back(worker_wage);
            }

            priority_queue<double> pq;

            double sum_wage=0; 
            for(auto &wage: group){
                sum_wage+=wage;
                pq.push(wage);

                if(pq.size()>k){
                    sum_wage-=pq.top();
                    pq.pop();
                }
           }
           result=min(result,sum_wage); 
        }
        return result;
  
    }

    double a3(vector<int>& quality, vector<int>& wage, int k){
          int n = quality.size();

        vector<pair<double, int>> worker_ratio(n);
        for(int worker = 0; worker < n; worker++) {
            worker_ratio[worker] = make_pair((double)wage[worker]/quality[worker], quality[worker]);
        }
        sort(begin(worker_ratio), end(worker_ratio));

        priority_queue<int, vector<int>> pq;
        
        double sum_quality = 0;
        for(int i = 0; i < k; i++) { 
            pq.push(worker_ratio[i].second); //push all qualities in max-heap
            sum_quality += worker_ratio[i].second; //Find sum of qualities
        }

        double managerRatio = worker_ratio[k-1].first; 
        double result       = managerRatio * sum_quality;

        for(int manager = k; manager < n; manager++) {
            
            managerRatio = worker_ratio[manager].first;

            pq.push(worker_ratio[manager].second); //push all qualities in max-heap
            sum_quality += worker_ratio[manager].second; //Find sum of qualities

            if(pq.size() > k) {
                sum_quality -= pq.top();
                pq.pop();
            }

            result = min(result, managerRatio*sum_quality);

        }

        return result;
    }
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        
        // APPROACH 1:- BRUTE FORCE APPROACH 
        // IT WILL GIVE TIME LIMIT EXCEEDED 
        // TIME COMPLEXITY :- O(N*(N+NLOGK)) SO O(N*N*LOGN)
            // return a1(quality,wage,k);

        // APPROACH 2:- BETTER BRUTE FORCE APPROACH
        // TIME COMPLEXITY :- O(N*(N+NLOGK)) SO O(N*N*LOGN)
            // return a2(quality,wage,k);
        
        //Approach-3 (Optimal)
        //T.C : O(nlogn + klogk + n*log(k))
        //S.C : O(n+k)
        return a3(quality,wage,k);

        

    }
};