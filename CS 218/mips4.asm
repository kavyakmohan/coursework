#  CS 218, MIPS Assignment #4
#  Kavya Mohan  Section 1001

#  MIPS assembly language program to perform
#  verification of a possible Suduko solution.

#  Sudoku is a popular brain-teaser puzzle that is solved by
#  placing digits 1 through 9 on a 9-by-9 grid of 81 individual
#  cells grouped into nine 3-by-3 regions.  The object of the
#  puzzle is to fill in all of the empty cells with digits from
#  1 to 9 so that the same digit doesn't appear twice in any
#  row, or any column, or any region.

##########################################################################
#  data segment

.data

hdr:	.ascii	"\nMIPS Assignment #4 \n"
	.asciiz	"Program to verify a possible Sudoku solution. \n\n"

TRUE = 1
FALSE = 0
GRID_SIZE = 9
SUB_GRID_SIZE = 3

lines:	.asciiz	"\n\n"

# -----
#  Sudoku Grids

SGrid1:	.word	5, 3, 4, 6, 7, 8, 9, 1, 2	# valid
	.word	6, 7, 2, 1, 9, 5, 3, 4, 8
	.word	1, 9, 8, 3, 4, 2, 5, 6, 7
	.word	8, 5, 9, 7, 6, 1, 4, 2, 3
	.word	4, 2, 6, 8, 5, 3, 7, 9, 1
	.word	7, 1, 3, 9, 2, 4, 8, 5, 6
	.word	9, 6, 1, 5, 3, 7, 2, 8, 4
	.word	2, 8, 7, 4, 1, 9, 6, 3, 5
	.word	3, 4, 5, 2, 8, 6, 1, 7, 9

SGrid2:	.word	5, 3, 4, 6, 7, 8, 9, 1, 2	# valid
	.word	6, 7, 2, 1, 9, 5, 3, 4, 8
	.word	1, 9, 8, 3, 4, 2, 5, 6, 7
	.word	8, 5, 9, 7, 6, 1, 4, 2, 3
	.word	4, 2, 6, 8, 5, 3, 7, 9, 1
	.word	7, 1, 3, 9, 2, 4, 8, 5, 6
	.word	9, 6, 1, 5, 3, 7, 2, 8, 4
	.word	2, 8, 7, 4, 1, 9, 6, 3, 5
	.word	3, 4, 5, 2, 8, 6, 1, 7, 9

SGrid3:	.word	1, 2, 3, 4, 5, 6, 7, 8, 9	# valid
	.word	4, 5, 6, 7, 8, 9, 1, 2, 3
	.word	7, 8, 9, 1, 2, 3, 4, 5, 6
	.word	2, 3, 4, 5, 6, 7, 8, 9, 1
	.word	5, 6, 7, 8, 9, 1, 2, 3, 4
	.word	8, 9, 1, 2, 3, 4, 5, 6, 7
	.word	3, 4, 5, 6, 7, 8, 9, 1, 2
	.word	6, 7, 8, 9, 1, 2, 3, 4, 5
	.word	9, 1, 2, 3, 4, 5, 6, 7, 8

SGrid4:	.word	5, 3, 4, 6, 7, 8, 9, 1, 2	# invalid, bad row
	.word	6, 7, 2, 1, 9, 5, 3, 4, 8
	.word	1, 9, 8, 3, 4, 2, 5, 6, 7
	.word	8, 5, 9, 7, 6, 1, 4, 2, 3
	.word	4, 2, 6, 8, 5, 3, 7, 9, 1
	.word	7, 1, 3, 9, 2, 4, 8, 5, 6
	.word	9, 6, 1, 5, 3, 7, 2, 8, 4
	.word	2, 8, 7, 4, 2, 9, 6, 3, 5
	.word	3, 4, 5, 2, 8, 6, 1, 7, 9

SGrid5:	.word	2, 3, 4, 5, 6, 7, 8, 9, 1	# invalid, bad col
	.word	5, 6, 7, 8, 9, 1, 2, 3, 4
	.word	8, 9, 1, 2, 3, 4, 5, 6, 7
	.word	1, 2, 3, 4, 5, 6, 7, 8, 9
	.word	4, 5, 6, 7, 8, 9, 1, 2, 3
	.word	3, 4, 5, 6, 7, 8, 9, 1, 2
	.word	7, 8, 9, 1, 2, 3, 4, 5, 6
	.word	6, 7, 8, 9, 1, 2, 3, 4, 5
	.word	8, 9, 1, 2, 3, 4, 5, 6, 7

SGrid6:	.word	2, 3, 4, 5, 6, 7, 8, 9, 1	# invalid, bad col
	.word	5, 6, 7, 8, 9, 1, 2, 3, 4
	.word	8, 9, 1, 2, 3, 4, 5, 6, 7
	.word	1, 2, 3, 4, 5, 6, 7, 8, 9
	.word	7, 8, 9, 1, 2, 3, 4, 5, 6
	.word	4, 5, 6, 7, 8, 9, 1, 2, 3
	.word	3, 4, 5, 6, 7, 8, 9, 1, 2
	.word	7, 8, 9, 1, 2, 3, 4, 5, 6
	.word	9, 1, 2, 3, 4, 5, 6, 7, 8

SGrid7:	.word	1, 2, 3, 4, 5, 6, 7, 8, 9	# invalid, bad subgrid
	.word	2, 3, 4, 5, 6, 7, 8, 9, 1
	.word	3, 4, 5, 6, 7, 8, 9, 1, 2
	.word	4, 5, 6, 7, 8, 9, 1, 2, 3
	.word	5, 6, 7, 8, 9, 1, 2, 3, 4
	.word	6, 7, 8, 9, 1, 2, 3, 4, 5
	.word	7, 8, 9, 1, 2, 3, 4, 5, 6
	.word	8, 9, 1, 2, 3, 4, 5, 6, 7
	.word	9, 1, 2, 3, 4, 5, 6, 7, 8

SGrid8:	.word	2, 3, 4, 5, 6, 7, 8, 9, 1	# invalid, bad subgrid
	.word	5, 6, 7, 8, 9, 1, 2, 3, 4
	.word	8, 9, 1, 2, 3, 4, 5, 6, 7
	.word	1, 2, 3, 4, 5, 6, 7, 8, 9
	.word	4, 5, 6, 7, 8, 9, 1, 2, 3
	.word	3, 4, 5, 6, 7, 8, 9, 1, 2
	.word	7, 8, 9, 1, 2, 3, 4, 5, 6
	.word	6, 7, 8, 9, 1, 2, 3, 4, 5
	.word	9, 1, 2, 3, 4, 5, 6, 7, 8

SGrid9:	.word	1, 2, 3, 4, 5, 6, 7, 8, 9	# valid
	.word	4, 5, 6, 7, 8, 9, 1, 2, 3
	.word	7, 8, 9, 1, 2, 3, 4, 5, 6
	.word	2, 3, 4, 5, 6, 7, 8, 9, 1
	.word	5, 6, 7, 8, 9, 1, 2, 3, 4
	.word	8, 9, 1, 2, 3, 4, 5, 6, 7
	.word	3, 4, 5, 6, 7, 8, 9, 1, 2
	.word	6, 7, 8, 9, 1, 2, 3, 4, 5
	.word	9, 1, 2, 3, 4, 5, 6, 7, 8

SGrid10:
	.word	1, 2, 3, 4, 5, 6, 7, 8, 9	# invalid, bad subgrid
	.word	4, 5, 6, 7, 8, 9, 1, 2, 3
	.word	7, 8, 9, 1, 2, 3, 4, 5, 6
	.word	2, 3, 4, 5, 6, 7, 8, 9, 1
	.word	5, 6, 7, 8, 9, 1, 2, 3, 4
	.word	3, 4, 5, 6, 7, 8, 9, 1, 2
	.word	8, 9, 1, 2, 3, 4, 5, 6, 7
	.word	6, 7, 8, 9, 1, 2, 3, 4, 5
	.word	9, 1, 2, 3, 4, 5, 6, 7, 8

isValid:	.byte	TRUE

notValid:	.byte	FALSE

addrs:	.word	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0

stars:	.ascii	"\n********************************** \n\n"
	.asciiz	"Grid Number:  "


# -----
#  Variables for sudokuVerify function.

found:	.byte	FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE


# -----
#  Variables for displaySudoku function.

new_ln:	.asciiz	"\n"
top_ln:	.asciiz	"  +-------+-------+-------+ \n"
bar:	.asciiz	"| "
space:	.asciiz	" "
space2:	.asciiz	"  "

vmsg:	.asciiz	"\nSudoku Solution IS valid.\n\n"
invmsg:	.asciiz	"\nSudoku Solution IS NOT valid.\n\n"


##########################################################################
#  text/code segment

.text

.globl main
.ent main
main:

# -----
#  Display main program header.

	la	$a0, hdr
	li	$v0, 4
	syscall					# print header

# -----
#  Set grid addresses array.
#	Address array is used to allow a looped calls
#	the Sudoku verification and display routines.

	la	$t0, addrs

	la	$t1, SGrid1
	sw	$t1, ($t0)
	la	$t1, SGrid2
	sw	$t1, 4($t0)
	la	$t1, SGrid3
	sw	$t1, 8($t0)
	la	$t1, SGrid4
	sw	$t1, 12($t0)
	la	$t1, SGrid5
	sw	$t1, 16($t0)
	la	$t1, SGrid6
	sw	$t1, 20($t0)
	la	$t1, SGrid7
	sw	$t1, 24($t0)
	la	$t1, SGrid8
	sw	$t1, 28($t0)
	la	$t1, SGrid9
	sw	$t1, 32($t0)
	la	$t1, SGrid10
	sw	$t1, 36($t0)
	sw	$zero, 40($t0)

# -----
#  Main loop to check and display all grids.
#	grid addresses are stored in an array.
#	last entry in addresses array is zero, for loop termination

	la	$s0, addrs
	li	$s1, 1			# grid number counter

mainSudokuLoop:
	lw	$t0, ($s0)
	beqz	$t0, sudokuDone

# -----
#  Verify a possible Sudoku solution.

	lw	$a0, ($s0)
	la	$a1, isValid
	jal	sudokuVerify

# -----
#  Display header and Sudoku grid count

	li	$v0, 4
	la	$a0, stars
	syscall

	li	$v0, 1
	move	$a0, $s1
	syscall

	li	$v0, 4
	la	$a0, lines
	syscall

# -----
#  Display sudoku grid with result.

	lw	$a0, ($s0)
#	li	$a1, 0
	
	beq 	$a1, FALSE, sendfalseMSG

	beq	$a1, TRUE, sendtrueMSG

	sendfalseMSG:
	lb	$a1, notValid
	j	msgInitialized

	sendtrueMSG:
	lb	$a1, isValid

	msgInitialized:
	jal	displaySudoku

# -----
#  Update counters and loop to check for next grid.

	add	$s1, $s1, 1
	addu	$s0, $s0, 4
	b	mainSudokuLoop

# -----
#  Done, terminate program.

sudokuDone:
	li	$v0, 10
	syscall

.end main


# ---------------------------------------------------------
#  Procedure to verify a Sudoku solution.

#  A valid Sudoku solution must satisfy the following constraints:
#     * Each value (1 through 9) must appear exactly once in each row.
#     * Each value (1 through 9) must appear exactly once in each column.
#     * Each value (1 through 9) must appear exactly once in each
#       3 x 3 sub-grid, where the  9 x 9 board is divided into 9 such sub-grids.

# -----
#  Formula for multiple dimension array indexing:
#	addr of ARRY(x,y) = [ (x * y_dimension) + y ] * data_size

# -----
#  Arguments
#	$a0 - address Sudoku grid
#	$a1 - address of boolean variable for result (true/false)

.globl	sudokuVerify
.ent	sudokuVerify
sudokuVerify:


#	YOUR CODE GOES HERE
	################# CHECK ROWS

	li	$t1, 0				#row idx
	rowLoop:
		li	$t0, 0			#store sum
		li	$t3, 0			#col idx
		loop2:
			mul	$t2, $t1, GRID_SIZE	#ROW IDX * column size
			add	$t2, $t2, $t3		#added column idx
			mul	$t2, $t2, 4		#offset
	
			add	$t4, $a0, $t2

			lw	$t5, ($t4)

			add	$t0, $t0, $t5
		
			add	$t3, $t3, 1
		
			#if col Idx is 9
			blt	$t3, 9, loop2
	
	
	checkRowSum:
	bne	$t0, 45, setFalse

	add	$t1, $t1, 1

	#if less than 9 ... repeat loop
	blt	$t1, 9, rowLoop


####################### CHECK COLUMNS
	li	$t1, 0			#column idx
	columnLoop:
		li	$t0, 0		#store sum
		li	$t3, 0		#row idx
		
		innerLoop:
			mul	$t2, $t3, GRID_SIZE
			add	$t2, $t2, $t1
			mul	$t2, $t2, 4

			add	$t4, $a0, $t2

			lw	$t5, ($t4)

			add	$t0, $t0, $t5

			add	$t3, $t3, 1

			blt	$t3, 9, innerLoop

		checkColSum:
		bne	$t0, 45, setFalse

		add	$t1, $t1, 1

		blt	$t1, 9, columnLoop



#################SUB GRIDS
	############################### grid 1
	li	$t0, 0		#sum
	li	$t1, 0		#row idx

	grid1:
	li	$t2, 0		#column idx
		grid1rows:
			mul	$t3, $t1, GRID_SIZE
			add	$t3, $t3, $t2
			mul	$t3, $t3, 4
			
			add	$t4, $a0, $t3

			lw	$t5, ($t4)

			add	$t0, $t0, $t5

			add	$t2, $t2, 1

			blt	$t2, 3, grid1rows

	add	$t1, $t1, 1

	blt	$t1, 3, grid1

	bne	$t0, 45, setFalse
		
	
	############################### grid 2
	li	$t0, 0		#sum
	li	$t1, 0		#row idx
	grid2:
	li	$t2, 3		#column idx
		grid2rows:
			mul	$t3, $t1, GRID_SIZE
			add	$t3, $t3, $t2
			mul	$t3, $t3, 4
			
			add	$t4, $a0, $t3

			lw	$t5, ($t4)

			add	$t0, $t0, $t5

			add	$t2, $t2, 1

			blt	$t2, 6, grid2rows

	add	$t1, $t1, 1

	blt	$t1, 3, grid2

	bne	$t0, 45, setFalse
		

	############################### grid 3
	li	$t0, 0		#sum
	li	$t1, 0		#row idx
	grid3:
	li	$t2, 6		#column idx
		grid3rows:
			mul	$t3, $t1, GRID_SIZE
			add	$t3, $t3, $t2
			mul	$t3, $t3, 4
			
			add	$t4, $a0, $t3

			lw	$t5, ($t4)

			add	$t0, $t0, $t5

			add	$t2, $t2, 1

			blt	$t2, 9, grid3rows

	add	$t1, $t1, 1

	blt	$t1, 3, grid3

	bne	$t0, 45, setFalse
		

################################ ROW 2 OF SUBGRIDS

############################### grid 4
	li	$t0, 0		#sum
	li	$t1, 3		#row idx

	grid4:
	li	$t2, 0		#column idx
		grid4rows:
			mul	$t3, $t1, GRID_SIZE
			add	$t3, $t3, $t2
			mul	$t3, $t3, 4
			
			add	$t4, $a0, $t3

			lw	$t5, ($t4)

			add	$t0, $t0, $t5

			add	$t2, $t2, 1

			blt	$t2, 3, grid4rows

	add	$t1, $t1, 1

	blt	$t1, 6, grid4

	bne	$t0, 45, setFalse
		
	
	############################### grid 5
	li	$t0, 0		#sum
	li	$t1, 3		#row idx
	grid5:
	li	$t2, 3		#column idx
		grid5rows:
			mul	$t3, $t1, GRID_SIZE
			add	$t3, $t3, $t2
			mul	$t3, $t3, 4
			
			add	$t4, $a0, $t3

			lw	$t5, ($t4)

			add	$t0, $t0, $t5

			add	$t2, $t2, 1

			blt	$t2, 6, grid5rows

	add	$t1, $t1, 1

	blt	$t1, 6, grid5

	bne	$t0, 45, setFalse
		

	############################### grid 6
	li	$t0, 0		#sum
	li	$t1, 3		#row idx
	grid6:
	li	$t2, 6		#column idx
		grid6rows:
			mul	$t3, $t1, GRID_SIZE
			add	$t3, $t3, $t2
			mul	$t3, $t3, 4
			
			add	$t4, $a0, $t3

			lw	$t5, ($t4)

			add	$t0, $t0, $t5

			add	$t2, $t2, 1

			blt	$t2, 9, grid6rows

	add	$t1, $t1, 1

	blt	$t1, 6, grid6

	bne	$t0, 45, setFalse

############################################## row 3 of sub grids
############################### grid 7
	li	$t0, 0		#sum
	li	$t1, 6		#row idx

	grid7:
	li	$t2, 0		#column idx
		grid7rows:
			mul	$t3, $t1, GRID_SIZE
			add	$t3, $t3, $t2
			mul	$t3, $t3, 4
			
			add	$t4, $a0, $t3

			lw	$t5, ($t4)

			add	$t0, $t0, $t5

			add	$t2, $t2, 1

			blt	$t2, 3, grid7rows

	add	$t1, $t1, 1

	blt	$t1, 9, grid7

	bne	$t0, 45, setFalse
		
	
	############################### grid 8
	li	$t0, 0		#sum
	li	$t1, 6		#row idx
	grid8:
	li	$t2, 3		#column idx
		grid8rows:
			mul	$t3, $t1, GRID_SIZE
			add	$t3, $t3, $t2
			mul	$t3, $t3, 4
			
			add	$t4, $a0, $t3

			lw	$t5, ($t4)

			add	$t0, $t0, $t5

			add	$t2, $t2, 1

			blt	$t2, 6, grid8rows

	add	$t1, $t1, 1

	blt	$t1, 9, grid8

	bne	$t0, 45, setFalse
		

	############################### grid 9
	li	$t0, 0		#sum
	li	$t1, 6		#row idx
	grid9:
	li	$t2, 6		#column idx
		grid9rows:
			mul	$t3, $t1, GRID_SIZE
			add	$t3, $t3, $t2
			mul	$t3, $t3, 4
			
			add	$t4, $a0, $t3

			lw	$t5, ($t4)

			add	$t0, $t0, $t5

			add	$t2, $t2, 1

			blt	$t2, 9, grid9rows

	add	$t1, $t1, 1

	blt	$t1, 9, grid9

	bne	$t0, 45, setFalse

	setTrue:
	lb	$a1, isValid
	j	returnFunc

	setFalse:
	lb	$a1, notValid

	returnFunc:
	jr	$ra
.end	sudokuVerify


# ---------------------------------------------------------
#  Function to zero 'found' array (9)

# -----
#  Arguments
#	$a0 - address of 'found' array
# -----
#  Returns
#	found array, all entries set to false.

.globl	zeroFoundArray
.ent	zeroFoundArray
zeroFoundArray:


#	YOUR CODE GOES HERE

	#9 elements in found array
		
#	li	($a0), FALSE	#found[0]
#	li	4($a0), FALSE	#found[1]
#	li	8($a0), FALSE	#found[2]
#	li	12($a0), FALSE	#found[3]
#	li	16($a0), FALSE	#found[4]
#	li	20($a0), FALSE	#found[5]
#	li	24($a0), FALSE	#found[6]
#	li	28($a0), FALSE	#found[7]
#	li	32($a0), FALSE	#found[8]

	jr	$ra		#return to main

.end	zeroFoundArray


# ---------------------------------------------------------
#  Function to check 'found' array.
#	if a FALSE is found, returns FALSE
#	if no FALSE is found, returns TRUE

# -----
#  Arguments
#	$a0 - address of 'found' array
# -----
#  Returns
#	$v0 - FALSE or TRUE

.globl	checkFoundArray
.ent	checkFoundArray
checkFoundArray:


#	YOUR CODE GOES HERE


	jr	$ra
.end	checkFoundArray


# ---------------------------------------------------------
#  Function to set 'found' array.
#	sets found($a1)

# -----
#  Arguments
#	$a0 - address of 'found' array
#	$a1 - index to set
# -----
#  Returns
#	found array, with $a1 entries set to true

.globl	setFoundArray
.ent	setFoundArray
setFoundArray:


#	YOUR CODE GOES HERE


	jr	$ra
.end	setFoundArray


# ---------------------------------------------------------
#  Procedure to display formatted Sudoku grid to output.
#	formatting as per assignment directions

#  Arguments:
#	$a0 - starting address of matrix to ptint
#	$a1 - flag valid (true) or not valid (false)

.globl	displaySudoku
.ent	displaySudoku
displaySudoku:


#	YOUR CODE GOES HERE

	#save $a0
	move	$t0, $a0

	
	#print new line
	la	$a0, new_ln
	li	$v0, 4
	syscall
	
	#print first line of separators
	la	$a0, top_ln
	li	$v0, 4
	syscall

	#doublespace
	la	$a0, space2
	li	$v0, 4
	syscall
	
	#print bar
	la	$a0, bar
	li	$v0, 4
	syscall

	#num 1
	lw	$a0, ($t0)
	li	$v0, 1
	syscall

	#space
	la	$a0, space
	li	$v0, 4
	syscall

	#num 2
	lw	$a0, 4($t0)
	li	$v0, 1
	syscall

	#space
	la	$a0, space
	li	$v0, 4
	syscall

	#num 3
	lw	$a0, 8($t0)
	li	$v0, 1
	syscall

	#space
	la	$a0, space
	li	$v0, 4
	syscall

	#print bar
	la	$a0, bar
	li	$v0, 4
	syscall

	#num 4
	lw	$a0, 12($t0)
	li	$v0, 1
	syscall

	#space
	la	$a0, space
	li	$v0, 4
	syscall

	#num 5
	lw	$a0, 16($t0)
	li	$v0, 1
	syscall

	#space
	la	$a0, space
	li	$v0, 4
	syscall

	#num 6
	lw	$a0, 20($t0)
	li	$v0, 1
	syscall

	#space
	la	$a0, space
	li	$v0, 4
	syscall

	#bar
	la	$a0, bar
	li	$v0, 4
	syscall

	#num 7
	lw	$a0, 24($t0)
	li	$v0, 1
	syscall

	#space
	la	$a0, space
	li	$v0, 4
	syscall

	#num 8
	lw	$a0, 28($t0)
	li	$v0, 1
	syscall
	
	#space
	la	$a0, space
	li	$v0, 4
	syscall

	#num 9
	lw	$a0, 32($t0)
	li	$v0, 1
	syscall

	#space
	la	$a0, space
	li	$v0, 4
	syscall

	#bar
	la	$a0, bar
	li	$v0, 4
	syscall

	#new line
	la	$a0, new_ln
	li	$v0, 4
	syscall

	##doublespace
	la	$a0, space2
	li	$v0, 4
	syscall



	################# ROW 2
	#print bar
	la	$a0, bar
	li	$v0, 4
	syscall

	#num 1
	lw	$a0, 36($t0)
	li	$v0, 1
	syscall

	#space
	la	$a0, space
	li	$v0, 4
	syscall

	#num 2
	lw	$a0, 40($t0)
	li	$v0, 1
	syscall

	#space
	la	$a0, space
	li	$v0, 4
	syscall

	#num 3
	lw	$a0, 44($t0)
	li	$v0, 1
	syscall

	#space
	la	$a0, space
	li	$v0, 4
	syscall

	#print bar
	la	$a0, bar
	li	$v0, 4
	syscall

	#num 4
	lw	$a0, 48($t0)
	li	$v0, 1
	syscall

	#space
	la	$a0, space
	li	$v0, 4
	syscall

	#num 5
	lw	$a0, 52($t0)
	li	$v0, 1
	syscall

	#space
	la	$a0, space
	li	$v0, 4
	syscall

	#num 6
	lw	$a0, 56($t0)
	li	$v0, 1
	syscall

	#space
	la	$a0, space
	li	$v0, 4
	syscall

	#bar
	la	$a0, bar
	li	$v0, 4
	syscall

	#num 7
	lw	$a0, 60($t0)
	li	$v0, 1
	syscall

	#space
	la	$a0, space
	li	$v0, 4
	syscall

	#num 8
	lw	$a0, 64($t0)
	li	$v0, 1
	syscall

	#space
	la	$a0, space
	li	$v0, 4
	syscall

	#num 9
	lw	$a0, 68($t0)
	li	$v0, 1
	syscall

	#space
	la	$a0, space
	li	$v0, 4
	syscall

	#bar
	la	$a0, bar
	li	$v0, 4
	syscall

	#new line
	la	$a0, new_ln
	li	$v0, 4
	syscall

	##doublespace
	la	$a0, space2
	li	$v0, 4
	syscall
	
	

	################ ROW 3
	#print bar
	la	$a0, bar
	li	$v0, 4
	syscall

	#num 1
	lw	$a0, 72($t0)
	li	$v0, 1
	syscall

	#space
	la	$a0, space
	li	$v0, 4
	syscall

	#num 2
	lw	$a0, 76($t0)
	li	$v0, 1
	syscall

	#space
	la	$a0, space
	li	$v0, 4
	syscall

	#num 3
	lw	$a0, 80($t0)
	li	$v0, 1
	syscall

	#space
	la	$a0, space
	li	$v0, 4
	syscall

	#print bar
	la	$a0, bar
	li	$v0, 4
	syscall

	#num 4
	lw	$a0, 84($t0)
	li	$v0, 1
	syscall

	#space
	la	$a0, space
	li	$v0, 4
	syscall

	#num 5
	lw	$a0, 88($t0)
	li	$v0, 1
	syscall

	#space
	la	$a0, space
	li	$v0, 4
	syscall

	#num 6
	lw	$a0, 92($t0)
	li	$v0, 1
	syscall

	#space
	la	$a0, space
	li	$v0, 4
	syscall

	#bar
	la	$a0, bar
	li	$v0, 4
	syscall

	#num 7
	lw	$a0, 96($t0)
	li	$v0, 1
	syscall

	#space
	la	$a0, space
	li	$v0, 4
	syscall

	#num 8
	lw	$a0, 100($t0)
	li	$v0, 1
	syscall

	#space
	la	$a0, space
	li	$v0, 4
	syscall

	#num 9
	lw	$a0, 104($t0)
	li	$v0, 1
	syscall

	#space
	la	$a0, space
	li	$v0, 4
	syscall

	#bar
	la	$a0, bar
	li	$v0, 4
	syscall

	la	$a0, new_ln
	li	$v0, 4
	syscall

	#############DIVIDERS
	la	$a0, top_ln
	li	$v0, 4
	syscall

	###################ROW 4

	##doublespace
	la	$a0, space2
	li	$v0, 4
	syscall
	
		#print bar
	la	$a0, bar
	li	$v0, 4
	syscall

	#num 1
	lw	$a0, 108($t0)
	li	$v0, 1
	syscall

	#space
	la	$a0, space
	li	$v0, 4
	syscall

	#num 2
	lw	$a0, 112($t0)
	li	$v0, 1
	syscall

	#space
	la	$a0, space
	li	$v0, 4
	syscall

	#num 3
	lw	$a0, 116($t0)
	li	$v0, 1
	syscall

	#space
	la	$a0, space
	li	$v0, 4
	syscall

	#print bar
	la	$a0, bar
	li	$v0, 4
	syscall

	#num 4
	lw	$a0, 120($t0)
	li	$v0, 1
	syscall

	#space
	la	$a0, space
	li	$v0, 4
	syscall

	#num 5
	lw	$a0, 124($t0)
	li	$v0, 1
	syscall

	#space
	la	$a0, space
	li	$v0, 4
	syscall

	#num 6
	lw	$a0, 128($t0)
	li	$v0, 1
	syscall

	#space
	la	$a0, space
	li	$v0, 4
	syscall

	#bar
	la	$a0, bar
	li	$v0, 4
	syscall

	#num 7
	lw	$a0, 132($t0)
	li	$v0, 1
	syscall

	#space
	la	$a0, space
	li	$v0, 4
	syscall

	#num 8
	lw	$a0, 136($t0)
	li	$v0, 1
	syscall

	#space
	la	$a0, space
	li	$v0, 4
	syscall

	#num 9
	lw	$a0, 140($t0)
	li	$v0, 1
	syscall	

	#	#space
	la	$a0, space
	li	$v0, 4
	syscall

	#bar
	la	$a0, bar
	li	$v0, 4
	syscall

	############### ROW 5
	#new line
	la	$a0, new_ln
	li	$v0, 4
	syscall

	##doublespace
	la	$a0, space2
	li	$v0, 4
	syscall
	
	#print bar
	la	$a0, bar
	li	$v0, 4
	syscall

	#num 1
	lw	$a0, 144($t0)
	li	$v0, 1
	syscall

	#space
	la	$a0, space
	li	$v0, 4
	syscall

	#num 2
	lw	$a0, 148($t0)
	li	$v0, 1
	syscall

	#space
	la	$a0, space
	li	$v0, 4
	syscall

	#num 3
	lw	$a0, 152($t0)
	li	$v0, 1
	syscall

	#space
	la	$a0, space
	li	$v0, 4
	syscall

	#print bar
	la	$a0, bar
	li	$v0, 4
	syscall

	#num 4
	lw	$a0, 156($t0)
	li	$v0, 1
	syscall

	#space
	la	$a0, space
	li	$v0, 4
	syscall

	#num 5
	lw	$a0, 160($t0)
	li	$v0, 1
	syscall

	#space
	la	$a0, space
	li	$v0, 4
	syscall

	#num 6
	lw	$a0, 164($t0)
	li	$v0, 1
	syscall

	#space
	la	$a0, space
	li	$v0, 4
	syscall

	#bar
	la	$a0, bar
	li	$v0, 4
	syscall

	#num 7
	lw	$a0, 168($t0)
	li	$v0, 1
	syscall

	#space
	la	$a0, space
	li	$v0, 4
	syscall

	#num 8
	lw	$a0, 172($t0)
	li	$v0, 1
	syscall

	#space
	la	$a0, space
	li	$v0, 4
	syscall

	#num 9
	lw	$a0, 176($t0)
	li	$v0, 1
	syscall	

	#	#space
	la	$a0, space
	li	$v0, 4
	syscall

	#bar
	la	$a0, bar
	li	$v0, 4
	syscall


	########## ROW 6 
		#new line
	la	$a0, new_ln
	li	$v0, 4
	syscall

	##doublespace
	la	$a0, space2
	li	$v0, 4
	syscall
	
	#print bar
	la	$a0, bar
	li	$v0, 4
	syscall

	#num 1
	lw	$a0, 180($t0)
	li	$v0, 1
	syscall

	#space
	la	$a0, space
	li	$v0, 4
	syscall

	#num 2
	lw	$a0, 184($t0)
	li	$v0, 1
	syscall

	#space
	la	$a0, space
	li	$v0, 4
	syscall

	#num 3
	lw	$a0, 188($t0)
	li	$v0, 1
	syscall

	#space
	la	$a0, space
	li	$v0, 4
	syscall

	#print bar
	la	$a0, bar
	li	$v0, 4
	syscall

	#num 4
	lw	$a0, 192($t0)
	li	$v0, 1
	syscall

	#space
	la	$a0, space
	li	$v0, 4
	syscall

	#num 5
	lw	$a0, 196($t0)
	li	$v0, 1
	syscall

	#space
	la	$a0, space
	li	$v0, 4
	syscall

	#num 6
	lw	$a0, 200($t0)
	li	$v0, 1
	syscall

	#space
	la	$a0, space
	li	$v0, 4
	syscall

	#bar
	la	$a0, bar
	li	$v0, 4
	syscall

	#num 7
	lw	$a0, 204($t0)
	li	$v0, 1
	syscall

	#space
	la	$a0, space
	li	$v0, 4
	syscall

	#num 8
	lw	$a0, 208($t0)
	li	$v0, 1
	syscall

	#space
	la	$a0, space
	li	$v0, 4
	syscall

	#num 9
	lw	$a0, 212($t0)
	li	$v0, 1
	syscall	

	#	#space
	la	$a0, space
	li	$v0, 4
	syscall

	#bar
	la	$a0, bar
	li	$v0, 4
	syscall

	########## DIVIDERS
	#new line
	la	$a0, new_ln
	li	$v0, 4
	syscall

	la	$a0, top_ln
	li	$v0, 4
	syscall

	########################## ROW 7
	##doublespace
	la	$a0, space2
	li	$v0, 4
	syscall
	
		#print bar
	la	$a0, bar
	li	$v0, 4
	syscall

	#num 1
	lw	$a0, 216($t0)
	li	$v0, 1
	syscall

	#space
	la	$a0, space
	li	$v0, 4
	syscall

	#num 2
	lw	$a0, 220($t0)
	li	$v0, 1
	syscall

	#space
	la	$a0, space
	li	$v0, 4
	syscall

	#num 3
	lw	$a0, 224($t0)
	li	$v0, 1
	syscall

	#space
	la	$a0, space
	li	$v0, 4
	syscall

	#print bar
	la	$a0, bar
	li	$v0, 4
	syscall

	#num 4
	lw	$a0, 228($t0)
	li	$v0, 1
	syscall

	#space
	la	$a0, space
	li	$v0, 4
	syscall

	#num 5
	lw	$a0, 232($t0)
	li	$v0, 1
	syscall

	#space
	la	$a0, space
	li	$v0, 4
	syscall

	#num 6
	lw	$a0, 236($t0)
	li	$v0, 1
	syscall

	#space
	la	$a0, space
	li	$v0, 4
	syscall

	#bar
	la	$a0, bar
	li	$v0, 4
	syscall

	#num 7
	lw	$a0, 240($t0)
	li	$v0, 1
	syscall

	#space
	la	$a0, space
	li	$v0, 4
	syscall

	#num 8
	lw	$a0, 244($t0)
	li	$v0, 1
	syscall

	#space
	la	$a0, space
	li	$v0, 4
	syscall

	#num 9
	lw	$a0, 248($t0)
	li	$v0, 1
	syscall	

	#	#space
	la	$a0, space
	li	$v0, 4
	syscall

	#bar
	la	$a0, bar
	li	$v0, 4
	syscall


	###################### ROW 8
	
	#new line
	la	$a0, new_ln
	li	$v0, 4
	syscall

	##doublespace
	la	$a0, space2
	li	$v0, 4
	syscall
	
	#print bar
	la	$a0, bar
	li	$v0, 4
	syscall

	#num 1
	lw	$a0, 252($t0)
	li	$v0, 1
	syscall

	#space
	la	$a0, space
	li	$v0, 4
	syscall

	#num 2
	lw	$a0, 256($t0)
	li	$v0, 1
	syscall

	#space
	la	$a0, space
	li	$v0, 4
	syscall

	#num 3
	lw	$a0, 260($t0)
	li	$v0, 1
	syscall

	#space
	la	$a0, space
	li	$v0, 4
	syscall

	#print bar
	la	$a0, bar
	li	$v0, 4
	syscall

	#num 4
	lw	$a0, 264($t0)
	li	$v0, 1
	syscall

	#space
	la	$a0, space
	li	$v0, 4
	syscall

	#num 5
	lw	$a0, 268($t0)
	li	$v0, 1
	syscall

	#space
	la	$a0, space
	li	$v0, 4
	syscall

	#num 6
	lw	$a0, 272($t0)
	li	$v0, 1
	syscall

	#space
	la	$a0, space
	li	$v0, 4
	syscall

	#bar
	la	$a0, bar
	li	$v0, 4
	syscall

	#num 7
	lw	$a0, 276($t0)
	li	$v0, 1
	syscall

	#space
	la	$a0, space
	li	$v0, 4
	syscall

	#num 8
	lw	$a0, 280($t0)
	li	$v0, 1
	syscall

	#space
	la	$a0, space
	li	$v0, 4
	syscall

	#num 9
	lw	$a0, 284($t0)
	li	$v0, 1
	syscall	

	#	#space
	la	$a0, space
	li	$v0, 4
	syscall

	#bar
	la	$a0, bar
	li	$v0, 4
	syscall


	########################## ROW 9
	
		#new line
	la	$a0, new_ln
	li	$v0, 4
	syscall

	##doublespace
	la	$a0, space2
	li	$v0, 4
	syscall
	
	#print bar
	la	$a0, bar
	li	$v0, 4
	syscall

	#num 1
	lw	$a0, 288($t0)
	li	$v0, 1
	syscall

	#space
	la	$a0, space
	li	$v0, 4
	syscall

	#num 2
	lw	$a0, 292($t0)
	li	$v0, 1
	syscall

	#space
	la	$a0, space
	li	$v0, 4
	syscall

	#num 3
	lw	$a0, 296($t0)
	li	$v0, 1
	syscall

	#space
	la	$a0, space
	li	$v0, 4
	syscall

	#print bar
	la	$a0, bar
	li	$v0, 4
	syscall

	#num 4
	lw	$a0, 300($t0)
	li	$v0, 1
	syscall

	#space
	la	$a0, space
	li	$v0, 4
	syscall

	#num 5
	lw	$a0, 304($t0)
	li	$v0, 1
	syscall

	#space
	la	$a0, space
	li	$v0, 4
	syscall

	#num 6
	lw	$a0, 308($t0)
	li	$v0, 1
	syscall

	#space
	la	$a0, space
	li	$v0, 4
	syscall

	#bar
	la	$a0, bar
	li	$v0, 4
	syscall

	#num 7
	lw	$a0, 312($t0)
	li	$v0, 1
	syscall

	#space
	la	$a0, space
	li	$v0, 4
	syscall

	#num 8
	lw	$a0, 316($t0)
	li	$v0, 1
	syscall

	#space
	la	$a0, space
	li	$v0, 4
	syscall

	#num 9
	lw	$a0, 320($t0)
	li	$v0, 1
	syscall	

	#	#space
	la	$a0, space
	li	$v0, 4
	syscall

	#bar
	la	$a0, bar
	li	$v0, 4
	syscall

	########## DIVIDERS
	#new line
	la	$a0, new_ln
	li	$v0, 4
	syscall

	la	$a0, top_ln
	li	$v0, 4
	syscall

	############# true or false message

	la	$a0, new_ln
	li	$v0, 4
	syscall

	#if $a1 is true or false
	beq 	$a1, 0, falseMSG

	beq	$a1, 1, trueMSG

	falseMSG:
	la	$a0, invmsg
	li	$v0, 4
	syscall
	
	j	msgSent

	trueMSG:
	la	$a0, vmsg
	li	$v0, 4
	syscall


	msgSent:

	la	$a0, new_ln
	li	$v0, 4
	syscall

	jr	$ra
.end displaySudoku

