make clean
make all
if [ $# -eq 0 ]; then
    echo "Running default with n=10000"
    ./a0 10000
else
    echo "Running with n=$1"
    ./a0 $1
fi
