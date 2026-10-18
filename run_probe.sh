#!/bin/bash
echo "=== probe nop ==="
/home/conker/ido/ido5.3_recomp/cc -c -32 -mips2 -o32 -o /tmp/probe_nop.o /mnt/c/Users/Ocho/Documents/Proyectos/conker/probe_nop.c 2>&1
echo "exit_nop: $?"
echo "=== probe tlbr ==="
/home/conker/ido/ido5.3_recomp/cc -c -32 -mips2 -o32 -o /tmp/probe_tlbr.o /mnt/c/Users/Ocho/Documents/Proyectos/conker/probe_tlbr.c 2>&1
echo "exit_tlbr: $?"
