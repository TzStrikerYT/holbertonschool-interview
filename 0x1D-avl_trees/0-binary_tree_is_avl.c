#include "binary_trees.h"

/**
 * subtree - Function that checks if a subtree contains only values less than n
 * @tree: root of a subtree
 * @n: value to check
 * @flag: 1 if left or 0 if right
 * Return: 1 if a subtree contains only lesser values, otherwise 0
 */

int subtree(const binary_tree_t *tree, int n, int flag)
{
	int r_left = 1, r_right = 1;

	if (tree->left)
		r_left = subtree(tree->left, n, flag);
	if (tree->right)
		r_right = subtree(tree->right, n, flag);

	if (flag && tree->n >= n)
		return (0);
	else if (!flag && tree->n <= n)
		return (0);

	return (r_left * r_right);
}
/**
 * bst_binary_tree - Function that checks if a tree is a Binary search tree
 * @tree: root of the tree
 * Return: 1 if the tree is BTS or 0 if not
 */
int bst_binary_tree(const binary_tree_t *tree)
{
	int r_left = 1, r_right = 1;

	if (!tree)
		return (0);

	if (tree->left)
	{
		if (!subtree(tree->left, tree->n, 1))
			return (0);
		r_left = bst_binary_tree(tree->left);
	}
	else
		return (1);

	if (tree->right)
	{
		if (!subtree(tree->right, tree->n, 0))
			return (0);
		r_right = bst_binary_tree(tree->right);
	}
	else
		return (1);

	return (r_left * r_right);
}

/**
 * rheight - function that calculates the height using recursion
 * @tree: node to find recursion
 * Return: the number of height nodes
 */

size_t rheight(const binary_tree_t *tree)
{
	size_t c_left = 0, c_right = 0;

	if (tree->left)
		c_left = rheight(tree->left);
	if (tree->right)
		c_right = rheight(tree->right);
	return ((c_left > c_right) ? c_left + 1 : c_right + 1);
}

/**
 * balance_binary - returns the height of a tree
 * @tree: is the node from which to get the node
 * Return: an integer with the height or 0 if node is null
 */
int balance_binary(const binary_tree_t *tree)
{
	int left = 0, right = 0;

	if (tree)
	{
		if (tree->left)
			left = rheight(tree->left);
		if (tree->right)
			right = rheight(tree->right);
		return (left - right);
	}
	else
		return (0);
}

/**
 * binary_tree_is_avl - Function to checks if a binary tree is a valid AVLTree
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if tree is a valid AVL Tree, and 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int r_left = 1, r_right = 1;

	if (!tree)
		return (0);

	if ((balance_binary(tree) != 1 && balance_binary(tree) != 0 &&
	balance_binary(tree) != -1) || !bst_binary_tree(tree))
		return (0);
	if (tree->left)
		r_left = binary_tree_is_avl(tree->left);
	if (tree->right)
		r_right = binary_tree_is_avl(tree->right);

	return (r_left * r_right);
}
