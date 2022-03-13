#  CSC218, MIPS Assignment #3
#  Kavya Mohan  Section 1001
#  MIPS assembly language main program and functions:

#  * MIPS assembly language function, randomNumbers(), to create
#    a series of random numbers, which are stored in an array.
#    The pseudo random number generator uses the linear
#    congruential generator method as follows:
#        R(n+1) = ( A * R(n) + B) mod 2^24

#  * MIPS void function, printNumbers(), to print a list of right
#    justified numbers including a passed header string.

#  * MIPS assembly language function, selectionSort(), to
#    sort a list of numbers into ascending (small to large) order.
#    Uses the shell sort algorithm.

#  * MIPS value returning function, estimatedMedian(), to compute
#    the estimated median of the unsorted array. If the list length
#    is even, the estimated median is computed by summing the first,
#    last, and two middle values and then dividing by 4. If the list
#    length is odd, the estimated median is computed by summing the
#    first, last, and middle values and then dividing by 3.

#  * MIPS void function, stats(), that will find the minimum,
#    median, maximum, sum, and average of the numbers array. The
#    function is called after the list is sorted. The average should
#    be calculated and returned as a floating point value.

#  * MIPS void function, showStats(), to print the list and
#    the statistical information (minimum, maximum, median, estimated
#    median, sum, average) in the format shown in the example.
#    The numbers should be printed 10 per line (see example).
#    In addition, the function should compute and display the difference
#    between actual median and the estimated median (as a floating
#    point value). The formula for percentage change is as follows:
#	pctDiff = (estimate median − actual median) / actual_median


#####################################################################
#  data segment

.data

# -----
#  Data declarations for main.

lst1:		.space		60		# 15 * 4
len1:		.word		15
seed1:		.word		19
min1:		.word		0
med1:		.word		0
max1:		.word		0
estMed1:	.word		0
fSum1:		.float		0.0
fAve1:		.float		0.0


lst2:		.space		340		# 85 * 4
len2:		.word		85
seed2:		.word		39
min2:		.word		0
med2:		.word		0
max2:		.word		0
estMed2:	.word		0
fSum2:		.float		0.0
fAve2:		.float		0.0

lst3:		.space		2800		# 700 * 4
len3:		.word		700
seed3:		.word		239
min3:		.word		0
med3:		.word		0
max3:		.word		0
estMed3:	.word		0
fSum3:		.float		0.0
fAve3:		.float		0.0

lst4:		.space		14160		# 3540 * 4
len4:		.word		3540
seed4:		.word		137
min4:		.word		0
med4:		.word		0
max4:		.word		0
estMed4:	.word		0
fSum4:		.float		0.0
fAve4:		.float		0.0

lst5:		.space		16628		# 4157 * 4
len5:		.word		4157
seed5:		.word		731
min5:		.word		0
med5:		.word		0
max5:		.word		0
estMed5:	.word		0
fSum5:		.float		0.0
fAve5:		.float		0.0


hdr:		.asciiz	"MIPS Assignment #3\n"
hdrMain:		.ascii	"\n---------------------------"
		.asciiz	"\nData Set #"
hdrLength:	.asciiz	"\nLength: "
hdrUnsorted:	.asciiz	"\n\n Random Numbers: \n"
hdrSorted:	.asciiz	"\n Sorted Numbers: \n"

str1:		.asciiz	"         Sum = "
str2:		.asciiz	"     Average = "
str3:		.asciiz	"     Minimum = "
str4:		.asciiz	"      Median = "
str5:		.asciiz	"     Maximum = "
str6:		.asciiz	"  Est Median = "
str7:		.asciiz " Median Diff = "

# -----
#  Variables/constants for randomNumbers function.

A = 127691
B = 7
RAND_LIMIT = 100000

# -----
#  Variables/constants for selection sort function.

TRUE = 1
FALSE = 0

# -----
#  Variables/constants for printNumbers function.

fOneHundred:	.float	100.0

sp1:		.asciiz	" "
sp2:		.asciiz	"  "
sp3:		.asciiz	"   "
sp4:		.asciiz	"    "
sp5:		.asciiz	"     "
sp6:		.asciiz	"      "
sp7:		.asciiz	"       "

# -----
#  Variables for showStats function.

newLine:	.asciiz	"\n"


#####################################################################
#  text/code segment

.text

.globl	main
.ent	main
main:

# -----
#  Display Program Header.

	la	$a0, hdr
	li	$v0, 4
	syscall					# print header

	li	$s0, 1				# counter, data set number

# -----
#  Call routines:
#	* Generate random numbers
#	* Display unsorted numbers
#	* find estimated median
#	* Sort numbers
#	* Find stats (min, median, max, float sum, and float average)
#	* Display stats, show sorted numbers, find difference 
#            between estimate median and real median

# ----------------------------
#  Data Set #1
#  Headers

	la	$a0, hdrMain
	li	$v0, 4
	syscall

	move	$a0, $s0
	li	$v0, 1
	syscall

	la	$a0, hdrLength
	li	$v0, 4
	syscall

	lw	$a0, len1
	li	$v0, 1
	syscall

	add	$s0, $s0, 1

# -----
#  Generate random numbers.
#	randomNumbers(lst, len, seed)

	la	$a0, lst1
	lw	$a1, len1
	lw	$a2, seed1
	jal	randomNumbers

# -----
#  Display unsorted numbers

	la	$a0, hdrUnsorted
	la	$a1, lst1
	lw	$a2, len1
	jal	printNumbers


# -----
#  Get estimate median
#	estMed = estimatedMedian(lst, len)

	la	$a0, lst1
	lw	$a1, len1
	jal	estimatedMedian

	sw	$v0, estMed1

# -----
#  Sort numbers.
#	selectionSort(lst, len)

	la	$a0, lst1
	lw	$a1, len1
	jal	selectionSort

# -----
#  Find lists stats.
#	stats(lst, len, min, med, max, fSum, fAve)

	la	$a0, lst1			# arg #1
	lw	$a1, len1			# arg #2
	la	$a2, min1			# arg #3
	la	$a3, med1			# arg #4
	la	$t0, max1			# arg #5
	la	$t1, fSum1			# arg #6
	la	$t2, fAve1			# arg #7
	sub	$sp, $sp, 12
	sw	$t0, ($sp)
	sw	$t1, 4($sp)
	sw	$t2, 8($sp)

	jal	stats
	add	$sp, $sp, 12

# -----
#  Display stats
#	showStats(lst, len, fSum, fAve, min, med, max, estMed, dhrStr)

	la	$a0, lst1
	lw	$a1, len1
	l.s	$f2, fSum1
	l.s	$f4, fAve1
	lw	$t0, min1
	lw	$t1, med1
	lw	$t2, max1
	lw	$t3, estMed1
	la	$t4, hdrSorted
	sub	$sp, $sp, 28
	s.s	$f2, ($sp)
	s.s	$f4, 4($sp)
	sw	$t0, 8($sp)
	sw	$t1, 12($sp)
	sw	$t2, 16($sp)
	sw	$t3, 20($sp)
	sw	$t4, 24($sp)

	jal	showStats
	add	$sp, $sp, 28

# ----------------------------
#  Data Set #2

	la	$a0, hdrMain
	li	$v0, 4
	syscall

	move	$a0, $s0
	li	$v0, 1
	syscall

	la	$a0, hdrLength
	li	$v0, 4
	syscall

	lw	$a0, len2
	li	$v0, 1
	syscall

	add	$s0, $s0, 1

# -----
#  Generate random numbers.
#	randomNumbers(lst, len, seed)

	la	$a0, lst2
	lw	$a1, len2
	lw	$a2, seed2
	jal	randomNumbers

# -----
#  Display unsorted numbers

	la	$a0, hdrUnsorted
	la	$a1, lst2
	lw	$a2, len2
	jal	printNumbers


# -----
#  Get estimate median
#	estMed = estimatedMedian(lst, len)

	la	$a0, lst2
	lw	$a1, len2
	jal	estimatedMedian

	sw	$v0, estMed2

# -----
#  Sort numbers.
#	selectionSort(lst, len)

	la	$a0, lst2
	lw	$a1, len2
	jal	selectionSort

# -----
#  Find lists stats.
#	stats(lst, len, min, med, max, fSum, fAve)

	la	$a0, lst2			# arg #1
	lw	$a1, len2			# arg #2
	la	$a2, min2			# arg #3
	la	$a3, med2			# arg #4
	la	$t0, max2			# arg #5
	la	$t1, fSum2			# arg #6
	la	$t2, fAve2			# arg #7
	sub	$sp, $sp, 12
	sw	$t0, ($sp)
	sw	$t1, 4($sp)
	sw	$t2, 8($sp)

	jal	stats
	add	$sp, $sp, 12

# -----
#  Display stats
#	showStats(lst, len, fSum, fAve, min, med, max, estMed, dhrStr)

	la	$a0, lst2
	lw	$a1, len2
	l.s	$f2, fSum2
	l.s	$f4, fAve2
	lw	$t0, min2
	lw	$t1, med2
	lw	$t2, max2
	lw	$t3, estMed2
	la	$t4, hdrSorted
	sub	$sp, $sp, 28
	s.s	$f2, ($sp)
	s.s	$f4, 4($sp)
	sw	$t0, 8($sp)
	sw	$t1, 12($sp)
	sw	$t2, 16($sp)
	sw	$t3, 20($sp)
	sw	$t4, 24($sp)

	jal	showStats
	add	$sp, $sp, 28

# ----------------------------
#  Data Set #3

	la	$a0, hdrMain
	li	$v0, 4
	syscall

	move	$a0, $s0
	li	$v0, 1
	syscall

	la	$a0, hdrLength
	li	$v0, 4
	syscall

	lw	$a0, len3
	li	$v0, 1
	syscall

	add	$s0, $s0, 1

# -----
#  Generate random numbers.
#	randomNumbers(lst, len, seed)

	la	$a0, lst3
	lw	$a1, len3
	lw	$a2, seed3
	jal	randomNumbers

# -----
#  Display unsorted numbers

	la	$a0, hdrUnsorted
	la	$a1, lst3
	lw	$a2, len3
	jal	printNumbers


# -----
#  Get estimate median
#	estMed = estimatedMedian(lst, len)

	la	$a0, lst3
	lw	$a1, len3
	jal	estimatedMedian

	sw	$v0, estMed3

# -----
#  Sort numbers.
#	selectionSort(lst, len)

	la	$a0, lst3
	lw	$a1, len3
	jal	selectionSort

# -----
#  Find lists stats.
#	stats(lst, len, min, med, max, fSum, fAve)

	la	$a0, lst3			# arg #1
	lw	$a1, len3			# arg #2
	la	$a2, min3			# arg #3
	la	$a3, med3			# arg #4
	la	$t0, max3			# arg #5
	la	$t1, fSum3			# arg #6
	la	$t2, fAve3			# arg #7
	sub	$sp, $sp, 12
	sw	$t0, ($sp)
	sw	$t1, 4($sp)
	sw	$t2, 8($sp)

	jal	stats
	add	$sp, $sp, 12

# -----
#  Display stats
#	showStats(lst, len, fSum, fAve, min, med, max, estMed, dhrStr)

	la	$a0, lst3
	lw	$a1, len3
	l.s	$f2, fSum3
	l.s	$f4, fAve3
	lw	$t0, min3
	lw	$t1, med3
	lw	$t2, max3
	lw	$t3, estMed3
	la	$t4, hdrSorted
	sub	$sp, $sp, 28
	s.s	$f2, ($sp)
	s.s	$f4, 4($sp)
	sw	$t0, 8($sp)
	sw	$t1, 12($sp)
	sw	$t2, 16($sp)
	sw	$t3, 20($sp)
	sw	$t4, 24($sp)

	jal	showStats
	add	$sp, $sp, 28

# ----------------------------
#  Data Set #4

	la	$a0, hdrMain
	li	$v0, 4
	syscall

	move	$a0, $s0
	li	$v0, 1
	syscall

	la	$a0, hdrLength
	li	$v0, 4
	syscall

	lw	$a0, len4
	li	$v0, 1
	syscall

	add	$s0, $s0, 1

# -----
#  Generate random numbers.
#	randomNumbers(lst, len, seed)

	la	$a0, lst4
	lw	$a1, len4
	lw	$a2, seed4
	jal	randomNumbers

# -----
#  Display unsorted numbers

	la	$a0, hdrUnsorted
	la	$a1, lst4
	lw	$a2, len4
	jal	printNumbers

# -----
#  Get estimate median
#	estMed = estimatedMedian(lst, len)

	la	$a0, lst4
	lw	$a1, len4
	jal	estimatedMedian

	sw	$v0, estMed4

# -----
#  Sort numbers.
#	selectionSort(lst, len)

	la	$a0, lst4
	lw	$a1, len4
	jal	selectionSort

# -----
#  Find lists stats.
#	stats(lst, len, min, med, max, fSum, fAve)

	la	$a0, lst4			# arg #1
	lw	$a1, len4			# arg #2
	la	$a2, min4			# arg #3
	la	$a3, med4			# arg #4
	la	$t0, max4			# arg #5
	la	$t1, fSum4			# arg #6
	la	$t2, fAve4			# arg #7
	sub	$sp, $sp, 12
	sw	$t0, ($sp)
	sw	$t1, 4($sp)
	sw	$t2, 8($sp)

	jal	stats
	add	$sp, $sp, 12

# -----
#  Display stats
#	showStats(lst, len, fSum, fAve, min, med, max, estMed, dhrStr)

	la	$a0, lst4
	lw	$a1, len4
	l.s	$f2, fSum4
	l.s	$f4, fAve4
	lw	$t0, min4
	lw	$t1, med4
	lw	$t2, max4
	lw	$t3, estMed4
	la	$t4, hdrSorted
	sub	$sp, $sp, 28
	s.s	$f2, ($sp)
	s.s	$f4, 4($sp)
	sw	$t0, 8($sp)
	sw	$t1, 12($sp)
	sw	$t2, 16($sp)
	sw	$t3, 20($sp)
	sw	$t4, 24($sp)

	jal	showStats
	add	$sp, $sp, 28

# ----------------------------
#  Data Set #5

	la	$a0, hdrMain
	li	$v0, 4
	syscall

	move	$a0, $s0
	li	$v0, 1
	syscall

	la	$a0, hdrLength
	li	$v0, 4
	syscall

	lw	$a0, len5
	li	$v0, 1
	syscall

	add	$s0, $s0, 1

# -----
#  Generate random numbers.
#	randomNumbers(lst, len, seed)

	la	$a0, lst5
	lw	$a1, len5
	lw	$a2, seed5
	jal	randomNumbers

# -----
#  Display unsorted numbers

	la	$a0, hdrUnsorted
	la	$a1, lst5
	lw	$a2, len5
	jal	printNumbers

# -----
#  Get estimate median
#	estMed = estimatedMedian(lst, len)

	la	$a0, lst5
	lw	$a1, len5
	jal	estimatedMedian

	sw	$v0, estMed5

# -----
#  Sort numbers.
#	selectionSort(lst, len)

	la	$a0, lst5
	lw	$a1, len5
	jal	selectionSort

# -----
#  Find lists stats.
#	stats(lst, len, min, med, max, fSum, fAve)

	la	$a0, lst5			# arg #1
	lw	$a1, len5			# arg #2
	la	$a2, min5			# arg #3
	la	$a3, med5			# arg #4
	la	$t0, max5			# arg #5
	la	$t1, fSum5			# arg #6
	la	$t2, fAve5			# arg #7
	sub	$sp, $sp, 12
	sw	$t0, ($sp)
	sw	$t1, 4($sp)
	sw	$t2, 8($sp)

	jal	stats
	add	$sp, $sp, 12

# -----
#  Display stats
#	showStats(lst, len, fSum, fAve, min, med, max, estMed, dhrStr)

	la	$a0, lst5
	lw	$a1, len5
	l.s	$f2, fSum5
	l.s	$f4, fAve5
	lw	$t0, min5
	lw	$t1, med5
	lw	$t2, max5
	lw	$t3, estMed5
	la	$t4, hdrSorted
	sub	$sp, $sp, 28
	s.s	$f2, ($sp)
	s.s	$f4, 4($sp)
	sw	$t0, 8($sp)
	sw	$t1, 12($sp)
	sw	$t2, 16($sp)
	sw	$t3, 20($sp)
	sw	$t4, 24($sp)

	jal	showStats
	add	$sp, $sp, 28

# -----
#  Done, terminate program.

	li	$v0, 10
	syscall					# au revoir...

.end main

#####################################################################
#  Generate pseudo random numbers using the linear
#  congruential generator method.
#    R(n+1) = (A × Rn + B) mod 2^24

# -----
#    Arguments:
#	$a0 - starting address of the list
#	$a1 - count of random numbers to generate
#	$a2 - seed

#    Returns:
#	N/A

.globl	randomNumbers
randomNumbers:


;	YOUR CODE GOES HERE

	

	#calc 2^24 into $t2

	li	$t2, 2		#$t2 = 2
	li	$t3, 0		#$t3 = 0
	li	$t4, 24		#$t4 = 24

	powerLoop:
		mul 	$t2, $t2, 2	#$t2 = $t2 * 2
		add	$t3, $t3, 1	#increment loop counter $t3

		#if below 24 loops ... loop again
		blt	$t3, $t4, powerLoop


	#first set Rn to seed
	la	$t1, $a2	#a2 is into t1 ... 
	
	li	$t3, 0		#loop counter

	#loop runs $a1 times
	randLoop:

		#multiply Rn by A
		mul	$t1, $t1, A

		#add b
		add	$t1, $t1, B

		#mod by 2^24
		rem	$t1, $t1, $t2

		#store in array
		sw	$t1, ($a0)

		#check num of loops run
		blt	$t3, $a1, incrementRandInfo

		#if it equals ... jump outside of loop
		j	exitRandLoop

		incrementRandInfo:

		#increment list address 
		addu	$a0, $a0, 4

		#increment loop counter
		add	$t3, $t3, 1

		j	randLoop
		
	
	exitRandLoop:

	jr	$ra	#return to main

.end	randomNumbers

#####################################################################
#  Sort a list of numbers using standard selection sort.

# -----
#    Arguments:
#	$a0 - starting address of the list
#	$a1 - list length

#    Returns:
#	sorted list (via passed address)

.globl selectionSort
selectionSort:


;	YOUR CODE GOES HERE


.end selectionSort

#####################################################################
#  Find estimated median (first, last, and middle two).

# -----
#    Arguments:
#	$a0 - starting address of the list
#	$a1 - list length

#    Returns:
#	$v0, estimated median

.globl estimatedMedian
estimatedMedian:


;	YOUR CODE GOES HERE

	#store list length in reg
	move	$t0, $a1		#$t0 stores list length

	#initialize median
	li	$t1, 0
	
	#div by 2
	div	$t0, 2			#divide list length by 2

	#if $hi = 0
	beqz	$hi, evenMedian		

	#if $hi = 1
	beq	$hi, 1, oddMedian

	evenMedian:
		#add 0()
		lw	$t2, ($a0)
		add	$t1, $t1, $t2

		#add 	$lo * 4( )

		#increment $lo

		#add	$lo * 4( )

		#add	($a1 - 1) * 4 ( )

		#divide by 4

		j	medianFound



	oddMedian:
		#add first value in list

		#add last value in list

		#add middle value in list

		#divide by 3

		j	medianFound


	medianFound:
	#store from reg into $v0

	jr	$ra		#return to main
	
.end estimatedMedian


#####################################################################
#  MIPS assembly language function, stats(), that will
#    find the sum, average, minimum, maximum, and median of the list.
#    The average is returned as floating point value.

#  HLL Call:
#	call stats(lst, len, min, med, max, fSum, fAve)

# -----
#    Arguments:
#	$a0 - starting address of the list
#	$a1 - list length
#	$a2 - addr of min
#	$a3 - addr of med
#	($fp) - addr of max
#	4($fp) - addr of fSum
#	8($fp) - addr of fAve

#    Returns (via reference):
#	min
#	med
#	max
#	fSum
#	fAve

.globl stats
stats:


;	YOUR CODE GOES HERE

	#store first val in array into min and max

	#BIG LOOP
		
		#update sum

		#check if current val in less than min

		#check if current val is greater than max


	#calc average

	#calculate median

	

.end stats

#####################################################################
#  MIPS assembly language function, printNumbers(), to display
#    the right justified numbers in the passed array.
#    The numbers should be printed 10 per line (see example).

# -----
#    Arguments:
#	$a0 - address of header string
#	$a1 - starting address of the list
#	$a2 - list length

#    Returns:
#	N/A

.globl	printNumbers
printNumbers:


;	YOUR CODE GOES HERE



.end	printNumbers

#####################################################################
#  MIPS assembly language function, showStats(), to display
#    the tAreas and the statistical information:
#	sum (float), average (float), minimum, median, maximum,
#	estimated median in the presribed format.
#    The numbers should be printed four (4) per line (see example).

#  Note, due to the system calls, the saved registers must
#        be used.  As such, push/pop saved registers altered.

#  HLL Call:
#	call showStats(lst, len, fSum, fAve, min, med, max, estMed, hdrStr)

# -----
#    Arguments:
#	$a0 - starting address of the list
#	$a1 - list length
#	($fp) - sum (float)
#	4($fp) - average (float)
#	8($fp) - min
#	12($fp) - med
#	16($fp) - max
#	20($fp) - est median
#	24($fp) - header string addr

#    Returns:
#	N/A

.globl	showStats
showStats:


;	YOUR CODE GOES HERE



.end showStats

#####################################################################

