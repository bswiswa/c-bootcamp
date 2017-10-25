/*
Codefights challenge solutions
Given a binary tree t and an integer s, determine whether there is a root to leaf path in t such that the sum of vertex values equals s.

Example

For

t = {
    "value": 4,
    "left": {
        "value": 1,
        "left": {
            "value": -2,
            "left": null,
            "right": {
                "value": 3,
                "left": null,
                "right": null
            }
        },
        "right": null
    },
    "right": {
        "value": 3,
        "left": {
            "value": 1,
            "left": null,
            "right": null
        },
        "right": {
            "value": 2,
            "left": {
                "value": -2,
                "left": null,
                "right": null
            },
            "right": {
                "value": -3,
                "left": null,
                "right": null
            }
        }
    }
}
and
s = 7,
the output should be hasPathWithGivenSum(t, s) = true.

This is what this tree looks like:

      4
     / \
    1   3
   /   / \
  -2  1   2
    \    / \
     3  -2 -3
Path 4 -> 3 -> 2 -> -2 gives us 7, the required sum.

For

t = {
    "value": 4,
    "left": {
        "value": 1,
        "left": {
            "value": -2,
            "left": null,
            "right": {
                "value": 3,
                "left": null,
                "right": null
            }
        },
        "right": null
    },
    "right": {
        "value": 3,
        "left": {
            "value": 1,
            "left": null,
            "right": null
        },
        "right": {
            "value": 2,
            "left": {
                "value": -4,
                "left": null,
                "right": null
            },
            "right": {
                "value": -3,
                "left": null,
                "right": null
            }
        }
    }
}
and
s = 7,
the output should be hasPathWithGivenSum(t, s) = false.

This is what this tree looks like:

      4
     / \
    1   3
   /   / \
  -2  1   2
    \    / \
     3  -4 -3
There is no path from root to leaf with the given sum 7.

Input/Output

[time limit] 500ms (c)
[input] tree.integer t

A binary tree of integers.

Guaranteed constraints:
0 ≤ tree size ≤ 5 · 104,
-1000 ≤ node value ≤ 1000.

[input] integer s

An integer.

Guaranteed constraints:
-4000 ≤ s ≤ 4000.

[output] boolean

Return true if there is a path from root to leaf in t such that the sum of node values in it is equal to s, otherwise return false.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct tree_integer {
  int value;
  struct tree_integer *left;
  struct tree_integer *right;
} tree_integer;
  
tree_integer *alloc_tree_integer(int v) {
  tree_integer *t = calloc(1, sizeof(tree_integer));
  t->value = v;
  return t;
}

bool hasPathWithGivenSum(tree_integer *t, int s){
  int sum = 0, diff = 0;
  if(t != NULL){
    sum += t->value;
    diff = s-sum;
    if(t->left == NULL && t->right == NULL){
      printf("no children for %d\n",t->value);
      if(diff == 0){
	printf("returning true...\n");
	return true;
      }
      else return false;
    }
    else if(t->left != NULL && t->right != NULL){
      printf("checking the OR\n");
      return (hasPathWithGivenSum(t->left, diff) || hasPathWithGivenSum(t->right, diff));
    }
    else if(t->left != NULL) return hasPathWithGivenSum(t->left, diff);
    else return hasPathWithGivenSum(t->right, diff);
  }
  else{
    printf("t is NULL\n");
    if(diff == 0) return true;
    else return false;
  }
}

int main(){
  tree_integer *head = alloc_tree_integer(1);
  head->left = alloc_tree_integer(0);
  head->right = alloc_tree_integer(1);
  if(hasPathWithGivenSum(head,2) == false) printf("false\n");
  else printf("true\n");
  return 0;
}
