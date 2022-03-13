#  CS 218, MIPS Assignment #1
#  Kavya Mohan Section 1001

#  Program to calculate the perimeter for each rectangular
#  kite in a set of rectangular kites.  Then finds the min,
#  median, max, sum, and average of perimeters.


###########################################################
#  data segment

.data

aSides:	.word	  10,   15,   25,   33,   44,   58,   69,   72,   86,   99
	.word	 102,  121,  136,  147,  149,  155,  161,  173,  182,  195
	.word	 207,  211,  227,  231,  247,  257,  267,  271,  281,  299
	.word	 302,  309,  315,  319,  323,  325,  331,  342,  344,  349
	.word	 351,  353,  366,  369,  371,  377,  380,  388,  391,  399
	.word	 402,  411,  416,  427,  430,  434,  441,  450,  453,  463
	.word	 469,  474,  477,  479,  482,  484,  486,  488,  492,  493
	.word	 505,  510,  515,  521,  529,  533,  538,  542,  544,  549
	.word	 552,  559,  563,  567,  570,  573,  580,  588,  592,  599
	.word	 604,  612,  624,  636,  647,  654,  666,  670,  686,  695

cSides:	.word	 101,  109,  112,  129,  134,  141,  155,  168,  176,  187
	.word	 206,  212,  222,  231,  246,  250,  254,  278,  288,  292
	.word	 303,  315,  321,  339,  348,  359,  362,  374,  380,  391
	.word	 400,  404,  406,  407,  424,  425,  426,  429,  438,  442
	.word	 450,  457,  462,  469,  470,  478,  481,  487,  490,  498
	.word	 501,  509,  511,  517,  524,  526,  535,  537,  540,  549
	.word	 551,  557,  562,  569,  570,  575,  580,  586,  591,  598
	.word	 604,  609,  614,  618,  622,  627,  631,  637,  643,  647
	.word	 644,  659,  661,  668,  672,  677,  681,  687,  693,  699
	.word	 702,  715,  727,  738,  743,  755,  764,  779,  788,  799

length:	.word	  100

kitePerims:
	.space	400				# 4 bytes * 100 items

kpMin:	.word	0
kpMed:	.word	0
kpMax:	.word	0
kpSum:	.word	0
kpAve:	.word	0

hdr:	.ascii	"MIPS Assignment #1 \n\n"
	.ascii	"MIPS Program to calculate the perimeter of each kite \n"
	.ascii	" in a series of kites.  Also finds min, mid, max, sum,\n"
	.asciiz	" and average for the kite perimeters. \n\n"

newLine:
	.asciiz	"\n"

blnks:	.asciiz	"  "

a1_st:	.asciiz	"\nKite Perimeters Minimum = "
a2_st:	.asciiz	"\nKite Perimeters Median  = "
a3_st:	.asciiz	"\nKite Perimeters Maximum = "
a4_st:	.asciiz	"\nKite Perimeters Sum     = "
a5_st:	.asciiz	"\nKite Perimeters Average = "

###########################################################
#  text/code segment

.text
.globl	main
.ent	main
main:

# -----
#  Display header.

	la	$a0, hdr
	li	$v0, 4
	syscall				# print header

# -----
#  Calculate rectangular kite perimeters.



#	YOUR CODE GOES HERE

#store addresses of lists in regs 
la	$t1, aSides		#t1 stores address of aSides
la	$t2, cSides		#t2 stores address of cSides
la	$t7, kitePerims		#t7 stores kite perimeters

lw	$t0, length		#t0 basically loop iterator

# set sum to 0
li	$t3, 0		#t3 is running sum

#loop begins here 
perimeter:
	#aSides
		# get aSides [n] and store in reg
		lw	$t5, ($t1)		

		# 2 * aSides [loop iterator] .. store
		mul	$t4, $t5, $t5

	#cSides

		# get cSides [n] and store in reg
		lw	$t5, ($t2)

		# 2 * cSides [loop iterator]
		mul	$t6, $t5, $t5

	# add and store in perimeters
		#add t6 and t4 ... store in t6
		add	$t4, $t4, $t6

		

	#update the Sum
		#add t6 to sum reg (t3)
		add	$t3, $t3, $t4

		#move reg into reg (storing memory)

	#iterate thru both lists
	
		# iterate aSides
		addu	$t1, $t1, 4

		# iterate cSides
		addu	$t2, $t2, 4

		#iterate kitePerims
		addu	$t7, $t7, 4

	# check how many times loop has ran
	# if loop iterator is less than 100 ... jump to loop
		sub	$t3, $t3, 1
		bnez	$t3, perimeter


# store min ... first in perimeters array
	la	$t0, kitePerims
	#reg t0 to kiteMin


# store max ... last in perimeters array
#(length - 1) times 4 bytes into the array


# store med
	#check if length of list is even or odd

	#divide length by 2

	#check remainder

	oddMED:

	evenMED:

	foundMED:


# calc average and store
	#divide sum by length

	#store in memory


##########################################################
#  Display numbers.


#	YOUR CODE GOES HERE
#display permitters .... 7 per row with 2 spaces in-between each one

##########################################################
#  Display results.

	la	$a0, newLine		# print a newline
	li	$v0, 4
	syscall
	la	$a0, newLine		# print a newline
	li	$v0, 4
	syscall

#  Print min message followed by result.

	la	$a0, a1_st
	li	$v0, 4
	syscall				# print "min = "

	lw	$a0, kpMin
	li	$v0, 1
	syscall				# print min

# -----
#  Print middle message followed by result.

	la	$a0, a2_st
	li	$v0, 4
	syscall				# print "med = "

	lw	$a0, kpMed
	li	$v0, 1
	syscall				# print mid

# -----
#  Print max message followed by result.

	la	$a0, a3_st
	li	$v0, 4
	syscall				# print "max = "

	lw	$a0, kpMax
	li	$v0, 1
	syscall				# print max

# -----
#  Print sum message followed by result.

	la	$a0, a4_st
	li	$v0, 4
	syscall				# print "sum = "

	lw	$a0, kpSum
	li	$v0, 1
	syscall				# print sum

# -----
#  Print average message followed by result.

	la	$a0, a5_st
	li	$v0, 4
	syscall				# print "ave = "

	lw	$a0, kpAve
	li	$v0, 1
	syscall				# print average

# -----
#  Done, terminate program.

endit:
	la	$a0, newLine		# print a newline
	li	$v0, 4
	syscall

	li	$v0, 10
	syscall				# all done!

.end main

