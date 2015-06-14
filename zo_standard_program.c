/**************************
 * Standard Program
 *
 **************************/

unsigned char program[] = 
{
    function , MOV, 0x0 , 0   , 0x0 , STEP_DT,
	function , MOV, 0x0 , 255 , 0x0 , A,
    function , MOV, 0x0 , 2 , 0x0 , SUB_B,
    
    	function , MOV , 0x0 , 20 , 0x0 , G,
    	function , CLRS,
    	function , MOV , 0x0 , 255 , 0x0 , G,
    
	   	function , AT , 0x0 , M_X, 0x0 , X1,
	    function , AT , 0x0 , M_Y , 0x0 , Y1,
	    
	    function , AT , 0x0 , M_X, 0x0 , SUB_A,
	    function , SUB,
	    function , AT , 0x0 , SUB_X , 0x0 , X2,
	    function , AT , 0x0 , M_Y , 0x0 , Y2,
	    
	    function , DRAW,
	    
	    function , AT , 0x0 , M_Y, 0x0 , SUB_A,
	    function , SUB,
	    function , AT , 0x0 , SUB_X , 0x0 , Y2,
	    function , AT , 0x0 , M_X , 0x0 , X2,
	    
	    function , DRAW,
	    
	    
	    function , RNDR,
	    
	function , MOV , 0x0 , PROGRAM_START + 3*3 , 0x0 , JMP_X,
	function , JMP 
};
