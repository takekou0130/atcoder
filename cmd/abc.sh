#!/bin/zsh
set -euo pipefail
cd `dirname $0`
cd ..

if [ $# != 1 ]; then
  echo '引数が不足しています。作成したい番号を渡してください。'
  exit 1
fi

abcDir="abc-problems/"
targetDir="${abcDir}$1"

if [ -d $targetDir ]; then
  echo "${targetDir} is already exist"
else
  mkdir $targetDir
  echo "${targetDir} is created"
fi

problems=(A B C D E F G)
templatePath="./template.cpp"
for problem in $problems; do
  problemDir="${targetDir}/${problem}"
  if [ -d $problemDir ]; then
    echo "${problemDir} is already exist"
  else
    mkdir $problemDir
    cp $templatePath "${problemDir}/main.cpp"
    echo "${problemDir}/main.cpp is created"
  fi
done
