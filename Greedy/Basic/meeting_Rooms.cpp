#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

class Solution{
    public:
    bool canAttendMeetings(vector<vector<int>>& interval){
        if(interval.size() == 0) return true;
        vector<int> start;
        vector<int> ending;

        for(auto p: interval){
            start.push_back(p[0]);
            ending.push_back(p[1]);
        }

        sort(start.begin(), start.end());
        sort(ending.begin(), ending.end());

        int i =1;
        int j=0;
        bool flage = true;
        while(i< start.size() && j< ending.size()){
            if(start[i]< ending[j]) return false;
            else if(start[i]> ending[j]){
                flage = true;
                i++;
                j++;
            }
            else{    // tell us starting and the end timming  are equal 
                flage = true;
                i++;
                j++;
            }
        }
        return flage;

    }
};
int main(){

    vector<vector<int>> p = {{0,30},{5,10},{15,20}};

    Solution ans ;
    bool flage  = ans.canAttendMeetings(p);
    cout<< flage;

}