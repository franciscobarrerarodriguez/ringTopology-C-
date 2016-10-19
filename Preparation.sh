
#! /bin/bash
#----Attributes
user=francisco
#----Preparation
# First, a public key is created and copied to all in the network
ssh-keygen -b 4096 -t rsa
while read line
do
  ssh-copy-id $user@$line
  #ips file has all ips in the network either dynamic or static
done < ips
