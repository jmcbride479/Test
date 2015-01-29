# This script make directories to save the results of the simulations
 b=0    #initiation of variable
 for i in 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30; do
 a=I$i
 test -d $a   #check if exist the directories I1, I2 ...
    b=$?      #if exist b=0 otherwise b=1
    if [ $b -eq 1 ]; then

       mkdir $a  # if the directory does not exist then it is created
       
       cp control.inp config.new config.inp $a
       mv *.dat  $a
       mv config.new config.inp

       test -f history.xyz
       c=$?
       if [ $c -eq 0 ]; then
         mv history.xyz $a
       fi

       

       break
    fi
 done
