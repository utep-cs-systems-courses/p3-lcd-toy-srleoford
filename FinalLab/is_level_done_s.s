	.arch msp430g2553
	.p2align 1,0
	.text

	.global is_level_done
	.extern pIndex
	.extern level

is_level_done:
	cmp &level, &pIndex
	jz match
	mov #0, r12
	pop r0

match:
	mov #1, r12
	pop r0

	

