# COMPILERS_LAB

**A1**:  
Used github copilot along with extension x86_64 assembly code syntax highlighting on vscode for assignment 1

**A2**:  
Needed to refer to some articles to fully understand asm utility in C, rest of the part was easy as it was done in spl lab, fail and pass test very from person to person

**A3**:  
Needed to make flex rules carefully,especially be careful in identifying comments,string literals and escape sequence.Make a robust test file for testing as it carries marks.Make sure no mistakes as this lexer will be used further in constructing tinyC compiler.

**A4**:
Had to write down the rules as mentioned in the question.We used %union to declare the attributes for all the tokens,and stored in them the values of all tokens(identifiers,constants etc).We modified flex file so as to capture any token(terminal) differently and therefore each keyword,punctuator and etc were assigned separate manifest constants for their identification.%nonassoc was used to assign '(' a higher precedence than 'else'.This might have also been done with %rightassoc.This was so done as the rules in the question had an ambiguity in the selection statement (dangling else).Error recovery modes were not used.Test file was prepared so as to check the syntactic correctness and therefore did not pay attention to semantic correctness.
