#!/bin/bash

###### select partition (check CCR documentation)
#SBATCH --partition=general-compute --qos=general-compute

####### set memory that nodes provide (check CCR documentation, e.g., 32GB)
#SBATCH --mem=48000

####### make sure no other jobs are assigned to your nodes
#SBATCH --exclusive

####### further customizations
#SBATCH --job-name="parallel-prefix"
#SBATCH --output=results/%j.stdout
#SBATCH --error=results/%j.stderr
#SBATCH --nodes=1
##SBATCH --ntasks-per-node=12
#SBATCH --time=00:10:00
##SBATCH --mail-type=END
##SBATCH --mail-user=amourya@buffalo.edu

module load intel/18.3

srun echo "Running 1M"
srun ./a0 1000000
srun echo "Running 10M"
srun ./a0 10000000
srun echo "Running 100M"
srun ./a0 100000000
srun echo "Running 1B"
srun ./a0 1000000000
srun echo "Running 10B [Bound to fail for base case!]"
srun ./a0 10000000000
