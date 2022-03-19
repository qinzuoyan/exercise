#include <vector>
using namespace std;

class Bank {
public:
    Bank(vector<long long>& balance) : _balance(balance) {
    }
    
    bool transfer(int account1, int account2, long long money) {
        if (account1 < 1 || account1 > (int)_balance.size() ||
                account2 < 1 || account2 > (int)_balance.size())
            return false;
        if (money >= 0 && money <= _balance[account1-1]) {
            _balance[account1-1] -= money;
            _balance[account2-1] += money;
            return true;
        }
        return false;
    }
    
    bool deposit(int account, long long money) {
        if (account < 1 || account > (int)_balance.size())
            return false;
        if (money >= 0) {
            _balance[account-1] += money;
            return true;
        }
        return false;
    }
    
    bool withdraw(int account, long long money) {
        if (account < 1 || account > (int)_balance.size())
            return false;
        if (money >= 0 && money <= _balance[account-1]) {
            _balance[account-1] -= money;
            return true;
        }
        return false;
    }

private:
    vector<long long> _balance;
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */
