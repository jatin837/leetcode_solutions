Amazing problem.
Solving with dfs is a little tricky and inefficient at the same time.
​
But, solving with string matching is a god-level ingeniousness.
​
My approach
=======
if dfs of root and subRoot matches, then return true
otherwise, recursively check if root->right or root->left contains subRoot
​
dfs is a simple function which check if every node in subRoot is present exhaustively and exclusively in root
​
Now, leetcode official solution provides an amazing solution in the form of string matching. This is an opportunity for KMP algorithm. But, however, you need to understand how to serialize the tree into string first.