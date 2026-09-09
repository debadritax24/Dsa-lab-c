//! write a program in c to prefer creation , modify, delete and display  operations in a single linked list//

#include <stdio.h>
#include <stdlib.h>

// Definition of Node structure for Circular Linked List
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert/create node at the end of Circular Linked List
struct Node* createOrInsert(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
        head->next = head; // Points to itself in circular list
        return head;
    }

    struct Node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = head;
    return head;
}

// Function to display the Circular Linked List
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("Circular Linked List is empty.\n");
        return;
    }

    struct Node* temp = head;
    printf("Circular Linked List: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(head: %d)\n", head->data);
}

// Function to modify data in the Circular Linked List
void modifyNode(struct Node* head, int oldValue, int newValue) {
    if (head == NULL) {
        printf("List is empty. Cannot modify.\n");
        return;
    }

    struct Node* temp = head;
    do {
        if (temp->data == oldValue) {
            temp->data = newValue;
            printf("Node with value %d updated to %d successfully.\n", oldValue, newValue);
            return;
        }
        temp = temp->next;
    } while (temp != head);

    printf("Value %d not found in the list.\n", oldValue);
}

// Function to delete a node with given value from Circular Linked List
struct Node* deleteNode(struct Node* head, int value) {
    if (head == NULL) {
        printf("List is empty. Deletion failed.\n");
        return NULL;
    }

    struct Node *curr = head, *prev = NULL;

    // Check if head node is to be deleted
    if (head->data == value) {
        // Case 1: List has only one node
        if (head->next == head) {
            free(head);
            printf("Node %d deleted. List is now empty.\n", value);
            return NULL;
        }

        // Case 2: List has more than one node and head is to be deleted
        struct Node* last = head;
        while (last->next != head) {
            last = last->next;
        }
        last->next = head->next;
        struct Node* temp = head;
        head = head->next;
        free(temp);
        printf("Node %d deleted successfully.\n", value);
        return head;
    }

    // Deleting non-head node
    prev = head;
    curr = head->next;
    while (curr != head) {
        if (curr->data == value) {
            prev->next = curr->next;
            free(curr);
            printf("Node %d deleted successfully.\n", value);
            return head;
        }
        prev = curr;
        curr = curr->next;
    }

    printf("Value %d not found in the list.\n", value);
    return head;
}

// Function to free memory of all nodes in Circular Linked List
void freeList(struct Node* head) {
    if (head == NULL) return;

    struct Node* current = head;
    struct Node* nextNode;
    struct Node* last = head;

    while (last->next != head) {
        last = last->next;
    }
    last->next = NULL;

    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
}

int main() {
    struct Node* head = NULL;
    int choice, val, oldVal, newVal, n, i;

    while (1) {
        printf("\n--- Circular Linked List Operations ---\n");
        printf("1. Create / Insert Node\n");
        printf("2. Modify Node\n");
        printf("3. Delete Node\n");
        printf("4. Display List\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            break;
        }

        switch (choice) {
            case 1:
                printf("How many nodes do you want to insert? ");
                if (scanf("%d", &n) == 1 && n > 0) {
                    for (i = 0; i < n; i++) {
                        printf("Enter value for node %d: ", i + 1);
                        scanf("%d", &val);
                        head = createOrInsert(head, val);
                    }
                }
                break;
            case 2:
                printf("Enter old value to modify: ");
                scanf("%d", &oldVal);
                printf("Enter new value: ");
                scanf("%d", &newVal);
                modifyNode(head, oldVal, newVal);
                break;
            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &val);
                head = deleteNode(head, val);
                break;
            case 4:
                displayList(head);
                break;
            case 5:
                freeList(head);
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    freeList(head);
    return 0;
}

