
struct Node {
    int maxPrefix, maxSuffix, totalSum, maxSubarraySum;
    Node() {
        maxPrefix = maxSuffix = maxSubarraySum = totalSum = 0;
    }
    Node(int val) {
        maxPrefix = maxSuffix = maxSubarraySum = totalSum = val;
    }
};

class ST {
public:
    vector<Node> seg;
    ST(int n) {
        seg.resize(4 * n + 1);
    }

    Node merge(Node left, Node right) {
        Node parent;
        parent.totalSum = left.totalSum + right.totalSum;
        parent.maxPrefix = max(left.maxPrefix, left.totalSum + right.maxPrefix);
        parent.maxSuffix = max(right.maxSuffix, right.totalSum + left.maxSuffix);
        parent.maxSubarraySum = max({left.maxSubarraySum, right.maxSubarraySum, left.maxSuffix + right.maxPrefix});
        return parent;
    }

    void build(int ind, int low, int high, vector<int>& a) {
        if (low == high) {
            seg[ind] = Node(a[low]);
            return;
        }
        int mid = low + (high - low) / 2;
        build(2 * ind + 1, low, mid, a);       
        build(2 * ind + 2, mid + 1, high, a);   
        seg[ind] = merge(seg[2 * ind + 1], seg[2 * ind + 2]);
    }

    Node query(int ind, int low, int high, int l, int r) {
        if (low > r || high < l) {
            return Node(INT_MIN); 
        }
        if (low >= l && high <= r) { 
            return seg[ind];
        }
        int mid = low + (high - low) / 2;
        Node left = query(2 * ind + 1, low, mid, l, r);
        Node right = query(2 * ind + 2, mid + 1, high, l, r);
        return merge(left, right);
    }
};
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        ST sg(n);
        sg.build(0,0,n-1,nums);
        return sg.query(0,0,n-1,0,n-1).maxSubarraySum;
    }
};