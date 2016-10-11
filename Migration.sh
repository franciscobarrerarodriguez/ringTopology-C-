#! /bin/bash
#----Attributes
user=maria
directory="/home/francisco/Dropbox/Uptc/2016-II/SistemasDistribuidos/ringTopology-C-"
#----Migration
# Second, directory will be copied to all in the network.
while read line
do
  echo "Copying. . ."
  scp -r  $directory $user@$line:~/
done < ips
