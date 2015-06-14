/**********************
*
*Interpretter types
*
***********************/

//Variable type
typedef enum variable_type {variable, function} variable_type;

//Tape type
typedef struct tape_type{
    variable_type type;
    unsigned char value;
}tape_type;

//Default parameter location
typedef enum DEFAULT_PARAM
{
	HEAD,
    JMP_X,
    CMP_A,
    CMP_B,
    LESS_X,
    EQUAL_X,
    GREATER_X,
    ADD_A,
    ADD_B,
    ADD_X,
    SUB_A,
    SUB_B,
    SUB_X,
    MUL_A,
    MUL_B,
    MUL_X,
    NOT_A,
    NOT_X,
    AND_A,
    AND_B,
    AND_X,
    XOR_A,
    XOR_B,
    XOR_X,
    SHIFT_A,
    SHIFT_Left,
    SHIFT_Right,
    SHIFT_X,
    X1,
    Y1,
    X2,
    Y2,
    X3,
    Y3,
    R,
    G,
    B,
    A,
    M_X,
    M_Y,
    
    STEP_DT,

    PROGRAM_START
}DEFAULT_PARAM;


    
//Function implementations
typedef enum DEFAULT_FUNCTIONS
{
	END,
    MOV,
    AT,
    JMP,
    LESS,
    EQUAL,
    GREATER,
    ADD,
    SUB,
    MUL,
    NOT,
    AND,
    XOR,
    SHIFT_L,
    SHIFT_R,
    
    DRAW,
    FILL,
    CLRS,
    RNDR,
    
    EXIT,
    
    NO_OF_FUNCTIONS
}DEFAULT_FUNCTIONS;

