# Basic OpenMP Prefix Scan
## Approach
- This implementation of parallel prefix scan applies the 2-half approach, wherein the first half we compute the total sum and then in a subsequent second loop go on to compute the intermediate sums
- Since input size n is supplied as an int here, it restricts the algorithm to ~2B size of inputs

## File Descriptions
- a0.hpp that implements the actual OMP scan function
- a0.cpp (as supplied with the assignment)
- Makefile (with compiler optimizations disabled)
- bash scripts: Simple wrapper scripts used for faster triggering of SLURM jobs

## Summary
- Below is a quick summary of the benchmarks run on the algorithm:

| Job ID | p/n | T1 (1M) | Tp (1M) | Sp (1M) | T1 (10M) | Tp (10M) | Sp (10M) | T1 (100M) | Tp (100M) | Sp (100M) | T1 (1B) | Tp (1B) | Sp (1B) |
|--------|-----|---------|---------|---------|----------|----------|----------|-----------|-----------|-----------|---------|---------|---------|
| 267963 | 4   | 0.03    | 0.008   | 3.94    | 0.219    | 0.05     | 3.6      | 2.19      | 0.56      | 3.86      | 22.55   | 6.46    | 3.49    |
| 267964 | 8   | 0.03    | 0.004   | 6.64    | 0.219    | 0.039    | 5.57     | 2.19      | 0.379     | 5.76      | 22.6    | 4.65    | 4.86    |
| 267965 | 12  | 0.03    | 0.012   | 2.57    | 0.24     | 0.04     | 6.03     | 2.32      | 0.223     | 10.38     | 22.4    | 3.4     | 6.5     |
| 267804 | 16  | 0.03    | 0.009   | 3.73    | 0.27     | 0.04     | 5.84     | 2.77      | 0.37      | 7.47      | 30.2    | 2.31    | 13.06   |
