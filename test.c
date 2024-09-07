#include "stl.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void test_stack()
{
    stack *s = createStack();
    int n = 6;
    do
    {
        printf("Test the following:\n");
        printf("1. Push an element into stack\n");
        printf("2. Pop an element from stack\n");
        printf("3. Get top element of stack\n");
        printf("4. Get size of stack\n");
        printf("5. Check if stack is empty\n");
        printf("6. Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &n);

        switch (n)
        {
        case 1:
            int number;
            printf("Enter the number to be push into stack : ");
            scanf("%d", &number);
            spush(s, number);
            printf("Successfully pushed %d\n\n", number);
            break;
        case 2:
            spop(s);
            printf("Successfully removed top element of Stack\n\n");
            break;
        case 3:
            printf("Top element of Stack : %d\n\n", stop(s));
            break;
        case 4:
            printf("Size of Stack = %d\n\n", sgetSize(s));
            break;
        case 5:
            if (sisEmpty(s))
                printf("Stack is empty.\n\n");
            else
                printf("Stack is not empty.\n\n");
            break;
        default:
            break;
        }
    } while (n != 6);

    deleteStack(s);
}

void test_queue()
{
    queue *q = createQueue();

    int n = 6;
    do
    {
        printf("Test the following:\n");
        printf("1. Push an element into queue\n");
        printf("2. Pop an element from queue\n");
        printf("3. Get front element of queue\n");
        printf("4. Get size of queue\n");
        printf("5. Check if queue is empty\n");
        printf("6. Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &n);

        switch (n)
        {
        case 1:
            int number;
            printf("Enter the number to push into queue: ");
            scanf("%d", &number);
            qpush(q, number);
            printf("Successfully pushed %d\n\n", number);
            break;
        case 2:
            qpop(q);
            printf("Successfully removed front element of Queue\n\n");
            break;
        case 3:
            printf("Front element of Queue: %d\n\n", qfront(q));
            break;
        case 4:
            printf("Size of Queue: %d\n\n", qgetSize(q));
            break;
        case 5:
            if (qisEmpty(q))
                printf("Queue is empty.\n\n");
            else
                printf("Queue is not empty.\n\n");
            break;
        default:
            break;
        }
    } while (n != 6);

    deleteQueue(q);
}

void test_priorityQueue()
{
    priority_queue *pq = createPriorityQueue(10, NULL);

    int n = 6;
    do
    {
        printf("Test the following:\n");
        printf("1. Insert an element into priority queue\n");
        printf("2. Pop top element from priority queue\n");
        printf("3. Get top element of priority queue\n");
        printf("4. Get size of priority queue\n");
        printf("5. Check if priority queue is empty\n");
        printf("6. Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &n);

        switch (n)
        {
        case 1:
            int number;
            printf("Enter the number to insert into priority queue: ");
            scanf("%d", &number);
            pqpush(pq, number);
            printf("Successfully inserted %d\n\n", number);
            break;
        case 2:
            pqpop(pq);
            printf("Successfully removed top element of Priority Queue\n\n");
            break;
        case 3:
            printf("Top element of Priority Queue: %d\n\n", pqtop(pq));
            break;
        case 4:
            printf("Size of Priority Queue: %d\n\n", pqgetSize(pq));
            break;
        case 5:
            if (pqisEmpty(pq))
                printf("Priority Queue is empty.\n\n");
            else
                printf("Priority Queue is not empty.\n\n");
            break;
        default:
            break;
        }
    } while (n != 6);

    deletePriorityQueue(pq);
}

void test_linkedList()
{
    LinkedList *l = createLinkedList();

    int n = 11;
    int index, number;
    do
    {
        printf("Test the following:\n");
        printf("1. Push an element to end of linked list\n");
        printf("2. Push an element to start of linked list\n");
        printf("3. Delete an element from end of linked list\n");
        printf("4. Delete an element from start of linked list\n");
        printf("5. Set an element at an index of linked list\n");
        printf("6. Remove an element at an index from linked list\n");
        printf("7. Get an element at an index of linked list\n");
        printf("8. Get size of linked list\n");
        printf("9. Check if linked list is empty\n");
        printf("10. Display linked list\n");
        printf("11. Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &n);

        switch (n)
        {
        case 1:
            printf("Enter the number to insert to end of linked list: ");
            scanf("%d", &number);
            push_back(l, number);
            printf("Successfully inserted %d to end of list\n\n", number);
            break;
        case 2:
            printf("Enter the number to insert to start of linked list: ");
            scanf("%d", &number);
            push_front(l, number);
            printf("Successfully inserted %d to start of list\n\n", number);
            break;
        case 3:
            pop_back(l);
            printf("Successfully deleted an element from end of list\n\n");
            break;
        case 4:
            pop_front(l);
            printf("Successfully deleted an element from start of list\n\n");
            break;
        case 5:
            printf("Enter the index where an element is to be set :");
            scanf("%d", &index);
            printf("Enter the number to be inserted : ");
            scanf("%d", &number);
            setElement(l, index, number);
            printf("Successfully inserted %d at index %d.\n\n", number, index);
            break;
        case 6:
            printf("Enter the index of element to be deleted : ");
            scanf("%d", &index);
            removeElement(l, index);
            printf("Successfully removed element at index %d\n\n", index);
            break;
        case 7:
            printf("Enter index of element to get element : ");
            scanf("%d", &index);
            printf("Element at index %d is %d\n\n", index, getElement(l, index));
            break;
        case 8:
            printf("Size of Linked List: %d\n\n", getSize(l));
            break;
        case 9:
            if (isEmpty(l))
                printf("Linked list is empty.\n\n");
            else
                printf("Linked list is not empty.\n\n");
            break;
        case 10:
            printList(l);
            printf("\n\n");
            break;
        default:
            break;
        }
    } while (n != 11);

    deleteList(l);
}

void test_binarySearchTree()
{
    BST *bst;

    int n = 5;
    do
    {
        printf("Test the following:\n");
        printf("1. Insert an element into BST\n");
        printf("2. Search an element in BST\n");
        printf("3. Delete an element from BST\n");
        printf("4. In-order traversal of BST\n");
        printf("5. Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &n);

        switch (n)
        {
        case 1:
            int number;
            printf("Enter the number to insert into BST: ");
            scanf("%d", &number);
            bst = tinsert(bst, number);
            printf("Successfully inserted %d\n\n", number);
            break;
        case 2:
            printf("Enter the number to search in BST: ");
            scanf("%d", &number);
            BST *node = tsearch(bst, number);
            if (node != NULL)
                printf("Element %d found in BST\n\n", number);
            else
                printf("Element %d not found in BST\n\n", number);
            break;
        case 3:
            printf("Enter the number to delete from BST: ");
            scanf("%d", &number);
            bst = tdeleteNode(bst, number);
            printf("Successfully deleted %d\n\n", number);
            break;
        case 4:
            printf("In-order traversal of BST: \n");
            tinorderTraversal(bst);
            printf("\n\n");
            break;
        default:
            break;
        }
    } while (n != 5);

    deleteBST(bst);
}

void test_unordered_map()
{
    unordered_map *mp = createMap();

    int n = 9;
    int key, value;
    int length;

    do
    {
        printf("\nTest the following:\n");
        printf("1. Insert a key-value pair into the unordered map\n");
        printf("2. Find a value by key in the unordered map\n");
        printf("3. Erase a key-value pair from the unordered map\n");
        printf("4. Check if a key exists in the unordered map\n");
        printf("5. Get the size of the unordered map\n");
        printf("6. Check if the unordered map is empty\n");
        printf("7. Clear the unordered map\n");
        printf("8. Get all key-value pairs from the unordered map\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &n);

        switch (n)
        {
        case 1:
            printf("Enter key to insert: ");
            scanf("%d", &key);
            printf("Enter value to insert: ");
            scanf("%d", &value);
            mpinsert(mp, key, value);
            printf("Inserted key-value pair (%d, %d) into the map\n\n", key, value);
            break;
        case 2:
            printf("Enter key to find: ");
            scanf("%d", &key);
            if (mpfind(mp, key, &value))
            {
                printf("Key %d found with value %d\n\n", key, value);
            }
            else
            {
                printf("Key %d not found in the map\n\n", key);
            }
            break;
        case 3:
            printf("Enter key to erase: ");
            scanf("%d", &key);
            mperase(mp, key);
            printf("Erased key %d from the map\n\n", key);
            break;
        case 4:
            printf("Enter key to check existence: ");
            scanf("%d", &key);
            if (mpcontains(mp, key))
            {
                printf("Key %d exists in the map\n\n", key);
            }
            else
            {
                printf("Key %d does not exist in the map\n\n", key);
            }
            break;
        case 5:
            printf("Size of the unordered map: %d\n\n", mpgetSize(mp));
            break;
        case 6:
            if (mpisEmpty(mp))
            {
                printf("The unordered map is empty\n\n");
            }
            else
            {
                printf("The unordered map is not empty\n\n");
            }
            break;
        case 7:
            mpclear(mp);
            printf("Cleared the unordered map\n\n");
            break;
        case 8:
            int **mapArray = mpgetMap(mp, &length);
            if (length == 0)
                printf("The unordered map is empty\n\n");
            else
            {
                printf("Key-Value pairs in the unordered map:\n\n");
                for (int i = 0; i < length; i++)
                    printf("Key: %d, Value: %d\n", mapArray[i][0], mapArray[i][1]);
                printf("\n\n");
            }
            free(mapArray);
            break;
        default:
            break;
        }
    } while (n != 9);

    deleteMap(mp);
}

void test_search()
{
    int n = 3;
    int size, ele, ans;
    int arr[1000];
    do
    {
        printf("\nTest the following:\n");
        printf("1. Linear Search\n");
        printf("2. Binary Search\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &n);

        switch (n)
        {
        case 1:
            printf("Enter size of array : ");
            scanf("%d", &size);
            printf("Enter %d space separated elements\n\n", size);
            for (int i = 0; i < size; i++)
                scanf("%d", &arr[i]);
            printf("Enter element to be searched linearly in array : ");
            scanf("%d", &ele);
            ans = linear_search(arr, &ele, size);
            if (ans == -1)
                printf("Element not found in array.\n\n");
            else
                printf("Element found at index %d\n\n", ans);
            break;
        case 2:
            printf("Enter size of array : ");
            scanf("%d", &size);
            printf("Enter %d space separated sorted elements\n\n", size);
            for (int i = 0; i < size; i++)
                scanf("%d", &arr[i]);
            printf("Enter element to be searched in array : ");
            scanf("%d", &ele);
            ans = binary_search(arr, &ele, size);
            if (ans == -1)
                printf("Element not found in array.\n\n");
            else
                printf("Element found at index %d\n\n", ans);
            break;
        default:
            break;
        }
    } while (n != 3);
}

void test_sort()
{
    int n = 6;
    int size;
    int arr[1000];
    do
    {
        printf("\nTest the following sorting algorithms:\n");
        printf("1. Insertion Sort\n");
        printf("2. Selection Sort\n");
        printf("3. Bubble Sort\n");
        printf("4. Merge Sort\n");
        printf("5. Quick Sort\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &n);

        switch (n)
        {
        case 1:
            printf("Enter size of array : ");
            scanf("%d", &size);
            printf("Enter %d space separated elements\n", size);
            for (int i = 0; i < size; i++)
                scanf("%d", &arr[i]);
            insertion_sort(arr, n, defaultCmp);
            printf("Sorted Array (Insertion Sort): ");
            for (int i = 0; i < n; i++)
                printf("%d ", arr[i]);
            printf("\n\n");
            break;

        case 2:
            printf("Enter size of array : ");
            scanf("%d", &size);
            printf("Enter %d space separated elements\n", size);
            for (int i = 0; i < size; i++)
                scanf("%d", &arr[i]);
            selection_sort(arr, n, defaultCmp);
            printf("Sorted Array (Selection Sort): ");
            for (int i = 0; i < n; i++)
                printf("%d ", arr[i]);
            printf("\n\n");
            break;

        case 3:
            printf("Enter size of array : ");
            scanf("%d", &size);
            printf("Enter %d space separated elements\n", size);
            for (int i = 0; i < size; i++)
                scanf("%d", &arr[i]);
            bubble_sort(arr, n, defaultCmp);
            printf("Sorted Array (Bubble Sort): ");
            for (int i = 0; i < n; i++)
                printf("%d ", arr[i]);
            printf("\n\n");
            break;

        case 4:
            printf("Enter size of array : ");
            scanf("%d", &size);
            printf("Enter %d space separated elements\n", size);
            for (int i = 0; i < size; i++)
                scanf("%d", &arr[i]);
            merge_sort(arr, n, defaultCmp);
            printf("Sorted Array (Merge Sort): ");
            for (int i = 0; i < n; i++)
                printf("%d ", arr[i]);
            printf("\n\n");
            break;

        case 5:
            printf("Enter size of array : ");
            scanf("%d", &size);
            printf("Enter %d space separated elements\n", size);
            for (int i = 0; i < size; i++)
                scanf("%d", &arr[i]);
            quick_sort(arr, n, defaultCmp);
            printf("Sorted Array (Quick Sort): ");
            for (int i = 0; i < n; i++)
                printf("%d ", arr[i]);
            printf("\n\n");
            break;
        default:
            break;
        }
    } while (n != 6);
}

int main()
{
    int n = 9;
    do
    {
        printf("\nTest the following:\n");
        printf("1. Stack\n");
        printf("2. Queue\n");
        printf("3. Priority Queue\n");
        printf("4. Linked List\n");
        printf("5. Binary Search Tree\n");
        printf("6. Unordered Map\n");
        printf("7. Searching\n");
        printf("8. Sorting\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            test_stack();
            break;
        case 2:
            test_queue();
            break;
        case 3:
            test_priorityQueue();
            break;
        case 4:
            test_linkedList();
            break;
        case 5:
            test_binarySearchTree();
            break;
        case 6:
            test_unordered_map();
            break;
        case 7:
            test_search();
            break;
        case 8:
            test_sort();
            break;
        default:
            break;
        }
    } while(n != 9);
    return 0;
}