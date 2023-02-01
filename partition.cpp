

bool ispossible(vector<int> &arr, int n, int k, int mid){
    int paintingcount=1,sumcount=0;
    if(n<k) return false;
    for(int i=0;i<n;i++){
        if((sumcount+arr[i])<=mid){
            sumcount+=arr[i];
        }
        else{
            paintingcount++;
            if(paintingcount>k || arr[i]>mid) return false;
           
            sumcount=arr[i];
        }
    }
    return true;
}

int findLargestMinDistance(vector<int> &boards, int k)
{
    //    Write your code here
    int left=0;
    int right;
   
    int n= boards.size();
   
    //if(n<k) return -1;
   
   
    int sum=0;
   
    for(int i=0;i<n;i++) sum+=boards[i];
   
    right= sum;
   
    int ans=-1;
   
    int mid=left+(right-left)/2;
   
    while(left<=right){
        if(ispossible(boards,n,k,mid)){
            ans=mid;
            right=mid-1;
        }
        else{
            left=mid+1;
        }
        mid=left+(right-left)/2;
    }
   
    return ans;
   
}
