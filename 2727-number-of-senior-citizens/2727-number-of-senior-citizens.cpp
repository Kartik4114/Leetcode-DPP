class Solution {
public:
    int countSeniors(vector<string>& details) {
        
        int ageCnt=0;
        for(auto str:details){

            int ageIdx1=str[11]-'0';
            int ageIdx2=str[12]-'0';
            int age=ageIdx1*10+ageIdx2;

            if(age>=61) ageCnt++;
        }
        return ageCnt;
    }
};