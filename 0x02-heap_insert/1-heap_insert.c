#include "binary_trees.h"

/**
 * binary_tree_height - Height
 * @tree: Root
 *
 * Return: Height
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t levelr = 0, levell = 0;

	if (!tree)
		return (0);
	if (tree->left)
	{
		levell = binary_tree_height(tree->left);
		levell += 1;
	}
	if (tree->right)
	{
		levelr = binary_tree_height(tree->right);
		levelr += 1;
	}
	return (levelr > levell ? levelr : levell);
}

/**
 * binary_tree_is_full - Full
 * @tree: Root
 *
 * Return: 1 if full, otherwise 0
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	if (!tree->left && !tree->right)
		return (1);
	if (tree->left && tree->right)
		return (binary_tree_is_full(tree->right) &&
			binary_tree_is_full(tree->left));
	return (0);
}

void great_than_parent(heap_t **child, heap_t **parent)
{
	heap_t *child_left = (*child)->left, *child_right = (*child)->right;
	heap_t *parent_swp;

	if ((*child)->n > (*parent)->n)
	{
		(*child)->parent = (*parent)->parent;
		if ((*parent)->left == *child)
		{
			parent_swp = (*parent)->right;
			(*parent)->left = child_left;
			(*parent)->right = child_right;
			(*child)->left = *parent;
			(*child)->right = parent_swp;
		}
		else
		{
			parent_swp = (*parent)->left;
			(*parent)->left = child_left;
			(*parent)->right = child_right;
			(*child)->right = *parent;
			(*child)->right = parent_swp;
		}
	}
}

/**
 * heap_inser - function that inserts a value into a Max Binary Heap
 * @root: root is a double pointer to the root node of the Heap
 * @value: value is the value store in the node to be inserted
 * Return: Return a pointer to the inserted node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node;

	if (!*root)
	{
		*root = new_node = binary_tree_node(NULL, value);
		return (new_node);
	}

	if (binary_tree_is_full(*root) || !binary_tree_is_full((*root)->left))
	{
		if (!(*root)->left)
		{
			new_node = binary_tree_node(*root, value);
			(*root)->left = new_node;
			great_than_parent(&(*root)->left, root);
			return (new_node);
		}
		else
		{
			new_node = heap_insert(&(*root)->left, value);
			great_than_parent(&(*root)->left, root);
			return (new_node);
		}
	}
	return (NULL);
}
