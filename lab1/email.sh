#!/bin/sh
set `wc -l emails.txt`
password="PASSWORD"
email_from="kajetanzdanowicz@wp.pl"
title="important meeting"
set `cat emails.txt`
num=1;
echo $
while [ $num -le $# ] ; do
    sendEmail -f $email_from -t `sed -n ${num}p emails.txt` -a `find -name "pedeef*.pdf"` -u "`echo $title`" -m "` cat text.txt`" -s smtp.wp.pl:25 -xu `echo $email_from` -xp `echo $password`
num=$(($num + 1))
done
exit
