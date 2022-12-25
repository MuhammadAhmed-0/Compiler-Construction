import re
import ast


def tokenize(expression):
    token_regex = r"\d+|[a-zA-Z]+|."
    return re.findall(token_regex, expression)


def create_syntax_tree(expression):
    tree = ast.parse(expression)
    print(tree)
    print(ast.dump(tree, indent=4))

print("1st Module answer\n")
tokens = tokenize("a + (b * c)")
print(tokens)

print("2nd Module answer\n")

# Create and print the syntax tree
create_syntax_tree("a + (b * c)")
