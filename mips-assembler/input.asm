.text
fun: 
mfc0 k1  status
add k1 k0 k1
int0:
mtc0 k1  status
mfc0 k0 cause
int1: 
sub k0 k0 k1
mtc0 k0 cause
.data
a: .word 0:10

