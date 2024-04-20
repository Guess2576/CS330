.data               # start of data section
# put any global or static variables here

.section .rodata    # start of read-only data section
# constants here, such as strings
# modifying these during runtime causes a segmentation fault, so be cautious!
myString: .string "The answer is %d\n"

.text               # start of text /code
# everything inside .text is read-only, which includes your code!
.global main        # required, tells gcc where to begin execution

# === functions here ===

main:               # start of main() function
# preamble
pushq %rbp
movq %rsp, %rbp



# === main() code here ======================================================================================================

# set up a=2
movq $2, %rdi                   # a=2 now in RDI

# set up b=3
movq $3, %rax                   # b=3 now in RAX 

# add c=a+b 
adq %rdi, %rax                  # a(rdi) + b(rax) =c(rax) (2nd R gets the result)
                                # B now no longer in RAX, replaced by C 


# ==========================================================================================================================
# printf('The Answer is %d\n', c);
# 1. save any caller-saved registers
movq %rdi, %r12                                                             # a=2 now in r12 (alternate ways of storing caller-saved registers)
pushq %rdi                                                                  # a=2 now on stack (alternate ways of storing caller-saved registers) #1
pushq %rdi                                                                  # a=2 on stacvk again, to get 16 byte alignment. remember to pop off  #2

# 2. set up registers: 1st arg in %rdi. 2ne in %rsi, etc.
movq $myString, %rdi                                                        # pointer to string is in rdi
movq %rax, %rsi                                                             # C now in RSI (answer)
# 3. place 0 in %rax, indicates we're using 0 floating point regs
movq $0, %rax                                                               # puts a 0 in RAX to indicate no floating registers, can also do "xorq %rax, %rax"


# 4. call function
call printf

# 5. restore caller saved registers. (pop it off the stack)
popq %rdi                                                                   # return a=2 to rdi from stack (#2)
popq %rax                                                                   # return a=2 to rax from stack (#1)


# ==========================================================================================================================     if last digit of stack address is 0 then you know you're on a 16 byte boundary (good)
# clean up and return
movq $0, %rax       # place return value in rax
leave               # undo preamble, clean up the stack
ret                 # return
