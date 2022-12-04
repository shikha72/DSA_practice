class Solution {
public:
    void moveZeroes(vector<int>& arr) {
        int j=-1, n=arr.size();
	    for(int i=0;i<n;i++){
	        if(arr[i]!=0){
	            j++;
	            swap(arr[j],arr[i]);
	        }
	    }
	    j++;
	    for(j;j<n;j++){
	        arr[j]=0;
	    }
    }
};