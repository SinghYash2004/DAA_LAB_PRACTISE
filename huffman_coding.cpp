#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

/**
 * Huffman Coding Algorithm (Greedy Approach)
 * 
 * Logic:
 * 1. Create a leaf node for each unique character and build a min-heap of all leaf nodes.
 * 2. Extract two nodes with the minimum frequency from the min-heap.
 * 3. Create a new internal node with a frequency equal to the sum of the two nodes frequencies. 
 *    Make the first node as left child and the other node as right child. Add this node to the min-heap.
 * 4. Repeat steps 2 and 3 until the heap contains only one node. The remaining node is the root.
 * 
 * Time Complexity: O(n log n) where n is the number of unique characters.
 */

struct Node {
    char data;
    unsigned freq;
    Node *left, *right;

    Node(char data, unsigned freq) {
        left = right = nullptr;
        this->data = data;
        this->freq = freq;
    }
};

struct compare {
    bool operator()(Node* l, Node* r) {
        return (l->freq > r->freq);
    }
};

void printCodes(Node* root, string str) {
    if (!root) return;

    if (root->data != '$')
        cout << root->data << ": " << str << "\n";

    printCodes(root->left, str + "0");
    printCodes(root->right, str + "1");
}

void HuffmanCodes(char data[], int freq[], int size) {
    Node *left, *right, *top;

    // Create a min heap & insert all characters of data[]
    priority_queue<Node*, vector<Node*>, compare> minHeap;

    for (int i = 0; i < size; ++i)
        minHeap.push(new Node(data[i], freq[i]));

    // Iterate while size of heap doesn't become 1
    while (minHeap.size() != 1) {
        left = minHeap.top();
        minHeap.pop();

        right = minHeap.top();
        minHeap.pop();

        // '$' is a special value for internal nodes
        top = new Node('$', left->freq + right->freq);

        top->left = left;
        top->right = right;

        minHeap.push(top);
    }

    // Print Huffman codes using the Huffman tree built above
    cout << "Huffman Codes:\n";
    printCodes(minHeap.top(), "");
}

int main() {
    char arr[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {5, 9, 12, 13, 16, 45};
    int size = sizeof(arr) / sizeof(arr[0]);

    HuffmanCodes(arr, freq, size);

    return 0;
}
