
cd `dirname $0`

set -e
echo $1
clang $1 -g -Wno-incompatible-pointer-types
set +e
time ./a.out

if(($? != 0));then
    lldb a.out
fi