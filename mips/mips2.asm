#  CS 218, MIPS Assignment #2
#  Kavya Mohan Section 1001

#  MIPS assembly language program to calculate the
#  area for each rectangular kite in a set of
#  rectangular kites.

#  Then find est median, max, sum, and average
#  for the kite areas.


###########################################################
#  data segment

.data

pSides:
	.word	  327,   344,   310,   372,   324 
	.word	  325,   316,   362,   328,   392 
	.word	  317,   314,   315,   372,   324 
	.word	  325,   316,   362,   338,   392 
	.word	  321,   383,   333,   330,   337 
	.word	  342,   335,   358,   323,   335 
	.word	  327,   326,   326,   327,   227 
	.word	  357,   387,   399,   311,   323 
	.word	  324,   325,   326,   375,   394 
	.word	  349,   326,   362,   331,   327 
	.word	  377,   399,   397,   375,   314 
	.word	  364,   341,   342,   373,   366 
	.word	  304,   346,   323,   356,   363 
	.word	  321,   318,   377,   343,   378 
	.word	  312,   311,   310,   335,   310 
	.word	  377,   399,   377,   375,   314 
	.word	  394,   324,   312,   343,   376 
	.word	  334,   326,   332,   356,   363 
	.word	  324,   319,   322,   383,   310 
	.word	  391,   392,   329,   329,   322 

qSides:
	.word	  226,   252,   257,   267,   234 
	.word	  217,   254,   217,   225,   253 
	.word	  223,   273,   235,   261,   259 
	.word	  225,   224,   263,   247,   223 
	.word	  234,   234,   256,   264,   242 
	.word	  233,   214,   273,   231,   255 
	.word	  264,   273,   274,   223,   256 
	.word	  244,   252,   231,   242,   256 
	.word	  255,   224,   236,   275,   246 
	.word	  253,   223,   253,   267,   235 
	.word	  254,   229,   264,   267,   234 
	.word	  256,   253,   264,   253,   265 
	.word	  236,   252,   232,   231,   246 
	.word	  250,   254,   278,   288,   292 
	.word	  282,   295,   247,   252,   257 
	.word	  257,   267,   279,   288,   294 
	.word	  234,   252,   274,   286,   297 
	.word	  244,   276,   242,   236,   253 
	.word	  232,   251,   236,   287,   290 
	.word	  220,   241,   223,   232,   245 

length:	.word	100 

kiteAreas:
	.space	400 

kaMin:	.word	0 
kaMid:	.word	0 
kaMax:	.word	0 
kaSum:	.word	0 
kaAve:	.word	0 

LN_CNTR	= 6

# -----

hdr:	.ascii	"MIPS Assignment #2 \n"
	.ascii	"  Rectangular Kite Areas Program:\n"
	.ascii	"  Also finds minimum, est median, value, maximum,\n"
	.asciiz	"  sum, and average for the areas.\n\n"

a1_st:	.asciiz	"\nAreas Minimum      = "
a2_st:	.asciiz	"\nAreas Est. Median  = "
a3_st:	.asciiz	"\nAreas Maximum      = "
a4_st:	.asciiz	"\nAreas Sum          = "
a5_st:	.asciiz	"\nAreas Average      = "

newLn:	.asciiz	"\n"
blnks:	.asciiz	"  "


###########################################################
#  text/code segment

# --------------------
#  Compute Areas and statistics.

.text
.globl main
.ent main
main:

# -----
#  Display header.

	la	$a0, hdr
	li	$v0, 4
	syscall				# print header

# -----



#	YOUR CODE GOES HERE

# store address of pSides into register
la	$t1, pSides

# store address of qSides into register
la	$t2, qSides

# store address of kiteAreas into register
la	$t7, kiteAreas

# store length into register ... loop counter
lw	$t0, length

#initialize reg to 0 ... to store sum
li	$t6, 0

areaCalc:

	#check if at end of loop
	#cmp $t0 and 0 ... if true exit loop
	beqz	$t0, exitLoop

	#store pSides[n] into reg
	lw	$t3, ($t1)

	#store qSides[n] into reg
	lw	$t4, ($t2)

	#multiply pSides[n] and qSides[n]
	mul	$t3, $t3, $t4

	#divide by 2
	div	$t3, $t3, 2

	#store in kiteAreas[n]
	la	$t5, ($t7)
	sw	$t3, ($t5)
	
	#update sum
	add	$t6, $t6, $t3

	#if at last loop iteration aka n = 1.. skip iterating thru arrays
	ble	$t0, 1, updateCounter

	#iterate tru pSides
	add	$t1, $t1, 4

	#iterate thru qSides
	add	$t2, $t2, 4

	#iterate thru kiteAreas
	add	$t7, $t7, 4
	
	updateCounter:

	#decrement loop counter
	sub	$t0, $t0, 1

	#jump to beginning of loop
	j	areaCalc

exitLoop:

#sum
la	$t0, kaSum
sw	$t6, ($t0)

#average
lw	$t0, length
div	$t6, $t6, $t0
sw	$t6, kaAve

#median ... 49 + 50 ... divide by 2
la	$t0, kiteAreas
lw	$t1, 196($t0)
lw	$t2, 200($t0)
add	$t1, $t1, $t2
div	$t1, $t1, 2
sw	$t1, kaMid

#min
#initialize kaMin to first element in areas array
la	$t1, kiteAreas
lw	$t2, ($t1)
sw	$t2, kaMin

li	$t0, 0

#loop 100 times
minLoop:
	#loop checking
	beq	$t0, 100, endMinLoop

	lw	$t3, ($t1)

	#if less than kaMin .. rewrite
	lw	$t4, kaMin
	ble	$t3, $t4, newMin

	j	updateIterators

	newMin:
	sw	$t3, kaMin

	updateIterators:
	#increment loop iterator
	add	$t0, $t0, 1

	#increment thru t0
	addu	$t1, $t1, 4

	j	minLoop

endMinLoop:


#MAX
la	$t1, kiteAreas
lw	$t2, 396($t1)
sw	$t2, kaMax

li	$t0, 0

maxLoop:
	beq	$t0, 100, endMaxLoop

	lw	$t3, ($t1)

	lw	$t4, kaMax

	bgt	$t3, $t4, newMax

	j	updateIterators2

	newMax:
	sw	$t3, kaMax

	updateIterators2:
	add	$t0, $t0, 1

	addu	$t1, $t1, 4

	j	maxLoop

endMaxLoop:

##########################################################
#  Display Areas Array

# $t0 - 100 cnt loop iterator
# $t1 - line iterator

# store address of kiteAreas into register
la	$t2, kiteAreas

# store length into register ... loop counter
lw	$t0, length

#initialize reg to 0 ... to count numbers in line
li	$t1, 0

displayLoop:
#loop from index length

	#cmp $t0 and 0 ... if true exit loop
	beqz	$t0, exitDisplayLoop	

	#inner loop for each line from 1 to 6
	
	#check if line iterator is 6 
	beq	$t1, 6, outputLineFeed

	j	numberOutput
	
		outputLineFeed:
		li	$t1, 0
		
		la	$a0, newLn		# print a newline
		li	$v0, 4
		syscall

	numberOutput:

	#output current area
	#load from memory into reg $a0
	lw	$a0, ($t2)
	li	$v0, 1
	syscall

	#output spaces
	la	$a0, blnks
	li	$v0, 4
	syscall

	#increment t1
	add	$t1, $t1, 1

	#if at last loop iteration aka n = 1.. skip iterating thru arrays
	ble	$t0, 1, updateDisplayCounter

	#iterate thru kiteAreas
	addu	$t2, $t2, 4
	
	updateDisplayCounter:

	#decrement loop counter
	sub	$t0, $t0, 1

	#jump to beginning of loop
	j	displayLoop


exitDisplayLoop:

##########################################################
#  Display results.

	la	$a0, newLn		# print a newline
	li	$v0, 4
	syscall

#  Print min message followed by result.

	la	$a0, a1_st
	li	$v0, 4
	syscall				# print "min = "

	lw	$a0, kaMin
	li	$v0, 1
	syscall				# print min

# -----
#  Print middle message followed by result.

	la	$a0, a2_st
	li	$v0, 4
	syscall				# print "est med = "

	lw	$a0, kaMid
	li	$v0, 1
	syscall				# print mid

# -----
#  Print max message followed by result.

	la	$a0, a3_st
	li	$v0, 4
	syscall				# print "max = "

	lw	$a0, kaMax
	li	$v0, 1
	syscall				# print max

# -----
#  Print sum message followed by result.

	la	$a0, a4_st
	li	$v0, 4
	syscall				# print "sum = "

	lw	$a0, kaSum
	li	$v0, 1
	syscall				# print sum

# -----
#  Print average message followed by result.

	la	$a0, a5_st
	li	$v0, 4
	syscall				# print "ave = "

	lw	$a0, kaAve
	li	$v0, 1
	syscall				# print average

# -----
#  Done, terminate program.

endit:
	la	$a0, newLn		# print a newline
	li	$v0, 4
	syscall

	li	$v0, 10
	syscall				# all done!

.end main

