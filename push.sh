#!/bin/bash
#folder="./test"

i=0
function readfile ()
{
#这里`为esc下面的按键符号
 for file in `ls $1`
 do
#这里的-d表示是一个directory，即目录/子文件夹
 if [ -d $1"/"$file ]
 then
#如果子文件夹则递归
  i=$(($i+1))
  readfile $1"/"$file
 else
#否则就能够读取该文件的地址
  echo $1"/"$file
  git add $1"/"$file
  i=$(($i+1))
  b=$(( $i % 10 ))
  if [ $b = 0 ]
  then
    echo $i
  fi
 fi
 done
}
#函数定义结束，这里用来运行函数
folder="."
readfile $folder

#folder="./prebuilt/toolchain"
#readfile $folder
echo $i
