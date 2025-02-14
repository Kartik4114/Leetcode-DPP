class ProductOfNumbers {
public:
    vector<int> productNum;
    vector<int> zeroCnt;
    
    ProductOfNumbers() {
        productNum.clear();
        zeroCnt.clear();
    }
    
    void add(int num) {
        if (num == 0) {
            productNum.push_back(1);  // Reset product tracking
            zeroCnt.push_back((zeroCnt.empty() ? 0 : zeroCnt.back()) + 1);
        } else {
            if (productNum.empty()) {
                productNum.push_back(num);
            } else {
                productNum.push_back(productNum.back() * num);
            }
            zeroCnt.push_back(zeroCnt.empty() ? 0 : zeroCnt.back());
        }
    }
    
    int getProduct(int k) {
        int n = productNum.size();
        if (zeroCnt[n - 1] - (n - k - 1 >= 0 ? zeroCnt[n - k - 1] : 0) > 0) {
            return 0;
        }
        if (n - k - 1 >= 0) {
            return productNum.back() / productNum[n - k - 1];
        }
        return productNum.back();
    }
};
