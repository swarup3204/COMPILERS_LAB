# COMPILERS_LAB

**A1**:  
Used github copilot along with extension x86_64 assembly code syntax highlighting on vscode for assignment 1

**A2**:  
Needed to refer to some articles to fully understand asm utility in C, rest of the part was easy as it was done in spl lab, fail and pass test very from person to person

**A3**:  
Needed to make flex rules carefully,especially be careful in identifying comments,string literals and escape sequence.Make a robust test file for testing as it carries marks.Make sure no mistakes as this lexer will be used further in constructing tinyC compiler.

**A4**:  
Had to write down the rules as mentioned in the question.We used %union to declare the attributes for all the tokens,and stored in them the values of all tokens(identifiers,constants etc).We modified flex file so as to capture any token(terminal) differently and therefore each keyword,punctuator and etc were assigned separate manifest constants for their identification.%nonassoc was used to assign '(' a higher precedence than 'else'.This might have also been done with %rightassoc.This was so done as the rules in the question had an ambiguity in the selection statement (dangling else).Error recovery modes were not used.Test file was prepared so as to check the syntactic correctness and therefore did not pay attention to semantic correctness. 

**A5**:  
Making .y file was the most challenging ,semantic rules mentioned in slides used extensively.Added some more rules on own wherever needed.However for the sake of honesty, A5 was done referring a senior's repository.The data structures used can be different but the semantic rules overall need to be same as in class. No optimisation needed.  

**A6**:  
A difficult assignment.Completed with the help of the same senior's repository.Too much load did not allow us to explore much but the idea is that we simply map every three adress code to a given set of macros.This is highly unoptimised method and hence no register allocation or assignment was needed.The register to be used were hard coded.Many of the data structures in the translators were significantly changed and hence correspodning .y and translator.cxx underwent changes.
Note that many things (for ex the space allocated to the parameters in the activation record is set to 16 ,max 4 parameters are supposed to be allowed in a function call) is hard coded.Even if a senior's repo is referred,understanding the code properly is needed.Refer to books in the intro slides for coding help.

**Class tests**:  
Needed to learn up the slides well (yes remember the codes and write them down).Advised to remember many parts of the slides for scoring well in exam.
