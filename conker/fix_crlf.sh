#!/bin/bash
cd /home/conker/conker
find . -type f \( -name "*.c" -o -name "*.h" -o -name "*.s" -o -name "*.yaml" -o -name "*.txt" -o -name "*.py" -o -name "Makefile" -o -name "*.md" \) -exec sed -i 's/\r$//' {} +
echo CR-STRIP-DONE
