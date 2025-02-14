class ProductOfNumbers {
public:
    vector<int>nums;
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        nums.push_back(num);
    }
    
    int getProduct(int k) {
    
        int n=nums.size();
        int pr=1;
        for(int i=n-1;i>=0 && k>0;i--){
            pr=pr*nums[i];
            k--;
        }
        return pr;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */