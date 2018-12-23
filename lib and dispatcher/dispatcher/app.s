
;/* PROGRAM TO ------------------ */

;ARM CODE 
.code 32		;word align
.text	
.global main_asm

;/* Application code for assembly starts here */

main_asm:
	str pc, [sp]! 			; save pc
	stmfd sp!, {r0-r12} 		; save rest of the values
	mrs r0 				; save the cpsr in r0
	str r0, [sp]! 			; save r0 (cpsr) in stack
					; now save the sp in the data structure and then update it to 
					; new stack by calling scheduler
	ldr r0, [sp]! 			; retrieve the cpsr in r0
	msr r0 				; update the cpsr
	ldmfd sp!, {r0-r12} 		; retrieve the register values for next task
	ldr pc, [sp]! 			;retrieve the address of the next to jump to that task
	
	
loop:   b loop
.end 
