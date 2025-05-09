#include <iostream>
#include <stack>
#include <sstream>
#include <string>

using namespace std;

// Node structure for the expression tree
struct ExpressionTreeNode {
    string value;
    ExpressionTreeNode* left;
    ExpressionTreeNode* right;

    ExpressionTreeNode(string val) : value(val), left(nullptr), right(nullptr) {}
};

// ExpressionTree class
class ExpressionTree {
public:
    ExpressionTreeNode* root;

    ExpressionTree(string postfixExpr) {
        root = buildTree(postfixExpr);
    }

    // Builds the expression tree from the postfix expression
    ExpressionTreeNode* buildTree(string postfixExpr) {
        stack<ExpressionTreeNode*> stack;
        stringstream ss(postfixExpr);
        string token;

        while (ss >> token) {
            if (isdigit(token[0])) {  // If the token is an operand (number)
                stack.push(new ExpressionTreeNode(token));
            } else {  // If the token is an operator
                ExpressionTreeNode* right = stack.top(); stack.pop();
                ExpressionTreeNode* left = stack.top(); stack.pop();
                ExpressionTreeNode* node = new ExpressionTreeNode(token);
                node->left = left;
                node->right = right;
                stack.push(node);
            }
        }

        return stack.top();  // The root of the expression tree
    }

    // Evaluate the expression tree recursively
    int evaluate(ExpressionTreeNode* node) {
        if (node == nullptr) return 0;

        // If it's a leaf node, return the value
        if (node->left == nullptr && node->right == nullptr) {
            return stoi(node->value);
        }

        // Otherwise, it's an operator, evaluate both children
        int leftVal = evaluate(node->left);
        int rightVal = evaluate(node->right);

        // Apply the operator
        if (node->value == "+") return leftVal + rightVal;
        if (node->value == "-") return leftVal - rightVal;
        if (node->value == "*") return leftVal * rightVal;
        if (node->value == "/") return leftVal / rightVal;

        return 0;
    }

    // Inorder traversal: left -> node -> right (infix expression)
    void inorder(ExpressionTreeNode* node) {
        if (node == nullptr) return;
        inorder(node->left);
        cout << node->value << " ";
        inorder(node->right);
    }

    // Postorder traversal: left -> right -> node (postfix expression)
    void postorder(ExpressionTreeNode* node) {
        if (node == nullptr) return;
        postorder(node->left);
        postorder(node->right);
        cout << node->value << " ";
    }
};

// Client program
int main() {
    string postfixExpr = "8 12 + 20 *";  // Example postfix expression: 3 7 + 14 *

    // Create the expression tree
    ExpressionTree exprTree(postfixExpr);

    // Evaluate the expression tree
    int result = exprTree.evaluate(exprTree.root);
    cout << "Evaluation result: " << result << endl;

    // Display the infix form using inorder traversal
    cout << "Infix expression: ";
    exprTree.inorder(exprTree.root);
    cout << endl;

    // Display the postfix form using postorder traversal
    cout << "Postfix expression: ";
    exprTree.postorder(exprTree.root);
    cout << endl;

    return 0;
}
