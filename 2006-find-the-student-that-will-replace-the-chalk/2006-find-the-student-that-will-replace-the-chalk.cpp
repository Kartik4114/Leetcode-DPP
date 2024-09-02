class Solution {
public:
    int a1(vector<int> &chalk,int k){
        int n=chalk.size();
        int i=0;

        while(k>=0){
            k-=chalk[i%n];
            if(k<0) return i;
            i=(i+1)%n;
        }

        return -1;
    }
    int a2(vector<int> &chalk,int k){
        int n=chalk.size();

        long long sum=0;
        for(auto &c:chalk) sum+=c;
        
        int chalkLeft=(k%sum);
        
        cout<<chalkLeft<<endl;
        int i=0;
        while(chalkLeft>=0){

            chalkLeft-=chalk[i];
            if(chalkLeft<0) return i;

            i++;
        }
        return -1;

    }
    int chalkReplacer(vector<int>& chalk, int k) {
        
        // APPROACH 1:- WILL GIVE TLE BEC. K=10^9;
        // return a1(chalk,k);

        // APPROACH 2:-
        return a2(chalk,k); 
    }
};