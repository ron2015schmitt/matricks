#!/bin/bash

DIR=`dirname $0`
source ${DIR}/style.bash || exit 1

EXEC=$*

# echo $#
# [[ $# -lt 1 ]] && echo "nope" && exit 0;

echo -e "${BLUE}${BOLD}Creating run file${DEFCLR}${NORMAL}: ${EXEC}" 
echo '# ****  This was created by the command "make createrun" and will be deleted upon "make cleanall" ******************' > run
for name in ${EXEC}
do
    printf "./$name  && " >> run
done
echo "echo -e \"${BLUE}${BOLD}All executables ran succesfully${DEFCLR}${NORMAL}\"" >> run
chmod a+rx run
