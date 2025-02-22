#include <bits/stdc++.h>

using namespace std;

struct Node {
    int value;
    vector<int> inEdges;
    vector<int> outEdges;

    Node(int v): value(v) { }
};

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums);
    int minOperations(vector<int>& nums);
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people);
    vector<vector<int>> generate(int numRows);
    int kthGrammar(int n, int k);
    string longestPalindrome(string s);
    vector<int> getRow(int rowIndex);
    int maxProfit(vector<int>& prices);
    int poorPigs(int buckets, int minutesToDie, int minutesToTest);
    vector<int> sortByBits(vector<int>& arr);
    int climbStairs(int n);
    vector<int> findArray(vector<int>& pref);
    int getMaximumGenerated(int n);
    vector<int> findMode(TreeNode* root);
    bool isSubsequence(string s, string t);
    int averageOfSubtree(TreeNode* root);
    vector<TreeNode*> allPossibleFBT(int n);
    vector<string> buildArray(vector<int>& target, int n);
    int pseudoPalindromicPaths (TreeNode* root);
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges);
    string frequencySort(string s);
    bool increasingTriplet(vector<int>& nums);
    int compress(vector<char>& chars);
    int maxArea(vector<int>& height);
    int maxVowels(string s, int k);
    int pathSum(TreeNode* root, int targetSum);
};
