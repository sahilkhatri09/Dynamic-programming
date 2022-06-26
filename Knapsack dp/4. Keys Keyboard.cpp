//recursive
class Solution {
    int getMin(int size,int p,int n){
        if(size == n)return 0;
        if(size > n)return 10000;
        int copy = 10000;
        if(size != p) copy = 1+ getMin(size,size,n);
        int paste = 10000;
        if(p != 0) paste = 1 + getMin(size+p,p,n);
        return  min(copy,paste);
    }
public:
    int minSteps(int n) {
        return getMin(1,0,n);
    }
};

