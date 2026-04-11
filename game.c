#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_LEVELS 30 

typedef struct {
    int id;
    char task[200];
    char code_template[400];
    char correct_answer[50];
    char hint[200];
} Level;

// --- C-Lang Laboratory (30 Levels) ---
Level c_lab[MAX_LEVELS] = {
    {1, "Declare an integer 'data' and assign it 101.", "int _______ = 101;", "data", "The variable name is in the task."},
    {2, "Use the correct format specifier to print an integer.", "printf(\"%__\", score);", "d", "Think 'decimal'."},
    {3, "Create a pointer 'ptr' that points to 'val'.", "int *___ = &val;", "ptr", "Use the name 'ptr'."},
    {4, "Check if 'x' is greater than 10.", "__(x > 10)", "if", "Standard conditional keyword."},
    {5, "Return success code from main.", "return _;", "0", "Standard exit code."},
    {6, "Include the standard I/O library.", "#include <_____.h>", "stdio", "Short for Standard Input/Output."},
    {7, "Declare a character variable 'letter'.", "____ letter = 'A';", "char", "Data type for characters."},
    {8, "Allocate memory for 5 ints.", "malloc(_ * sizeof(int));", "5", "Match the number in the task."},
    {9, "Access value at address 'p'.", "int val = _p;", "*", "The dereference operator."},
    {10, "Define a constant PI.", "#define PI ____", "3.14", "The numeric value of PI."},
    {11, "Compare if two values are equal.", "if (a __ b)", "==", "Double equals for comparison."},
    {12, "Exit a loop immediately.", "____;", "break", "The keyword used to stop loops."},
    {13, "Get the size of an integer type.", "_______(int)", "sizeof", "Operator for memory size."},
    {14, "Declare a decimal variable 'price'.", "_____ price = 9.99;", "float", "Type for floating-point numbers."},
    {15, "The entry point function name.", "int ____() { ... }", "main", "Where execution starts."},
    {16, "Define a custom data structure 'Node'.", "______ Node { int x; };", "struct", "Used to group different types."},
    {17, "Format specifier for a string.", "printf(\"%_\", name);", "s", "Think 'string'."},
    {18, "Logical 'AND' operator.", "if (a > 0 __ b > 0)", "&&", "Double ampersand."},
    {19, "Logical 'OR' operator.", "if (a < 0 __ b < 0)", "||", "Double pipe symbol."},
    {20, "Continue to the next loop iteration.", "________;", "continue", "Skips the rest of the current loop."},
    {21, "Declare a constant integer 'MAX'.", "_____ int MAX = 100;", "const", "Keyword for read-only variables."},
    {22, "Format specifier for a float.", "printf(\"%_\", price);", "f", "Think 'float'."},
    {23, "Increment variable 'i' by 1.", "i__;", "++", "Double plus operator."},
    {24, "Decrement variable 'i' by 1.", "i__;", "--", "Double minus operator."},
    {25, "Read an integer from the user.", "_____(\"%d\", &val);", "scanf", "Scan formatted input."},
    {26, "Create a long integer variable.", "____ distance = 100000L;", "long", "Used for larger whole numbers."},
    {27, "A pointer that points to nothing.", "int *p = ____;", "null", "Commonly used for unassigned pointers."},
    {28, "Header for string functions.", "#include <______.h>", "string", "Used for strlen, strcpy, etc."},
    {29, "Switch case default keyword.", "_______: printf(\"Error\");", "default", "Runs if no cases match."},
    {30, "The address-of operator.", "int *p = _val;", "&", "Ampersand gets the memory address."}
};

// --- Python Comparison Lab (30 Levels) ---
Level python_lab[MAX_LEVELS] = {
    {1, "Python: print(). C: ?", "_______(\"Hi\");", "printf", "Print formatted."},
    {2, "Python: list. C: fixed-size ______.", "int arr[_];", "5", "Fixed collection."},
    {3, "Python: for x in range. C: ?", "___(int i=0; i<5; i++)", "for", "Standard loop keyword."},
    {4, "Python: None. C: ?", "void* p = ____;", "null", "The empty pointer."},
    {5, "Python: True. C: (integer)?", "int ok = _;", "1", "Zero is false, __ is true."},
    {6, "What ends a line in C (unlike Python)?", "int x = 5_", ";", "The semicolon character."},
    {7, "Python: def. C: (type name)?", "___ func() { ... }", "int", "Most common return type."},
    {8, "Python: # comment. C: ?", "__ comment", "//", "Double forward slash."},
    {9, "Python: elif. C: ?", "____ if (cond)", "else", "It's two words."},
    {10, "Python: and. C: ?", "if (a __ b)", "&&", "C uses symbols for logic."},
    {11, "Python: or. C: ?", "if (a __ b)", "||", "Double pipe symbol."},
    {12, "Python: len(list). C: ?", "______(arr)", "sizeof", "Calculates memory size."},
    {13, "C keyword for 'None' return type.", "____ func()", "void", "The keyword for 'nothing'."},
    {14, "Python: input(). C: ?", "_____(\"%d\", &x);", "scanf", "Scan formatted input."},
    {15, "Python: class. C: ?", "______ Person { ... };", "struct", "Groups data in C."},
    {16, "Python: False. C: (integer)?", "int error = _;", "0", "Zero is always false in C."},
    {17, "Python uses indentation. C uses ______.", "_ code _", "{", "Curly braces define blocks."},
    {18, "Python: str(). C format?", "sprintf(buf, \"%_\", val);", "s", "The string specifier."},
    {19, "Python: append(). C requires manually ______ memory.", "______(ptr, size);", "realloc", "Used to resize memory."},
    {20, "Python: list[0]. C: ?", "arr[_]", "0", "Both use zero-based indexing."},
    {21, "Python lists are dynamic. C arrays are ______.", "/* Arrays are _____ size */", "fixed", "Cannot change size easily."},
    {22, "Python: range(0, 10). C loop condition?", "i < __", "10", "The limit of the loop."},
    {23, "Python: import. C: ?", "_______ <math.h>", "#include", "Pre-processor directive."},
    {24, "Python: x += 1. C shortcut?", "x__", "++", "The increment operator."},
    {25, "Python uses 'not'. C uses symbol?", "if (_is_ready)", "!", "The exclamation point."},
    {26, "Python: float. C: ?", "_____ x = 1.1;", "float", "Same name, but must be declared."},
    {27, "Python: pass. C: ?", "_", ";", "An empty semicolon does nothing."},
    {28, "Python: __init__. C: (initialization)?", "void _____(Node* n);", "init", "Manual initialization function."},
    {29, "Python: global x. C: (variable location)?", "/* Outside main */ int x;", "global", "Variables declared outside functions."},
    {30, "Python: break. C: ?", "_____", "break", "The keyword is the same!"}
};

void clear() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void play(Level levels[], const char* name) {
    char input[50];
    for (int i = 0; i < MAX_LEVELS; i++) {
        clear();
        printf("--- %s LAB: LEVEL %d/30 --- \n\n", name, i + 1);
        printf("TASK: %s\nCODE: %s\n", levels[i].task, levels[i].code_template);
        printf("\nAnswer (or 'hint'): ");
        
        if (scanf("%s", input) != 1) continue;
        for(int j = 0; input[j]; j++) input[j] = (char)tolower(input[j]);

        if (strcmp(input, "hint") == 0) {
            printf("\nHINT: %s\nPress Enter...", levels[i].hint);
            while(getchar() != '\n'); getchar(); i--; 
        } else if (strcmp(input, levels[i].correct_answer) == 0) {
            printf("\n>>> SUCCESS! Moving to next sector.\nPress Enter...");
            while(getchar() != '\n'); getchar();
        } else {
            printf("\n>>> ACCESS DENIED. Try again.\nPress Enter...");
            while(getchar() != '\n'); getchar(); i--;
        }
    }
    printf("\nCONGRATULATIONS! Lab %s fully decrypted.\n", name);
    printf("Press Enter to return to main frame...");
    while(getchar() != '\n'); getchar();
}

int main() {
    int choice = 0;
    while (choice != 3) {
        clear();
        printf("========================================\n");
        printf("   CYBER ESCAPE: LOCKED IN  \n");
        printf("========================================\n");
        printf("1. C Lab\n");
        printf("2. Python Lab\n");
        printf("3. Exit\n\n");
        printf("Selection: ");
        if (scanf("%d", &choice) != 1) { while(getchar() != '\n'); continue; }
        if (choice == 1) play(c_lab, "C-LANG");
        else if (choice == 2) play(python_lab, "PYTHON");
    }
    return 0;
}