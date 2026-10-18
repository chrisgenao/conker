#!/bin/bash
# usage: check_func.sh <srcfile.c> <funcname>
SRC=$1
FUNC=$2
cp /mnt/c/Users/Ocho/Documents/Proyectos/conker/conker/src/$SRC /home/conker/conker/src/$SRC
sed -i 's/\r$//' /home/conker/conker/src/$SRC
cp /mnt/c/Users/Ocho/Documents/Proyectos/conker/conker/include/functions.h /home/conker/conker/include/functions.h
cp /mnt/c/Users/Ocho/Documents/Proyectos/conker/conker/include/variables.h /home/conker/conker/include/variables.h
cp /mnt/c/Users/Ocho/Documents/Proyectos/conker/conker/include/structs.h /home/conker/conker/include/structs.h
sed -i 's/\r$//' /home/conker/conker/include/functions.h /home/conker/conker/include/variables.h /home/conker/conker/include/structs.h
cd /home/conker/conker
/home/conker/ido/ido5.3_recomp/cc -c -32 -G 0 -Xfullwarn -Xcpluscomm -signed -nostdinc -non_shared -Wab,-r4300_mul -D_LANGUAGE_C -D_FINALROM -DF3DEX_GBI_2 -D_MIPS_SZLONG=32 -woff 649,838 -I . -I include -I include/2.0L -I include/2.0L/PR -I include/libc -I src/libultra/os -I src/libultra/audio -I src/libultra/io -O2 -g3 -mips2 -o32 -o /tmp/check.o src/$SRC 2>&1 | grep -v 'Warning 712' | head -20
echo '=== GENERATED ==='
mips-linux-gnu-objdump -d /tmp/check.o 2>/dev/null | sed -n "/<${FUNC}>:/,/^\$/p" | head -60
