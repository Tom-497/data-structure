#include <iostream>
#include <cstdlib> 
// 链表节点
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// 头插法创建链表（方便测试）
ListNode* createList(int arr[], int n) {
    if (n == 0) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* cur = head;
    for (int i = 1; i < n; i++) {
        cur->next = new ListNode(arr[i]);
        cur = cur->next;
    }
    return head;
}

// 打印链表
void printList(ListNode* head) {
    ListNode* cur = head;
    while (cur != nullptr) {
        std::cout << cur->val;
        if (cur->next != nullptr) std::cout << " -> ";
        cur = cur->next;
    }
    std::cout << " -> NULL" << std::endl;
}

// ===== 核心：就地逆置链表 =====
ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;   // 前一个节点
    ListNode* cur = head;       // 当前节点
    ListNode* next = nullptr;   // 临时保存下一个节点
    
    while (cur != nullptr) {
        next = cur->next;       // 先保存下一个节点，防止断链
        cur->next = prev;       // 把当前节点的 next 指向前一个节点（反转）
        prev = cur;             // prev 前移
        cur = next;             // cur 前移
    }
    
    return prev;  // 新的头节点
}

// 释放链表内存
void destroyList(ListNode* head) {
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    // 测试数据
    system("chcp 65001");
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    std::cout << "===== 链表就地逆置 =====" << std::endl;
    
    // 创建链表
    ListNode* head = createList(arr, n);
    std::cout << "原链表: ";
    printList(head);
    
    // 逆置
    head = reverseList(head);
    std::cout << "逆置后: ";
    printList(head);
    
    // 边界测试：空链表
    std::cout << "\n===== 边界测试 =====" << std::endl;
    ListNode* empty = reverseList(nullptr);
    std::cout << "空链表逆置: " << (empty == nullptr ? "成功（返回NULL）" : "失败") << std::endl;
    
    // 边界测试：单节点
    ListNode* single = new ListNode(100);
    std::cout << "单节点逆置前: ";
    printList(single);
    single = reverseList(single);
    std::cout << "单节点逆置后: ";
    printList(single);
    
    // 释放内存
    destroyList(head);
    destroyList(single);
    
    return 0;
}