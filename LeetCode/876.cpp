#include <iostream>
#include<algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *fast = head;//¿ìÖ¸Õë
        ListNode *slow = head;//ÂýÖ¸Õë
        while(fast != NULL && fast -> next != NULL) {
            fast = fast -> next -> next;
            slow = slow -> next;
        }
        return slow;
    }
};
