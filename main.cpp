#include <iostream>

using namespace std;

class Node
{
    public:
        int data;
        Node* left;
        Node* rigth;
};

class BinarySearchTree
{
    Node* root;
    int length;

    /**
     * Prints the elements
     * @param node Node object class
     * @returns Void
     */
    void inorder(Node* node)
    {
        if (!node) return;

        cout << node->data << ": ";

        if (node->left) cout << "L" << node->left->data << " ";
        if (node->rigth) cout << "R" << node->rigth->data << " ";
        
        cout << endl;

        inorder(node->left);
        inorder(node->rigth);
    }

    /**
     * Fill the elements of binary search tree using an array
     * @param arr Array of elements
     * @param start Start index
     * @param end End index
     * @returns Node object model
     */
    Node* populateByArray(int *arr, int start, int end)
    {
        if (end < start) return NULL;

        int middle = (start + end) / 2;
        Node* node = new Node();
        
        node->data = arr[middle];
        node->left = populateByArray(arr, start, middle - 1);
        node->rigth = populateByArray(arr, middle + 1, end);

        return node;
    }

    public:
        BinarySearchTree()
        {
            root = NULL;
            length = 0;
        }

        /**
         * Prints the elements to the console
         */
        void print()
        {
            inorder(root);
            cout << endl;
        }

        /**
         * Fills the binary search tree using elements from an array
         * @param arr Array of elements
         * @param length Array length
         */
        void createByArray(int *arr, int length)
        {
            root = populateByArray(arr, 0, length - 1);
            this->length = this->length + length;
        }
};

int main()
{
    BinarySearchTree binarySearchTree;
    int arr[] = {1, 2, 3, 4, 5, 6};
    int length = sizeof(arr)/sizeof(arr[0]);

    binarySearchTree.createByArray(arr, length);
    binarySearchTree.print();
}