bool sortcol(const vector<int>&v1, const vector<int>&v2){
        return v1[1]>v2[1];
    }
class Solution {
public:
    
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int max_unit=0, i=0;
        sort(boxTypes.begin(), boxTypes.end(), sortcol);
        while(truckSize>0 && i<boxTypes.size()){
            int no=boxTypes[i][0];
            int units=boxTypes[i][1];
            if(no<=truckSize){
                max_unit+=no*units;
                truckSize-=no;
            }
            else{
                max_unit+=truckSize*units;
                truckSize=0;
            }
            i++;
        }
        return max_unit;
    }
};