sbatch --cpus-per-task=4 --ntasks=1 --job-name="parallel-prefix-4-core" job.sh
sbatch --cpus-per-task=8 --job-name="parallel-prefix-8-core" job.sh
sbatch --cpus-per-task=12 --job-name="parallel-prefix-12-core" job.sh
sbatch --cpus-per-task=16 --job-name="parallel-prefix-16-core" job.sh
