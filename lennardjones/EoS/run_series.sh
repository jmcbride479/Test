#$ -cwd
#$ -V
#$ -m e

t1=.001
deltaP=.001
for (( c=1; c<=5; c++ ))
do
  ./smarties
  mv config.new config.inp

  test -f history.xyz
  k=$?
  if [ $k -eq 0 ]; then
    rm history.xyz
  fi

  ./smarties
  mkdir "p$t1"
  ./renames.sh
  mv I1  "p$t1"
  t2=$(echo "scale=2;$t1+$deltaP"| bc)
  echo $t1 $t2
  sed "2d" control.inp | sed  "2i  $t2         0.9" > aux
  mv aux control.inp
  t1=$t2
done
