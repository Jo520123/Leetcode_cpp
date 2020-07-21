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
#include<iostream>
using namespace std;

class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		ListNode *cur = head;
		ListNode *prev = NULL, *next = NULL;

		while (cur != NULL) {
			next = cur->next;
			cur->next = prev;
			prev = cur;
			cur = next;
		}
		head = prev;
		return head;
	}
};