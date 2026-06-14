#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    int pairSum(ListNode* head) {
        int a = 0;
        ListNode* l = head;

        auto dfs = [&](this auto&& dfs, ListNode* r) -> void {
            if (r->next)
                dfs(r->next);

            a = max(a, l->val + r->val);
            l = l->next;
        };

        dfs(head);
        return a;
    }
};

int main() {
    vector<int> vals = {1, 2, 3, 4};

    ListNode* head = new ListNode(vals[0]);
    ListNode* cur = head;

    for (int i = 1; i < vals.size(); i++) {
        cur->next = new ListNode(vals[i]);
        cur = cur->next;
    }

    Solution sol;
    cout << sol.pairSum(head) << '\n';

    return 0;
}