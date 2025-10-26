class Bank {
    long [] bal;
    int n;
    public Bank(long[] balance) {
        n=balance.length;
        bal=balance.clone();
    }
    
    public boolean transfer(int account1, int account2, long money) {
        if(account1<=0 || account1>n || account2<=0 || account2>n) return false;
        if(bal[account1-1]<money) return false;
        bal[account1-1]-=money;
        bal[account2-1]+=money;
        return true;
    }
    
    public boolean deposit(int account, long money) {
        if(account>n || account<=0) return false;
        bal[account-1]+=money;
        return true;
    }
    
    public boolean withdraw(int account, long money) {
        if(account>n || account<=0) return false;
        if(bal[account-1]<money) return false;
        bal[account-1]-=money;
        return true;
    }
}

/**
 * Your Bank object will be instantiated and called as such:
 * Bank obj = new Bank(balance);
 * boolean param_1 = obj.transfer(account1,account2,money);
 * boolean param_2 = obj.deposit(account,money);
 * boolean param_3 = obj.withdraw(account,money);
 */