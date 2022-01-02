#  CS 218, MIPS Assignment #5
#  Kavya Mohan  Section 1001
#  Nellis Parking Lot Program

###########################################################################
#  data segment

.data

# -----
#  Constants

TRUE = 1
FALSE = 0

# -----
#  Variables for main

hdr:		.ascii	"\nMIPS Assignment #5\n"
		.asciiz	"Nellis Parking Lot Program\n\n"

againPrompt:	.asciiz	"Try another parking lot size (y/n)? "

endMsg:		.ascii	"\nYou have reached recursive nirvana.\n"
		.asciiz	"Program Terminated.\n"

# -----
#  Local variables for prtNewline function.

newLine:	.asciiz	"\n"

# -----
#  Local variables for displayResult() function.

maxMsg1:	.ascii	"The maximum number of ways to park "
		.asciiz	"for a parking lot size of "
maxMsg2:	.asciiz " is "
maxMsg3:	.asciiz "."

# -----
#  Local variables for readParkingLotSize() function.

MINSIZE = 1
MAXSIZE = 50

strtMsg1:	.asciiz	"Enter parking lots size ("
strtMsg2:	.asciiz	"-"
strtMsg3:	.asciiz	"): "

errValue:	.ascii	"\nError, invalid size. "
		.asciiz	"Please re-enter.\n"

# -----
#  Local variables for askPrompt() function.

ansErr:		.asciiz	"Error, must answer with (y/n).\n"
ans:		.space	3


###########################################################################
#  text/code segment

.text
.globl main
.ent main
main:

# -----
#  Display program header.

	la	$a0, hdr
	li	$v0, 4
	syscall					# print header

# -----
#  Basic steps:
#	read praking lot size
#	compute max
#	display result

tryAgain:
	jal	readParkingLotSize
	move	$s0, $v0			# parking lot size

	move	$a0, $v0
	jal	nellisParkingLot

	move	$a0, $s0
	move	$a1, $v0
	jal	displayResult

# -----
#  See if user want to try another?

	jal	prtNewline
	la	$a0, againPrompt
	jal	askPrompt

	beq	$v0, TRUE, tryAgain

# -----
#  Done, show message and terminate program.

gameOver:
	li	$v0, 4
	la	$a0, endMsg
	syscall

	li	$v0, 10
	syscall					# all done...
.end main

# =========================================================================
#  Very simple function to print a new line.
#	Note, use of this routine is optional.

.globl	prtNewline
.ent	prtNewline
prtNewline:
	la	$a0, newLine
	li	$v0, 4
	syscall

	jr	$ra
.end	prtNewline

# =========================================================================
#  Prompt for, read, and check starting position.
#	must be > 0 and <= length

# -----
#    Arguments:
#	none

#    Returns:
#	$v0, parking lot size

.globl	readParkingLotSize
.ent	readParkingLotSize
readParkingLotSize:


#	YOUR CODE GOES HERE
	#print strtMSG1
	li	$v0, 4			#print string call num
	la	$a0, strtMsg1
	syscall


	#print MINSIZE
	li	$v0, 1
	li	$a0, 1
	syscall

	#print dash (strtMSG2)
	li	$v0, 4
	la	$a0, strtMsg2
	syscall

	#print MAXSIZE
	li	$v0, 1
	li	$a0, 100
	syscall

	#print )    (strtMSG3)
	li	$v0, 4
	la	$a0, strtMsg3
	syscall

	# receive the input
	li	$v0, 5
	syscall			#lot size in $v0

	#check if lot size is valid

		#if less than or equal to zero
		blez	$v0, sendLotERRMsg

		#if greater than maxsize
		bgt	$v0, MAXSIZE, sendLotERRMsg
		

		#jump to end of func
		j	endofFUNC

	sendLotERRMsg:
		li	$v0, 4
		la	$a0, errValue
		syscall

	endofFUNC:

	jr	$ra

.end	readParkingLotSize

# =========================================================================
#  Function to recursivly determine the maximum number of
#	ways to park in the Nellis parking lot.

# -----
#  Arguments:
#	$a0 - parking lot size

#  Returns:
#	$v0 - maximum ways

.globl	nellisParkingLot
.ent	nellisParkingLot
nellisParkingLot:


#	YOUR CODE GOES HERE

#	YOUR CODE GOES HERE
	# if n = 0 ........ 1
	# if n = 1 ........ 1
	# if n = 2 ........ 2
	# if n >= 3 ....... 


	subu	$sp, $sp, 12
	sw	$ra, ($sp)
	sw	$s0, 4($sp)

	move	$v0, $a0	#check for base cases
	#if equal to 0 ... jump to calc done 1
		blez	$a0, calcDone

	#if equal to 1 ... jump to calc done 1
		ble	$a0, 1, calcDone

	#if equal to 2 ... jump to calc done 2
		ble	$a0, 2, calcDone

	#if equal to or greater than 3
		#call func for (n-1)
		move	$s0, $a0
		sub	$a0, $a0, 1
		jal	nellisParkingLot

		#call func for (n-2)
		move	$s1, $s0		#save n
		move	$a0, $s0
		sub	$a0, $a0, 2
		move	$s0, $v0		#save fib(n-1)
		jal	fib

		#call func for (n-3)
		move	$a0, $s1
		sub	$a0, $a0, 3
		move	$s2, $v0		#save fib(n-2)
		jal	fib

		add	$v0, $v0, $s2

		add	$v0, $v0, $s0

	calcDone:
		lw	$ra, ($sp)
		lw	$s0, 4($sp)
		addu	$sp, $sp, 12

	jr	$ra

.end nellisParkingLot

# =========================================================================
#  Function to display formatted final result.

# -----
#    Arguments:
#	$a0 - parking lot size
#	$a1 - maximum number of ways to park

#    Returns:
#	n/a

.globl	displayResult
.ent	displayResult
displayResult:





.end	displayResult

# =========================================================================
#  Function to ask user if they want to do another start position.

#  Basic flow:
#	prompt user
#	read user answer (as character)
#		if y/Y -> return TRUE
#		if n/N -> return FALSE
#	otherwise, display error and re-prompt
#  Note, uses read string syscall.

# -----
#  Arguments:
#	$a0 - prompt string
#  Returns:
#	$v0 - TRUE/FALSE

.globl	askPrompt
.ent	askPrompt
askPrompt:


#	YOUR CODE GOES HERE
	move	$t0, $a0

	li	$v0, 4
	la	$a0, againPrompt
	syscall

	li	$v0, 12
	syscall		

	#if $v0 is y ... set true
	beq	$v0, y, setTrue
	

	#if $v0 is n 
	beq	$v0, n, setFalse

	#if neither
	li	$v0, 4
	la	$v0, ansErr
	syscall
	j	endofThisFunc
	
	setTrue:
	

	j	endofThisFUNC
	
	
	setFalse:

	j	endoThisFUNC


	endofThisFUNC:
	jr	$ra

.end	askPrompt

#####################################################################

