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

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int pairSum(ListNode* head) {
        if( !head || !head->next ) return 0;
        ListNode* s = head;
        ListNode* f = head;
        ListNode* k = NULL;
        ListNode* t = NULL;

        while( f && f->next ){
            f = f->next->next;
            t = s-> next;
            s->next = k;
            k = s;
            s = t;
        }
        int ma = 0;
        while( s && k ){
            ma = max( ma, s->val + k->val );
            cout<<s->val + k->val;
            s = s->next;
            k = k->next;
        }
        return ma;




        // stack <int> s;
        // if( head == nullptr || head -> next == nullptr ) return 0;
        // ListNode* sl = head;
        // ListNode* f=head;
        // while( f && f->next ){
        //     s.push(sl->val);
        //     sl = sl->next;
        //     f = f->next->next;
        // }
        // int a = 0;
        // while(sl){
        //     a = max(a, sl->val + s.top());
        //     sl = sl -> next;
        //     s.pop();
        // }
        // return a;






        // int a =0;
        // ListNode* l = head;

        // auto dfs = [&](this auto&& dfs, ListNode* r) -> void{
        //     if( r->next ) dfs( r->next );

        //     a = max( a, l->val + r-> val );
        //     l = l->next;
        // };
        // dfs(head);
        // return a;
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